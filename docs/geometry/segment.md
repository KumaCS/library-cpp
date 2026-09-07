二次元平面上の線分に関する交差判定と距離計算を扱う．

二次元平面上の線分を両端点 `a`, `b` で表す．`Segment` は `Line` を継承する．

- `is_intersect_sp(s, p)`：線分 `s` が点 `p` を含むか判定する．
- `is_intersect_ss(s, t)`：線分 `s`, `t` が交わるか判定する．端点で接する場合と重なる場合も真．
- `cross_point_ss(s, t)`：交わる二線分の交点を返す．重なる場合は一方の端点を返す．
- `distance_sp(s, p)`：線分 `s` と点 `p` の距離を返す．
- `distance_ss(s, t)`：線分 `s`, `t` の距離を返す．

## 資料

- [geometry/segment.hpp - Nyaan's Library](https://nyaannyaan.github.io/library/geometry/segment.hpp)
