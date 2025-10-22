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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
  bundledCode: "#line 1 \"verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"modint/modint.hpp\"\n\ntemplate\
    \ <unsigned int m = 998244353>\nstruct ModInt {\n  using mint = ModInt;\n  unsigned\
    \ int _v;\n  static constexpr unsigned int get_mod() { return m; }\n  static mint\
    \ raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n  ModInt() : _v(0)\
    \ {}\n  ModInt(int64_t v) {\n    long long x = (long long)(v % (long long)(umod()));\n\
    \    if (x < 0) x += umod();\n    _v = (unsigned int)(x);\n  }\n  unsigned int\
    \ val() const { return _v; }\n  mint &operator++() {\n    _v++;\n    if (_v ==\
    \ umod()) _v = 0;\n    return *this;\n  }\n  mint &operator--() {\n    if (_v\
    \ == 0) _v = umod();\n    _v--;\n    return *this;\n  }\n  mint operator++(int)\
    \ {\n    mint result = *this;\n    ++*this;\n    return result;\n  }\n  mint operator--(int)\
    \ {\n    mint result = *this;\n    --*this;\n    return result;\n  }\n\n  mint\
    \ &operator+=(const mint &rhs) {\n    _v += rhs._v;\n    if (_v >= umod()) _v\
    \ -= umod();\n    return *this;\n  }\n  mint &operator-=(const mint &rhs) {\n\
    \    _v -= rhs._v;\n    if (_v >= umod()) _v += umod();\n    return *this;\n \
    \ }\n  mint &operator*=(const mint &rhs) {\n    unsigned long long z = _v;\n \
    \   z *= rhs._v;\n    _v = (unsigned int)(z % umod());\n    return *this;\n  }\n\
    \  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }\n\n\
    \  mint operator+() const { return *this; }\n  mint operator-() const { return\
    \ mint() - *this; }\n\n  mint pow(long long n) const {\n    assert(0 <= n);\n\
    \    mint x = *this, r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n     \
    \ x *= x;\n      n >>= 1;\n    }\n    return r;\n  }\n  mint inv() const {\n \
    \   assert(_v);\n    return pow(umod() - 2);\n  }\n\n  friend mint operator+(const\
    \ mint &lhs, const mint &rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint\
    \ operator-(const mint &lhs, const mint &rhs) {\n    return mint(lhs) -= rhs;\n\
    \  }\n  friend mint operator*(const mint &lhs, const mint &rhs) {\n    return\
    \ mint(lhs) *= rhs;\n  }\n  friend mint operator/(const mint &lhs, const mint\
    \ &rhs) {\n    return mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint\
    \ &lhs, const mint &rhs) {\n    return lhs._v == rhs._v;\n  }\n  friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) {\n    return lhs._v != rhs._v;\n  }\n  friend istream\
    \ &operator>>(istream &is, mint &x) {\n    return is >> x._v;\n  }\n  friend ostream\
    \ &operator<<(ostream &os, const mint &x) {\n    return os << x.val();\n  }\n\n\
    \ private:\n  static constexpr unsigned int umod() { return m; }\n};\n#line 5\
    \ \"verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp\"\nusing mint =\
    \ ModInt<998244353>;\n#line 2 \"modint/factorial.hpp\"\n\ntemplate <class mint>\n\
    struct Factorial {\n  static void reserve(int n) {\n    inv(n);\n    fact(n);\n\
    \    fact_inv(n);\n  }\n  static mint inv(int n) {\n    static long long mod =\
    \ mint::get_mod();\n    static vector<mint> _inv({0, 1});\n    assert(n != 0);\n\
    \    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n      _inv =\
    \ vector<mint>({0, 1});\n    }\n    if (_inv.size() <= n) _inv.reserve(n + 1);\n\
    \    while (_inv.size() <= n) {\n      long long k = _inv.size(), q = (mod + k\
    \ - 1) / k;\n      _inv.push_back(q * _inv[k * q - mod]);\n    }\n    return _inv[n];\n\
    \  }\n  static mint fact(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> _fact({1, 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      _fact = vector<mint>({1, 1});\n    }\n\
    \    if (_fact.size() <= n) _fact.reserve(n + 1);\n    while (_fact.size() <=\
    \ n) {\n      long long k = _fact.size();\n      _fact.push_back(_fact.back()\
    \ * k);\n    }\n    return _fact[n];\n  }\n  static mint fact_inv(int n) {\n \
    \   static long long mod = mint::get_mod();\n    static vector<mint> _fact_inv({1,\
    \ 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      _fact_inv = vector<mint>({1, 1});\n    }\n    if (_fact_inv.size() <= n)\
    \ _fact_inv.reserve(n + 1);\n    while (_fact_inv.size() <= n) {\n      long long\
    \ k = _fact_inv.size();\n      _fact_inv.push_back(_fact_inv.back() * inv(k));\n\
    \    }\n    return _fact_inv[n];\n  }\n  static mint binom(int n, int r) {\n \
    \   if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r) * fact_inv(n\
    \ - r);\n  }\n  static mint binom_naive(int n, int r) {\n    if (r < 0 || r >\
    \ n) return 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i < r; i++) res\
    \ *= n - i;\n    return res;\n  }\n  static mint multinom(const vector<int>& r)\
    \ {\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return 0;\n   \
    \   n += x;\n    }\n    mint res = fact(n);\n    for (auto& x : r) res *= fact_inv(x);\n\
    \    return res;\n  }\n  static mint P(int n, int r) {\n    if (r < 0 || r > n)\
    \ return 0;\n    return fact(n) * fact_inv(n - r);\n  }\n  // partition n items\
    \ to r groups (allow empty group)\n  static mint H(int n, int r) {\n    if (n\
    \ < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n + r - 1, r);\n  }\n\
    };  // namespace Factorial\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\
    \n */\n#line 2 \"math/lpf-table.hpp\"\n\nvector<int> LPFTable(int n) {\n  vector<int>\
    \ lpf(n + 1, 0);\n  iota(lpf.begin(), lpf.end(), 0);\n  for (int p = 2; p * p\
    \ <= n; p += (p & 1) + 1) {\n    if (lpf[p] != p) continue;\n    for (int i =\
    \ p * p; i <= n; i += p)\n      if (lpf[i] == i) lpf[i] = p;\n  }\n  return lpf;\n\
    }\n/**\n * @brief LPF Table\n */\n#line 3 \"modint/power-table.hpp\"\n\n// 0^k,1^k,2^k,...,n^k\n\
    template <class T>\nvector<T> PowerTable(int n, int k) {\n  assert(k >= 0);\n\
    \  vector<T> f;\n  if (k == 0) {\n    f = vector<T>(n + 1, 0);\n    f[0] = 1;\n\
    \  } else {\n    f = vector<T>(n + 1, 1);\n    f[0] = 0;\n    auto lpf = LPFTable(n);\n\
    \    for (int i = 2; i <= n; i++)\n      f[i] = lpf[i] == i ? T(i).pow(k) : f[i\
    \ / lpf[i]] * f[lpf[i]];\n  }\n  return f;\n}\n/**\n * @brief Power Table\n */\n\
    #line 3 \"fps/interpolate.hpp\"\n\n// f(0),f(1),...,f(n-1) -> f(x)\ntemplate <class\
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
    sum_{i}r^i poly(i)$\n * @docs docs/fps/sum-of-exp-poly.md\n */\n#line 9 \"verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp\"\
    \n\nint main() {\n  mint r;\n  int d;\n  ll n;\n  in(r, d, n);\n  auto f = PowerTable<mint>(d,\
    \ d);\n  out(SumOfExpPoly(n, r, f));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n\n#include \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing\
    \ mint = ModInt<998244353>;\n#include \"modint/factorial.hpp\"\n#include \"modint/power-table.hpp\"\
    \n#include \"fps/sum-of-exp-poly.hpp\"\n\nint main() {\n  mint r;\n  int d;\n\
    \  ll n;\n  in(r, d, n);\n  auto f = PowerTable<mint>(d, d);\n  out(SumOfExpPoly(n,\
    \ r, f));\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - modint/factorial.hpp
  - modint/power-table.hpp
  - math/lpf-table.hpp
  - fps/sum-of-exp-poly.hpp
  - fps/interpolate.hpp
  isVerificationFile: true
  path: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
  requiredBy: []
  timestamp: '2025-10-23 01:57:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
layout: document
redirect_from:
- /verify/verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
- /verify/verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp.html
title: verify/fps/LC_sum_of_exponential_times_polynomial.test.cpp
---
