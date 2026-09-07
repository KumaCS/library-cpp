多点評価．

$n$ 次の多項式 $f$ に対し $f(x_1),f(x_2),\dots,f(x_m)$ を $O(m(\log m)^2+n\log n)$ 時間で求める．

また評価点が等比数列 $a,ar,\dots,ar^{m-1}$ の場合には $O(m\log m+n\log n)$ 時間で求められる（chirp z-transform）．

## アルゴリズム

### 一般

剰余の定理により $f(x)\bmod (x-x_i)$ を求めればよく，ダブリングすればよい．

- 参考：[Multipoint Evaluation の アルゴリズム - 37zigenのHP](https://37zigen.com/multipoint-evaluation/)

転置原理を用いることで定数倍のよりよい実装が得られるらしいが未実装．

- 参考：[転置原理まとめ - Mathenachia](https://www.mathenachia.blog/tellegens)

### 等比数列

chirp z-transform と呼ばれる変換で，DFT の一般化になっている．

$f=\sum_{i=0}^{n-1}f_ix^i$ とおくと，$j$ について列挙したい値は以下のように変形できる．

$$\begin{align*}
f(ar^j)
&=\sum_{i=0}^{n-1}f_ia^ir^{ij}\\
&=\sum_{i=0}^{n-1}f_ia^ir^{\binom{i+j}{2}-\binom{i}{2}-\binom{j}{2}}\\
&=r^{-\binom{j}{2}}\sum_{i=0}^{n-1}r^{\binom{i+j}{2}}f_ia^ir^{-\binom{i}{2}}
\end{align*}$$

middle product で $O((n+m)\log(n+m))$ 時間．