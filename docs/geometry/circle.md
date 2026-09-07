二次元平面上の円に関する交点，接線，面積計算を扱う．

二次元平面上の円を中心 `p` と半径 `r` で表す．

- `intersect(c1, c2)`：二円の位置関係を返す．内包，内接，二点で交差，外接，離れている場合にそれぞれ $0,1,2,3,4$．
- `cross_point_cl(c, l)`：円 `c` と直線 `l` の交点を返す．接する場合は同じ点を二つ返す．
- `cross_point_cc(c1, c2)`：二円の交点を返す．接する場合は同じ点を二つ返す．
- `tangent_points(c, p)`：点 `p` から円 `c` に引いた接線の接点を返す．
- `common_tangents(c1, c2)`：二円の共通接線を列挙する．
- `common_area(c1, c2)`：二円の共通部分の面積を返す．

交点を返す関数には，交点が存在する入力を与える必要がある．

## 資料

- [geometry/circle.hpp - Nyaan's Library](https://nyaannyaan.github.io/library/geometry/circle.hpp)
