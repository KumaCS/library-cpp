三次元空間上の平面に関する判定，射影，交差計算を扱う．

平面を平面上の点 `p` と非零な法線ベクトル `n` を用いた `Plane3D` で表す．三点を渡して構築する場合，三点は同一直線上にあってはならない．

- `Plane3D(p, n)`：点 `p` を通り，法線ベクトルが `n` の平面を構築する．
- `Plane3D(a, b, c)`：同一直線上にない三点を通る平面を構築する．
- `plane_value(pl, p)`：$\mathrm{pl.n}\cdot(p-\mathrm{pl.p})$ を返す．
- `is_intersect_pp(pl, p)`：平面 `pl` が点 `p` を含むか判定する．
- `is_parallel(a, b)`：二平面が平行か判定する．
- `is_orthogonal(a, b)`：二平面が直交するか判定する．
- `projection(pl, p)`：点 `p` の平面 `pl` への射影を返す．
- `reflection(pl, p)`：平面 `pl` に関して点 `p` と対称な点を返す．
- `signed_distance_pp(pl, p)`：法線 `pl.n` の向きを正とする符号付き距離を返す．
- `distance_pp(pl, p)`：平面 `pl` と点 `p` の距離を返す．
- `is_intersect_lp(l, pl)`：直線 `l` と平面 `pl` が共有点をもつか判定する．直線が平面に含まれる場合も真．
- `cross_point_lp(l, pl)`：直線と平面が一点で交わる場合は交点を返す．平行または直線が平面に含まれる場合は `nullopt`．
- `distance_lp(l, pl)`：直線 `l` と平面 `pl` の距離を返す．
- `cross_line_pp(a, b)`：二平面が一つの直線で交わる場合は交線を返す．平行または一致する場合は `nullopt`．
- `distance_pp(a, b)`：二平面の距離を返す．
