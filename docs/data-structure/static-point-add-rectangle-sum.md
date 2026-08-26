点への加算と長方形内の総和を offline で処理する．

`StaticPointAddRectangleSum<T, I>` として使う．座標の型 `I` の既定値は `int`，値の型 `T` は加減算が可能な型とする．長方形は半開領域 $[lx,rx)\times[ly,ry)$ で表す．

- `query_add(x, y, value)`：点 $(x,y)$ に `value` を加える操作を登録する．
- `query_sum(lx, rx, ly, ry)`：長方形内の点の値の総和を求めるクエリを登録する．
- `calc()`：登録順の総和クエリの答えを返す．

点とクエリの総数を $N$ として，`calc()` は $O(N\log N)$ 時間，$O(N)$ 空間．$x$ 座標順に走査し，$y$ 座標を Binary Indexed Tree で管理する．

## 資料

- [Library Checker: Rectangle Sum](https://judge.yosupo.jp/problem/rectangle_sum)
