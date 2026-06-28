
区分線形凸関数を管理するデータ構造．

最小値と，傾きが変わる点を 2 つの priority queue で管理する．
DP の遷移で $\max(0,x-a)$, $\max(0,a-x)$, $|x-a|$ を足したり，片側の累積 min を取ったりするときに使う．

- `get_min()`：現在の関数の最小値を返す．
- `get_min_range()`：最小値を取る区間を返す．
- `add_const(a)`：関数全体に定数 $a$ を足す．
- `add_x_minus_a(a)`：$\max(0,x-a)$ を足す．
- `add_a_minus_x(a)`：$\max(0,a-x)$ を足す．
- `add_abs(a)`：$|x-a|$ を足す．
- `clear_right()`：$f(x)\gets\min_{y\leq x} f(y)$ とする．
- `clear_left()`：$f(x)\gets\min_{x\leq y} f(y)$ とする．
- `shift(a, b)`：$f(x)\gets\min_{x-b\leq y\leq x-a} f(y)$ とする．

https://ei1333.github.io/library/structure/others/slope-trick.hpp.html
https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
