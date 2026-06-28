---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/math/UNIT_util.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ u128 = __uint128_t;\n\ntemplate <class T, class S = T>\nS SUM(const vector<T>&\
    \ a) {\n  return accumulate(ALL(a), S(0));\n}\ntemplate <class T>\ninline bool\
    \ chmin(T& a, T b) {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return\
    \ false;\n}\ntemplate <class T>\ninline bool chmax(T& a, T b) {\n  if (a < b)\
    \ {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\ntemplate <class\
    \ T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n}\ntemplate <class\
    \ T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n}\n\
    template <class T>\nint lowbit(T x) {\n  return (x == 0 ? -1 : __builtin_ctzll(x));\n\
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
    \ 0;\n  long long x = sqrt(n);\n  while ((__int128)(x + 1) * (x + 1) <= n) x++;\n\
    \  while ((__int128)x * x > n) x--;\n  return x;\n}\nlong long floor_root(long\
    \ long n, int k) {\n  assert(n >= 0);\n  if (n == 0) return 0;\n  assert(k >=\
    \ 1);\n  if (k == 1) return n;\n  if (k > 64) return 1;\n  long long x = round(pow((long\
    \ double)n, 1.0L / k));\n  auto check = [&](long long a) {\n    if (a <= 0) return\
    \ true;\n    __int128_t p = 1;\n    for (int i = 0; i < k; ++i)\n      if ((p\
    \ *= a) > n) return false;\n    return true;\n  };\n  while (check(x + 1)) x++;\n\
    \  while (!check(x)) x--;\n  return x;\n}\n// return g=gcd(a,b)\n// a*x+b*y=g\n\
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
    \  if (m == 1) return 0;\n  x = (x % m + m) % m;\n  long long y = 1;\n  while\
    \ (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n\
    \  return y;\n}\nconstexpr long long pow_mod_constexpr(long long x, long long\
    \ n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m = (unsigned int)(m);\n\
    \  unsigned long long r = 1;\n  unsigned long long y = x % m;\n  if (y >= m) y\
    \ += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n\
    \    n >>= 1;\n  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n\
    \  if (n <= 1) return false;\n  if (n == 2 || n == 7 || n == 61) return true;\n\
    \  if (n % 2 == 0) return false;\n  long long d = n - 1;\n  while (d % 2 == 0)\
    \ d /= 2;\n  constexpr long long bases[3] = {2, 7, 61};\n  for (long long a :\
    \ bases) {\n    long long t = d;\n    long long y = pow_mod_constexpr(a, t, n);\n\
    \    while (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n    \
    \  t <<= 1;\n    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n\
    \    }\n  }\n  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
    };  // namespace Math\n#line 5 \"verify/math/UNIT_util.test.cpp\"\n\nvoid test_division()\
    \ {\n  rep(a, -100, 101) rep(b, -100, 101) {\n    if (b == 0) continue;\n    int\
    \ m = abs(b);\n    int r = Math::safe_mod(a, b);\n    assert(0 <= r && r < m);\n\
    \    assert(((b < 0 ? -a : a) - r) % m == 0);\n\n    int f = Math::floor(a, b);\n\
    \    int c = Math::ceil(a, b);\n    long double v = (long double)a / b;\n    assert(f\
    \ <= v && v < f + 1);\n    assert(c - 1 < v && v <= c);\n  }\n}\n\nvoid test_roots()\
    \ {\n  auto check_sqrt = [](long long n) {\n    long long x = Math::isqrt(n);\n\
    \    assert((__int128)x * x <= n);\n    assert((__int128)(x + 1) * (x + 1) > n);\n\
    \  };\n  rep(n, 0, 100000) check_sqrt(n);\n  for (long long n : {1000000000000LL,\
    \ 9223372036854775807LL}) check_sqrt(n);\n\n  rep(n, 0, 10000) rep(k, 1, 11) {\n\
    \    long long x = Math::floor_root(n, k);\n    auto leq = [&](long long a) {\n\
    \      __int128 p = 1;\n      rep(i, 0, k) p *= a;\n      return p <= n;\n   \
    \ };\n    assert(leq(x));\n    assert(!leq(x + 1));\n  }\n  assert(Math::floor_root(9223372036854775807LL,\
    \ 2) == 3037000499LL);\n}\n\nvoid test_number_theory() {\n  rep(a, -100, 101)\
    \ rep(b, -100, 101) {\n    if (a == 0 && b == 0) continue;\n    long long x, y;\n\
    \    long long g = Math::ext_gcd((long long)a, (long long)b, x, y);\n    assert(g\
    \ == gcd(abs(a), abs(b)));\n    assert((long long)a * x + (long long)b * y ==\
    \ g);\n  }\n\n  rep(m, 2, 200) rep(a, 1, m) {\n    if (gcd(a, m) == 1) assert(a\
    \ * Math::inv_mod(a, m) % m == 1);\n  }\n  rep(x, -20, 21) rep(n, 0, 20) rep(m,\
    \ 1, 50) {\n    long long expected = 1 % m;\n    rep(i, 0, n) expected = expected\
    \ * Math::safe_mod(x, m) % m;\n    assert(Math::pow_mod(x, n, m) == expected);\n\
    \  }\n  rep(n, 0, 1000) {\n    bool prime = n >= 2;\n    for (int d = 2; d * d\
    \ <= n; d++) prime &= n % d != 0;\n    assert(Math::is_prime_constexpr(n) == prime);\n\
    \  }\n}\n\nint main() {\n  test_division();\n  test_roots();\n  test_number_theory();\n\
    \n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"math/util.hpp\"\n\nvoid test_division() {\n\
    \  rep(a, -100, 101) rep(b, -100, 101) {\n    if (b == 0) continue;\n    int m\
    \ = abs(b);\n    int r = Math::safe_mod(a, b);\n    assert(0 <= r && r < m);\n\
    \    assert(((b < 0 ? -a : a) - r) % m == 0);\n\n    int f = Math::floor(a, b);\n\
    \    int c = Math::ceil(a, b);\n    long double v = (long double)a / b;\n    assert(f\
    \ <= v && v < f + 1);\n    assert(c - 1 < v && v <= c);\n  }\n}\n\nvoid test_roots()\
    \ {\n  auto check_sqrt = [](long long n) {\n    long long x = Math::isqrt(n);\n\
    \    assert((__int128)x * x <= n);\n    assert((__int128)(x + 1) * (x + 1) > n);\n\
    \  };\n  rep(n, 0, 100000) check_sqrt(n);\n  for (long long n : {1000000000000LL,\
    \ 9223372036854775807LL}) check_sqrt(n);\n\n  rep(n, 0, 10000) rep(k, 1, 11) {\n\
    \    long long x = Math::floor_root(n, k);\n    auto leq = [&](long long a) {\n\
    \      __int128 p = 1;\n      rep(i, 0, k) p *= a;\n      return p <= n;\n   \
    \ };\n    assert(leq(x));\n    assert(!leq(x + 1));\n  }\n  assert(Math::floor_root(9223372036854775807LL,\
    \ 2) == 3037000499LL);\n}\n\nvoid test_number_theory() {\n  rep(a, -100, 101)\
    \ rep(b, -100, 101) {\n    if (a == 0 && b == 0) continue;\n    long long x, y;\n\
    \    long long g = Math::ext_gcd((long long)a, (long long)b, x, y);\n    assert(g\
    \ == gcd(abs(a), abs(b)));\n    assert((long long)a * x + (long long)b * y ==\
    \ g);\n  }\n\n  rep(m, 2, 200) rep(a, 1, m) {\n    if (gcd(a, m) == 1) assert(a\
    \ * Math::inv_mod(a, m) % m == 1);\n  }\n  rep(x, -20, 21) rep(n, 0, 20) rep(m,\
    \ 1, 50) {\n    long long expected = 1 % m;\n    rep(i, 0, n) expected = expected\
    \ * Math::safe_mod(x, m) % m;\n    assert(Math::pow_mod(x, n, m) == expected);\n\
    \  }\n  rep(n, 0, 1000) {\n    bool prime = n >= 2;\n    for (int d = 2; d * d\
    \ <= n; d++) prime &= n % d != 0;\n    assert(Math::is_prime_constexpr(n) == prime);\n\
    \  }\n}\n\nint main() {\n  test_division();\n  test_roots();\n  test_number_theory();\n\
    \n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - math/util.hpp
  isVerificationFile: true
  path: verify/math/UNIT_util.test.cpp
  requiredBy: []
  timestamp: '2026-06-28 19:44:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/UNIT_util.test.cpp
layout: document
redirect_from:
- /verify/verify/math/UNIT_util.test.cpp
- /verify/verify/math/UNIT_util.test.cpp.html
title: verify/math/UNIT_util.test.cpp
---
