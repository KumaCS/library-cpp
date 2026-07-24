---
name: library-code-style
description: Implement, revise, or review C++ headers for this competitive programming library in the established repository style. Use for work on public or supporting `.hpp` files when Codex must choose placement, naming, API shape, templates, project-local dependencies, assertions, interval conventions, or the trailing documentation annotation. Before implementing a new library, present the proposed specification and wait for one user confirmation. Do not use for verification-only or documentation-only work.
---

# Library Code Style

## 手順

1. `AGENTS.md` と `git status --short` を確認し，既存の未コミット変更を保護する．
2. 対象と同じカテゴリから，目的と API が近い公開ヘッダを 2-3 個読む．必要な依存先も読む．
3. 公開機能か内部部品かを決め，配置，型名，API，前提条件，計算量を既存例に合わせた仕様案としてまとめる．
4. 新しいライブラリを実装する場合は，仕様案をユーザーに提示して一度確認を求め，返答を待つ．承認されるまでファイルを作成・編集しない．同じ作業で `$add-library` などが同じ仕様の確認を済ませている場合は再確認しない．既存実装の修正・レビューでは，仕様変更を伴わない限りこの確認を省略する．
5. 承認された範囲だけを実装し，無関係な整理や既存 API の変更を混ぜない．
6. 対応する既存 verify があれば実行する．新しい verify が必要な作業では `$library-verify-style` を使う．

仕様案には少なくとも，目的，配置する header path，公開型・関数・主要メソッド，区間や入力の前提条件，想定計算量を簡潔に含める．ユーザーの最初の依頼に仕様が詳しく書かれていても，実装前に理解した内容を短くまとめて確認する．

## 配置と命名

- ヘッダを原則として `<category>/<library-name>.hpp` に置く．既存カテゴリで同じ概念を扱う場合は新しいカテゴリを作らない．
- ファイル名と include path には kebab-case，型名には PascalCase，関数・メソッド・変数には snake_case を優先する．近い既存 API が別の命名を使う場合は互換性を優先する．
- ファイルを `#pragma once` で始める．
- 直接利用するプロジェクト内依存を `#include "category/file.hpp"` で明示する．標準ヘッダや `using namespace std` の扱いは周辺ヘッダに合わせ，依頼されていない self-contained 化を広げない．
- namespace は周辺実装が使う場合だけ導入する．

## 実装

- 値型，添字型，演算，代数構造を既存ライブラリと同程度に template 化する．既存の monoid，modint，FPS，graph などの抽象化を再実装しない．
- 区間 API には原則として半開区間 `[l, r)` を使う．空区間の動作を定める．
- 添字範囲，サイズ一致，非負性などの利用条件を既存コードと同様に `assert` で表す．
- 読み取り操作を可能な範囲で `const` にする．公開 API と内部状態を分け，補助型・補助関数は外部利用が必要でなければ `private` に置く．
- 返り値，番兵値，境界条件，整数 overflow，空入力を明示的に検討する．
- 短い競技プログラミング用実装を保ちつつ，計算量を悪化させるコピーや初期化を避ける．
- 不要な改行や空行を極力挟まず，連続する宣言・メソッド・処理をコンパクトに配置する．短い関数，条件式，初期化，単純な分岐は可能な範囲で 1 行に収める．
- 引数列，式，関数本体を慣習的に読みやすい長さへ収められない場合だけ改行する．空行は include 群，型やアクセス区分など明確なまとまりの境界に必要な最小限だけ置き，周辺ヘッダより疎なレイアウトにしない．

## 公開ヘッダの注釈

独立した公開機能に docs を対応させる場合，ヘッダ末尾に次の形式を置く．内部部品に機械的に docs を作らない．

```cpp
/**
 * @brief Library Name
 * @docs docs/category/library-name.md
 */
```

`@brief` は周辺ヘッダの表記に合わせる．docs 本文の作成・修正には `$library-doc-style` を使う．

## 確認

- 公開 API が要求を満たし，既存の命名と概念に自然に接続しているか確認する．
- 境界値，空入力，半開区間，型の上限，計算量を確認する．
- include path と `@docs` path が実在するか確認する．
- 変更が対象ヘッダと必要な依存修正だけに収まっているか確認する．
