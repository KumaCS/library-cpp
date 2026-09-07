必要になったノードだけを作る 2 次元双対セグメント木．

`DynamicDualSegmentTree2D<M, I>` として使う．`M` は可換モノイド，`I` は座標の型で，既定は `long long`．

- `DynamicDualSegmentTree2D<M, I>(xl, xr, yl, yr)`：座標範囲 $[xl,xr)\times[yl,yr)$ で初期化する．
- `apply(xl, xr, yl, yr, f)`：矩形 $[xl,xr)\times[yl,yr)$ に `f` を作用させる．
- `get(x, y)`：点 $(x,y)$ の値を返す．
- `x_nodes()`：作られた外側のノード数を返す．
- `y_nodes()`：作られた内側のノード数の合計を返す．

初期値はすべて `M::e()` とみなす．

## 計算量

座標範囲の幅を $X,Y$ とする．

- `apply`：$O(\log X\log Y)$
- `get`：$O(\log X\log Y)$

空間は，更新によって実際に作られたノード数に比例する．

2 次元版は矩形加算・一点取得のような可換な作用を想定している．
