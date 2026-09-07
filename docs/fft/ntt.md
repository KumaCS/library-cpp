数論変換（Number Theoretic Transform, NTT）．

素数 $p$ に対する $\mathbb{F}_p$ 上での離散フーリエ変換．

$\omega$ を $\mathbb{F}_p$ での $1$ の原始 $n$ 乗根とする．

数列 $f=(f_0,f_1,\dots,f_{n-1})$ に対し以下で定まる $F=(F_0,F_1,\dots,F_{n-1})$ を $O(n\log n)$ 時間で計算する（NTT）．

$$F_i=\sum_{j=0}^{n-1}f_j\omega^{ij}$$

また NTT の逆変換（INTT）は以下を計算すればよく，これも同じ計算量で求められる．

$$f_i=\frac{1}{n}\sum_{j=0}^{n-1}F_j\omega^{-ij}$$