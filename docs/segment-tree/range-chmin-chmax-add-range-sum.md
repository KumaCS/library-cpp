列に対する区間 `chmin`，区間 `chmax`，区間加算，区間和取得を扱う．

`RangeChminChmaxAddRangeSum<T>` として使う．区間は半開区間 $[l,r)$ で指定する．

- `RangeChminChmaxAddRangeSum<T>(n)`：長さ $n$，全要素 $0$ で初期化する．
- `RangeChminChmaxAddRangeSum<T>(a)`：列 `a` で初期化する．
- `set(p, x)`：$A_p\gets x$ とする．
- `get(p)`：$A_p$ を返す．
- `chmin(l, r, x)`：$l\leq i\lt r$ に対して $A_i\gets\min(A_i,x)$ とする．
- `chmax(l, r, x)`：$l\leq i\lt r$ に対して $A_i\gets\max(A_i,x)$ とする．
- `add(l, r, x)`：$l\leq i\lt r$ に対して $A_i\gets A_i+x$ とする．
- `sum(l, r)` / `prod(l, r)`：$A_l+A_{l+1}+\cdots+A_{r-1}$ を返す．
- `all_sum()` / `all_prod()`：列全体の和を返す．

空区間への更新は何もせず，空区間の和は $0$ とする．`T` は符号付き整数型とする．`B = numeric_limits<T>::max() / 4` として，全ての要素と `chmin`, `chmax` の引数が $(-B,B)$ に収まり，番兵を含む中間演算と総和が `T` の範囲に収まることを要求する．

## 計算量

- `set`, `get`, `add`, `sum`：$O(\log N)$
- `chmin`, `chmax`：償却 $O(\log^2 N)$
- `all_sum`：$O(1)$

空間計算量は $O(N)$．

## 仕組み

各節点に区間の最小値・二番目の最小値・最大値・二番目の最大値，最小値と最大値の個数，区間の要素数と総和を持つ．

`chmin` の上限が二番目の最大値より大きければ，最大値を取る要素だけが変化するため，節点の情報を直接更新できる．`chmax` も同様である．直接更新できない場合は `SegmentTreeBeats` の `fail` を立て，作用を子へ伝播して節点を再構築する．

## 資料

- [Library Checker: Range Chmin Chmax Add Range Sum](https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum)
- [atcoder::lazy_segtree に1行書き足すだけの抽象化 Segment Tree Beats](https://rsm9.hatenablog.com/entry/2021/02/01/220408)
