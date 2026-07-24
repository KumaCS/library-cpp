---
name: library-verify-style
description: Create, revise, review, or run verification code for this C++ competitive programming library. Use for files under `verify/`, for choosing between Library Checker, another online judge, and assertion-based UNIT verification, or for deciding whether existing verification sufficiently covers a feature. Enforce the repository rule that a sufficient Library Checker problem must not be duplicated by a UNIT verification.
---

# Library Verify Style

## 手順

1. `AGENTS.md` と `git status --short` を確認し，対象機能と既存の未コミット変更を把握する．
2. 対象ヘッダの公開 API，前提条件，境界条件を読み，既存の `verify/<category>/` と Library Checker coverage を調べる．
3. 下記の優先順位で最小の検証方法を選ぶ．
4. 対象と同じカテゴリに verification-helper 形式の `.test.cpp` を追加または修正する．
5. 対象 verify を実行し，失敗時は verify と実装のどちらが誤っているか切り分ける．

## 検証方法の選択

1. 機能を十分に直接検証できる Library Checker 問題があれば使う．この場合，同じ機能のための UNIT を追加しない．
2. Library Checker に適切な問題がなければ，AOJ など安定した online judge の問題を使う．
3. 対応問題がない場合，または問題だけでは重要な API・境界条件を検証できない場合だけ UNIT を使う．既存の judge 検証と重なる部分ではなく，不足する性質を対象にする．

複数の Library Checker 問題が別々の操作を検証する場合は必要なものだけを追加する．一つの問題で複数実装を検証するときは，既存例に合わせて filename の variant 部分で区別する．

## ファイル形式

- Library Checker は `verify/<category>/LC_<problem>[.<variant>].test.cpp` とする．
- 独自 UNIT は `verify/<category>/UNIT_<feature>.test.cpp` とする．
- AOJ は周辺例に合わせて `AOJ_<problem>.test.cpp` とする．
- 1 行目に `#define PROBLEM "<url>"` を置き，続けて `template/template.hpp`，対象ヘッダ，追加依存を include する．
- judge 検証では問題の入出力を対象 API へ直接写像し，別実装を verification code 内に持ち込まない．

## UNIT の作り方

- `#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"` を使い，`main()` の回答処理より前に `assert` ベースのテストを実行する．
- 固定ケースで空入力，最小サイズ，境界値，典型操作列を確認する．
- 状態を持つ複雑な機能では，小さい愚直解とのランダム比較を優先する．必要なら既存の `util/xorshift.hpp` を使い，再現可能なテストにする．
- 実装と同じロジックを愚直解へコピーしない．公開 API 経由で検証する．
- 実行時間を抑えながら，word 境界，block 境界，符号，空区間など実装固有の境界を含める．

## 実行と確認

- online judge または `aplusb` を使う対象 verify は `tools/run_test.sh verify/...test.cpp` で実行する．
- 変更の波及が広い場合だけ `oj-verify run` などの広い検証を追加する．ネットワークが必要な実行は環境の承認規則に従う．
- Library Checker 対応状況を確認するときは `tools/library_checker_coverage.py` を利用できる．`coverage.md` はローカル確認専用とし，stage，commit，push しない．
- 成功した問題 URL，対象 API，追加した境界ケースを確認する．Library Checker で十分な機能に重複 UNIT がないことを最後に確認する．
