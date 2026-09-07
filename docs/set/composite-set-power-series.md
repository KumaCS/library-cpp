多項式 $\sum_{i=0}^{m-1}c_ix^i$，$2^n$ の集合冪級数 $a$ について $\sum_{i=0}^{m-1}c_ia^i$ を $O(n^22^m)$ 時間で計算する．

## EGF との合成

$[x^0]a=0$ のとき EGF $f(x)=\sum_{k\geq 0}f_k\frac{x^k}{k!}$ との合成 $f(a)=\sum_{k\geq 0}f_k\frac{a^k}{k!}$ を考える．

- [https://codeforces.com/blog/entry/92183]

$R[x_1,\dots,x_n]/(x_1^2,\dots,x_n^2)$ の元として考えると $[x_n^1]f(a)=[x_n^0]f'(a)[x_n^1]a$ が成り立つ．

従って $[x_n^0]f'(a)$ から $f(a)$ を得られる．

再帰的に計算すると長さ $2^i$ の subset convolution を $n-i$ 回行うことになり，計算量は $O(n^22^n)$ と評価できる．

## 多項式との合成

$[x^0]a=0$ のとき EGF との合成に帰着される．

$[x^0]a=c\neq 0$ のとき $f(x+c)$ と $a-c$ を合成すればよい．
$f(x+c)$ は $n$ 次まで求めれば十分なので $O(nm)$ 時間で計算できる．


## 別の手法

- [https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h]
- [https://hos-lyric.hatenablog.com/entry/2021/01/14/201231]

ゼータ変換した先の多項式を FPS と合成することでも求められる．

log や pow は定数倍が改善する．