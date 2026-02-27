---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/prime-sieve.hpp
    title: "\u7D20\u6570\u7BE9"
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/number-theory/lucy-dp.md
    document_title: Lucy DP
    links: []
  bundledCode: "#line 2 \"number-theory/lucy-dp.hpp\"\n\n#line 2 \"math/util.hpp\"\
    \n\nnamespace Math {\ntemplate <class T>\nT safe_mod(T a, T b) {\n  assert(b !=\
    \ 0);\n  if (b < 0) a = -a, b = -b;\n  a %= b;\n  return a >= 0 ? a : a + b;\n\
    }\ntemplate <class T>\nT floor(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a\
    \ = -a, b = -b;\n  return a >= 0 ? a / b : (a + 1) / b - 1;\n}\ntemplate <class\
    \ T>\nT ceil(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return\
    \ a > 0 ? (a - 1) / b + 1 : a / b;\n}\nlong long isqrt(long long n) {\n  if (n\
    \ <= 0) return 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n)\
    \ x++;\n  while (x * x > n) x--;\n  return x;\n}\n// return g=gcd(a,b)\n// a*x+b*y=g\n\
    // - b!=0 -> 0<=x<|b|/g\n// - b=0  -> ax=g\ntemplate <class T>\nT ext_gcd(T a,\
    \ T b, T& x, T& y) {\n  T a0 = a, b0 = b;\n  bool sgn_a = a < 0, sgn_b = b < 0;\n\
    \  if (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n  if (b == 0) {\n    x = sgn_a ?\
    \ -1 : 1;\n    y = 0;\n    return a;\n  }\n  T x00 = 1, x01 = 0, x10 = 0, x11\
    \ = 1;\n  while (b != 0) {\n    T q = a / b, r = a - b * q;\n    x00 -= q * x01;\n\
    \    x10 -= q * x11;\n    swap(x00, x01);\n    swap(x10, x11);\n    a = b, b =\
    \ r;\n  }\n  x = x00, y = x10;\n  if (sgn_a) x = -x;\n  if (sgn_b) y = -y;\n \
    \ if (b0 != 0) {\n    a0 /= a, b0 /= a;\n    if (b0 < 0) a0 = -a0, b0 = -b0;\n\
    \    T q = x >= 0 ? x / b0 : (x + 1) / b0 - 1;\n    x -= b0 * q;\n    y += a0\
    \ * q;\n  }\n  return a;\n}\nconstexpr long long inv_mod(long long x, long long\
    \ m) {\n  x %= m;\n  if (x < 0) x += m;\n  long long a = m, b = x;\n  long long\
    \ y0 = 0, y1 = 1;\n  while (b > 0) {\n    long long q = a / b;\n    swap(a -=\
    \ q * b, b);\n    swap(y0 -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n \
    \ return y0;\n}\nlong long pow_mod(long long x, long long n, long long m) {\n\
    \  x = (x % m + m) % m;\n  long long y = 1;\n  while (n) {\n    if (n & 1) y =\
    \ y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr\
    \ long long pow_mod_constexpr(long long x, long long n, int m) {\n  if (m == 1)\
    \ return 0;\n  unsigned int _m = (unsigned int)(m);\n  unsigned long long r =\
    \ 1;\n  unsigned long long y = x % m;\n  if (y >= m) y += m;\n  while (n) {\n\
    \    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n    n >>= 1;\n  }\n\
    \  return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n  if (n <= 1) return\
    \ false;\n  if (n == 2 || n == 7 || n == 61) return true;\n  if (n % 2 == 0) return\
    \ false;\n  long long d = n - 1;\n  while (d % 2 == 0) d /= 2;\n  constexpr long\
    \ long bases[3] = {2, 7, 61};\n  for (long long a : bases) {\n    long long t\
    \ = d;\n    long long y = pow_mod_constexpr(a, t, n);\n    while (t != n - 1 &&\
    \ y != 1 && y != n - 1) {\n      y = y * y % n;\n      t <<= 1;\n    }\n    if\
    \ (y != n - 1 && t % 2 == 0) {\n      return false;\n    }\n  }\n  return true;\n\
    }\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n};  //\
    \ namespace Math\n#line 2 \"math/prime-sieve.hpp\"\n\nvector<int> PrimeSieve(int\
    \ n) {\n  vector<bool> f(n + 1, false);\n  for (int p = 2; p * p <= n; p += (p\
    \ & 1) + 1) {\n    if (f[p]) continue;\n    for (int i = p * p; i <= n; i += p)\
    \ f[i] = true;\n  }\n  vector<int> ps;\n  for (int p = 2; p <= n; p += (p & 1)\
    \ + 1)\n    if (!f[p]) ps.push_back(p);\n  return ps;\n}\n/**\n * @brief \u7D20\
    \u6570\u7BE9\n */\n#line 5 \"number-theory/lucy-dp.hpp\"\n\ntemplate <class T>\n\
    pair<vector<long long>, vector<T>> LucyDP(long long n, function<T(ll)> point_value,\
    \ function<T(ll)> prefix_sum) {\n  using ll = long long;\n  const ll sq = Math::isqrt(n);\n\
    \n  vector<ll> qs(sq * 2 - (sq * sq == n));\n  for (int i = 0; i < sq; i++) qs[i]\
    \ = i + 1;\n  for (int i = 0; i < sq; i++) qs[qs.size() - 1 - i] = n / (i + 1);\n\
    \  vector<T> s(qs.size());\n  auto v1 = point_value(1);\n  for (int i = 0; i <\
    \ qs.size(); i++) s[i] = prefix_sum(qs[i]) - v1;\n\n  auto ps = PrimeSieve(sq);\n\
    \  for (ll p : ps) {\n    auto v = point_value(p);\n    for (int i = (int)qs.size()\
    \ - 1; i >= 0; i--) {\n      ll q = qs[i];\n      if (p * p > q) break;\n    \
    \  ll x = q / p;\n      int j = x <= sq ? x - 1 : (int)s.size() - n / x;\n   \
    \   s[i] -= (s[j] - s[p - 2]) * v;\n    }\n  }\n\n  return {qs, s};\n}\n\n/**\n\
    \ * @brief Lucy DP\n * @docs docs/number-theory/lucy-dp.md\n */\n"
  code: "#pragma once\n\n#include \"math/util.hpp\"\n#include \"math/prime-sieve.hpp\"\
    \n\ntemplate <class T>\npair<vector<long long>, vector<T>> LucyDP(long long n,\
    \ function<T(ll)> point_value, function<T(ll)> prefix_sum) {\n  using ll = long\
    \ long;\n  const ll sq = Math::isqrt(n);\n\n  vector<ll> qs(sq * 2 - (sq * sq\
    \ == n));\n  for (int i = 0; i < sq; i++) qs[i] = i + 1;\n  for (int i = 0; i\
    \ < sq; i++) qs[qs.size() - 1 - i] = n / (i + 1);\n  vector<T> s(qs.size());\n\
    \  auto v1 = point_value(1);\n  for (int i = 0; i < qs.size(); i++) s[i] = prefix_sum(qs[i])\
    \ - v1;\n\n  auto ps = PrimeSieve(sq);\n  for (ll p : ps) {\n    auto v = point_value(p);\n\
    \    for (int i = (int)qs.size() - 1; i >= 0; i--) {\n      ll q = qs[i];\n  \
    \    if (p * p > q) break;\n      ll x = q / p;\n      int j = x <= sq ? x - 1\
    \ : (int)s.size() - n / x;\n      s[i] -= (s[j] - s[p - 2]) * v;\n    }\n  }\n\
    \n  return {qs, s};\n}\n\n/**\n * @brief Lucy DP\n * @docs docs/number-theory/lucy-dp.md\n\
    \ */"
  dependsOn:
  - math/util.hpp
  - math/prime-sieve.hpp
  isVerificationFile: false
  path: number-theory/lucy-dp.hpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number-theory/lucy-dp.hpp
