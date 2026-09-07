## メビウス関数

メビウス関数 $\mu(n)$ に関する関数群．

- `MobiusFunction::table(N)`：`mu[i]` が $\mu(i)$ となる長さ $N+1$ の列を返す．$O(N\log\log N)$ 時間．
- `MobiusFunction::sum(N)`：Mertens 関数 $\sum_{i=1}^{N}\mu(i)$ を返す．$N\leq 0$ のときは $0$ を返す．$O(N^{2/3}\log\log N)$ 時間，$O(N^{2/3})$ 空間．

`sum` は $\lceil N^{2/3}\rceil\leq\operatorname{INT\_MAX}$ を仮定する．
