長方形の和集合の面積を求める．

`RectangleUnionArea<I>` として使う．座標と面積の型 `I` の既定値は `long long`．長方形は半開領域 $[lx,rx)\times[ly,ry)$ で表す．

- `add_rectangle(lx, rx, ly, ry)`：$lx<rx$ かつ $ly<ry$ を満たす長方形を追加する．
- `calc()`：追加した長方形の和集合の面積を返す．

長方形の個数を $N$ として，`calc()` は $O(N\log N)$ 時間，$O(N)$ 空間．

## アルゴリズム

$x$ 座標順に長方形の左辺と右辺を処理する．$y$ 座標を座標圧縮し，各区間を覆う長方形の個数の最小値と，その最小値を取る区間幅を Lazy Segment Tree で管理する．隣り合うイベント間の幅と，少なくとも一つの長方形に覆われる $y$ 方向の長さの積を加算する．

## 資料

- [Library Checker: Area of Union of Rectangles](https://judge.yosupo.jp/problem/area_of_union_of_rectangles)
