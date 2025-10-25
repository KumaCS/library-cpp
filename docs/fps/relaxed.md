多項式 $f(x),g(x)$ について $i=0,1,\dots$ について順に以下を処理する．

> $[x^i]f(x),[x^i]g(x)$ が新しく与えられる．$[x^i]f(x)g(x)$ を返す．

$N$ 次まで求めるとき $O(N(\log N)^2)$ 時間．

$g$ がはじめからわかっている場合 (semi-relaxed convolution) は定数倍が改善できる．

また inv/exp/log/sqrt なども積と同じ計算量で求められる．

## 積

適切に分割してまとめて計算する．

通常の畳み込みよりも middle product の方が相性がよい．

- https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c

上の資料で middle product の項で提示されている形よりは以下の形の方が扱いやすいはず

![](https://kumacs.github.io/library-cpp/relaxed.png)

## inv / FPS 除算

より一般に $h(x)=f(x)/g(x)$ を求めることができる（$[x^0]g(x)\neq 0$）．

$f=gh$ より任意の $i$ に対し

$$h_i=\frac{1}{g_0}\left(f_i-\sum_{j=0}^{i-1}h_{i-1-j}g_{j+1}\right)$$

であるから積の計算に帰着される（特に定数倍は変化しない）．

## exp

$g(x)=\exp f(x)\ ([x^0]f(x)=0)$ のとき $g_0=1$ である．また $g'=f'g$ より $1$ 次以上の部分は積の計算に帰着される．

## log

$g(x)=\log f(x)\ ([x^0]f(x)=1)$ のとき $g_0=0$ である．また $g'=f'/f$ より $1$ 次以上の部分は FPS の除算に帰着される．

## sqrt

$g(x)=\sqrt{f(x)}\ ([x^0]f(x)\neq 0)$ のとき $g_0=\sqrt{f_0}$ である．また $g^2=f$ より $i\geq 1$ について

$$2g_0g_i+\sum_{j=1}^{i-1}g_jg_{i-j}=f_i$$

であるから積の計算に帰着できる．
