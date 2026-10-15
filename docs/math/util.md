整数の除算，累乗，根，拡張 Euclid の互除法などを扱う．すべて `Math` namespace にある．

演算途中の値も各整数型に収まるものとする．

- `safe_mod(a, b)`：$0\leq r<|b|$ を満たす剰余を返す．負の `b` では `-a` を法 `|b|` で評価する．$b\neq 0$．
- `floor(a, b)`，`ceil(a, b)`：それぞれ $\lfloor a/b\rfloor$，$\lceil a/b\rceil$ を返す．$b\neq 0$．
- `ipow(x, n)`：整数 $x^n$ を `long long` で返す．$n\geq 0$．$0^0=1$ とする．最後の反復でも `x*x` を計算するため，答えだけでなくその積も `long long` に収まる必要がある．
- `isqrt(n)`：$n>0$ なら $\lfloor\sqrt n\rfloor$，$n\leq 0$ なら $0$ を返す．
- `floor_root(n, k)`：非負整数 $n$ の $k$ 乗根の切り捨てを返す．$k\geq 1$．
- `floor_root_unsigned(n, k)`：`unsigned long long` の全域で $k$ 乗根の切り捨てを返す．$k\geq 1$．二分探索を用いる．
- `ext_gcd(a, b, x, y)`：$ax+by=\gcd(a,b)$ を満たす `x, y` を設定し，非負の gcd を返す．$b\neq 0$ なら $0\leq x<|b|/\gcd(a,b)$ となる．$a=b=0$ の場合は除く．
- `inv_mod(x, m)`：法 $m$ における逆元を返す．$m\geq 1$，$\gcd(x,m)=1$ とする．
- `pow_mod(x, n, m)`，`pow_mod_constexpr(x, n, m)`：$x^n\bmod m$ を返す．$n\geq 0$，$m\geq 1$．後者は定数評価に対応する．
- `is_prime_constexpr(n)`，`is_prime<n>`：`int` の整数が素数か判定する．定数評価に対応する．

計算量は `ipow`・`pow_mod`・`pow_mod_constexpr` が $O(\log n)$ 時間，`floor_root_unsigned` が $O(k\log n)$ 時間．
