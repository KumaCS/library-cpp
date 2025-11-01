---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/barrett.hpp
    title: math/barrett.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"verify/modint/LC_binomial_coefficient_prime_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
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
    };  // namespace Math\n#line 2 \"math/barrett.hpp\"\n\nstruct barrett {\n  unsigned\
    \ int _m;\n  unsigned long long im;\n  explicit barrett(unsigned int m) : _m(m),\
    \ im((unsigned long long)(-1) / m + 1) {}\n  unsigned int umod() const { return\
    \ _m; }\n  unsigned int mul(unsigned int a, unsigned int b) const {\n    unsigned\
    \ long long z = a;\n    z *= b;\n#ifdef _MSC_VER\n    unsigned long long x;\n\
    \    _umul128(z, im, &x);\n#else\n    unsigned long long x = (unsigned long long)(((unsigned\
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
    \ operator>>(istream& is, mint& x) { return is >> x._v; }\n  friend ostream& operator<<(ostream&\
    \ os, const mint& x) { return os << x.val(); }\n\n private:\n  unsigned int _v;\n\
    \  static constexpr unsigned int umod() { return bar.umod(); }\n  static barrett\
    \ bar;\n};\ntemplate <int id>\nbarrett DynamicModInt<id>::bar(998244353);\n#line\
    \ 5 \"verify/modint/LC_binomial_coefficient_prime_mod.test.cpp\"\nusing mint =\
    \ DynamicModInt<0>;\n#line 2 \"modint/factorial.hpp\"\n\ntemplate <class mint>\n\
    struct Factorial {\n  static void reserve(int n) {\n    inv(n);\n    fact(n);\n\
    \    fact_inv(n);\n  }\n  static mint inv(int n) {\n    static long long mod =\
    \ mint::get_mod();\n    static vector<mint> buf({0, 1});\n    assert(n != 0);\n\
    \    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n      buf =\
    \ vector<mint>({0, 1});\n    }\n    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity()\
    \ * 2);\n    while ((int)buf.size() <= n) {\n      long long k = buf.size(), q\
    \ = (mod + k - 1) / k;\n      buf.push_back(q * buf[k * q - mod]);\n    }\n  \
    \  return buf[n];\n  }\n  static mint fact(int n) {\n    static long long mod\
    \ = mint::get_mod();\n    static vector<mint> buf({1, 1});\n    assert(n >= 0);\n\
    \    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n      buf =\
    \ vector<mint>({1, 1});\n    }\n    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity()\
    \ * 2);\n    while ((int)buf.size() <= n) {\n      long long k = buf.size();\n\
    \      buf.push_back(buf.back() * k);\n    }\n    return buf[n];\n  }\n  static\
    \ mint fact_inv(int n) {\n    static long long mod = mint::get_mod();\n    static\
    \ vector<mint> buf({1, 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      buf = vector<mint>({1, 1});\n    }\n\
    \    if ((int)buf.size() <= n) inv(n);\n    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity()\
    \ * 2);\n    while ((int)buf.size() <= n) {\n      long long k = buf.size();\n\
    \      buf.push_back(buf.back() * inv(k));\n    }\n    return buf[n];\n  }\n \
    \ static mint binom(int n, int r) {\n    if (r < 0 || r > n) return 0;\n    return\
    \ fact(n) * fact_inv(r) * fact_inv(n - r);\n  }\n  static mint binom_naive(int\
    \ n, int r) {\n    if (r < 0 || r > n) return 0;\n    mint res = fact_inv(r);\n\
    \    for (int i = 0; i < r; i++) res *= n - i;\n    return res;\n  }\n  static\
    \ mint multinom(const vector<int>& r) {\n    int n = 0;\n    for (auto& x : r)\
    \ {\n      if (x < 0) return 0;\n      n += x;\n    }\n    mint res = fact(n);\n\
    \    for (auto& x : r) res *= fact_inv(x);\n    return res;\n  }\n  static mint\
    \ P(int n, int r) {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(n\
    \ - r);\n  }\n  // partition n items to r groups (allow empty group)\n  static\
    \ mint H(int n, int r) {\n    if (n < 0 || r < 0) return 0;\n    return r == 0\
    \ ? 1 : binom(n + r - 1, r);\n  }\n};\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\
    \u4FC2\u6570\n */\n#line 7 \"verify/modint/LC_binomial_coefficient_prime_mod.test.cpp\"\
    \nusing fact = Factorial<mint>;\n\nint main() {\n  int t, m;\n  in(t, m);\n  mint::set_mod(m);\n\
    \  while (t--) {\n    int n, k;\n    in(n, k);\n    out(fact::binom(n, k));\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"template/template.hpp\"\n#include \"modint/dynamic-modint.hpp\"\
    \nusing mint = DynamicModInt<0>;\n#include \"modint/factorial.hpp\"\nusing fact\
    \ = Factorial<mint>;\n\nint main() {\n  int t, m;\n  in(t, m);\n  mint::set_mod(m);\n\
    \  while (t--) {\n    int n, k;\n    in(n, k);\n    out(fact::binom(n, k));\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/dynamic-modint.hpp
  - math/util.hpp
  - math/barrett.hpp
  - modint/factorial.hpp
  isVerificationFile: true
  path: verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2025-11-01 12:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
- /verify/verify/modint/LC_binomial_coefficient_prime_mod.test.cpp.html
title: verify/modint/LC_binomial_coefficient_prime_mod.test.cpp
---
