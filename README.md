# C++ Library

[![Actions Status](https://github.com/KumaCS/library-cpp/workflows/verify/badge.svg)](https://github.com/KumaCS/library-cpp/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://KumaCS.github.io/library-cpp/)

## 自動 verify

GitHub へ push すると [online-judge-tools/verification-helper](https://github.com/online-judge-tools/verification-helper/tree/master) を利用して自動で verify を実行します．

また verification-helper により生成されたドキュメントは Pages で確認できます．
Library Checker coverage も Pages に出力されます．

## 独自ツール

### ローカル実行

指定した verify ファイルを bundle し，サンプルをダウンロードしてローカル実行できます．

```sh
tools/run_test.sh verify/data-structure/LC_staticrmq.test.cpp
```

### Library Checker coverage

Library Checker の問題一覧と，このリポジトリ内の `verify/**/LC_*.test.cpp` の対応状況を照合します．

```sh
python3 tools/library_checker_coverage.py --refresh
```

初回や最新化したいときは `--refresh` を付けます．取得結果は `cache/library_checker_problems.json` に保存されるため，以後はネットワークなしでも実行できます．

```sh
python3 tools/library_checker_coverage.py --mode missing --format markdown
python3 tools/library_checker_coverage.py --mode covered --format json
```

markdown 出力では問題ジャンルごとに結果を表示します．
GitHub Actions では前回 push 時点との差分も確認し，対応済み問題数が減少した場合は coverage job が失敗します．
