必要になったノードだけを作るセグメント木．

`DynamicSegmentTree<M, I>` として使う．`M` はモノイド，`I` は座標の型で，既定は `long long`．

- `DynamicSegmentTree<M, I>(l, r)`：座標範囲 $[l,r)$ で初期化する．
- `set(p, v)`：点 $p$ の値を `v` にする．
- `apply(p, v)`：点 $p$ の値を `M::op(current, v)` で更新する．
- `get(p)`：点 $p$ の値を返す．
- `prod(l, r)`：$[l,r)$ の値を集約する．
- `all_prod()`：全体を集約する．
- `node_count()`：作られたノード数を返す．

初期値はすべて `M::e()` とみなす．

## 計算量

座標範囲の幅を $N$ とする．

- `set`, `apply`, `get`, `prod`：$O(\log N)$

空間は，更新によって実際に作られたノード数に比例する．

座標集合を事前に持てる場合は通常の `SegmentTree` や座標圧縮の方が速い．
巨大な座標範囲のごく一部だけを触る場合に使う．
