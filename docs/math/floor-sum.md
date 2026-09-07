## 使い方

以下の問題を解く．

> 整数 $n,m,a,b\ (m\neq 0)$ に対し以下の値を求めよ：
> $$f(n,m,a,b)=\sum_{i=0}^{n-1}\left\lfloor\frac{ai+b}{m}\right\rfloor$$

$an+b$ が `unsigned long long` におさまる必要がある．

## アルゴリズム

再帰的に考える．

$n=0$ のとき $f(n,m,a,b)=0$ である．

簡単な変形によって $m\geq 1$ および $0\leq a\lt m, 0\leq b\lt m$ として構わない．

$a\geq 0$ のとき $an+b=mq+r\,(0\leq r\lt m)$ とする．
$0\leq i\lt n$ に対し $0\leq\left\lfloor\frac{ai+b}{m}\right\rfloor\leq q$ であり，$\left\lfloor\frac{ai+b}{m}\right\rfloor\geq k$ となる $i$ の範囲は $\frac{mk-b}{a}\leq i$ であるから以下が成り立つ．

$$\begin{align*}
f(n,m,a,b)
&=\sum_{k=1}^{q}\left(n-\left\lceil\frac{mk-b}{a}\right\rceil\right)\\
&=\sum_{k=1}^{q}\left(n+\left\lfloor\frac{b-mk}{a}\right\rfloor\right)\\
&=\sum_{k=0}^{q-1}\left(n+\left\lfloor\frac{b-m(q-k)}{a}\right\rfloor\right)\\
&=\sum_{k=0}^{q-1}\left\lfloor\frac{mk+an+b-mq}{a}\right\rfloor\\
&=\sum_{k=0}^{q-1}\left\lfloor\frac{mk+r}{a}\right\rfloor\\
&=f(q,a,m,r)
\end{align*}$$

$m,a$ について Euclid の互除法と同じ議論ができ，$O(\log m)$ 回の反復で停止することが示せる．