layout: document
redirect_from:
- /library/number-theory/lucy-dp.hpp
- /library/number-theory/lucy-dp.hpp.html
title: Lucy DP
---
正整数 $N$ が与えられたとき，完全乗法的関数で prefix の和が簡単に計算できる $f$ について $\sum_{p:\text{prime},p\leq N}f(p)$ を $O(N^{2/3}/(\log N)^{1/3})$ 時間で求められる．

以下の情報を与える必要がある．
- 正整数 $k$ に対する $\sum_{i=1}^{\lfloor N/k\rfloor}f(i)$ の値（$O(\sqrt{N})$ 個）．
- $\sqrt{N}$ 以下の素数に対する $f$ の値．
  - 実際は上の総和から計算できる．


例題：
- https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_b


$f$ の例：
- $f(n)=n^k$：$k=0$ のとき $\sum_{p:\text{prime}}f(p)$ は $N$ 以下の素数の個数である．
- Dirichlet 指標：$4$ で割ったあまりが $1$ の素数の和なども求められる．

## アルゴリズム：$O(N^{3/4}/\log N)$

この節は [1] を大幅に参考にしている．

$S(n)=\sum_{p:\text{prime},p\leq n}f(p)$ とおく．

エラトステネスの篩の要領で計算する．

$S_x(n)$ を $\sum_{i=2}^{n}f(i)$ から $x$ 以下の素因数をもつ合成数についての $f$ の値を減じたものとする．$S_x$ は $x$ 以下の数について篩った時点での累積和であり，$x\geq\lfloor\sqrt{n}\rfloor$ ならば $S(n)=S_x(n)$ である．
また $S_1(n)=\sum_{i=2}^{n}f(i)$ である．

