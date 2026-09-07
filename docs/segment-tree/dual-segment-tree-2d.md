登録された 2 次元点集合上で，矩形作用と一点取得を行う双対セグメント木．

`DualSegmentTree2D<M>` として使う．`M` は可換モノイドとする．

- `DualSegmentTree2D<M>(points)`：取得されうる点集合 `points` で初期化する．重複は取り除かれる．
- `apply(xl, xr, yl, yr, f)`：登録点 $(x,y)$ のうち $xl\leq x<xr,\ yl\leq y<yr$ を満たすものへ `f` を作用させる．
- `get(x, y)`：登録済みの点 $(x,y)$ の値を返す．
- `contains(x, y)`：点 $(x,y)$ が登録済みかを返す．

`get` する点は構築時に `points` に含まれている必要がある．

## 計算量

登録点数を $N$ とする．

- 構築：$O(N\log N)$
- `apply`：$O(\log^2 N)$
- `get`：$O(\log^2 N)$
- 空間：$O(N\log N)$

2 次元版は矩形加算・一点取得のような可換な作用を想定している．
