多項式 $f(x),g(x)$ に対する $\gcd(f(x),g(x))$ を $n=\max(\deg f,\deg g)$ として $O(n(\log n)^2)$ 時間で計算する．

また $f(x)h(x)\equiv 1\pmod{g(x)}$ となる多項式 $h(x)$ も同じ計算量で求められる．

## Half-GCD 法

Euclid の互除法をそのまま適用すると，一回の反復で次数が $1$ しか減少しない場合に $\Omega(n^2\log n)$ 時間かかる．
解決するのが Half-GCD 法．

- [https://codeforces.com/blog/entry/101850]
- [https://dl.acm.org/doi/10.1145/800125.804045]

$f,g$ の GCD は互除法で求められる．

- $f_0=f,f_1=g$ とする（$\deg f\geq\deg g$）．
- $i=1,2,\dots$ について順に $f_{i-1}$ を $f_i$ で割った商を $q_i$ とし，$f_{i+1}=f_i-f_{i+1}q_i$ と定めていく．
- $f_{i+1}=0$ となったとき $\operatorname{GCD}(f,g)=f_i$ である．

過程は行列で表示できる：$M_i=\begin{pmatrix}0&1\\1&-q_i\end{pmatrix}$ とすると $\begin{pmatrix}f_i\\f_{i+1}\end{pmatrix}=M_i\cdots M_1\begin{pmatrix}f_0\\f_1\end{pmatrix}$ である．

$\deg f_t \gt \frac{1}{2}\deg f\geq \deg f_{t+1}$ となる $t$ について $\operatorname{HGCD}(f,g)=M_t\cdots M_1$ とおく．

HGCD は再帰的に計算できる（証明は後述）．ただし $\deg f\geq\deg g$ とし，`f >> k` は $f\operatorname{div}x^k$ を意味する．

```
def HGCD(f, g):
  if deg(g) <= deg(f) / 2: return I
  k = floor(deg(f) / 2) + 1
  M = HGCD(f >> k, g >> k)
  (f, g)^T = M * (f, g)^T
  if deg(g) <= deg(f) / 2: return M
  (通常の互除法の 1 step を行う)
  if deg(g) <= deg(f) / 2: return M
  l = 2 * k - deg(f)
  return HGCD(f >> l, g >> l) * M
```

2 回の HGCD ではどちらも次数が半分以下になっている．
また多項式除算を 1 回行っている．
従って $T(n)=2T(n/2)+n\log n$ を解いて $T(n)=n(\log n)^2$ であるから計算量は $O(n(\log n)^2)$ 時間である．


HGCD を用いれば以下のアルゴリズムで GCD が求められる．
ループごとに $f$ の次数が半減するので $T(n)+T(n/2)+T(n/4)+\cdots=O(n(\log n)^2)$ 時間．

```
def GCD(f, g):
  while g != 0:
    (f, g) = HGCD(f, g) * (f, g)
    if g == 0: break
    (f, g) = (g, f % g)
  return f
```


### 正当性

形式的 Laurent 級数（有限個の負冪の項を許す）として考えると，$f$ を $g$ で割った商 $q$ は

$$q(x^{-1})=\frac{f(x^{-1})}{g(x^{-1})}\bmod x$$

と表せる．



> **補題.** 多項式 $f,g\ (\deg f-\deg g=k)$ に対し $f$ を $g$ で割った商 $q$ は $f,g$ のそれぞれ上から $k+1$ 次の係数にのみ依存する（特に $\deg f$ の値によらない）．

<details>
<summary>証明</summary>

両辺に $x^k=x^{\deg f-\deg g}$ をかけると
$$\begin{align*}
x^kq(x^{-1})
&=\frac{x^{\deg f}f(x^{-1})}{x^{\deg g}g(x^{-1})}\bmod x^{k+1}\\
&=\frac{x^{\deg f}f(x^{-1})\bmod x^{k+1}}{x^{\deg g}g(x^{-1})\bmod x^{k+1}}\bmod x^{k+1}
\end{align*}$$
であるのでよい．
(証明終)

</details>

---

> **定理.** $(f,g)$ に対し互除法を適用して得られる行列を $M_1,M_2,\dots$ とする．非負整数 $k$ に対し，ある $t$ が存在して $\operatorname{HGCD}(f\operatorname{div}x^k,g\operatorname{div}x^k)=M_t\cdots M_1$ となる．

<details>
<summary>証明</summary>

$n=\deg f$ とする．

HGCD 側は $\deg f'_i\gt\frac{1}{2}(n-k)$ の間操作を行う．
これをみたす $i$ に対して以下を示すことができればよい．
- $\deg f_i=\deg f'_i+k$
- $f_i$ と $f'_i$ のそれぞれ上 $\deg f_{i-1}-\lfloor\frac{n+k}{2}\rfloor+1=\deg f'_{i-1}-\lfloor\frac{n-k}{2}\rfloor+1$ 次が一致する

(TODO: 証明する，実験では成り立ちそう & これより次数評価は緩められなさそう)
(証明終)

</details>