多項式 $f,g$ に対して $h_i=[x^k]f(x)g(x)^i$ とする．

$h_0,h_1,\dots,h_n$ を $O((n+k)(\log(n+k))^2)$ 時間で列挙する．

FPS の合成アルゴリズムである Kinoshita-Li 合成は FPS の合成の転置問題が power projection であることに基づいている．

- Yasunori Kinoshita and Baitian Li, Power Series Composition in Near-Linear Time, 2024 (https://arxiv.org/abs/2404.05177)

## アルゴリズム

$[x^0]g(x)=c$ とすれば以下が成り立つ．

$$h_i=\sum_{j}\binom{i}{j}c^{i-j}\cdot[x^k]f(x)(g(x)-c)^j$$

よって $[x^k]f(x)(g(x)-c)^i$ を列挙できれば，$h_i$ は畳み込みにより $O(k\log k)$ 時間で計算できる．

以下 $[x^0]g(x)=0$ であると仮定する．二変数 FPS として $h_i$ は次のように表現できる．

$$h_i=[x^ky^i]\frac{f(x)}{1-g(x)y}$$

$y$ についての FPS である $[x^k]\frac{f(x)}{1-g(x)y}$ が求められればよい．

Bostan-Mori 法の適用を考えると，イテレーション毎に $x$ の次数が半減，$y$ の次数が倍増するため，結局 $x$ の次数と $y$ の次数の積は $O(n+k)$ であり各イテレーションは $O((n+k)\log(n+k))$ 時間で行える．

従って全体では $O((n+k)(\log (n+k))^2)$ 時間で解ける．

## FFT 回数の削減

$h_i=[x^{k-1}]\cdots$ および $k$ が二冪であると仮定して構わない．
こうすると Bostan-Mori のイテレーション内で考えるべき $x$ の次数が常に奇数になる．

また分母が $1+y\cdot hoge$ の形であるのは扱いづらいので $y$ について reverse して考える．
すなわち $\frac{f(x)}{y-g(x)}$ についての Bostan-Mori を考える．

このときイテレーションにおいて出てくる形は $[x^{k-1}]\frac{p(x,y)}{y^l+q(x,y)}$ とおける．
ここで $k,l$ は二冪であり $p,q$ 共に $x$ の次数は $k$ 未満，$y$ の次数は $l$ 未満である．

$k=1$ のとき，仮定 $[x^0]g(x)=0$ より $[x^0]q(x,y)=0$ が成り立つため，$y$ の reverse を考慮すれば $[x^0]y^{l-1}p(x,y^{-1})$ が求めたいものである．

$k\geq 2$ のとき，まず分母の遷移を考える．
$(y^l+q(x,y))(y^l+q(-x,y))=y^{2l}+q'(x^2,y)$ とおくと

$$q'(x^2,y)=q(x,y)q(-x,y)+(q(x,y)+q(-x,y))y^l$$

である．
$m=2kl$ として $1$ の原始 $2m$ 乗根 $\omega$ をとり，$x=\omega,y=\omega^{2k}$ とすれば以下が成り立つ．

$$q'(\omega^{2i},\omega^{2ki})=q(\omega^i,\omega^{2ki})q(-\omega^i,\omega^{2ki})+(q(\omega^i,\omega^{2ki})+q(-\omega^i,\omega^{2ki}))\omega^{2kli}$$

$q(-\omega^i,\omega^{2ki})=q(\omega^{i+m},\omega^{2k(i+m)})$，また $\omega^{2kl}=\omega^m=-1$ であるから，左辺の値は $q(t,t^{2k})$ に対し長さ $2m$ の FFT を行うことで求められる．
また $q'$ において $x$ の次数は $k/2$ 未満，$y$ の次数は $2l$ 未満であるから，左辺を求めた上で長さ $m$ の IFFT を行うことで $q'(t,t^k)$ が得られる．

分母についても同様に考えられる．