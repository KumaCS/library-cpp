64 bit 整数を素因数分解する．

- `PollardRho::factorize(N)`：$N$ の素因数と指数の組を素因数の昇順に並べた列を返す．$1\leq N\leq 10^{18}$ とし，$N=1$ のとき空列を返す．

Miller-Rabin 素数判定と Pollard's rho algorithm を用いる．期待計算量は $O(N^{1/4}\log N)$．
