モノイド $(T,\cdot,e),(F,\circ,\mathrm{id})$ があり，$F$ は $T$ に左から作用するとする．

- 実際には各種演算は計算で出てくる範囲で定義されていれば構わない．

長さ $N$ の $T$ の列 $A=(A_0,A_1,\dots,A_{N-1})$ に対し，空間計算量 $\Theta(N)$ のもとで以下の操作を行える．

- `set(p, x)`：$A_p \gets x$ とする．$O(\log N)$ 時間．
- `get(p)`：$A_p$ を取得する．$O(\log N)$ 時間．
- `apply(l, r, f)`：$i=l,l+1,\dots,r-1$ に対し $A_i \gets f A_i$ とする．$O(\log N)$ 時間．
- `prod(l, r)`：$A_l\cdot A_{l+1}\cdot\cdots\cdot A_{r-1}$ を取得する．$O(\log N)$ 時間．
- 二分探索：$O(\log N)$ 時間．$\mathrm{cond}(e)=\mathrm{true}$ を要求する．
  - `max_right(l, cond)`：$\mathrm{cond}(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最大の $r$ を返す．
  - `min_left(r, cond)`：$\mathrm{cond}(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最小の $l$ を返す．
