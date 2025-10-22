多項式 $f$ について $g(n)=\sum_{i=0}^{n}f(i)$ を満たす多項式 $g$ を求める．

$d=\deg f$ として $O(d\log d)$ 時間．

## アルゴリズム

Bernoulli 数 $B_i=\left[\frac{x^i}{i!}\right]\dfrac{xe^x}{e^x-1}$ を用いると以下が成り立つ．

$$\begin{align*}
\sum_{i=1}^{n}i^k
&=k![x^k]\sum_{i=1}^{n}e^{ix}\\
&=k![x^k]\frac{(e^{nx}-1)e^x}{e^x-1}\\
&=k![x^k]\frac{e^{nx}-1}{x}\cdot\frac{xe^x}{e^x-1}\\
&=k!\sum_{i=0}^{k}\frac{n^{i+1}}{(i+1)!}\cdot\frac{B_{k-i}}{(k-i)!}
\end{align*}$$

これは Faulhaber の公式として知られている．

$f(x)=\sum_{i=0}^{d-1}f_ix^i$ とすると，上の結果から $1\leq l\leq d$ に対して

$$\begin{align*}
[x^l]g(x)
&=\frac{1}{l!}\sum_{k=l-1}^{d-1}f_kk!\cdot\frac{B_{k-(l-1)}}{(k-(l-1))!}\\
&=\frac{1}{l!}[x^{d-l}]\left(\sum_{i=0}^{d-1}f_ii!\cdot x^{d-1-i}\right)\frac{xe^x}{e^x-1}
\end{align*}$$

が成り立つ．また $[x^0]g(x)=f_0$ であるから，結局 $g$ は $O(d\log d)$ 時間で計算できる．

- https://codeforces.com/blog/entry/98563
- https://www.codechef.com/problems/SERSUM