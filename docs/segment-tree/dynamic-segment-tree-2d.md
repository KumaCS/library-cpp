必要になったノードだけを作る 2 次元セグメント木．

`DynamicSegmentTree2D<M, I>` として使う．`M` は可換モノイド，`I` は座標の型で，既定は `long long`．

- `DynamicSegmentTree2D<M, I>(xl, xr, yl, yr)`：座標範囲 $[xl,xr)\times[yl,yr)$ で初期化する．
- `apply(x, y, v)`：点 $(x,y)$ にある値を `M::op(current, v)` で更新する．
- `get(x, y)`：点 $(x,y)$ の値を返す．
- `prod(xl, xr, yl, yr)`：$xl\leq x<xr,\ yl\leq y<yr$ の値を集約する．
- `x_nodes()`：作られた外側のノード数を返す．
- `y_nodes()`：作られた内側のノード数を返す．

初期値はすべて `M::e()` とみなす．

## 計算量

座標範囲の幅を $X,Y$ とする．

- `apply`：$O(\log X\log Y)$
- `get`：$O(\log X\log Y)$
- `prod`：$O(\log X\log Y)$

空間は，更新によって実際に作られたノード数に比例する．

## 使い分け

更新される点を事前に列挙できる場合は `SegmentTree2D` の方が速く，メモリも読みやすい．
座標集合を事前に持てない場合や，巨大な座標空間のごく一部だけを触る場合はこちらを使う．
