高々 $n-1$ 次の多項式 $f$ で $0\leq i\lt n$ に対し $f(x_i)=y_i$ を満たすものを $O(n(\log n)^2)$ 時間で求める．

また評価点が等比級数ならば $O(n\log n)$ 時間で求められる．

## アルゴリズム

$g(x)=\prod_{i=0}^{n-1}(x-x_i)$ とすれば Lagrange 補間より以下が成り立つ．

$$f(x)=\sum_{i=0}^{n-1}\frac{y_ig(x)}{g'(x_i)(x-x_i)}$$

以下のようにして $O(n(\log n)^2)$ 時間で計算できる．

- $g(x)$ は分割統治により $O(n(\log n)^2)$ 時間で計算できる．
- $g'(x_i)$ は多点評価により $O(n(\log n)^2)$ 時間で列挙できる．
- $\sum_{i=0}^{n-1}\frac{y_i}{g'(x_i)(x-x_i)}$ は有理数の和として分割統治により $O(n(\log n)^2)$ 時間で計算できる．

$g(x)$ の計算過程はそれ以降にも流用できる．

## 等比級数の場合

- [https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence]
- [https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#noredirect]

$i=0,\dots,n-1$ について $f(ar^i)$ がわかっているとする．ただし $0\leq i\lt j\lt n$ ならば $ar^i\neq ar^j$．

$f$ は以下のように表示できる．
$$f(x)=\sum_{i=0}^{n-1}y_i\prod_{j\neq i}\frac{x-ar^j}{a(r^i-r^j)}$$

$g(x)=x^{n-1}f(x^{-1})$ とすると $g$ は以下のように表示できる．
$$g(x)=\sum_{i=0}^{n-1}y_i\prod_{j\neq i}\frac{1-ar^jx}{a(r^i-r^j)}$$

分母は以下のように変形できる．
$$\begin{align*}
\prod_{j\neq i}a(r^i-r^j)
&=\prod_{j=0}^{i-1}a(r^i-r^j)\prod_{j=i+1}^{n-1}a(r^i-r^j)\\
&=\prod_{j=1}^{i}r^{i-j}a(r^j-1)\prod_{j=1}^{n-1-i}ar^i(1-r^j)\\
&=(-1)^{i}r^{i(i-1)/2+i(n-1-i)}\prod_{j=1}^{i}a(1-r^j)\prod_{j=1}^{n-1-i}a(1-r^j)
\end{align*}$$

よって $w_i=y_i\prod_{j\neq i}\frac{1}{a(r^i-r^j)}$ は全ての $i$ に対し $O(n)$ 時間で求められるので以下を計算できればよい．
$$g(x)=\sum_{i=0}^{n-1}w_i\prod_{j\neq i}(1-ar^jx)=\left(\prod_{i=0}^{n-1}(1-ar^ix)\right)\left(\sum_{i=0}^{n-1}\frac{w_i}{1-ar^ix}\right)$$

$F(x)=\prod_{i=0}^{n-1}(1-ar^ix)$ とおくと $(1-ax)F(rx)=F(x)(1-ar^nx)$ より $F_i=[x^i]F(x)$ について
$$F_0=1,\quad (1-r^i)F_i=a(r^n-r^{i-1})F_{i-1}$$
が成り立ち，$O(n)$ 時間で $F$ は求められる．

$G(x)=\sum_{i=0}^{n-1}\frac{w_i}{1-ar^ix}$ とおくと
$$G(x)=\sum_{i=0}^{n-1}\sum_{j=0}^{\infty}w_i(ar^ix)^j=\sum_{j=0}^{\infty}a^j\left(\sum_{i=0}^{n-1}w_ir^{ij}\right)x^j$$
である．$G$ は $n-1$ 次まで求められればよいので，多項式 $\sum_{i=0}^{n-1}w_ix^i$ を $x=r^0,r^1,\dots,r^{n-1}$ で多点評価すればよい．