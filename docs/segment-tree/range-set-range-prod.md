モノイド $(T,\cdot,e)$ の列に対する区間代入と区間積を扱う．

`RangeSetRangeProd<M>` として使う．
`M` は `value_type`, `op(x,y)`, `e()` を持つモノイドを表す型．

長さ $N$ の列 $A=(A_0,A_1,\dots,A_{N-1})$ に対し，空間計算量 $O(N)$ のもとで以下の操作を行える．

- `set(p, x)`：$A_p\gets x$ とする．$O(\log N)$ 時間．
- `get(p)`：$A_p$ を取得する．$O(\log N)$ 時間．
- `apply(p, x)`：$A_p\gets x$ とする．$O(\log N)$ 時間．
- `apply(l, r, x)`：$l\leq i\lt r$ に対して $A_i\gets x$ とする．償却 $O(\log N)$ 時間．
- `prod(l, r)`：$A_l\cdot A_{l+1}\cdot\cdots\cdot A_{r-1}$ を取得する．$O(\log N)$ 時間．
- `all_prod()`：$A_0\cdot A_1\cdot\cdots\cdot A_{N-1}$ を取得する．$O(1)$ 時間．
- `max_right(l, cond)`：$\mathrm{cond}(A_l\cdot A_{l+1}\cdot\cdots\cdot A_{r-1})$ が真となる最大の $r$ を返す．$O(\log N)$ 時間．
- `min_left(r, cond)`：$\mathrm{cond}(A_l\cdot A_{l+1}\cdot\cdots\cdot A_{r-1})$ が真となる最小の $l$ を返す．$O(\log N)$ 時間．

二分探索では `cond(e)` が真であり，判定が単調であることを要求する．

## アルゴリズム

$x$ を代入するクエリごとに

$$
x,\ x^2,\ x^4,\ \dots,\ x^{2^{\lceil\log N\rceil}}
$$

を計算する．セグメント木の各節点が表す区間の長さは二冪なので，区間全体を $x$ に置き換えたときの積を $O(1)$ 回の参照で得られる．

$O(N/\log N)$ 回の区間代入ごとに全ての遅延値を子へ伝播し，保存した冪を破棄する．この伝播は $O(N)$ 時間なので，区間代入は償却 $O(\log N)$ 時間となる．全伝播が発生する単一の区間代入は最悪 $O(N)$ 時間かかる．

## 資料

- [区間代入/区間積 Θ(logN)/query](https://noshi91.hatenablog.com/entry/2019/10/05/203704)
