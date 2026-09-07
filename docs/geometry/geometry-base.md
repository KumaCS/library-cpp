二次元幾何で用いる点とベクトルの基本演算を扱う．

二次元平面上の点とベクトルを `Point` で表す．座標型は `long double` で，誤差判定には `EPS = 1e-10` を用いる．

- `dot(a, b)`：内積を返す．
- `cross(a, b)`：外積を返す．
- `abs(p)`：ベクトルの長さを返す．
- `norm(p)`：ベクトルの長さの二乗を返す．
- `arg(p)`：偏角を返す．
- `p.rotate(rad)`：`p` を反時計回りに `rad` 回転する．
- `p.rotate90()`：`p` を反時計回りに $90$ 度回転する．
- `ccw(a, b, c)`：有向直線 $a\to b$ に対する $c$ の位置を返す．反時計回りなら $1$，時計回りなら $-1$，一直線上で $c-a-b$ の順なら $2$，$a-b-c$ の順なら $-2$，線分 $ab$ 上なら $0$．

## 資料

- [geometry/geometry-base.hpp - Nyaan's Library](https://nyaannyaan.github.io/library/geometry/geometry-base.hpp)
