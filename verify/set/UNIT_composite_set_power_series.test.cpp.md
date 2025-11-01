---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':x:'
    path: set/composite-set-power-series.hpp
    title: Polynomial Composite Set Power Series
  - icon: ':x:'
    path: set/exp-of-set-power-series.hpp
    title: Exp Of Set Power Series
  - icon: ':x:'
    path: set/subset-convolution.hpp
    title: Subset Convolution
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/set/UNIT_composite_set_power_series.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"template/macro.hpp\"\
    \n#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)\n#define rrep(i, a,\
    \ b) for (int i = (int)(b) - 1; i >= (a); i--)\n#define ALL(v) (v).begin(), (v).end()\n\
    #define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define\
    \ SZ(v) (int)v.size()\n#define MIN(v) *min_element(ALL(v))\n#define MAX(v) *max_element(ALL(v))\n\
    #define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())\n#define UB(v, x)\
    \ int(upper_bound(ALL(v), (x)) - (v).begin())\n#define YN(b) cout << ((b) ? \"\
    YES\" : \"NO\") << \"\\n\";\n#define Yn(b) cout << ((b) ? \"Yes\" : \"No\") <<\
    \ \"\\n\";\n#define yn(b) cout << ((b) ? \"yes\" : \"no\") << \"\\n\";\n#line\
    \ 6 \"template/template.hpp\"\n\n#line 2 \"template/util.hpp\"\nusing uint = unsigned\
    \ int;\nusing ll = long long int;\nusing ull = unsigned long long;\nusing i128\
    \ = __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <class T, class S = T>\n\
    S SUM(const vector<T> &a) {\n  return accumulate(ALL(a), S(0));\n}\ntemplate <class\
    \ T>\ninline bool chmin(T &a, T b) {\n  if (a > b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <class T>\ninline bool chmax(T &a, T b) {\n\
    \  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\ntemplate\
    \ <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n}\ntemplate\
    \ <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
    }\ntemplate <class T>\nint lowbit(T x) {\n  return (x == 0 ? -1 : __builtin_ctzll(x));\n\
    }\n#line 8 \"template/template.hpp\"\n\n#line 2 \"template/inout.hpp\"\nstruct\
    \ Fast {\n  Fast() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n  }\n} fast;\n\ntemplate <class T1, class\
    \ T2>\nistream &operator>>(istream &is, pair<T1, T2> &p) {\n  return is >> p.first\
    \ >> p.second;\n}\ntemplate <class T1, class T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p) {\n  return os << p.first << \" \" << p.second;\n\
    }\ntemplate <class T>\nistream &operator>>(istream &is, vector<T> &a) {\n  for\
    \ (auto &v : a) is >> v;\n  return is;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &a) {\n  for (auto it = a.begin(); it != a.end();) {\n\
    \    os << *it;\n    if (++it != a.end()) os << \" \";\n  }\n  return os;\n}\n\
    template <class T>\nostream &operator<<(ostream &os, const set<T> &st) {\n  os\
    \ << \"{\";\n  for (auto it = st.begin(); it != st.end();) {\n    os << *it;\n\
    \    if (++it != st.end()) os << \",\";\n  }\n  os << \"}\";\n  return os;\n}\n\
    template <class T1, class T2>\nostream &operator<<(ostream &os, const map<T1,\
    \ T2> &mp) {\n  os << \"{\";\n  for (auto it = mp.begin(); it != mp.end();) {\n\
    \    os << it->first << \":\" << it->second;\n    if (++it != mp.end()) os <<\
    \ \",\";\n  }\n  os << \"}\";\n  return os;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &...u) {\n  cin >> t;\n  in(u...);\n}\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &...u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n#line 10 \"template/template.hpp\"\n\n#line 2 \"template/debug.hpp\"\
    \n#ifdef LOCAL\n#define debug 1\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\n\
    #else\n#define debug 0\n#define show(...) true\n#endif\ntemplate <class T>\nvoid\
    \ _show(int i, T name) {\n  cerr << '\\n';\n}\ntemplate <class T1, class T2, class...\
    \ T3>\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c) {\n  for (;\
    \ a[i] != ',' && a[i] != '\\0'; i++) cerr << a[i];\n  cerr << \":\" << b << \"\
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"math/util.hpp\"\n\nnamespace Math\
    \ {\ntemplate <class T>\nT safe_mod(T a, T b) {\n  assert(b != 0);\n  if (b <\
    \ 0) a = -a, b = -b;\n  a %= b;\n  return a >= 0 ? a : a + b;\n}\ntemplate <class\
    \ T>\nT floor(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n \
    \ return a >= 0 ? a / b : (a + 1) / b - 1;\n}\ntemplate <class T>\nT ceil(T a,\
    \ T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return a > 0 ? (a\
    \ - 1) / b + 1 : a / b;\n}\nlong long isqrt(long long n) {\n  if (n <= 0) return\
    \ 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n) x++;\n  while\
    \ (x * x > n) x--;\n  return x;\n}\n// return g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0\
    \ -> 0<=x<|b|/g\n// - b=0  -> ax=g\ntemplate <class T>\nT ext_gcd(T a, T b, T&\
    \ x, T& y) {\n  T a0 = a, b0 = b;\n  bool sgn_a = a < 0, sgn_b = b < 0;\n  if\
    \ (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n  if (b == 0) {\n    x = sgn_a ? -1 :\
    \ 1;\n    y = 0;\n    return a;\n  }\n  T x00 = 1, x01 = 0, x10 = 0, x11 = 1;\n\
    \  while (b != 0) {\n    T q = a / b, r = a - b * q;\n    x00 -= q * x01;\n  \
    \  x10 -= q * x11;\n    swap(x00, x01);\n    swap(x10, x11);\n    a = b, b = r;\n\
    \  }\n  x = x00, y = x10;\n  if (sgn_a) x = -x;\n  if (sgn_b) y = -y;\n  if (b0\
    \ != 0) {\n    a0 /= a, b0 /= a;\n    if (b0 < 0) a0 = -a0, b0 = -b0;\n    T q\
    \ = x >= 0 ? x / b0 : (x + 1) / b0 - 1;\n    x -= b0 * q;\n    y += a0 * q;\n\
    \  }\n  return a;\n}\nlong long inv_mod(long long x, long long m) {\n  x %= m;\n\
    \  if (x < 0) x += m;\n  long long a = m, b = x;\n  long long y0 = 0, y1 = 1;\n\
    \  while (b > 0) {\n    long long q = a / b;\n    swap(a -= q * b, b);\n    swap(y0\
    \ -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return y0;\n}\nlong long\
    \ pow_mod(long long x, long long n, long long m) {\n  x = (x % m + m) % m;\n \
    \ long long y = 1;\n  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x *\
    \ x % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m =\
    \ (unsigned int)(m);\n  unsigned long long r = 1;\n  unsigned long long y = x\
    \ % m;\n  if (y >= m) y += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n\
    \    y = (y * y) % _m;\n    n >>= 1;\n  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n  if (n <= 1) return false;\n  if (n == 2 || n == 7 || n == 61) return\
    \ true;\n  if (n % 2 == 0) return false;\n  long long d = n - 1;\n  while (d %\
    \ 2 == 0) d /= 2;\n  constexpr long long bases[3] = {2, 7, 61};\n  for (long long\
    \ a : bases) {\n    long long t = d;\n    long long y = pow_mod_constexpr(a, t,\
    \ n);\n    while (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n\
    \      t <<= 1;\n    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n\
    \    }\n  }\n  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
    };  // namespace Math\n#line 3 \"modint/modint.hpp\"\n\ntemplate <unsigned int\
    \ m = 998244353>\nstruct ModInt {\n  using mint = ModInt;\n  static constexpr\
    \ unsigned int get_mod() { return m; }\n  static mint raw(int v) {\n    mint x;\n\
    \    x._v = v;\n    return x;\n  }\n  ModInt() : _v(0) {}\n  ModInt(int64_t v)\
    \ {\n    long long x = (long long)(v % (long long)(umod()));\n    if (x < 0) x\
    \ += umod();\n    _v = (unsigned int)(x);\n  }\n  unsigned int val() const { return\
    \ _v; }\n  mint& operator++() {\n    _v++;\n    if (_v == umod()) _v = 0;\n  \
    \  return *this;\n  }\n  mint& operator--() {\n    if (_v == 0) _v = umod();\n\
    \    _v--;\n    return *this;\n  }\n  mint operator++(int) {\n    mint result\
    \ = *this;\n    ++*this;\n    return result;\n  }\n  mint operator--(int) {\n\
    \    mint result = *this;\n    --*this;\n    return result;\n  }\n  mint& operator+=(const\
    \ mint& rhs) {\n    _v += rhs._v;\n    if (_v >= umod()) _v -= umod();\n    return\
    \ *this;\n  }\n  mint& operator-=(const mint& rhs) {\n    _v -= rhs._v;\n    if\
    \ (_v >= umod()) _v += umod();\n    return *this;\n  }\n  mint& operator*=(const\
    \ mint& rhs) {\n    unsigned long long z = _v;\n    z *= rhs._v;\n    _v = (unsigned\
    \ int)(z % umod());\n    return *this;\n  }\n  mint& operator/=(const mint& rhs)\
    \ { return *this = *this * rhs.inv(); }\n  mint operator+() const { return *this;\
    \ }\n  mint operator-() const { return mint() - *this; }\n  mint pow(long long\
    \ n) const {\n    assert(0 <= n);\n    mint x = *this, r = 1;\n    while (n) {\n\
    \      if (n & 1) r *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return r;\n\
    \  }\n  mint inv() const {\n    if (is_prime) {\n      assert(_v);\n      return\
    \ pow(umod() - 2);\n    } else {\n      auto inv = Math::inv_mod(_v, umod());\n\
    \      return raw(inv);\n    }\n  }\n  friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n  friend istream&\
    \ operator>>(istream& is, mint& x) { return is >> x._v; }\n  friend ostream& operator<<(ostream&\
    \ os, const mint& x) { return os << x.val(); }\n\n private:\n  unsigned int _v;\n\
    \  static constexpr unsigned int umod() { return m; }\n  static constexpr bool\
    \ is_prime = Math::is_prime<m>;\n};\n#line 5 \"verify/set/UNIT_composite_set_power_series.test.cpp\"\
    \nusing mint = ModInt<998244353>;\n#line 2 \"set/subset-convolution.hpp\"\n\n\
    template <class mint, int n_>\nstruct SubsetConvolution {\n  static constexpr\
    \ int n = n_;\n  using poly = array<mint, n_ + 1>;\n  vector<int> pc;\n  SubsetConvolution()\
    \ {\n    pc.assign(1 << n, 0);\n    for (int i = 1; i < pc.size(); i++) pc[i]\
    \ = pc[i >> 1] + (i & 1);\n  }\n  void poly_add(poly& p, const poly& q, int d)\
    \ {\n    for (int i = 0; i < d; i++) p[i] += q[i];\n  }\n  void poly_sub(poly&\
    \ p, const poly& q, int d) {\n    for (int i = d; i <= n; i++) p[i] -= q[i];\n\
    \  }\n  void poly_mul(poly& p, const poly& q) {\n    poly r{};\n    for (int i\
    \ = 0; i <= n; i++)\n      for (int j = 0; j <= n - i; j++)\n        r[i + j]\
    \ += p[i] * q[j];\n    swap(p, r);\n  }\n  vector<poly> lift(const vector<mint>&\
    \ a) {\n    int n = a.size();\n    assert(n == (n & -n));\n    vector<poly> b(n);\n\
    \    for (int i = 0; i < n; i++) {\n      b[i].fill(0);\n      b[i][pc[i]] = a[i];\n\
    \    }\n    return b;\n  }\n  vector<mint> unlift(const vector<poly>& b) {\n \
    \   int n = b.size();\n    assert(n == (n & -n));\n    vector<mint> a(n);\n  \
    \  for (int i = 0; i < n; i++) a[i] = b[i][pc[i]];\n    return a;\n  }\n  void\
    \ ranked_zeta(vector<poly>& a) {\n    int n = a.size();\n    for (int i = 1; i\
    \ < n; i <<= 1)\n      for (int j = 0; j < n; j += i * 2)\n        for (int k\
    \ = 0; k < i; k++)\n          poly_add(a[i + j + k], a[j + k], pc[i + j + k]);\n\
    \  }\n  void ranked_mobius(vector<poly>& a) {\n    int n = a.size();\n    for\
    \ (int i = 1; i < n; i <<= 1)\n      for (int j = 0; j < n; j += i * 2)\n    \
    \    for (int k = 0; k < i; k++)\n          poly_sub(a[i + j + k], a[j + k], pc[i\
    \ + j + k]);\n  }\n  void ranked_mul(vector<poly>& a, const vector<poly>& b) {\n\
    \    for (int i = 0; i < a.size(); i++) poly_mul(a[i], b[i]);\n  }\n  vector<mint>\
    \ multiply(const vector<mint>& a, const vector<mint>& b) {\n    auto p = lift(a);\n\
    \    auto q = lift(b);\n    ranked_zeta(p);\n    ranked_zeta(q);\n    ranked_mul(p,\
    \ q);\n    ranked_mobius(p);\n    return unlift(p);\n  }\n};\n\n/**\n * @brief\
    \ Subset Convolution\n * @docs docs/set/subset-convolution.md\n */\n#line 3 \"\
    set/exp-of-set-power-series.hpp\"\n\nnamespace SetPowerSeries {\ntemplate <class\
    \ mint, int sz = 21>\nvector<mint> exp(const vector<mint>& a) {\n  static SubsetConvolution<mint,\
    \ sz> sc;\n  assert(a[0] == 0);\n  int l = __builtin_ctz(a.size());\n  assert(a.size()\
    \ == (1 << l));\n\n  vector<mint> f(1 << l, 0);\n  f[0] = 1;\n  for (int k = 0;\
    \ k < l; k++) {\n    vector<mint> g(f.begin(), f.begin() + (1 << k));\n    vector<mint>\
    \ h(a.begin() + (1 << k), a.begin() + (2 << k));\n    g = sc.multiply(g, h);\n\
    \    copy(g.begin(), g.end(), f.begin() + (1 << k));\n  }\n  return f;\n}\n};\
    \  // namespace SetPowerSeries\n/**\n * @brief Exp Of Set Power Series\n */\n\
    #line 3 \"set/composite-set-power-series.hpp\"\n\nnamespace SetPowerSeries {\n\
    template <class mint, int sz = 21>\nvector<mint> composite_egf(vector<mint> f,\
    \ vector<mint> a) {\n  static SubsetConvolution<mint, sz> sc;\n  assert(a[0] ==\
    \ 0);\n  if (f.empty()) return vector<mint>(a.size());\n  int l = __builtin_ctz(a.size());\n\
    \  f.resize(l + 1);\n  vector<vector<mint>> g(l + 1);\n  for (int i = 0; i <=\
    \ l; i++) g[i] = vector<mint>(1 << (l - i), 0);\n  for (int i = 0; i <= l; i++)\
    \ g[i][0] = f[i];\n  for (int k = 0; k < l; k++) {\n    auto p = sc.lift(vector<mint>(a.begin()\
    \ + (1 << k), a.begin() + (2 << k)));\n    sc.ranked_zeta(p);\n    for (int i\
    \ = 0; i < l - k; i++) {\n      auto q = sc.lift(vector<mint>(g[i + 1].begin(),\
    \ g[i + 1].begin() + (1 << k)));\n      sc.ranked_zeta(q);\n      sc.ranked_mul(q,\
    \ p);\n      sc.ranked_mobius(q);\n      auto h = sc.unlift(q);\n      copy(h.begin(),\
    \ h.end(), g[i].begin() + (1 << k));\n    }\n  }\n  return g[0];\n}\ntemplate\
    \ <class mint, int sz = 21>\nvector<mint> composite_polynomial(vector<mint> p,\
    \ vector<mint> a) {\n  if (p.empty()) return vector<mint>(a.size());\n  int l\
    \ = __builtin_ctz(a.size());\n  if (a[0] != 0) {\n    mint c = a[0];\n    a[0]\
    \ = 0;\n    vector<mint> p1(l + 1, 0), binom(l + 1, 0);\n    binom[0] = 1;\n \
    \   mint r0 = 1;\n    for (int i = 0; i < p.size(); i++) {\n      if (i > l) r0\
    \ *= c;\n      mint r = r0;\n      for (int j = min(i, l); j >= 0; j--, r *= c)\
    \ p1[j] += p[i] * binom[j] * r;\n      for (int j = l; j > 0; j--) binom[j] +=\
    \ binom[j - 1];\n    }\n    swap(p, p1);\n  }\n  mint r = 1;\n  for (int i = 1;\
    \ i <= l; i++) p[i] *= (r *= i);\n  return composite_egf<mint, sz>(p, a);\n}\n\
    \n// log(a), [x^0]a=1\n// require inverse of 1,...,sz\ntemplate <class mint, int\
    \ sz = 21>\nvector<mint> log(vector<mint> a) {\n  static SubsetConvolution<mint,\
    \ sz> sc;\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l ==\
    \ 0) return {0};\n  vector<mint> inv(l + 1, 1);\n  rep(i, 1, l + 1) inv[i] = mint(i).inv();\n\
    \  auto p = sc.lift(a);\n  sc.ranked_zeta(p);\n  for (int k = 0; k < p.size();\
    \ k++) {\n    auto q = p[k];\n    p[k][0] = 0;\n    for (int i = 1; i <= l; i++)\
    \ {\n      mint v = i * q[i];\n      for (int j = 1; j < i; j++) v -= j * p[k][j]\
    \ * q[i - j];\n      p[k][i] = v * inv[i];\n    }\n  }\n  sc.ranked_mobius(p);\n\
    \  return sc.unlift(p);\n}\n// log(a), [x^0]a=1\n// not require inverse of 1,...,sz\n\
    template <class mint, int sz = 21>\nvector<mint> log_arbitrary(vector<mint> a)\
    \ {\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l == 0) return\
    \ {0};\n  a[0] = 0;\n  vector<mint> f(l + 1, 0);\n  f[1] = 1;\n  for (int i =\
    \ 2; i <= l; i++) f[i] = f[i - 1] * (1 - i);\n  return composite_egf<mint, sz>(f,\
    \ a);\n}\n// a^m, [x^0]a=1\n// require inverse of 1,...,sz\ntemplate <class mint,\
    \ int sz = 21>\nvector<mint> pow(vector<mint> a, mint m) {\n  static SubsetConvolution<mint,\
    \ sz> sc;\n  assert(a[0] == 1);\n  int l = __builtin_ctz(a.size());\n  if (l ==\
    \ 0) return {1};\n  vector<mint> inv(l + 1, 1);\n  rep(i, 1, l + 1) inv[i] = mint(i).inv();\n\
    \  auto p = sc.lift(a);\n  sc.ranked_zeta(p);\n  for (int k = 0; k < p.size();\
    \ k++) {\n    auto q = p[k];\n    p[k][0] = 1;\n    for (int i = 1; i <= l; i++)\
    \ {\n      mint v = 0;\n      for (int j = 1; j < i; j++) v += (m * j - (i - j))\
    \ * p[k][i - j] * q[j];\n      v *= inv[i];\n      v += m * p[k][0] * q[i];\n\
    \      p[k][i] = v;\n    }\n  }\n  sc.ranked_mobius(p);\n  return sc.unlift(p);\n\
    }\n// a^m, [x^0]a=1\n// not require inverse of 1,...,sz\ntemplate <class mint,\
    \ int sz = 21>\nvector<mint> pow_arbitrary(vector<mint> a, mint m) {\n  assert(a[0]\
    \ == 1);\n  int l = __builtin_ctz(a.size());\n  if (l == 0) return {1};\n  a[0]\
    \ = 0;\n  vector<mint> f(l + 1, 0);\n  f[0] = 1;\n  for (int i = 1; i <= l; i++)\
    \ {\n    f[i] = f[i - 1] * m;\n    m -= 1;\n  }\n  return composite_egf<mint,\
    \ sz>(f, a);\n}\n};  // namespace SetPowerSeries\n/**\n * @brief Polynomial Composite\
    \ Set Power Series\n * @docs docs/set/composite-set-power-series.md\n */\n#line\
    \ 9 \"verify/set/UNIT_composite_set_power_series.test.cpp\"\n\nSubsetConvolution<mint,\
    \ 21> sc;\n\nvoid test_log(vector<mint> a) {\n  a[0] = 0;\n  {\n    auto b = SetPowerSeries::exp(a);\n\
    \    b = SetPowerSeries::log(b);\n    assert(a == b);\n  }\n  a[0] = 1;\n  {\n\
    \    auto b = SetPowerSeries::log(a);\n    b = SetPowerSeries::exp(b);\n    assert(a\
    \ == b);\n  }\n  {\n    auto b = SetPowerSeries::log(a);\n    auto c = SetPowerSeries::log_arbitrary(a);\n\
    \    assert(b == c);\n  }\n}\n\nvoid test_pow(vector<mint> a) {\n  a[0] = 1;\n\
    \  {\n    // sqrt\n    auto b = SetPowerSeries::pow(a, mint(2).inv());\n    b\
    \ = sc.multiply(b, b);\n    assert(a == b);\n  }\n  {\n    mint m = 12345;\n \
    \   auto b = SetPowerSeries::pow(a, m);\n    auto c = SetPowerSeries::pow_arbitrary(a,\
    \ m);\n    assert(b == c);\n\n    auto d = SetPowerSeries::log(a);\n    for (auto&\
    \ v : d) v *= m;\n    d = SetPowerSeries::exp(d);\n    assert(b == d);\n  }\n\
    }\n\nint main() {\n  rep(k, 0, 10) {\n    vector<mint> a(1 << k);\n    iota(ALL(a),\
    \ 0);\n    test_log(a);\n  }\n  rep(k, 0, 10) {\n    vector<mint> a(1 << k);\n\
    \    iota(ALL(a), 0);\n    test_pow(a);\n  }\n\n  int a, b;\n  in(a, b);\n  out(a\
    \ + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing mint = ModInt<998244353>;\n\
    #include \"set/subset-convolution.hpp\"\n#include \"set/exp-of-set-power-series.hpp\"\
    \n#include \"set/composite-set-power-series.hpp\"\n\nSubsetConvolution<mint, 21>\
    \ sc;\n\nvoid test_log(vector<mint> a) {\n  a[0] = 0;\n  {\n    auto b = SetPowerSeries::exp(a);\n\
    \    b = SetPowerSeries::log(b);\n    assert(a == b);\n  }\n  a[0] = 1;\n  {\n\
    \    auto b = SetPowerSeries::log(a);\n    b = SetPowerSeries::exp(b);\n    assert(a\
    \ == b);\n  }\n  {\n    auto b = SetPowerSeries::log(a);\n    auto c = SetPowerSeries::log_arbitrary(a);\n\
    \    assert(b == c);\n  }\n}\n\nvoid test_pow(vector<mint> a) {\n  a[0] = 1;\n\
    \  {\n    // sqrt\n    auto b = SetPowerSeries::pow(a, mint(2).inv());\n    b\
    \ = sc.multiply(b, b);\n    assert(a == b);\n  }\n  {\n    mint m = 12345;\n \
    \   auto b = SetPowerSeries::pow(a, m);\n    auto c = SetPowerSeries::pow_arbitrary(a,\
    \ m);\n    assert(b == c);\n\n    auto d = SetPowerSeries::log(a);\n    for (auto&\
    \ v : d) v *= m;\n    d = SetPowerSeries::exp(d);\n    assert(b == d);\n  }\n\
    }\n\nint main() {\n  rep(k, 0, 10) {\n    vector<mint> a(1 << k);\n    iota(ALL(a),\
    \ 0);\n    test_log(a);\n  }\n  rep(k, 0, 10) {\n    vector<mint> a(1 << k);\n\
    \    iota(ALL(a), 0);\n    test_pow(a);\n  }\n\n  int a, b;\n  in(a, b);\n  out(a\
    \ + b);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - math/util.hpp
  - set/subset-convolution.hpp
  - set/exp-of-set-power-series.hpp
  - set/composite-set-power-series.hpp
  isVerificationFile: true
  path: verify/set/UNIT_composite_set_power_series.test.cpp
  requiredBy: []
  timestamp: '2025-11-01 12:35:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/set/UNIT_composite_set_power_series.test.cpp
layout: document
redirect_from:
- /verify/verify/set/UNIT_composite_set_power_series.test.cpp
- /verify/verify/set/UNIT_composite_set_power_series.test.cpp.html
title: verify/set/UNIT_composite_set_power_series.test.cpp
---
