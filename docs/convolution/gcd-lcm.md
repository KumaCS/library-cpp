## GCD 畳み込み

長さ $\red{N+1}$ の vector $(a_0,a_1,\dots,a_N),(b_0,b_1,\dots,b_N)$ を受け取り，以下を満たす長さ $N+1$ の vector $(c_0,c_1,\dots,c_N)$ を返す．

- $c_0$ は未定義．
- $1\leq k\leq N$ に対し $c_k=\sum_{\gcd(i,j)=k}$．

$a$ を倍数ゼータ変換した列を $A$ とする．つまり $A_i=\sum_{i\mid j}a_j$ とする．$B,C$ も同様とする．

このとき $k\mid\gcd(i,j)\iff k\mid i\land k\mid j$ を用いると

$$\begin{align*}
C_k
&=\sum_{k\mid l}c_l\\
&=\sum_{k\mid\gcd(i,j)}a_ib_j\\
&=\sum_{k\mid i}\sum_{k\mid j}a_ib_j\\
&=A_kB_k
\end{align*}$$

となる．従って $c$ は $a,b$ を倍数ゼータ変換し，各点積をとって倍数メビウス変換すれば得られる．

## LCM 畳み込み

倍数ゼータ変換の代わりに約数ゼータ変換を用いれば LCM について畳み込みできる．

lcm の場合，$\operatorname{lcm}(i,j)\leq N$ とは限らない．