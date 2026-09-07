三次元空間上の直線に関する判定，射影，距離計算を扱う．

直線を異なる二点 `a`, `b` を用いた `Line3D` で表す．

- `is_intersect_lp(l, p)`：直線 `l` が点 `p` を含むか判定する．
- `is_parallel(l, m)`：二直線が平行か判定する．
- `is_orthogonal(l, m)`：二直線の方向ベクトルが直交するか判定する．
- `projection(l, p)`：点 `p` の直線 `l` への射影を返す．
- `reflection(l, p)`：直線 `l` に関して点 `p` と対称な点を返す．
- `closest_points_ll(l, m)`：二直線上の最近点をそれぞれ返す．平行な場合は最近点対の一つを返す．
- `distance_lp(l, p)`：直線 `l` と点 `p` の距離を返す．
- `distance_ll(l, m)`：二直線の距離を返す．ねじれの位置にも対応する．
- `is_intersect_ll(l, m)`：二直線が共有点をもつか判定する．一致する場合も真．
- `cross_point_ll(l, m)`：二直線が一点で交わる場合は交点を返す．平行，一致，ねじれの位置では `nullopt`．
