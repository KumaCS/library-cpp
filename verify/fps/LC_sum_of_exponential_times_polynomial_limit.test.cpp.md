---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: fps/interpolate.hpp
    title: Interpolate
  - icon: ':x:'
    path: fps/sum-of-exp-poly.hpp
    title: $\sum_{i}r^i poly(i)$
  - icon: ':x:'
    path: math/lpf-table.hpp
    title: LPF Table
  - icon: ':question:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':question:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':x:'
    path: modint/power-table.hpp
    title: Power Table
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"template/macro.hpp\"\n#define rep(i, a, b) for (int i = (a);\
    \ i < (int)(b); i++)\n#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (a);\
    \ i--)\n#define ALL(v) (v).begin(), (v).end()\n#define UNIQUE(v) sort(ALL(v)),\
    \ (v).erase(unique(ALL(v)), (v).end())\n#define SZ(v) (int)v.size()\n#define MIN(v)\
    \ *min_element(ALL(v))\n#define MAX(v) *max_element(ALL(v))\n#define LB(v, x)\
    \ int(lower_bound(ALL(v), (x)) - (v).begin())\n#define UB(v, x) int(upper_bound(ALL(v),\
    \ (x)) - (v).begin())\n#define YN(b) cout << ((b) ? \"YES\" : \"NO\") << \"\\\
    n\";\n#define Yn(b) cout << ((b) ? \"Yes\" : \"No\") << \"\\n\";\n#define yn(b)\
    \ cout << ((b) ? \"yes\" : \"no\") << \"\\n\";\n#line 6 \"template/template.hpp\"\
    \n\n#line 2 \"template/util.hpp\"\nusing uint = unsigned int;\nusing ll = long\
    \ long int;\nusing ull = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <class T, class S = T>\nS SUM(const vector<T>\
    \ &a) {\n  return accumulate(ALL(a), S(0));\n}\ntemplate <class T>\ninline bool\
    \ chmin(T &a, T b) {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return\
    \ false;\n}\ntemplate <class T>\ninline bool chmax(T &a, T b) {\n  if (a < b)\
    \ {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\ntemplate <class\
    \ T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n}\ntemplate <class\
    \ T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n}\n\
    template <class T>\nint lowbit(T x) {\n  return (x == 0 ? -1 : __builtin_ctzll(x));\n\
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
    \  }\n  return a;\n}\ntemplate <class T>\nT inv_mod(T x, T m) {\n  x %= m;\n \
    \ if (x < 0) x += m;\n  T a = m, b = x;\n  T y0 = 0, y1 = 1;\n  while (b > 0)\
    \ {\n    T q = a / b;\n    swap(a -= q * b, b);\n    swap(y0 -= q * y1, y1);\n\
    \  }\n  if (y0 < 0) y0 += m / a;\n  return y0;\n}\ntemplate <class T>\nT pow_mod(T\
    \ x, T n, T m) {\n  x = (x % m + m) % m;\n  T y = 1;\n  while (n) {\n    if (n\
    \ & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n}\n\
    constexpr long long pow_mod_constexpr(long long x, long long n, int m) {\n  if\
    \ (m == 1) return 0;\n  unsigned int _m = (unsigned int)(m);\n  unsigned long\
    \ long r = 1;\n  unsigned long long y = x % m;\n  if (y >= m) y += m;\n  while\
    \ (n) {\n    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n    n >>= 1;\n\
    \  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n  if (n <= 1)\
    \ return false;\n  if (n == 2 || n == 7 || n == 61) return true;\n  if (n % 2\
    \ == 0) return false;\n  long long d = n - 1;\n  while (d % 2 == 0) d /= 2;\n\
    \  constexpr long long bases[3] = {2, 7, 61};\n  for (long long a : bases) {\n\
    \    long long t = d;\n    long long y = pow_mod_constexpr(a, t, n);\n    while\
    \ (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n      t <<= 1;\n\
    \    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n    }\n  }\n\
    \  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
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
    \ is_prime = Math::is_prime<m>;\n};\n#line 5 \"verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \nusing mint = ModInt<998244353>;\n#line 2 \"modint/factorial.hpp\"\n\ntemplate\
    \ <class mint>\nstruct Factorial {\n  static void reserve(int n) {\n    inv(n);\n\
    \    fact(n);\n    fact_inv(n);\n  }\n  static mint inv(int n) {\n    static long\
    \ long mod = mint::get_mod();\n    static vector<mint> buf({0, 1});\n    assert(n\
    \ != 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n  \
    \    buf = vector<mint>({0, 1});\n    }\n    while ((int)buf.capacity() <= n)\
    \ buf.reserve(buf.capacity() * 2);\n    while ((int)buf.size() <= n) {\n     \
    \ long long k = buf.size(), q = (mod + k - 1) / k;\n      buf.push_back(q * buf[k\
    \ * q - mod]);\n    }\n    return buf[n];\n  }\n  static mint fact(int n) {\n\
    \    static long long mod = mint::get_mod();\n    static vector<mint> buf({1,\
    \ 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      buf = vector<mint>({1, 1});\n    }\n    while ((int)buf.capacity() <= n)\
    \ buf.reserve(buf.capacity() * 2);\n    while ((int)buf.size() <= n) {\n     \
    \ long long k = buf.size();\n      buf.push_back(buf.back() * k);\n    }\n   \
    \ return buf[n];\n  }\n  static mint fact_inv(int n) {\n    static long long mod\
    \ = mint::get_mod();\n    static vector<mint> buf({1, 1});\n    assert(n >= 0);\n\
    \    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n      buf =\
    \ vector<mint>({1, 1});\n    }\n    if ((int)buf.size() <= n) inv(n);\n    while\
    \ ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while ((int)buf.size()\
    \ <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back() * inv(k));\n\
    \    }\n    return buf[n];\n  }\n  static mint binom(int n, int r) {\n    if (r\
    \ < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r) * fact_inv(n - r);\n\
    \  }\n  static mint binom_naive(int n, int r) {\n    if (r < 0 || r > n) return\
    \ 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i < r; i++) res *= n -\
    \ i;\n    return res;\n  }\n  static mint multinom(const vector<int>& r) {\n \
    \   int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return 0;\n      n +=\
    \ x;\n    }\n    mint res = fact(n);\n    for (auto& x : r) res *= fact_inv(x);\n\
    \    return res;\n  }\n  static mint P(int n, int r) {\n    if (r < 0 || r > n)\
    \ return 0;\n    return fact(n) * fact_inv(n - r);\n  }\n  // partition n items\
    \ to r groups (allow empty group)\n  static mint H(int n, int r) {\n    if (n\
    \ < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n + r - 1, r);\n  }\n\
    };\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\n */\n#line 2 \"math/lpf-table.hpp\"\
    \n\nvector<int> LPFTable(int n) {\n  vector<int> lpf(n + 1, 0);\n  iota(lpf.begin(),\
    \ lpf.end(), 0);\n  for (int p = 2; p * p <= n; p += (p & 1) + 1) {\n    if (lpf[p]\
    \ != p) continue;\n    for (int i = p * p; i <= n; i += p)\n      if (lpf[i] ==\
    \ i) lpf[i] = p;\n  }\n  return lpf;\n}\n/**\n * @brief LPF Table\n */\n#line\
    \ 3 \"modint/power-table.hpp\"\n\n// 0^k,1^k,2^k,...,n^k\ntemplate <class T>\n\
    vector<T> PowerTable(int n, int k) {\n  assert(k >= 0);\n  vector<T> f;\n  if\
    \ (k == 0) {\n    f = vector<T>(n + 1, 0);\n    f[0] = 1;\n  } else {\n    f =\
    \ vector<T>(n + 1, 1);\n    f[0] = 0;\n    auto lpf = LPFTable(n);\n    for (int\
    \ i = 2; i <= n; i++)\n      f[i] = lpf[i] == i ? T(i).pow(k) : f[i / lpf[i]]\
    \ * f[lpf[i]];\n  }\n  return f;\n}\n/**\n * @brief Power Table\n */\n#line 3\
    \ \"fps/interpolate.hpp\"\n\n// f(0),f(1),...,f(n-1) -> f(x)\ntemplate <class\
    \ mint>\nmint Interpolate(const vector<mint>& f, mint x) {\n  int n = f.size();\n\
    \  vector<mint> l(n, 1), r(n, 1);\n  for (int i = 0; i + 1 < n; i++) l[i + 1]\
    \ = l[i] * (x - i);\n  for (int i = n - 1; i > 0; i--) r[i - 1] = r[i] * (x -\
    \ i);\n  using fact = Factorial<mint>;\n  mint s = 0;\n  for (int i = 0; i < n;\
    \ i++) {\n    mint v = f[i] * l[i] * r[i] * fact::fact_inv(i) * fact::fact_inv(n\
    \ - 1 - i);\n    if ((n - i) & 1)\n      s += v;\n    else\n      s -= v;\n  }\n\
    \  return s;\n}\n/**\n * @brief Interpolate\n * @docs docs/fps/interpolate.md\n\
    \ */\n#line 4 \"fps/sum-of-exp-poly.hpp\"\n\n// sum_{i=0}^{infty}r^i*poly(i)\n\
    // f[i]=poly(i)\ntemplate <class mint>\nmint SumOfExpPolyLimit(mint r, vector<mint>&\
    \ f) {\n  if (r == 0) return f[0];\n  assert(r != 1);\n  int k = f.size();\n \
    \ vector<mint> g(k + 1, 0);\n  mint prod = 1;\n  for (int i = 0; i < k; i++) {\n\
    \    g[i + 1] = g[i] + f[i] * prod;\n    prod *= r;\n  }\n  using fact = Factorial<mint>;\n\
    \  mint c = 0;\n  prod = 1;\n  for (int i = 0; i <= k; i++) {\n    c += fact::binom(k,\
    \ i) * prod * g[k - i];\n    prod *= -r;\n  }\n  c /= (1 - r).pow(k);\n  return\
    \ c;\n}\n// sum_{i=0}^{n-1}r^i*poly(i)\n// f[i]=poly(i)\ntemplate <class mint>\n\
    mint SumOfExpPoly(long long n, mint r, vector<mint>& f) {\n  if (n <= 0) return\
    \ 0;\n  if (r == 0) return f[0];\n  int k = f.size();\n  vector<mint> g(k + 1,\
    \ 0);\n  mint prod = 1;\n  for (int i = 0; i < k; i++) {\n    g[i + 1] = g[i]\
    \ + f[i] * prod;\n    prod *= r;\n  }\n  if (r == 1) return Interpolate(g, mint(n));\n\
    \  mint c = 0;\n  prod = 1;\n  using fact = Factorial<mint>;\n  for (int i = 0;\
    \ i <= k; i++) {\n    c += fact::binom(k, i) * prod * g[k - i];\n    prod *= -r;\n\
    \  }\n  c /= (1 - r).pow(k);\n  for (int i = 0; i <= k; i++) g[i] -= c;\n  mint\
    \ ir = r.inv();\n  prod = 1;\n  for (int i = 1; i <= k; i++) g[i] *= (prod *=\
    \ ir);\n  return Interpolate(g, mint(n)) * r.pow(n) + c;\n}\n/**\n * @brief $\\\
    sum_{i}r^i poly(i)$\n * @docs docs/fps/sum-of-exp-poly.md\n */\n#line 9 \"verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp\"\
    \n\nint main() {\n  mint r;\n  int d;\n  in(r, d);\n  auto f = PowerTable<mint>(d,\
    \ d);\n  out(SumOfExpPolyLimit(r, f));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing\
    \ mint = ModInt<998244353>;\n#include \"modint/factorial.hpp\"\n#include \"modint/power-table.hpp\"\
    \n#include \"fps/sum-of-exp-poly.hpp\"\n\nint main() {\n  mint r;\n  int d;\n\
    \  in(r, d);\n  auto f = PowerTable<mint>(d, d);\n  out(SumOfExpPolyLimit(r, f));\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - math/util.hpp
  - modint/factorial.hpp
  - modint/power-table.hpp
  - math/lpf-table.hpp
  - fps/sum-of-exp-poly.hpp
  - fps/interpolate.hpp
  isVerificationFile: true
  path: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  requiredBy: []
  timestamp: '2025-11-01 00:19:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
layout: document
redirect_from:
- /verify/verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
- /verify/verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp.html
title: verify/fps/LC_sum_of_exponential_times_polynomial_limit.test.cpp
---
