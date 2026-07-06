$N$ 以下の無平方数の個数を $O(N^{2/5}\log\log N)$ 時間で求める．

## アルゴリズム

参考：[Counting square free numbers - Blog of smsxgz](https://smsxgz.github.io/post/pe/counting_square_free_numbers/)

$N$ 以下の無平方数の個数を $S(N)$ とする．

### $\~O(\sqrt{N})$

素因数についての包除で次を得る．
$$S(N)=\sum_{d}\mu(d)\left\lfloor\frac{N}{d^2}\right\rfloor$$
$n$ 以下に対するMobius関数の列挙は篩で $\~O(n)$ なのでこれは $\~O(\sqrt{N})$ で計算できる．

### 高速化

$D$ を十分大きくとると，$\left\lfloor\frac{N}{d^2}\right\rfloor$ が $d\gt D$ の範囲であまり変化しなくなる．

$S_1(N)=\sum_{1\leq d\leq D}\mu(d)\left\lfloor\frac{N}{d^2}\right\rfloor,S_2(N)=\sum_{d\gt D}\mu(d)\left\lfloor\frac{N}{d^2}\right\rfloor$ とする．

$S_1$ は直接計算もできるが，$S_2$ でも使えるので $\mu$ 関数の値を列挙してそこから計算するようにする．
$\mu(1),\dots,\mu(D)$ の列挙は篩を考えると空間 $O(D)$，時間 $O(D\log\log D)$ で計算できる．

$S_2$ を考察．
$$\begin{align*}
S_2(N)
&=\sum_{d\gt D}\mu(d)\sum_i1_{i=\left\lfloor\frac{N}{d^2}\right\rfloor}i\\
&=\sum_i i\sum_{d\gt D}\mu(d)1_{i\leq\frac{N}{d^2}\lt i+1}\\
&=\sum_i i\sum_{d\gt D,\left\lfloor\sqrt{\frac{N}{i+1}}\right\rfloor\lt d\leq\left\lfloor\sqrt{\frac{N}{i}}\right\rfloor}\mu(d)
\end{align*}$$

$x_i=\sqrt{\frac{N}{i}}$ とおく．正整数 $I$ をとり $D=\lfloor x_I\rfloor$ とすれば，Mertens関数 $M(x)=\sum_{i=1}^{\lfloor x\rfloor}\mu(i)$ を用いて次のように表せる．
$$
S_2(N)
=\sum_{i=1}^{I-1}i(M(x_i)-M(x_{i+1}))
=\sum_{i=1}^{I-1}M(x_i)-(I-1)M(x_I)
$$

ここでメビウス反転公式から $\sum_{n=1}^{x}M\left(\frac{x}{n}\right)=1$ である．
変形すれば $M(x)=1-\sum_{n=2}^{x}M\left(\frac{x}{n}\right)$．

特に $M(x/n),n\geq 2$ の値がわかっているとき $M(x)$ が $O(\sqrt{x})$ で計算できる．

$M(x_I),M(x_{I-1}),\dots,M(x_1)$ をこの順に計算していくことを考える．

$M(x_k)$ を計算するには $M(x_k/i),2\leq i\leq x_k$ の値が必要．

- $x_k/i\lt D$ のとき：$S_1$ の計算で $\mu(j),j\leq D$ を列挙しているので累積和をとればよい．
- $x_k/i\geq D$ のとき：$x_k/i=x_{ki^2}\geq D=x_I$ より $ki^2\leq I$ であり $M(x_{ki^2})$ の値はすでに求めてある．

$M(x_k/i)$ は整数部分 $\lfloor x_k/i\rfloor$ で決まるので $M(x_k)$ は $O(\sqrt{x_k})$ で計算できる．

計算量を解析する．

$S_1$ の計算量は $O(D\log\log D)=O(\sqrt{N/I}\log\log(N/I))$．

$S_2$ の計算量は，次が成り立つから $O(N^{1/4}I^{3/4})$．
$$
\sum_{k=1}^{I}\sqrt{x_k}
=\sum_{k=1}^{I}\frac{N^{1/4}}{k^{1/4}}
=O(N^{1/4}I^{3/4})
$$

ここで $I=N^\alpha$ とおけば上の計算量はそれぞれ $O(N^{(1-\alpha)/2}\log\log N)$ および $O(N^{1/4+3/4\alpha})$ になる．
$\alpha=1/5$ とすれば全体の計算量は $O(N^{2/5}\log\log N)$ となった（このとき $D=N^{2/5}$）．