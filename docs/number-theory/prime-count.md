## 素数カウント

集合 $Q_N=\left\{\lfloor\frac{N}{x}\rfloor:1\leq x\leq N\right\}$ について，$Q_N=\{x_1,x_2,\dots,x_m\},x_1\lt x_2\lt\cdots\lt x_m$ とおく．
$\pi(x_1),\pi(x_2),\dots,\pi(x_m)$ を $O\left(\frac{N^{3/4}}{\log{N}}\right)$ 時間で列挙する．

- `PrimeCount::count(N)`：$N$ 以下の素数の個数 $\pi(N)$ を返す．
- `PrimeCount::table(N)`：`(xs, cnt)` を返す．`xs[i]` に対する $\pi(xs[i])$ が `cnt[i]` に入る．

### 概要

Lucy DP．

$N\leq 10^{12}$ 程度の場合，除算を double で行うことで定数倍高速化できる．
