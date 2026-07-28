非負整数の加算，乗算，累乗からなる式を法 $m$ で計算する．

通常の modint と異なり `PowerTowerModInt<m>` 自身を指数に指定できる．法と底が互いに素でない場合や，`0` の累乗も扱える．$0^0=1$ とする．

$1\leq m\lt 2^{31}$ である必要がある．通常の減算，除算，負数は扱わない．

## 使い方

- `PowerTowerModInt<m>(x)`：非負の 64 bit 整数 $x$ から構築する．
- `get_mod()`：法 $m$ を返す．
- `val()`：式の値を $m$ で割った余りを返す．
- `large_val()`：式の真の値を $x$ として，$x\lt m$ ならば $x$，そうでなければ $m+(x\bmod m)$ を返す．返り値は $[0,2m)$ に属する．
- `operator+`, `operator*`：式を加算または乗算する．
- `unsafe_subtract(rhs)`：自身と `rhs` が表す真の値をそれぞれ $x,y$ として，$x\gets x-y$ とする．$x\lt m$ ならば $0\leq y\leq x$，そうでなければ $x-y\geq m$ を仮定する．
- `unsafe_subtract(int64_t y)`：自身が表す真の値を $x$ として，$x\gets x-y$ とする．$x\lt m$ ならば $0\leq y\leq x$，そうでなければ $x-y\geq m$ を仮定する．
- `pow(e)`：自身を `e` 乗する．
- `operator==`, `operator!=`：`val()` が等しいかを判定する．

`unsafe_subtract` で結果が $m$ 以上となる場合の前提条件は内部表現から検査できない．`val()` の大小ではなく，加算，乗算，累乗からなる元の式の真の値について保証する必要がある．

## 仕組み

$m,\varphi(m),\varphi(\varphi(m)),\dots,1$ のそれぞれを法とする値を保持する．各法 $p$ では，非負整数 $x$ を

$$
\begin{cases}
x & (x\lt p),\\
p+(x\bmod p) & (x\geq p)
\end{cases}
$$

で表す．これにより，指数が周期へ入る前の小さい値と周期へ入った値を区別する．

## 計算量

オブジェクトの空間計算量は $O(\log m)$．構築，加算，乗算，`unsafe_subtract` は $O(\log m)$ 時間，`pow` は $O((\log m)^2)$ 時間，`val()` と `large_val()` は $O(1)$ 時間．

## 資料

- [指数に乗せられる Modint と Japanese Exponentation](https://trap.jp/post/1444/)
