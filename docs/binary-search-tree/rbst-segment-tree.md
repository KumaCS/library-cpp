乱択二分探索木により，列の挿入・削除・反転と区間積を処理する．

`RBSTSegmentTree<M>` として使う．`M` はモノイドを表す型とし，列を表す根 `t` は `RBSTBase` の操作と共通である．

- `get(t, k)`：$k$ 番目の値を返す．
- `set(t, k, x)`：$k$ 番目の値を $x$ とする．
- `prod(t, l, r)`：半開区間 $[l,r)$ の積を返す．空区間では `M::e()` を返す．
- `reverse(t, l, r)`：半開区間 $[l,r)$ を反転する．

`RBSTBase` の `build`，`insert`，`erase`，`size`，`split`，`merge` も利用できる．各操作の期待時間計算量は $O(\log N)$．

## 資料

- [Library Checker: Range Reverse Range Sum](https://judge.yosupo.jp/problem/range_reverse_range_sum)
