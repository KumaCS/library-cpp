三次元空間上の三角形に関する面積，包含判定，距離計算を扱う．

三角形を同一直線上にない三点 `a`, `b`, `c` を用いた `Triangle3D` で表す．

- `triangle_normal(t)`：三角形 `t` の法線ベクトル $(b-a)\times(c-a)$ を返す．
- `area(t)`：三角形 `t` の面積を返す．
- `signed_volume(a, b, c, d)`：四面体 $abcd$ の符号付き体積を返す．
- `volume(a, b, c, d)`：四面体 $abcd$ の体積を返す．
- `barycentric_coordinates(t, p)`：点 `p` の重心座標を返す．三角形が退化している場合は `nullopt`．`p` が三角形の平面上にあるかは判定しない．
- `is_intersect_tp(t, p)`：三角形 `t` が点 `p` を含むか判定する．辺上と頂点も含む．
- `closest_point_tp(t, p)`：点 `p` に最も近い三角形 `t` 上の点を返す．
- `distance_tp(t, p)`：三角形 `t` と点 `p` の距離を返す．
