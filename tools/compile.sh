#!/bin/zsh
set -eu

usage() {
  cat >&2 <<'EOF'
Usage: tools/compile.sh [--normal|--sanitize] [--bundle|--no-bundle] SOURCE

Modes:
  --normal       Compile with g++ -O2 (default)
  --sanitize     Compile with clang++ and AddressSanitizer/UBSan

Bundling:
  --bundle       Run oj-bundle before compiling (default)
  --no-bundle    Compile SOURCE directly

Outputs are written to the current directory as a.out and, when bundling,
bundled.cpp.
EOF
}

MODE=normal
BUNDLE=1
SOURCE=

while [[ $# -gt 0 ]]
do
  case $1 in
    --normal)
      MODE=normal
      ;;
    --sanitize)
      MODE=sanitize
      ;;
    --bundle)
      BUNDLE=1
      ;;
    --no-bundle)
      BUNDLE=0
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    -*)
      echo "Unknown option: $1" >&2
      usage
      exit 2
      ;;
    *)
      if [[ -n $SOURCE ]]
      then
        echo "Only one source file can be specified" >&2
        usage
        exit 2
      fi
      SOURCE=$1
      ;;
  esac
  shift
done

if [[ -z $SOURCE ]]
then
  usage
  exit 2
fi

if [[ ! -f $SOURCE ]]
then
  echo "Source file not found: $SOURCE" >&2
  exit 1
fi

SCRIPT_DIR=${0:A:h}
LIBRARY_DIR=${SCRIPT_DIR:h}
WORK_DIR=$PWD
COMPILE_SOURCE=$SOURCE

if [[ $BUNDLE -eq 1 ]]
then
  echo "[bundle] $SOURCE -> $WORK_DIR/bundled.cpp"
  oj-bundle "$SOURCE" -I "$LIBRARY_DIR" > "$WORK_DIR/bundled.cpp"
  COMPILE_SOURCE=$WORK_DIR/bundled.cpp
fi

if [[ $MODE == normal ]]
then
  echo "[compile: normal] g++ -> $WORK_DIR/a.out"
  g++ "$COMPILE_SOURCE" \
    -O2 \
    -std=c++20 \
    -DLOCAL \
    -I "$WORK_DIR" \
    -I "$LIBRARY_DIR" \
    -o "$WORK_DIR/a.out"
else
  echo "[compile: ASan/UBSan] clang++ -> $WORK_DIR/a.out"
  clang++ "$COMPILE_SOURCE" "$SCRIPT_DIR/sanitizer-default-options.cpp" \
    -O1 \
    -g \
    -std=c++20 \
    -DLOCAL \
    -Wall \
    -Wextra \
    -Wshadow \
    -fsanitize=address,undefined \
    -fno-sanitize-recover=all \
    -fno-omit-frame-pointer \
    -fno-optimize-sibling-calls \
    -I "$WORK_DIR" \
    -I "$LIBRARY_DIR" \
    -o "$WORK_DIR/a.out"
fi
