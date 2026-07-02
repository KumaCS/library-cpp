#!/bin/zsh
set -eu

if [[ $# -ne 1 ]]
then
    echo "Usage: tools/run_test.sh verify/path/to/test.cpp" >&2
    exit 2
fi

SCRIPT_DIR=${0:A:h}
ROOT_DIR=${SCRIPT_DIR:h}
cd $ROOT_DIR

FILE=$1
HEAD=$(head -n 1 $FILE)

if [[ $HEAD =~ ^#define\ PROBLEM\ \"(.*)\"$ ]]
then
    URL=${match[1]}
    oj-bundle $FILE -I ./ > bundled.cpp
    rm -rf ./test-local/
    g++ bundled.cpp -O2 -std=c++20 -DLOCAL -o a.out -I . && oj d $URL -a -s -d test-local && oj t -d test-local -s
else
    echo "The file is not verification code" >&2
    exit 1
fi
