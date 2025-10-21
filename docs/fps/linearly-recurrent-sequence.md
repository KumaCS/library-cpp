線形漸化式に関するライブラリ．

- `a, c` を入力に含むとき，初項が $a_0,\dots,a_{d-1}$ で漸化式 $a_i=\sum_{j=1}^{d}c_{j-1}a_{i-j}$ で定まる数列．
- `a` のみを入力に含むとき，Berlekamp-Massey アルゴリズムで漸化式を推定した上で計算する．
- `n, k` を入力に含むとき，$a_n,a_{n+1},\dots,a_{n+k-1}$ を計算する．
- `n` のみを入力に含むとき，$a_n$ のみを計算する．


## 連続する項

https://noshi91.hatenablog.com/entry/2023/06/04/233447

$\deg P(x)\lt d,\deg Q(x)=d,[x^0]Q(x)\neq 0$ とする．

次を満たす $S(x)$ を求められればよい．
$$\frac{P(x)}{Q(x)}=R(x)+x^n\cdot\frac{S(x)}{Q(x)},\quad \deg R(x)\lt n,\deg S(x)\lt d$$

$P(x)=Q(x)R(x)+x^nS(x)$ であるから $S(x)=x^{-n}P(x)\bmod Q(x)$ と表せる．

$\frac{1}{Q(x)}$ の $x^n$ から $x^{n+d-1}$ の係数を求めれば $P(x)$ のときの $S(x)$，すなわち $x^{-n}\bmod Q(x)$ が求められる．

`inverse-shift.hpp` で実装．

実質的に $\deg P(x)\geq\deg Q(x)$ であるようなケースに注意する．

例えば $a=(0,0,1,1,1,1,\dots)$ のようなケースに Berlekamp-Massey を用いると $q=(1,-1,0,0)$ が得られる．

このような場合，$q$ の末尾の $0$ の個数分 $a$ の先頭を取り除けばよい．