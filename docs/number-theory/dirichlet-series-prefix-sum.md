Dirichlet 級数の係数と，その累積和を管理する．

乗法的関数の累積和などの計算に利用できる．

参考資料：[Dirichlet 積と、数論関数の累積和 - maspyのHP](https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c)

template の `mint` は整数からの構築，四則演算，`pow`，`inv` に対応する型とする．
$N\geq 1$．
$K,L$ は $N$ に依存するパラメータであり，$K=\Theta((N/\log N)^{2/3}),L=\Theta(N^{1/3}(\log N)^{2/3})$．

- `DP(N)`：長さ $N$ として初期化する．
- `a[x]`：$1\leq x\leq K$ における係数 $a_x$．
- `s[x]`：$0\leq x\leq K$ における累積和 $\sum_{j=1}^x a_j$．
- `S[i]`：$1\leq i\leq L$ における累積和 $\sum_{j=1}^{\lfloor N/i\rfloor}a_j$．
- `calc_small_sum()`：`a` から `s` を再計算する．`S` は変更しない．
- `id(N)`：係数 $a_1=1$，それ以外が $0$ の乗法単位元を返す．
- `zeta(N, k=0)`：係数 $a_x=x^k$ の級数を返す．$0\leq k\leq 3$．
- `zeta_mul(N, k)`：係数が $k$ 乗数で $1$，それ以外で $0$ の級数 $\zeta(ks)$ を返す．$k\geq 1$．
- `rising(N, k)`，`falling(N, k)`：それぞれ係数が $\binom{x+k-1}{k}$，$\binom{x}{k}$ の級数を返す．
- `add(x, v)`：自身に $vx^{-s}$ を加え，自身への参照を返す．$x\geq 1$．
- `shift(x)`：自身に $x^{-s}$ を掛け，自身への参照を返す．$x\geq 1$．
- `+`, `-`：係数ごとの加減算を行う．
- `*`：級数同士では Dirichlet 積，`mint` に対しては係数の定数倍を行う．
- `/`，`inv()`：Dirichlet 積に関する商・逆元を返す．除数の $a_1$ は可逆である必要がある．

級数同士の演算では $N$ が一致する必要がある．

計算量はコンストラクタ・加減算・定数倍・`add`・`shift` が $O((N/\log N)^{2/3})$ 時間，積・商・逆元が $O(N^{2/3}(\log N)^{1/3})$ 時間．
