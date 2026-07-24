## 商の列挙

正整数 $N$ と $K$ に対し，集合 $Q_{N,K}$ を

$$Q_{N,K}=\left\{\left\lfloor\frac{N}{x^K}\right\rfloor : x\in\mathbb{Z},1\leq x^K\leq N\right\}$$

で定める．$|Q_{N,K}|=O(N^{1/(K+1)})$ である．引数 `K` を省略した場合は $K=1$ とする．

### `table(N)`，`table(N, K)`

$Q_{N,K}$ の元を昇順に並べた列を求める．

### `get_range(N, y)`，`get_range(N, y, K)`

$y\in Q_{N,K}$ に対し，$\left\lfloor\frac{N}{x^K}\right\rfloor=y$ となる $x$ の区間 $(l,r]$ を求める．

左側が開であることに注意．

### `iterate(N, f)`，`iterate(N, K, f)`

$q\in Q_{N,K}$ について昇順に，$(l,r]=\operatorname{get\_range}(N,q,K)$ として関数 `f(q,l,r)` を呼び出す．

$K=1$ では $O(\sqrt N)$ 時間，$K\geq 2$ では $O(KN^{1/(K+1)})$ 時間．
