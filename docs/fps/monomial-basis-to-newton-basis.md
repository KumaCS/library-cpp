$n-1$ 次以下の多項式 $f(x)$ と列 $p=(p_0,p_1,\dots,p_{n-1})$ に対し，

$$f(x)=\sum_{i=0}^{n-1}a_i\prod_{j=0}^{i-1}(x-p_j)$$

を満たす $a=(a_0,a_1,\dots,a_{n-1})$ を求める．`p[n-1]` は結果に影響しない．

- `MonomialToNewtonBasis(f, p)`：単項式基底で表された `f` を Newton 基底の係数列に変換する．$O(M(n)\log n)$ 時間．
- `MonomialToFallingFactorialBasis(f)`：下降階乗基底 $x^{\underline i}=x(x-1)\cdots(x-i+1)$ に変換する．

## アルゴリズム

区間 $[l,r)$ に対応する多項式を，$m=(l+r)/2$ として

$$f(x)=f_0(x)+\left(\prod_{i=l}^{m-1}(x-p_i)\right)f_1(x)$$

と商と剰余に分解する．$f_0$ と $f_1$ に再帰し，得られた係数列を連結する．区間積は積木で求める．ここで $M(n)$ は次数 $n$ の多項式乗算の時間計算量を表す．

$p_i=i$ の場合は，第二種 Stirling 数 $S(k,i)$ を用いて

$$a_i=\sum_{k=i}^{n-1}[x^k]f(x)S(k,i)$$

と表し，$S(k,i)=\frac{k!}{i!}[x^k](e^x-1)^i$ に転置合成を適用する．任意 mod 畳み込みの場合は積木を用いる．`MonomialToNewtonBasis(f, p)` も $p_i=i$ を検出するとこの処理を行う．
