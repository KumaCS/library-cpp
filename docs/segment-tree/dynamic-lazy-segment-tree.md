必要になったノードだけを作る遅延伝播セグメント木．

`DynamicLazySegmentTree<A, I>` として使う．`A` は `value_monoid`, `operator_monoid`, `mapping(f, x)` を持つ作用を表す型，`I` は座標の型で，既定は `long long`．

- `DynamicLazySegmentTree<A, I>(l, r)`：座標範囲 $[l,r)$ で初期化する．初期値は全区間で `value_monoid::e()` とする．
- `DynamicLazySegmentTree<A, I>(l, r, init)`：座標範囲 $[l,r)$ で初期化する．`init(a, b)` は初期列の区間 $[a,b)$ の積を返す関数とする．
- `set(p, x)`：$A_p\gets x$ とする．
- `get(p)`：$A_p$ を取得する．
- `apply(p, f)`：$A_p\gets f A_p$ とする．
- `apply(l, r, f)`：各 $i\in[l,r)$ に対し $A_i\gets f A_i$ とする．
- `prod(l, r)`：$A_l\cdot A_{l+1}\cdot\cdots\cdot A_{r-1}$ を取得する．
- `all_prod()`：全体の積を取得する．
- `node_count()`：作られたノード数を返す．

`init` は任意の $l\leq m\leq r$ に対し次を満たす必要がある．

$$
\mathrm{init}(l,r)=\mathrm{value\_monoid::op}(\mathrm{init}(l,m),\mathrm{init}(m,r))
$$

## 計算量

座標範囲の幅を $N$ とし，`init` と各モノイド操作が $O(1)$ 時間であるとする．

- `set`, `get`, `apply`, `prod`：$O(\log N)$
- `all_prod`, `node_count`：$O(1)$

空間は，操作によって実際に作られたノード数に比例する．