以下最小素因数を $\operatorname{lpf}(n)$ で表すことにする．

$S_x$ を $S_{x-1}$ で表す．
$x$ が素数でないならば篩うことはなく $S_x=S_{x-1}$ である．
$x$ が素数であるとき，エラトステネスの篩では $\operatorname{lpf}(i)=x$ かつ $i\neq x$ なる $i$ が篩われる．特に $x^2$ 未満の数は篩われないため以下が成り立つ．
$$S_x(n)=\begin{cases}
S_{x-1}(n)-\left(S_{x-1}(\lfloor n/x \rfloor)-S_{x-1}(x-1)\right)f(x)&(x:\text{prime}, x^2\leq n)\\
S_{x-1}(n)&(\text{otherwise})
\end{cases}$$

$S(N)$ を求めるためには $S_x(\lfloor N/*\rfloor)$ の形の部分だけ管理すればよく，$n$ について降順に計算することで in-place に更新できる．
$\lfloor N/*\rfloor$ のとりうる値の種類数は $O(\sqrt{N})$ であるため空間計算量は $O(\sqrt{N})$ になる．

時間計算量は $\lfloor N/*\rfloor$ の取り得る値すべてについての，その平方根以下の素数の個数の総和のオーダーである．
素数定理 
$$\pi(n)\approx\operatorname{Li}(n),\quad \operatorname{Li}(x)=\int_{2}^{x}\frac{1}{\log t}dt\approx\frac{x}{\log x}$$
を用いれば次のように見積もれる．

$$\begin{align*}
\sum_{n=2}^{\lfloor\sqrt{N}\rfloor}\pi(\sqrt{n})
+\sum_{n=1}^{\lfloor\sqrt{N}\rfloor}\pi\left(\sqrt{\frac{N}{n}}\right)
%&\approx\int_{2}^{\sqrt{N}}\operatorname{Li}(\sqrt{x})dx+\int_{1}^{\sqrt{N}}\operatorname{Li}\left(\sqrt{N/x}\right)dx\\
&\approx\int_{2}^{\sqrt{N}}\frac{\sqrt{x}}{\log\sqrt{x}}dx+\int_{1}^{\sqrt{N}}\frac{\sqrt{N/x}}{\log\sqrt{N/x}}dx\\
&\leq\int_{2}^{\sqrt{N}}\frac{N^{1/4}}{\frac{1}{2}\log x}dx+\int_{1}^{\sqrt{N}}\frac{\sqrt{N/x}}{\log N^{1/4}}dx\\
&\approx N^{1/4}\cdot 2\operatorname{Li}(\sqrt{N})+\frac{1}{\log N^{1/4}}\cdot\frac{N^{3/4}}{2}\\
&=O\left(\frac{N^{3/4}}{\log N}\right)
\end{align*}$$


以上の内容をアルゴリズムの形でまとめておく．
$Q=\{\lfloor N/i\rfloor \mid 1\leq i\leq N\}$ とする．

> - $S[q]=\sum_{i=2}^{q}f(i)$ と初期化．
> - $p^2\leq N$ なる素数 $p$ に対して以下を行う．
>   - $p^2\leq q$ なる $q\in Q$ について降順に $S[q]$ を $S[q]-(S[\lfloor q/p\rfloor]-S[p-1])f(p)$ で更新する．
> - return $S$．

## 高速化：$\tilde O(N^{2/3})$

$\tilde O(N^{2/3})$ 時間に高速化できる．

[2] では $O(N^{2/3}(\log N)^{1/3})$ 時間 / $\tilde O(N^{2/3})$ 空間のアルゴリズムが紹介されている．そこまで大きな改善ではなく空間計算量は悪化しているが実装はシンプルである．

<!--
Fenwick Tree による高速化ができる．

$\sqrt{N}\lt M\leq N$ なる $M$ をとり，$1,2,\dots,M$ については実際にエラトステネスの篩を行いながら，そこの分の $S$ の値を index が $1,\dots,M$ の Fenwick Tree を用いて管理する．

> - $S[q]=\sum_{i=2}^{q}f(i)$ と初期化．
> - Fenwick Tree $F$ を index $1,\dots,M$ について初期化．$i\geq 2$ について $F[i]=f(i)$ とする．
> - boolean 配列 $\mathrm{sieve}$ を index $2,3,\dots,M$ について $\mathrm{false}$ で初期化．
> - $p=2,3,\dots,\lfloor\sqrt{N}\rfloor$ に対して順に以下を行う．
>   - $\mathrm{sieve}[p]=\mathrm{true}$ ならば continue．
>   - $p^2\leq q$ かつ $q\gt M$ なる $q\in Q$ について降順に $S[q]$ を $S[q]-(S'(\lfloor q/p\rfloor)-S'(p-1)-1)f(p)$ で更新する．ここで $S'(i)$ は $i>M$ ならば $S[i]$，そうでないならば $F$ における $1$ から $i$ までの和．
>   - $\mathrm{sieve}$ をエラトステネスの篩の要領で $p$ について更新し，$F$ も合わせて更新する．
> - return $S$．

計算量を評価．

$F$ の更新回数は高々 $M$ 回なので $O(M\log M)$ 時間．

$S$ の直接的な更新は $q>M$ なる $q\in Q$ についてのみであるから，その回数は前節と同様にして
$$\begin{align*}
\sum_{n=1}^{\lfloor N/M\rfloor}\pi\left(\sqrt{\frac{N}{n}}\right)
&\approx\int_{1}^{N/M}\operatorname{Li}\left(\sqrt{N/x}\right)dx\\
&\leq \int_{1}^{N/M}\int_2^{\sqrt{N/x}}\frac{1}{\log t} dt dx\\
&\leq \int_2^{\sqrt{N}}\int_{1}^{\min(N/M,N/t^2)}\frac{1}{\log t} dx dt\\
&= \int_2^{\sqrt{M}}\frac{N/M}{\log t} dt+\int_{\sqrt{M}}^{\sqrt{N}}\frac{N/t^2}{\log t} dt\\
&=O\left(\frac{N}{\sqrt{M}\log M}\right)
\end{align*}$$
と評価できる．

更新において Fenwick Tree の総和取得を行うので，全体の計算量は $O\left(M\log M+N/\sqrt{M}\right)$ 時間であり，$M\approx(N/\log N)^{2/3}$ で $O(N^{2/3}(\log N)^{1/3})$ 時間となる．
-->


### $O(N^{2/3}/(\log N)^{1/3})$ 時間

[1] の内容．

計算量を評価しなおす．素数 $p$ の計算量への寄与は
$$\max(\sqrt{N}-p^2,0)+\min(N/p^2,\sqrt{N})$$
であるので，時間計算量は
$$\int_{2}^{\sqrt{N}}\left(\max(\sqrt{N}-x^2,0)+\min(N/x^2,\sqrt{N})\right)\frac{1}{\log x} dx$$
と近似できる．ここで $\frac{1}{\log x}$ は $\frac{d\operatorname{Li}(x)}{dx}=\frac{1}{\log x}$ に由来する．

$p\leq N^{1/6}$ なる $p$ に対応する部分は以下のように評価できる．
$$\begin{align*}
&\int_{2}^{N^{1/6}}\left(\max(\sqrt{N}-x^2,0)+\min(N/x^2,\sqrt{N})\right)\frac{1}{\log x}dx\\
&=\int_{2}^{N^{1/6}}\left((\sqrt{N}-x^2)+\sqrt{N}\right)\frac{1}{\log x}dx\\
&\leq 2\sqrt{N}\operatorname{Li}(N^{1/6})\\
&=O\left(\frac{N^{2/3}}{\log N}\right)
\end{align*}$$

また $N^{1/3}\leq p\leq N^{1/2}$ なる $p$ に対応する部分は以下のように評価できる．
$$\begin{align*}
&\int_{N^{1/3}}^{N^{1/2}}\left(\max(\sqrt{N}-x^2,0)+\min(N/x^2,\sqrt{N})\right)\frac{1}{\log x}dx\\
&=\int_{N^{1/3}}^{N^{1/2}}\frac{N}{x^2}\cdot\frac{1}{\log x}dx\\
&\leq\int_{N^{1/3}}^{N^{1/2}}\frac{N}{x^2}\cdot\frac{1}{\log N^{1/3}}dx\\
&=O\left(\frac{N^{2/3}}{\log N}\right)\\
\end{align*}$$

従ってこれらの範囲の $p$ については普通に Lucy DP の計算をしても $O\left(\frac{N^{2/3}}{\log N}\right)$ 時間で計算できる．

$N^{1/6}\lt p\lt N^{1/3}$ なる $p$ について考える．
$q\geq N^{2/3}$ なる $q\in Q$ は $O(N^{1/3})$ 個なのでその遷移は愚直に行うことにして，$N^{1/3}\lt p^2\leq q\lt N^{2/3}$ なる $q$ についての遷移を再考する．

(TODO: やる)

> - $S[q]=\sum_{i=2}^{q}f(i)$ と初期化．
> - $p^2\leq N$ なる素数 $p$ に対して以下を行う．
>   - $p^2\leq q$ なる $q\in Q$ について降順に $S[q]$ を $S[q]-(S[\lfloor q/p\rfloor]-S[p-1]-1)f(p)$ で更新する．
> - return $S$．




## 参考資料

- [1] : https://rsk0315.github.io/slides/prime-counting.pdf
- [2] : https://gbroxey.github.io/blog/2023/04/09/lucy-fenwick.html