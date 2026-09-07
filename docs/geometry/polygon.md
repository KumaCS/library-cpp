二次元平面上の多角形に関する包含判定，凸包，直径，切断を扱う．

頂点を反時計回りに並べた二次元多角形を `Polygon` で表す．

- `contains_polygon(P, p)`：単純多角形 `P` と点 `p` の位置関係を返す．外部，周上，内部ならそれぞれ $0,1,2$．`P` は凸でなくてもよい．$O(|P|)$ 時間．
- `area(P)`：多角形 `P` の符号付き面積を返す．$O(|P|)$ 時間．
- `is_convex(P)`：反時計回りの多角形 `P` が凸か判定する．周上に連続する三点が一直線上にある場合も許す．$O(|P|)$ 時間．
- `convex_hull<boundary>(ps)`：点集合 `ps` の凸包を反時計回りに返す．`boundary = true` なら周上の点をすべて含める．$O(|ps|\log |ps|)$ 時間．
- `contains_convex(C, p)`：反時計回りの凸多角形 `C` と点 `p` の位置関係を返す．外部，周上，内部ならそれぞれ $0,1,2$．$O(\log |C|)$ 時間．
- `convex_polygon_diameter(C)`：反時計回りの凸多角形 `C` の最遠点対を頂点番号の組で返す．$O(|C|)$ 時間．
- `argmax_dot(C, p)`：反時計回りの狭義凸多角形 `C` に対し，`dot(C[i], p)` を最大化する最小の頂点番号 `i` を返す．`p` は零ベクトルでないものとする．$O(\log |C|)$ 時間．
- `convex_polygon_cut_info(C, a, b)`：反時計回りの狭義凸多角形 `C` と有向直線 `a` $\to$ `b` の左閉半平面との共通部分を `ConvexPolygonCutResult` で返す．$O(\log |C|)$ 時間．
- `ConvexPolygonCutResult::to_polygon(C)`：切断結果を反時計回りの `Polygon` として構築する．出力頂点数を $K$ として $O(K)$ 時間．
- `convex_polygon_cut(C, a, b)`：`convex_polygon_cut_info(C, a, b).to_polygon(C)` を返す．$O(\log |C|+K)$ 時間．

`ConvexPolygonCutResult` の `[first, last)` は，切断後に残る元の頂点 `C[i % C.size()]` の巡回区間を表す．`front`, `back` はそれぞれ区間の前後に挿入する交点であり，交点が元の頂点に一致する場合は `nullopt` となる．

## 資料

- [geometry/polygon.hpp - Nyaan's Library](https://nyaannyaan.github.io/library/geometry/polygon.hpp)
