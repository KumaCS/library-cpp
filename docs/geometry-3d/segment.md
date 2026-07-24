三次元空間上の線分に関する包含判定，最近点，距離計算を扱う．

線分を両端点 `a`, `b` を用いた `Segment3D` で表す．`Segment3D` は `Line3D` を継承し，両端点が一致する退化線分も扱える．

- `closest_point_sp(s, p)`：点 `p` に最も近い線分 `s` 上の点を返す．
- `closest_points_ss(s, t)`：線分 `s`, `t` 上の最近点をそれぞれ返す．
- `distance_sp(s, p)`：線分 `s` と点 `p` の距離を返す．
- `distance_ss(s, t)`：線分 `s`, `t` の距離を返す．
- `is_intersect_sp(s, p)`：線分 `s` が点 `p` を含むか判定する．
- `is_intersect_ss(s, t)`：線分 `s`, `t` が交わるか判定する．端点で接する場合と重なる場合も真．
