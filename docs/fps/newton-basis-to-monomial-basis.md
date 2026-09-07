列 $a=(a_0,a_1,\dots,a_{n-1})$ と $p=(p_0,p_1,\dots,p_{n-1})$ に対し，

$$f(x)=\sum_{i=0}^{n-1}a_i\prod_{j=0}^{i-1}(x-p_j)$$

の単項式基底での係数列を求める．`p[n-1]` は結果に影響しない．

- `NewtonToMonomialBasis(a, p)`：Newton 基底の係数列 `a` を単項式基底に変換する．$O(M(n)\log n)$ 時間．
- `FallingFactorialToMonomialBasis(a)`：下降階乗基底 $x^{\underline i}=x(x-1)\cdots(x-i+1)$ から単項式基底に変換する．

## アルゴリズム

区間 $[l,r)$ の係数列を左右に分け，$m=(l+r)/2$ として左右から復元した多項式を $f_0,f_1$ とすると，

$$f(x)=f_0(x)+\left(\prod_{i=l}^{m-1}(x-p_i)\right)f_1(x)$$

で併合する．区間積は積木で求める．ここで $M(n)$ は次数 $n$ の多項式乗算の時間計算量を表す．

$p_i=i$ の場合は，第一種 Stirling 数 $s(i,k)$ を用いて

$$[x^k]f(x)=\sum_{i=k}^{n-1}a_is(i,k)$$

と表し，$s(i,k)=\frac{i!}{k!}[x^i](\log(1+x))^k$ に転置合成を適用する．任意 mod 畳み込みの場合は積木を用いる．`NewtonToMonomialBasis(a, p)` も $p_i=i$ を検出するとこの処理を行う．
