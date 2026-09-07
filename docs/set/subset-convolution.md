- [https://nyaannyaan.github.io/library/set-function/subset-convolution.hpp]
- [https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0]

$\{0,1,\dots,n-1\}$ の部分集合を $0$ 以上 $2^n$ 未満の整数と対応づけ，整数に対しても集合演算の記号を用いる．

また $S\cap T =\emptyset$ であるとき $S\cup T$ を $S\sqcup T$ とも表す．

$R$ を環とする．

## subset convolution

$(a_0,a_1,\dots,a_{2^n-1}),(b_0,b_1,\dots,b_{2^n-1})\in R^{2^n}$ の **subset convolution** $c\in R^{2^n}$ を以下で定める．

$$c_u=\sum_{s\sqcup t=u}a_sb_t$$

### アルゴリズム

or convolution $\sum_{s\cup t=u}a_sb_t$ はゼータ変換により $O(n2^n)$ 時間で計算できた．

$s\cup t=u$ のとき $s\cap t=\emptyset\iff |s|+|t|=|u|$ であるので変数 $X$ に対し

$$c_u=[X^{|u|}]\sum_{s\cup t=u}(a_sX^{|s|})(b_tX^{|t|})$$

として計算でき，計算量は $n$ 倍になる．

## set power series

$R^{2^n}$ に加算および定数倍は成分ごと，乗算は subset convolution として演算を定めた環を **set power series** と呼ぶ．

- 単位元は $(1,0,\dots,0)$．
- 剰余環 $R[x_0,\dots,x_{n-1}]/(x_0^2,\dots,x_{n-1}^2)$ に同型．

簡便のために列 $(a_0,a_1,\dots,a_{2^n-1})$ を一般の多項式のように $\sum_{i=0}^{2^n-1}a_ix^i$ とも表記する．

## EGF との合成

集合冪級数 $a$ について $\frac{a^k}{k!}$ を以下のように定める．

$$[x^t]\frac{a^k}{k!}=\sum_{\substack{0 \leq s_1 \lt s_2 \lt \cdots \lt s_k \lt 2^n \\ s_i\cap s_j=\emptyset(i\neq j)}}\prod_{i=1}^{k}a_{s_i}$$

$R$ において $\frac{1}{k!}$ が定義されなくてもよい．

$a_0=0$ なる集合冪級数について，EGF $f(x)=\sum_{i\geq 0}f_i\frac{x^i}{i!}$ との合成 $f(a)=\sum_{i\geq 0}f_i\frac{a^i}{i!}$ が定義できる．

詳細は `set/composite-set-power-series.hpp` を参照．

## power projection

$m=0,1,\dots,M$ に対し $\sum_{s}w_s(a^m)_s$ を $O(n^22^n)$ 時間で列挙する．

詳細は `set/power-projection-of-set-power-series.hpp` を参照．

## 数え上げ

### グラフの連結性

グラフについての何らかの条件があるとき

- $f_s$：頂点集合が $s$ の連結な部分グラフで条件を満たすものの個数
- $g_s$：頂点集合が $s$ の部分グラフで条件を満たすものの個数

とすると $\exp f=g, f=\log g$ であるので $g$ が計算できれば $f$ も計算できる．

- [https://atcoder.jp/contests/abc213/tasks/abc213_g]

### 多項式 / FPS との合成

- [https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h]
