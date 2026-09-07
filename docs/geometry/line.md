二次元平面上の直線に関する判定と幾何計算を扱う．

二次元平面上の直線を，異なる二点 `a`, `b` を用いて表す．

- `Line(a, b)`：二点 `a`, `b` を通る直線を構築する．
- `Line(A, B, C)`：$Ax+By=C$ で表される直線を構築する．
- `is_parallel(l, m)`：二直線が平行か判定する．
- `is_orthogonal(l, m)`：二直線が直交するか判定する．
- `is_intersect_ll(l, m)`：二直線が共有点をもつか判定する．
- `cross_point_ll(l, m)`：二直線の交点を返す．一致する場合は `m.a` を返し，平行かつ異なる直線は与えてはならない．
- `projection(l, p)`：点 `p` の直線 `l` への射影を返す．
- `reflection(l, p)`：直線 `l` に関して点 `p` と対称な点を返す．
- `distance_lp(l, p)`：直線 `l` と点 `p` の距離を返す．
- `convex_polygon_cut_info(P, l)`：反時計回りの狭義凸多角形 `P` と有向直線 `l.a` $\to$ `l.b` の左閉半平面との共通部分を `ConvexPolygonCutResult` で返す．$O(\log |P|)$ 時間．
- `convex_polygon_cut(P, l)`：同じ共通部分を反時計回りの `Polygon` として返す．出力頂点数を $K$ として $O(\log |P|+K)$ 時間．

## 資料

- [geometry/line.hpp - Nyaan's Library](https://nyaannyaan.github.io/library/geometry/line.hpp)
