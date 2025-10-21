$x\bmod m_1=r_1,x\bmod m_2=r_2,\dots,x\bmod m_n=r_n$ を満たす最小の非負整数 $x$ を求める．ただし $m_1,m_2,\dots,m_n$ のどの 2 つも互いに素．

## 解の mod をとらないとき

まず $n=2$ のときを考える．

$x=r_1+m_1y$ とおくと $y\equiv(r_2-r_1)m_1^{-1}\pmod{m_2}$ である．

従って $x=r_1+m_1((r_2-r_1)m_1^{-1}\bmod{m_2})$ として $x$ が求められる．

複数 mod のときも繰り返し用いればよい．

## 解の mod をとるとき

まず$n=2$ のときを考える．

$m_0$ を任意の mod とする（$m_1$ および $m_2$ と互いに素でなくとも構わない）．

$(x\bmod m_1)\bmod m_i$ の値がわかっているときに $(x\bmod m_1m_2)\bmod m_i$ の値を求める．

そのためには $(r_2-r_1)m_1^{-1}\bmod{m_2}$ の値がわかればよく，これは $(x\bmod m_1)\bmod m_2,m_1\bmod m_2$ の値から求められる．

その値（$y$ とする）が求まれば，計算済みの値にそれぞれ $m_1y$ を適宜 mod をとって加えればよい．

一般の $n$ に対しては，以下のように定める．

$$\begin{align*}
x_i&=\left(\sum_{j=1}^{i-1}y_j\left(\prod_{l=1}^{j-1}m_l\right)\right)\bmod{m_i}\quad (1\leq i\leq n)\\
y_i&=(r_i-x_i)\left(\prod_{l=1}^{i-1}m_l\right)^{-1}\bmod{m_i}\quad(1\leq i\leq n).
\end{align*}$$

このとき実際の値は $y_1+m_1y_2+\cdots+m_1\cdots m_{i-1}y_i$ であるから，これを適宜 mod を取り計算すればよい．

$x$ の値が非常に大きいような場合であっても，四則演算が各 mod の範囲でさえ行えれば計算できる．

## オンライン化

解の mod をとらないとき，単に直近の mod と解を持てばよい．

解の mod をとるとき，$m_i,y_i$ の値を管理しておけばよい．