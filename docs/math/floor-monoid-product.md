## 使い方

次の問題を $O(\log n+\log m+\log a+\log b)$ 回のモノイド演算により解く．

> 非負整数 $a,b$ および正整数 $m$ に対し $f(i)=\left\lfloor\frac{ai+b}{m}\right\rfloor$ とする．モノイドの元 $x,y$ に対し，以下の値を計算せよ．
> $$y^{f(0)}xy^{f(1)-f(0)}x\cdots xy^{f(n)-f(n-1)}$$

- 型 `T`
- 二項演算 `T op(T, T)`
- 単位元 `T e()`

を定義する必要がある．

また引数でべき乗 `pow` を渡すこともできる．渡さない場合には繰り返し二乗法を用いる．

型 `U` については $an+b$ が計算できる必要がある．


参考

- [モノイドの積を求めるやつ](https://259-momone.hatenablog.com/entry/2025/04/28/232456)
- [ARC183-F のユーザー解説](https://atcoder.jp/contests/arc183/editorial/10768)

## 具体的なモノイドの例

先に具体的なモノイドを提示して一般化になっていることを示す．

### 単純な floor sum

各 $x$ についてのそれより左側の $y$ の個数の総和を求めればよい．

そのためには区間内の $x,y$ の個数とその区間内でのスコアを持てばよく，例えば以下のようにすればよい．

- 台集合：$\mathbb{Z}_{\geq 0}^3$
- 演算：$(x_1,y_1,z_1)\cdot(x_2,y_2,z_2)=(x_1+x_2,y_1+y_2,z_1+z_2+y_1x_2)$
- 単位元：$(0,0,0)$
- $x=(1,0,0),y=(0,1,0)$

### 環上の floor sum

https://loj.ac/p/6440 を 0-indexed にし，一般の環にした問題：

> 環 $R$ の元 $A,B$ に対し，以下を求めよ：
> $$\sum_{i=0}^{n-1}A^{i}B^{\left\lfloor\frac{ai+b}{m}\right\rfloor}$$

各 $x$ についての $A^{(左にある x の個数)}B^{(左にある y の個数)}$ の総和を求めればよいので，非可換であることさえ注意すれば先ほどと同様に計算できる：

- 台集合：$R^3$
- 演算：$(x_1,y_1,z_1)\cdot(x_2,y_2,z_2)=(x_1x_2,y_1y_2,z_1+x_1z_2y_1)$
- 単位元：$(1,1,0)$
- $x=(A,1,1),y=(1,B,0)$

### 一般化 floor sum

> 整数 $n,m,a,b\ (m\geq 1)$ および $p,q\geq 0$ に対し以下の値を求めよ：
> $$\sum_{i=0}^{n-1}i^p\left\lfloor\frac{ai+b}{m}\right\rfloor^q$$

環上の floor sum で $R=K[[s,t]],A=e^s,B=e^t$ としたときの $\frac{s^p}{p!}\cdot\frac{t^q}{q!}$ の係数を求めればよい．

$A,B$ それぞれの総積は単に個数を持てばよく，また $s$ の $p+1$ 次以上および $t$ の $q+1$ 次以上は無視してよいから，以下のようにしてよい．

- 台集合：$\mathbb{Z}_{\geq 0}\times\mathbb{Z}_{\geq 0}\times K[[s,t]]/(s^{p+1},t^{q+1})$
- 演算：$(x_1,y_1,f_1)\cdot(x_2,y_2,f_2)=(x_1+x_2,y_1+y_2,f_1+e^{x_1s+y_1t}f_2)$
- 単位元：$(0,0,0)$
- $x=(1,0,1),y=(0,1,0)$

$\frac{s^i}{i!}\cdot\frac{t^j}{j!}$ の係数を管理すれば演算は二項係数を掛ければよく，特に逆元が存在しなくてもよい．

## アルゴリズム

求める値を $g(n,m,a,b,x,y)$ とおく．

$a,b,m$ についての制約から $f(0)\geq 0$ かつ $f$ は広義単調増加であるから，$f(n)=0$ のとき $g(n,m,a,b,x,y)=x^{n-1}$ となる．

$a\geq m$ のとき $a=mq+r$ とすれば $g(n,m,a,b,x,y)=g(n,m,r,b,xy^q,y)$ である．

また $b\geq m$ のとき $b=mq+r$ とすれば $g(n,m,a,b,x,y)=y^qg(n,m,a,r,x,y)$ である．

$a\lt m,b\lt m$ のとき，$f'(i)$ を $f(j)\geq i$ となる最小の非負整数 $j$ として定めれば $k=f(n)$ として以下が成り立つ．

$$g(n,m,a,b,x,y)=x^{f'(1)}yx^{f'(2)-f'(1)}y\cdots yx^{f'(k)-f'(k-1)}yx^{n-f'(k)}$$

$i\geq 1$ に対し $f'(i)=\left\lceil\frac{mi-b}{a}\right\rceil=\left\lfloor\frac{mi-b+a-1}{a}\right\rfloor$ であり，一番最後の指数については $n-f'(k)=\left\lfloor((an+b)\bmod m)/a\right\rfloor$ である．従って $c=an+b$ とすれば以下のように $m,a$ を swap したケースに帰着される．

$$\begin{align*}
g(n,m,a,b,x,y)
&=g\left(\lfloor c/m\rfloor-1,a,m,m+a-b-1,y,x\right)yx^{\left\lfloor(c\bmod m)/a\right\rfloor}
\end{align*}$$

停止性の議論は同様．