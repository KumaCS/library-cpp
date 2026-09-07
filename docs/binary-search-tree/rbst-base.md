乱択二分探索木

実装は [https://nyaannyaan.github.io/library/rbst/rbst-base.hpp] を参考

split / merge を基にした実装．

派生クラスで `Node` と `push`, `update` を定義して使う基底クラス．

- `make_tree()`：空の木を返す．
- `size(t)`：木 `t` のサイズを返す．
- `merge(l, r)`：列として `l` の後ろに `r` を連結する．
- `split(t, k)`：先頭 $k$ 要素と残りに分割する．
- `build(v)`：列 `v` から木を作る．
- `insert(t, k, args...)`：位置 `k` に要素を挿入する．
- `erase(t, k)`：位置 `k` の要素を削除する．

各操作の期待時間計算量は木の高さに比例し，通常 $O(\log N)$．
