以下の問題を $O((N+M)\log(N+M))$ 時間で解く．

> 次数 $N$ 未満の多項式 $f(x)$ について $f(0),f(1),\dots,f(N-1)$ が与えられる．
> $f(c),f(c+1),\dots,f(c+M-1)$ を列挙せよ．

## アルゴリズム

下降階乗冪を用いて $f(x)=\sum_{i=0}^{N-1}a_ix^{\underline{i}}$ とおくと $0\leq i\lt N$ に対し

$$f(k)=k!\sum_{i=0}^{k}\frac{a_i}{(k-i)!}$$

が成り立つため，$a_i$ は

$$a_i=[x^i]e^{-x}\sum_{k=0}^{N-1}\frac{f(k)}{k!}x^k$$

として計算できる．

また下降階乗冪について $(a+b)^{\underline{n}}=\sum_{i=0}^{n}\binom{n}{i}a^{\underline{i}}b^{\underline{n-i}}$ が成り立つため，$f(x+c)=\sum_{i=0}^{N-1}b_ix^{\underline{i}}$ とおくと

$$b_i=\frac{1}{i!}\sum_{j}(i+j)!a_{i+j}\cdot\frac{c^{\underline{j}}}{j!}$$

が成り立つ．あとは $a_i$ の計算の逆をすればよい．