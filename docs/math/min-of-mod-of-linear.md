整数 $M,A,B$ に対し $f(x)=(Ax+B)\bmod M$ とする．

任意の $0\leq y\lt x$ に対して $f(y)\lt f(x)$ となる $x$ 全体の集合を $S$ とすると，$S$ は $O(\log M)$ 個の

整数 $N,M,A,B$ に対し $\min\{f(x) \mid 0 \leq x \lt N\}$ を求めることも $O(\log M)$ 時間でできる．

- min を求める問題はモノイド版 floor sum でも解ける．

関連記事

- Library Checker：[https://judge.yosupo.jp/problem/min_of_mod_of_linear]
- 解説記事：[https://maspypy.com/library-checker-min-of-mod-of-linear]

## アルゴリズム

