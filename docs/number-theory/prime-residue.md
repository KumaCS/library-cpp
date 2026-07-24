## 素数の剰余類別集計

$N$ 以下の素数の個数と総和を $M$ を法とする剰余類ごとに求める．$N\geq 0$，$M\geq 1$ とする．

- `PrimeResidue::count(N, M)`：`(xs, count)` を返す．`count[i][k]` は $p\leq xs[i]$ かつ $p\equiv k\pmod M$ となる素数 $p$ の個数である．
- `PrimeResidue::sum<T>(N, M)`：`(xs, sum)` を返す．`sum[i][k]` は $p\leq xs[i]$ かつ $p\equiv k\pmod M$ となる素数 $p$ の総和である．`T` の既定値は `__int128_t`．

`xs` は集合 $\{\lfloor N/i\rfloor:1\leq i\leq N\}$ の元を昇順に並べた列である．

`T` は整数から構築でき，加減算と乗算ができる型とする．

## アルゴリズム

基底 $e_0,e_1,\dots,e_{M-1}$ に積 $e_a e_b=e_{ab\bmod M}$ を定める．`count` では完全乗法的関数 $e_{n\bmod M}$，`sum` では $ne_{n\bmod M}$ に Lucy DP を適用する．

いずれも時間計算量は $O\left(MN^{3/4}/\log N\right)$，空間計算量は $O(M\sqrt N)$．
