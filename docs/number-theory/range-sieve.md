## 区間篩

$L$ 以上 $R$ 以下の整数を区間篩により処理する．$1\leq L\leq R$ とする．
内部で `PrimeSieve::table` を用いるため，$\lfloor\sqrt R\rfloor\leq\operatorname{INT\_MAX}$ とする．

- `RangeSieve::lpf(L, R)`：`lpf[x - L]` が $x$ の最小素因数となる長さ $R-L+1$ の列を返す．ただし，$x=1$ のときは $1$ とする．
- `RangeSieve::table(L, R)`：$L$ 以上 $R$ 以下の素数を昇順に並べた列を返す．
- `RangeSieve::factorize(L, R)`：`factors[x - L]` が $x$ の素因数と指数の組を昇順に並べた列となる，長さ $R-L+1$ の列を返す．$1$ に対応する列は空である．

前計算に $O(\sqrt R\log\log R)$ 時間，区間の処理に $O((R-L+1)\log\log R)$ 時間を要する．
