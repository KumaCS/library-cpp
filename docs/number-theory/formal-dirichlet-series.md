形式的 Dirichlet 級数ライブラリ．

prefix の具体的な値を管理する．

## 形式的 Dirichlet 級数

$R$ を環とする．

$R$ の数列 $A,B:\mathbb{N}\to R$ の Dirichlet 積 $A*B:\mathbb{N}\to R$ を以下で定める．
$$(A*B)(k)=\sum_{ij=k}A(i)B(j)$$

$R^{\mathbb{N}}$ に対して加算を成分毎の加算，乗算を Dirichlet 積とすると環になる．これを形式的 Dirichlet 級数環と呼ぶことにする．
以下特に断りのない場合積の記号 $*$ は省略する．

Dirichlet 級数の記法を流用し $A\in R^{\mathbb{N}}$ を以下のようにも表す：
$$\sum_{n=1}^{\infty}\frac{A(n)}{n^{-s}}.$$
また $[n^{-s}]A=A(n)$ とする．

この記法を用いれば加法の単位元は $0$，乗法の単位元は $1$ である．
また Dirichlet 級数 $A$ の逆元が存在する必要十分条件は $[1^{-s}]A$ が逆元を持つことである．

## 乗算/除算

$A,B$ の前 $N$ 項がわかっているとき，$AB$ の前 $N$ 項が $O(N\log N)$ 時間で計算できる．

## exp/log

- [https://atcoder.jp/contests/abc428/editorial/14241]

形式的 Dirichlet 級数 $A$ について $[1^{-s}]A$ が適当な条件を満たすとき形式的冪級数 $\exp x,\log x$ との合成によって $\exp A,\log A$ を考えることができる．

$A$ から $\exp A$ や $\log A$ を高速に計算できないだろうか．

ここで $n$ の重複を込めた素因数の個数を $\Omega(n)$ として，演算子 $\mathfrak{D}$ を
$$\mathfrak{D}\left(\sum_{n\geq 1}\frac{a_n}{n^s}\right)=\sum_{n\geq 1}\frac{a_n\Omega(n)}{n^s}$$

によって定める．これは微分に対応する演算になっており，以下の性質を満たす．
- $\mathfrak{D}(A+B)=(\mathfrak{D} A)+(\mathfrak{D} B)$．
- $\mathfrak{D}(AB)=(\mathfrak{D} A)B+A(\mathfrak{D} B)$．
- $\mathfrak{D}(A^k)=k(\mathfrak{D} A)A^{k-1}$．
- 形式的冪級数 $f$ に対し，合成 $f(A)$ が定義されるならば $\mathfrak{D}(f(A))=f'(A)(\mathfrak{D} A)$．

> 逆に上二つの性質を満たす演算子は $\mathfrak{D}(p^{-s})$ を定めれば決まる．
> $\mathfrak{D}(p^{-s})=p^{-s}$ とすれば上記の $\mathfrak{D}$ が得られる．

従って以下が成り立つ．
$$\mathfrak{D}\exp A=(\mathfrak{D} A)\exp A,\quad \mathfrak{D}\log A=\frac{\mathfrak{D} A}{A}$$

これを用いれば $A$ の前 $N$ 項がわかっているとき $\exp,\log$ の前 $N$ 項は $O(N\log N)$ 時間で計算できる．
