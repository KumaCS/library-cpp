---
name: library-doc-style
description: Write or revise Markdown documentation for this C++ competitive programming library in the established local style. Use when creating, editing, reviewing, or translating files under docs/ or similar library documentation so the result matches the repository's concise Japanese prose, math notation, API bullets, headings, and reference conventions.
---

# Library Doc Style

## 手順

1. 対象のヘッダと同じカテゴリの既存 docs を読んでから書く．
2. まとまった追加・修正を行うときは `references/style-guide.md` を読む．
3. 新しい用語を作らず，既存 docs とヘッダ内の命名を優先する．
4. 説明は簡潔かつ数式寄りにし，読者は競技プログラミングと C++ ライブラリ API に慣れている前提にする．
5. 編集後に見出し，箇条書きのネスト，inline code，LaTeX の読みやすさを確認する．

## 文書の形

対象を説明できる最小の構造にする．

- 冒頭で目的または解く問題を 1-3 個の短い段落で説明する．
- 操作やメソッドを説明するときは API 箇条書きを置く．
- `## 使い方`, `## アルゴリズム`, `## 仕組み`, `## 計算量`, `## 資料` は必要な場合だけ置く．
- 実装上の注意は長いチュートリアルにせず，API やアルゴリズムの近くに置く．
- 参考になる実装，記事，論文がある場合は末尾の `## 資料` / `## 参考資料` に置く．

## 文体

- 確立した英語の技術用語を除き，日本語で書く．
- 句読点は `，` と `．` を使う．
- コード識別子，計算量，コード内の記号，ファイル名，API 名は半角 ASCII を使う．
- 数式は既存 docs に合わせて `$...$` と `$$...$$` を使う．
- 原則として太字などの強調は使わず，文章と数式で注意点を示す．
- 宣伝調，長い導入，初心者向けに寄せすぎた説明を避ける．
- 簡潔な既存 docs を過剰に膨らませない．このライブラリでは短いメモも許容する．
