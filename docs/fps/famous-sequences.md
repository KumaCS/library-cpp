## 分割数

非負整数 $n$ の分割数 $p_n$ とは，$n$ をいくつかの正整数の和（順序を区別しない）で表す方法の数．

母関数は $\prod_{k=1}^{\infty}\frac{1}{1-x^k}$ である．

オイラーの五角数定理より
$$\prod_{k=1}^{\infty}(1-x^k)=\sum_{k=-\infty}^{\infty}(-1)^kx^{k(3k-1)/2}$$
であることを用いれば $O(N\log N)$ 時間で $p_0,p_1,\dots,p_N$ が列挙できる．

## ベル数

$n$ 元集合を空でない部分集合に分割する方法の数 $B_n$ をベル数という．
指数型母関数が下のように計算できる．
$$\sum_{n}\frac{B_n}{n!}x^n
=\prod_{i=1}^{\infty}\sum_{j=0}^{\infty}\frac{1}{(i!)^jj!}x^{ij}
=\prod_{i=1}^{\infty}\exp\left(\frac{x^i}{i!}\right)
=\exp\left(\sum_{i=1}^{\infty}\frac{x^i}{i!}\right)
=\exp(e^x-1)$$

## モンモール数

長さ $n$ の撹乱順列，すなわち $(1,2,\dots,n)$ の順列 $(p_1,p_2,\dots,p_n)$ で $p_i\neq i$ を満たすものの個数．

$a_n$ とおくと $a_n=(n-1)(a_{n-1}+a_{n-2})$ であるから $O(n)$ 時間で列挙できる．

## 第一種スターリング数

$s(n,k)$ を以下で定める．
$$x(x-1)\cdots(x-(n-1))=\sum_{k=0}^{n}s(n,k)x^k$$

$s(n,i)$ の $0\leq i\leq n$ での列挙が $O(n\log n)$ 時間でできる．
- 分割統治をするが，一方の結果を Taylor Shift すればもう一方の結果を得られる．

また 
$$\sum_{i,j}s(i,j)\frac{x^i}{i!}y^j=(1+x)^y=\exp(y\log(1+x))=\sum_{j}(\log(1+x))^j\frac{y^j}{j!}$$
となるので $s(i,k)$ の $k\leq i\leq n$ での列挙が $O((n-k)\log (n-k))$ 時間でできる．

## 第二種スターリング数

$S(n,k)$ を以下で定める．
$$x^n=\sum_{k=0}^{n}S(n,k)x(x-1)\cdots(x-(k-1))$$

整数 $i$ について $x=i$ としたとき
$$i^n=i![y^i]\left(\sum_{k=0}^{n}S(n,k)y^k\right)e^y$$
と表示できるので
$$\sum_{k=0}^{n}S(n,k)y^k=e^{-y}\left(\sum_{i=0}^{\infty}\frac{i^n}{i!}y^i\right)$$
であり，$S(n,i)$ の $0\leq i\leq n$ での列挙が $O(n\log n)$ 時間でできる．
また
$$\sum_{i=0}^{\infty}\frac{i^n}{i!}y^i=n![x^n]\sum_{i=0}^{\infty}\frac{e^{ix}}{i!}y^i=n![x^n]\exp(e^xy)$$
より
$$\sum_{n,k}S(n,k)\frac{x^n}{n!}y^k=\exp((e^x-1)y)=\sum_{i\geq 0}(e^x-1)^i\frac{y^i}{i!}$$
となるので $S(i,k)$ の $k\leq i\leq n$ での列挙が $O((n-k)\log (n-k))$ 時間でできる．