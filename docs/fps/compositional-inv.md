逆関数．

$[x^0]f(x)=0,[x^1]f(x)\neq 0$ を満たす FPS $f$ に対し，$f(g(x))=g(f(x))=x$ を満たす FPS $g$ が一意に存在し，$f$ の逆関数と呼ぶ．

$f$ の逆関数の先頭 $n$ 項を $O(n(\log n)^2)$ 時間で求める．

## アルゴリズム

$f(x/c)$ の逆関数は $cg(x)$ であるから $[x^1]f(x)=1$ と仮定してよい．

Lagrange の反転公式により

$$[x^n]f(x)^i=\frac{i}{n}[x^{n-i}]\left(\frac{x}{g(x)}\right)^n$$

である．
power projection により $O(n\log n)$ 時間で $[x^n]f(x)^i$ が列挙でき，$G(x)=\left(\frac{x}{g(x)}\right)^n$ が求められる．

$[x^0]G(x)=1$ であるから $g(x)=x\exp\left(-\frac{1}{n}\log G(x)\right)$ とすれば $O(n\log n)$ 時間で $g$ が求められる．
