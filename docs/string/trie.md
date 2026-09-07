文字列の集合を trie で管理するデータ構造．
各ノードには，そのノードを通る登録文字列数と，そのノードで終端する文字列の ID 列を持つ．

`Trie<char_size, char_start>` として使う．
扱える文字は `char_start` 以上 `char_start + char_size` 未満であることを要求する．

- `add(s, id = -1)`：文字列 `s` を追加し，終端ノードを返す．`id = -1` のとき，追加前の登録文字列数を ID として使う．
- `insert(s, id = -1)`：`s` が存在しなければ追加して `true` を返す．既に存在する場合は何もせず `false` を返す．
- `erase(s)`：`s` が存在すれば 1 個削除して `true` を返す．存在しない場合は何もせず `false` を返す．
- `erase(s, id)`：`s` の ID 列に `id` が存在すればそれを削除して `true` を返す．存在しない場合は何もせず `false` を返す．
- `size()`, `count()`：登録されている文字列数を返す．
- `node_size()`：trie のノード数を返す．
- `empty()`：登録されている文字列がないか判定する．
- `count(s)`：`s` と一致する登録文字列数を返す．
- `count_prefix(s)`：`s` を prefix に持つ登録文字列数を返す．
- `contains(s)`：`s` が存在するか判定する．
- `find_ids(s)`：`s` と一致する登録文字列の ID 列を返す．
- `prefix_match(s)`：`s` の prefix として登録されている文字列の ID 列を返す．
- `enumerate_prefix(s)`：`s` を prefix に持つ登録文字列の ID 列を返す．
- `longest_prefix(s)`：`s` の prefix として登録されている文字列の最大長を返す．存在しない場合は `-1`．
- `root_node()`：根ノードの index を返す．
- `find_node(s)`：`s` に対応するノードの index を返す．存在しない場合は `-1`．
- `next_node(v, c)`：ノード `v` から文字 `c` で遷移した先の index を返す．存在しない場合は `-1`．
- `node(v)`：ノード `v` を返す．
- `restore(v)`：ノード `v` に対応する文字列を復元する．
- `clear()`：すべての文字列を削除する．

`erase` はノードを物理的には削除しない．

`add`, `insert`, `erase`, `count`, `count_prefix`, `contains`, `longest_prefix`, `find_node`, `restore` は文字列長を $L$ として $O(L)$ 時間．
ただし `erase(s, id)` は `s` と一致する ID の個数にも線形時間．
`find_ids(s)`, `prefix_match(s)` は返す ID 数を $K$ として $O(L+K)$ 時間．
`enumerate_prefix(s)` は走査する部分木のサイズと返す ID 数に対して線形時間．
