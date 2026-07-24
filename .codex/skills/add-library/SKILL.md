---
name: add-library
description: Add a complete public feature to this C++ competitive programming library by coordinating its header implementation, verification, and Markdown documentation. Use for end-to-end requests such as adding a new algorithm, data structure, math routine, or other library component together with appropriate tests and docs. Before implementation, present the complete proposed specification and wait for one user confirmation. Do not use for code-only, verify-only, or docs-only requests; use the corresponding focused skill instead.
---

# Add Library

## 子スキル

このスキルは詳細規約を複製せず，次のスキルを組み合わせる．作業前に各 `SKILL.md` を完全に読み，それぞれの対象作業で適用する．

- `$library-code-style`：`.codex/skills/library-code-style/SKILL.md`
- `$library-verify-style`：`.codex/skills/library-verify-style/SKILL.md`
- `$library-doc-style`：`.codex/skills/library-doc-style/SKILL.md`

## 手順

1. `AGENTS.md`，`git status --short`，対象カテゴリの近い実装・verify・docs を確認する．既存の未コミット変更をユーザーの作業として保護する．
2. 追加する公開機能，カテゴリ，basename，header path，公開型・関数・主要メソッド，前提条件，計算量，検証方針，docs の範囲を仕様案としてまとめる．内部補助ヘッダまで機械的に三点セットへ含めない．
3. 仕様案をユーザーに提示して一度確認を求め，返答を待つ．ユーザーの最初の依頼に仕様が詳しく書かれていても，理解した内容を短くまとめて確認する．承認されるまでコード，verify，docs を作成・編集しない．
4. 承認後，`$library-code-style` を使い，`<category>/<name>.hpp` を実装する．この仕様は確認済みなので，子スキルから同じ確認を重ねない．
5. `$library-verify-style` を使い，Library Checker，別の online judge，UNIT の順で適切な検証を選び，`verify/<category>/` に追加する．検証で実装上の問題が見つかった場合は手順 4 に戻る．承認済み仕様を変更する必要が生じた場合は，再実装前に変更点をユーザーへ確認する．
6. `$library-doc-style` を使い，必要な公開 docs を `docs/<category>/<name>.md` に追加し，ヘッダの `@docs` と接続する．
7. コード，verify，docs の整合性を確認してから対象テストを実行する．

## 統合確認

- ヘッダと docs のカテゴリおよび basename が対応し，`@docs` の参照先が存在することを確認する．
- verify が対象ヘッダを利用し，公開 API の主要な性質を実際に検証することを確認する．
- API 名，引数の意味，半開区間，前提条件，返り値，計算量がコードと docs で一致することを確認する．
- Library Checker 問題で十分に検証できる機能に UNIT を重複追加していないことを確認する．
- 公開機能ではない内部部品に不要な docs や独立 verify を追加していないことを確認する．
- `git diff --check` を実行し，差分が要求された追加と必要な関連修正だけであることを確認する．

## 完了条件

- 実装，必要な verify，必要な docs が揃っている．
- 対象 verify が成功している．広い影響がある場合は関連 verify も成功している．
- 既存のユーザー変更を上書きしていない．
- `coverage.md` を stage，commit，push していない．
- ユーザーが依頼していない限り，stage，commit，push を行っていない．
