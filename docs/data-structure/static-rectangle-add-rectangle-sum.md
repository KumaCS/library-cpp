長方形への加算と長方形内の総和を offline で処理する．

`StaticRectangleAddRectangleSum<T, I>` として使う．座標の型 `I` の既定値は `int`，値の型 `T` は加減算と `I` との乗算が可能な型とする．長方形は半開領域 $[lx,rx)\times[ly,ry)$ で表す．

- `query_add(lx, rx, ly, ry, value)`：長方形内の各格子点に `value` を加える操作を登録する．
- `query_sum(lx, rx, ly, ry)`：長方形内の値の総和を求めるクエリを登録する．
- `calc()`：登録順の総和クエリの答えを返す．

登録した操作の総数を $N$ として，`calc()` は $O(N\log N)$ 時間，$O(N)$ 空間．

## アルゴリズム

長方形加算を 2 次元差分により 4 個の点イベントへ変換する．点イベント $(a,b,v)$ の 2 次元累積和における $(x,y)$ への寄与は

$$
v(x-a)(y-b)=vxy-vay-vbx+vab
$$

となる．$1,x,y,xy$ の係数を 4 本の Binary Indexed Tree で管理し，$x$ 座標順に走査する．

## 資料

- [Library Checker: Static Rectangle Add Rectangle Sum](https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum)
