Berlekamp-Massey のアルゴリズム．

数列 $a=(a_0,\dots,a_{n-1})$ に対し，以下を満たす $g(x)$ のうち最も次数の低いものを $O(n^2)$ 時間で求める．

$$\exists f(x),\quad \frac{f(x)}{g(x)}\bmod x^n=a_0+\cdots+a_{n-1}x^{n-1}$$

## アルゴリズム

$\frac{f_0+\cdots+f_{k-1}x^{k-1}}{g_0+\cdots+g_kx^k}\bmod x^{k+1}=a_0+\cdots+a_kx^k$ のとき

$a_kx^k$