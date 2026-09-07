二項係数 $\binom{n}{k}\bmod m$ を $n,k\leq 10^{18},m\leq 10^6$ 程度の制約下で求める．


## アルゴリズム

$0\leq k\leq n$ であるとする．

中国剰余定理より $m$ が素べき $p^e$ の場合に帰着できる．

非負整数 $a$ に対し $a!_{(p)}$ を $1,2,\dots,a$ のうち $p$ の倍数でないものの総積とする．
特に $0!_{(p)}=1$ である．
また $r=n-k$ として $n_j=\lfloor n/p^j\rfloor, k_j=\lfloor k/p^j\rfloor, r_j=\lfloor r/p^j\rfloor$ とおく．

このとき $n!=p^{\sum_{j=1}^{\infty}n_j} \cdot \prod_{j=0}^{\infty}n_j!_{(p)}$ が成り立つ．

$a!_{(p)}$ は任意の $a$ について $p$ および $p^e$ と互いに素であるから

$$\binom{n}{k} \equiv p^{\sum_{j=1}^{\infty}n_j-\sum_{j=1}^{\infty}k_j-\sum_{j=1}^{\infty}r_j} \cdot \prod_{j=0}^{\infty}\frac{n_j!_{(p)}}{k_j!_{(p)}\cdot r_j!_{(p)}} \pmod{p^e}$$

と表示できる．$a!_{(p)}$ は $0\leq a\lt p^e$ の範囲を前計算しておけば $a\leq 10^{18}$ のようなケースでも高速に計算できる．