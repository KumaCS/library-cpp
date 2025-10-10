## 商の列挙

正整数 $N$ に対し，集合 $Q_N$ を

$$Q_N=\left\{\left\lfloor\frac{N}{x}\right\rfloor : x\in\mathbb{Z},1\leq x\leq N\right\}$$

で定める．$|Q_N|=O(\sqrt{N})$ である．

### `table(N)`

$Q_N$ の元を昇順に並べた列を求める．

### `get_range(N, y)`

$y\in Q_N$ に対し，$\left\lfloor\frac{N}{x}\right\rfloor=y$ となる $x$ の区間 $(l,r]$ を求める．

左側が開であることに注意．

### `iterate(N, f)`

$q\in Q_N$ について昇順に，$(l,r]=\operatorname{get\_range}(q)$ として関数 `f(q,l,r)` を呼び出す．