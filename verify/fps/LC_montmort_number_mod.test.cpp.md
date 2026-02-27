---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/famous-sequences.hpp
    title: "\u6709\u540D\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: fps/taylor-shift.hpp
    title: Taylor Shift
  - icon: ':heavy_check_mark:'
    path: math/barrett.hpp
    title: math/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: math/lpf-table.hpp
    title: LPF Table
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic-modint.hpp
    title: modint/dynamic-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  - icon: ':heavy_check_mark:'
    path: modint/power-table.hpp
    title: Power Table
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "#line 1 \"verify/fps/LC_montmort_number_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\n#line 2 \"template/template.hpp\"\
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
    S SUM(const vector<T>& a) {\n  return accumulate(ALL(a), S(0));\n}\ntemplate <class\
    \ T>\ninline bool chmin(T& a, T b) {\n  if (a > b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <class T>\ninline bool chmax(T& a, T b) {\n\
    \  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\ntemplate\
    \ <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n}\ntemplate\
    \ <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
    }\ntemplate <class T>\nint lowbit(T x) {\n  return (x == 0 ? -1 : __builtin_ctzll(x));\n\
    }\n#line 8 \"template/template.hpp\"\n\n#line 2 \"template/inout.hpp\"\nstruct\
    \ Fast {\n  Fast() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n  }\n} fast;\n\nostream& operator<<(ostream&\
    \ os, __uint128_t x) {\n  char buf[40];\n  size_t k = 0;\n  while (x > 0) buf[k++]\
    \ = (char)(x % 10 + '0'), x /= 10;\n  if (k == 0) buf[k++] = '0';\n  while (k)\
    \ os << buf[--k];\n  return os;\n}\nostream& operator<<(ostream& os, __int128_t\
    \ x) {\n  return x < 0 ? (os << '-' << (__uint128_t)(-x)) : (os << (__uint128_t)x);\n\
    }\ntemplate <class T1, class T2>\nistream& operator>>(istream& is, pair<T1, T2>&\
    \ p) {\n  return is >> p.first >> p.second;\n}\ntemplate <class T1, class T2>\n\
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) {\n  return os << p.first\
    \ << \" \" << p.second;\n}\ntemplate <class T>\nistream& operator>>(istream& is,\
    \ vector<T>& a) {\n  for (auto& v : a) is >> v;\n  return is;\n}\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& a) {\n  for (auto it =\
    \ a.begin(); it != a.end();) {\n    os << *it;\n    if (++it != a.end()) os <<\
    \ \" \";\n  }\n  return os;\n}\ntemplate <class T>\nostream& operator<<(ostream&\
    \ os, const set<T>& st) {\n  os << \"{\";\n  for (auto it = st.begin(); it !=\
    \ st.end();) {\n    os << *it;\n    if (++it != st.end()) os << \",\";\n  }\n\
    \  os << \"}\";\n  return os;\n}\ntemplate <class T1, class T2>\nostream& operator<<(ostream&\
    \ os, const map<T1, T2>& mp) {\n  os << \"{\";\n  for (auto it = mp.begin(); it\
    \ != mp.end();) {\n    os << it->first << \":\" << it->second;\n    if (++it !=\
    \ mp.end()) os << \",\";\n  }\n  os << \"}\";\n  return os;\n}\n\nvoid in() {}\n\
    template <typename T, class... U>\nvoid in(T& t, U&... u) {\n  cin >> t;\n  in(u...);\n\
    }\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep\
    \ = ' '>\nvoid out(const T& t, const U&... u) {\n  cout << t;\n  if (sizeof...(u))\
    \ cout << sep;\n  out(u...);\n}\n\nnamespace IO {\nnamespace Graph {\nvector<vector<int>>\
    \ unweighted(int n, int m, bool directed = false, int offset = 1) {\n  vector<vector<int>>\
    \ g(n);\n  for (int i = 0; i < m; i++) {\n    int u, v;\n    cin >> u >> v;\n\
    \    u -= offset, v -= offset;\n    g[u].push_back(v);\n    if (!directed) g[v].push_back(u);\n\
    \  }\n  return g;\n}\ntemplate <class T>\nvector<vector<pair<int, T>>> weighted(int\
    \ n, int m, bool directed = false, int offset = 1) {\n  vector<vector<pair<int,\
    \ T>>> g(n);\n  for (int i = 0; i < m; i++) {\n    int u, v;\n    T w;\n    cin\
    \ >> u >> v >> w;\n    u -= offset, v -= offset;\n    g[u].push_back({v, w});\n\
    \    if (!directed) g[v].push_back({u, w});\n  }\n  return g;\n}\n}  // namespace\
    \ Graph\nnamespace Tree {\nvector<vector<int>> unweighted(int n, bool directed\
    \ = false, int offset = 1) {\n  return Graph::unweighted(n, n - 1, directed, offset);\n\
    }\ntemplate <class T>\nvector<vector<pair<int, T>>> weighted(int n, bool directed\
    \ = false, int offset = 1) {\n  return Graph::weighted<T>(n, n - 1, directed,\
    \ offset);\n}\nvector<vector<int>> rooted(int n, bool to_root = true, bool to_leaf\
    \ = true, int offset = 1) {\n  vector<vector<int>> g(n);\n  for (int i = 1; i\
    \ < n; i++) {\n    int p;\n    cin >> p;\n    p -= offset;\n    if (to_root) g[i].push_back(p);\n\
    \    if (to_leaf) g[p].push_back(i);\n  }\n  return g;\n}\n}  // namespace Tree\n\
    }  // namespace IO\n#line 10 \"template/template.hpp\"\n\n#line 2 \"template/debug.hpp\"\
    \n#ifdef LOCAL\n#define debug 1\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\n\
    #else\n#define debug 0\n#define show(...) true\n#endif\ntemplate <class T>\nvoid\
    \ _show(int i, T name) {\n  cerr << '\\n';\n}\ntemplate <class T1, class T2, class...\
    \ T3>\nvoid _show(int i, const T1& a, const T2& b, const T3&... c) {\n  for (;\
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
    \  }\n  return a;\n}\nconstexpr long long inv_mod(long long x, long long m) {\n\
    \  x %= m;\n  if (x < 0) x += m;\n  long long a = m, b = x;\n  long long y0 =\
    \ 0, y1 = 1;\n  while (b > 0) {\n    long long q = a / b;\n    swap(a -= q * b,\
    \ b);\n    swap(y0 -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return\
    \ y0;\n}\nlong long pow_mod(long long x, long long n, long long m) {\n  x = (x\
    \ % m + m) % m;\n  long long y = 1;\n  while (n) {\n    if (n & 1) y = y * x %\
    \ m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr long long\
    \ pow_mod_constexpr(long long x, long long n, int m) {\n  if (m == 1) return 0;\n\
    \  unsigned int _m = (unsigned int)(m);\n  unsigned long long r = 1;\n  unsigned\
    \ long long y = x % m;\n  if (y >= m) y += m;\n  while (n) {\n    if (n & 1) r\
    \ = (r * y) % _m;\n    y = (y * y) % _m;\n    n >>= 1;\n  }\n  return r;\n}\n\
    constexpr bool is_prime_constexpr(int n) {\n  if (n <= 1) return false;\n  if\
    \ (n == 2 || n == 7 || n == 61) return true;\n  if (n % 2 == 0) return false;\n\
    \  long long d = n - 1;\n  while (d % 2 == 0) d /= 2;\n  constexpr long long bases[3]\
    \ = {2, 7, 61};\n  for (long long a : bases) {\n    long long t = d;\n    long\
    \ long y = pow_mod_constexpr(a, t, n);\n    while (t != n - 1 && y != 1 && y !=\
    \ n - 1) {\n      y = y * y % n;\n      t <<= 1;\n    }\n    if (y != n - 1 &&\
    \ t % 2 == 0) {\n      return false;\n    }\n  }\n  return true;\n}\ntemplate\
    \ <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n};  // namespace\
    \ Math\n#line 2 \"math/barrett.hpp\"\n\nstruct barrett {\n  unsigned int _m;\n\
    \  unsigned long long im;\n  explicit barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n  unsigned int umod() const { return _m; }\n  unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n    unsigned long long z =\
    \ a;\n    z *= b;\n#ifdef _MSC_VER\n    unsigned long long x;\n    _umul128(z,\
    \ im, &x);\n#else\n    unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n#endif\n    unsigned long long y = x * _m;\n    return\
    \ (unsigned int)(z - y + (z < y ? _m : 0));\n  }\n};\n#line 4 \"modint/dynamic-modint.hpp\"\
    \n\ntemplate <int id>\nstruct DynamicModInt {\n  using mint = DynamicModInt;\n\
    \  static void set_mod(int m) {\n    assert(1 <= m);\n    bar = barrett(m);\n\
    \  }\n  static constexpr unsigned int get_mod() { return (int)bar.umod(); }\n\
    \  static mint raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n\
    \  DynamicModInt() : _v(0) {}\n  DynamicModInt(int64_t v) {\n    long long x =\
    \ (long long)(v % (long long)(bar.umod()));\n    if (x < 0) x += umod();\n   \
    \ _v = (unsigned int)(x);\n  }\n  unsigned int val() const { return _v; }\n  mint&\
    \ operator++() {\n    _v++;\n    if (_v == umod()) _v = 0;\n    return *this;\n\
    \  }\n  mint& operator--() {\n    if (_v == 0) _v = umod();\n    _v--;\n    return\
    \ *this;\n  }\n  mint operator++(int) {\n    mint result = *this;\n    ++*this;\n\
    \    return result;\n  }\n  mint operator--(int) {\n    mint result = *this;\n\
    \    --*this;\n    return result;\n  }\n  mint& operator+=(const mint& rhs) {\n\
    \    _v += rhs._v;\n    if (_v >= umod()) _v -= umod();\n    return *this;\n \
    \ }\n  mint& operator-=(const mint& rhs) {\n    _v -= rhs._v;\n    if (_v >= umod())\
    \ _v += umod();\n    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n\
    \    _v = bar.mul(_v, rhs._v);\n    return *this;\n  }\n  mint& operator/=(const\
    \ mint& rhs) { return *this = *this * rhs.inv(); }\n  mint operator+() const {\
    \ return *this; }\n  mint operator-() const { return mint() - *this; }\n  mint\
    \ pow(long long n) const {\n    assert(0 <= n);\n    mint x = *this, r = 1;\n\
    \    while (n) {\n      if (n & 1) r *= x;\n      x *= x;\n      n >>= 1;\n  \
    \  }\n    return r;\n  }\n  mint inv() const {\n    auto inv = Math::inv_mod(_v,\
    \ umod());\n    return raw(inv);\n  }\n  friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n  friend istream&\
    \ operator>>(istream& is, mint& x) {\n    int64_t v;\n    is >> v;\n    x = mint(v);\n\
    \    return is;\n  }\n  friend ostream& operator<<(ostream& os, const mint& x)\
    \ { return os << x.val(); }\n\n private:\n  unsigned int _v;\n  static constexpr\
    \ unsigned int umod() { return bar.umod(); }\n  static barrett bar;\n};\ntemplate\
    \ <int id>\nbarrett DynamicModInt<id>::bar(998244353);\n#line 5 \"verify/fps/LC_montmort_number_mod.test.cpp\"\
    \nusing mint = DynamicModInt<0>;\n#line 2 \"modint/factorial.hpp\"\n\ntemplate\
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
    \ * f[lpf[i]];\n  }\n  return f;\n}\n/**\n * @brief Power Table\n */\n#line 2\
    \ \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \  FormalPowerSeries(const vector<mint>& r) : vector<mint>(r) {}\n  FormalPowerSeries(vector<mint>&&\
    \ r) : vector<mint>(std::move(r)) {}\n  FPS& operator=(const vector<mint>& r)\
    \ {\n    vector<mint>::operator=(r);\n    return *this;\n  }\n  FPS& operator+=(const\
    \ FPS& r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n  FPS& operator+=(const mint& r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n  FPS& operator-=(const FPS& r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n \
    \ FPS& operator-=(const mint& r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n  FPS& operator*=(const mint& v)\
    \ {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return\
    \ *this;\n  }\n  FPS& operator/=(const FPS& r) {\n    if (this->size() < r.size())\
    \ {\n      this->clear();\n      return *this;\n    }\n    int n = this->size()\
    \ - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n\
    \      g.shrink();\n      mint coeff = g.at(g.size() - 1).inv();\n      for (auto&\
    \ x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n   \
    \   int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i >=\
    \ 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n  FPS& operator%=(const FPS& r) {\n  \
    \  *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n  FPS operator+(const\
    \ FPS& r) const { return FPS(*this) += r; }\n  FPS operator+(const mint& v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS& r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint& v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS& r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint& v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS& r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS& r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n  void shrink() {\n    while (this->size() && this->back() == mint(0)) this->pop_back();\n\
    \  }\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n\
    \    return ret;\n  }\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n  FPS operator>>=(int sz)\
    \ {\n    assert(sz >= 0);\n    if ((int)this->size() <= sz)\n      this->clear();\n\
    \    else\n      this->erase(this->begin(), this->begin() + sz);\n    return *this;\n\
    \  }\n  FPS operator>>(int sz) const {\n    if ((int)this->size() <= sz) return\
    \ {};\n    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n  \
    \  return ret;\n  }\n  FPS operator<<=(int sz) {\n    assert(sz >= 0);\n    this->insert(this->begin(),\
    \ sz, mint(0));\n    return *this;\n  }\n  FPS operator<<(int sz) const {\n  \
    \  FPS ret(*this);\n    ret.insert(ret.begin(), sz, mint(0));\n    return ret;\n\
    \  }\n  FPS diff() const {\n    const int n = (int)this->size();\n    FPS ret(max(0,\
    \ n - 1));\n    mint one(1), coeff(1);\n    for (int i = 1; i < n; i++) {\n  \
    \    ret[i - 1] = (*this)[i] * coeff;\n      coeff += one;\n    }\n    return\
    \ ret;\n  }\n  FPS integral() const {\n    const int n = (int)this->size();\n\
    \    FPS ret(n + 1);\n    ret[0] = mint(0);\n    if (n > 0) ret[1] = mint(1);\n\
    \    auto mod = mint::get_mod();\n    for (int i = 2; i <= n; i++) ret[i] = (-ret[mod\
    \ % i]) * (mod / i);\n    for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n\
    \    return ret;\n  }\n  mint eval(mint x) const {\n    mint r = 0, w = 1;\n \
    \   for (auto& v : *this) r += w * v, w *= x;\n    return r;\n  }\n  FPS log(int\
    \ deg = -1) const {\n    assert((*this)[0] == mint(1));\n    if (deg == -1) deg\
    \ = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \  }\n  FPS pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n\
    \        FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret\
    \ *= (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if\
    \ ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return ret;\n   \
    \   }\n      if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \ }\n    return FPS(deg, mint(0));\n  }\n\n  static void* ntt_ptr;\n  static void\
    \ set_ntt();\n  FPS& operator*=(const FPS& r);\n  FPS middle_product(const FPS&\
    \ r) const;\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_root();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid* FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    #line 4 \"fps/taylor-shift.hpp\"\n\n// f(x+a)\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ TaylorShift(FormalPowerSeries<mint> f, mint a) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = f.size();\n  using fact = Factorial<mint>;\n  fact::reserve(n);\n \
    \ for (int i = 0; i < n; i++) f[i] *= fact::fact(i);\n  reverse(f.begin(), f.end());\n\
    \  fps g(n, mint(1));\n  for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * fact::inv(i);\n\
    \  f = (f * g).pre(n);\n  reverse(f.begin(), f.end());\n  for (int i = 0; i <\
    \ n; i++) f[i] *= fact::fact_inv(i);\n  return f;\n}\n/**\n * @brief Taylor Shift\n\
    \ * @docs docs/fps/taylor-shift.md\n */\n#line 6 \"fps/famous-sequences.hpp\"\n\
    \ntemplate <class mint>\nFormalPowerSeries<mint> PartitionFunction(int n) {\n\
    \  FormalPowerSeries<mint> g(n + 1);\n  for (int k = 0; k * (3 * k - 1) / 2 <=\
    \ n; k++) g[k * (3 * k - 1) / 2] += k & 1 ? -1 : 1;\n  for (int k = 1; k * (3\
    \ * k + 1) / 2 <= n; k++) g[k * (3 * k + 1) / 2] += k & 1 ? -1 : 1;\n  return\
    \ g.inv(n + 1);\n}\ntemplate <class mint>\nFormalPowerSeries<mint> BellNumber(int\
    \ n) {\n  using fact = Factorial<mint>;\n  FormalPowerSeries<mint> f(n + 1);\n\
    \  for (int i = 1; i < f.size(); i++) f[i] = fact::fact_inv(i);\n  f = f.exp();\n\
    \  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i);\n  return f;\n}\n\
    template <class mint>\nvector<mint> MontmortNumber(int n) {\n  vector<mint> f(n\
    \ + 1);\n  f[0] = 1, f[1] = 0;\n  for (int i = 2; i < f.size(); i++) f[i] = (i\
    \ - 1) * (f[i - 1] + f[i - 2]);\n  return f;\n}\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ FirstKindStirlingNumbers(int n) {\n  FormalPowerSeries<mint> f{1};\n  for (int\
    \ l = 30; l >= 0; l--) {\n    if (f.size() > 1) f *= TaylorShift(f, mint(-(n >>\
    \ (l + 1))));\n    if ((n >> l) & 1) f = (f << 1) - f * mint((n >> l) - 1);\n\
    \  }\n  return f;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> FirstKindStirlingNumbersFixedK(int\
    \ n, int k) {\n  using fact = Factorial<mint>;\n  if (k > n) return FormalPowerSeries<mint>{};\n\
    \  FormalPowerSeries<mint> f(n - k + 1);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] = fact::inv(i + 1) * (i & 1 ? -1 : 1);\n  f = f.pow(k);\n  f *= fact::fact_inv(k);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);\n  return f;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint> SecondKindStirlingNumbers(int\
    \ n) {\n  using fact = Factorial<mint>;\n  FormalPowerSeries<mint> f(n + 1);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] = fact::fact_inv(i) * (i & 1 ? -1 :\
    \ 1);\n  FormalPowerSeries<mint> g(PowerTable<mint>(n, n));\n  for (int i = 0;\
    \ i < g.size(); i++) g[i] *= fact::fact_inv(i);\n  f *= g;\n  f.resize(n + 1);\n\
    \  return f;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> SecondKindStirlingNumbersFixedK(int\
    \ n, int k) {\n  using fact = Factorial<mint>;\n  if (k > n) return FormalPowerSeries<mint>{};\n\
    \  FormalPowerSeries<mint> f(n - k + 1);\n  for (int i = 0; i < f.size(); i++)\
    \ f[i] = fact::fact_inv(i + 1);\n  f = f.pow(k);\n  f *= fact::fact_inv(k);\n\
    \  for (int i = 0; i < f.size(); i++) f[i] *= fact::fact(i + k);\n  return f;\n\
    }\n\n/**\n * @brief \u6709\u540D\u6570\u5217\n * @docs docs/fps/famous-sequences.md\n\
    \ */\n#line 7 \"verify/fps/LC_montmort_number_mod.test.cpp\"\n\nint main() {\n\
    \  int n, m;\n  in(n, m);\n  mint::set_mod(m);\n  auto a = MontmortNumber<mint>(n);\n\
    \  a.erase(a.begin());\n  out(a);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\
    \n#include \"template/template.hpp\"\n#include \"modint/dynamic-modint.hpp\"\n\
    using mint = DynamicModInt<0>;\n#include \"fps/famous-sequences.hpp\"\n\nint main()\
    \ {\n  int n, m;\n  in(n, m);\n  mint::set_mod(m);\n  auto a = MontmortNumber<mint>(n);\n\
    \  a.erase(a.begin());\n  out(a);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/dynamic-modint.hpp
  - math/util.hpp
  - math/barrett.hpp
  - fps/famous-sequences.hpp
  - modint/factorial.hpp
  - modint/power-table.hpp
  - math/lpf-table.hpp
  - fps/formal-power-series.hpp
  - fps/taylor-shift.hpp
  isVerificationFile: true
  path: verify/fps/LC_montmort_number_mod.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fps/LC_montmort_number_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/fps/LC_montmort_number_mod.test.cpp
- /verify/verify/fps/LC_montmort_number_mod.test.cpp.html
title: verify/fps/LC_montmort_number_mod.test.cpp
---
