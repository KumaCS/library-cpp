---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mod-sqrt.hpp
    title: modint/mod-sqrt.hpp
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
  bundledCode: "#line 1 \"verify/modint/UNIT_mod_sqrt.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
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
    \    cout << fixed << setprecision(15);\n  }\n} fast;\n\ntemplate <class T1, class\
    \ T2>\nistream& operator>>(istream& is, pair<T1, T2>& p) {\n  return is >> p.first\
    \ >> p.second;\n}\ntemplate <class T1, class T2>\nostream& operator<<(ostream&\
    \ os, const pair<T1, T2>& p) {\n  return os << p.first << \" \" << p.second;\n\
    }\ntemplate <class T>\nistream& operator>>(istream& is, vector<T>& a) {\n  for\
    \ (auto& v : a) is >> v;\n  return is;\n}\ntemplate <class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& a) {\n  for (auto it = a.begin(); it != a.end();) {\n \
    \   os << *it;\n    if (++it != a.end()) os << \" \";\n  }\n  return os;\n}\n\
    template <class T>\nostream& operator<<(ostream& os, const set<T>& st) {\n  os\
    \ << \"{\";\n  for (auto it = st.begin(); it != st.end();) {\n    os << *it;\n\
    \    if (++it != st.end()) os << \",\";\n  }\n  os << \"}\";\n  return os;\n}\n\
    template <class T1, class T2>\nostream& operator<<(ostream& os, const map<T1,\
    \ T2>& mp) {\n  os << \"{\";\n  for (auto it = mp.begin(); it != mp.end();) {\n\
    \    os << it->first << \":\" << it->second;\n    if (++it != mp.end()) os <<\
    \ \",\";\n  }\n  os << \"}\";\n  return os;\n}\nostream& operator<<(ostream& os,\
    \ __uint128_t x) {\n  char buf[40];\n  size_t k = 0;\n  while (x > 0) buf[k++]\
    \ = (char)(x % 10 + '0'), x /= 10;\n  if (k == 0) buf[k++] = '0';\n  while (k)\
    \ os << buf[--k];\n  return os;\n}\nostream& operator<<(ostream& os, __int128_t\
    \ x) {\n  return x < 0 ? (os << '-' << (__uint128_t)(-x)) : (os << (__uint128_t)x);\n\
    }\n\nvoid in() {}\ntemplate <typename T, class... U>\nvoid in(T& t, U&... u) {\n\
    \  cin >> t;\n  in(u...);\n}\nvoid out() { cout << \"\\n\"; }\ntemplate <typename\
    \ T, class... U, char sep = ' '>\nvoid out(const T& t, const U&... u) {\n  cout\
    \ << t;\n  if (sizeof...(u)) cout << sep;\n  out(u...);\n}\n#line 10 \"template/template.hpp\"\
    \n\n#line 2 \"template/debug.hpp\"\n#ifdef LOCAL\n#define debug 1\n#define show(...)\
    \ _show(0, #__VA_ARGS__, __VA_ARGS__)\n#else\n#define debug 0\n#define show(...)\
    \ true\n#endif\ntemplate <class T>\nvoid _show(int i, T name) {\n  cerr << '\\\
    n';\n}\ntemplate <class T1, class T2, class... T3>\nvoid _show(int i, const T1&\
    \ a, const T2& b, const T3&... c) {\n  for (; a[i] != ',' && a[i] != '\\0'; i++)\
    \ cerr << a[i];\n  cerr << \":\" << b << \" \";\n  _show(i + 1, a, c...);\n}\n\
    #line 2 \"modint/mod-sqrt.hpp\"\n\n#line 2 \"math/util.hpp\"\n\nnamespace Math\
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
    \ Math\n#line 4 \"modint/mod-sqrt.hpp\"\n\nlong long ModSqrt(long long a, long\
    \ long p) {\n  if (a >= p) a %= p;\n  if (p == 2) return a & 1;\n  if (a == 0)\
    \ return 0;\n  if (Math::pow_mod(a, (p - 1) / 2, p) != 1) return -1;\n  if (p\
    \ % 4 == 3) return Math::pow_mod(a, (3 * p - 1) / 4, p);\n  unsigned int z = 2,\
    \ q = p - 1;\n  while (Math::pow_mod(z, (p - 1) / 2, p) == 1) z++;\n  int s =\
    \ 0;\n  while (!(q & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n  unsigned\
    \ int c = Math::pow_mod(z, q, p);\n  unsigned int t = Math::pow_mod(a, q, p);\n\
    \  unsigned int r = Math::pow_mod(a, (q + 1) / 2, p);\n  while (true) {\n    if\
    \ (t == 1) return r;\n    unsigned int pow = t;\n    int j = 1;\n    for (; j\
    \ < m; j++) {\n      pow = 1ll * pow * pow % p;\n      if (pow == 1) break;\n\
    \    }\n    unsigned int b = c;\n    for (int i = 0; i < m - j - 1; i++) b = 1ll\
    \ * b * b % p;\n    m = j;\n    c = 1ll * b * b % p;\n    t = 1ll * t * c % p;\n\
    \    r = 1ll * r * b % p;\n  }\n}\n#line 5 \"verify/modint/UNIT_mod_sqrt.test.cpp\"\
    \n\nvoid test(int mod) {\n  rep(i, 0, 10000) {\n    ll sq = ModSqrt(i, mod);\n\
    \    if (sq != -1) assert(sq * sq % mod == i % mod);\n  }\n  {\n    ll a = 998;\n\
    \    rep(i, 0, 10000) {\n      a = (a * 244 + 353) % mod;\n      {\n        ll\
    \ sq = ModSqrt(a, mod);\n        if (sq != -1) assert(sq * sq % mod == a);\n \
    \     }\n      {\n        ll sq = ModSqrt(a * a, mod);\n        assert(sq == a\
    \ || sq == mod - a);\n      }\n    }\n  }\n}\n\nint main() {\n  vector<int> psmall{2,\
    \ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};\n  for (auto p : psmall)\
    \ test(p);\n  vector<int> plarge{998244353, 1000000007};\n  for (auto p : plarge)\
    \ test(p);\n\n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"modint/mod-sqrt.hpp\"\n\nvoid test(int mod)\
    \ {\n  rep(i, 0, 10000) {\n    ll sq = ModSqrt(i, mod);\n    if (sq != -1) assert(sq\
    \ * sq % mod == i % mod);\n  }\n  {\n    ll a = 998;\n    rep(i, 0, 10000) {\n\
    \      a = (a * 244 + 353) % mod;\n      {\n        ll sq = ModSqrt(a, mod);\n\
    \        if (sq != -1) assert(sq * sq % mod == a);\n      }\n      {\n       \
    \ ll sq = ModSqrt(a * a, mod);\n        assert(sq == a || sq == mod - a);\n  \
    \    }\n    }\n  }\n}\n\nint main() {\n  vector<int> psmall{2, 3, 5, 7, 11, 13,\
    \ 17, 19, 23, 29, 31, 37, 41, 43, 47};\n  for (auto p : psmall) test(p);\n  vector<int>\
    \ plarge{998244353, 1000000007};\n  for (auto p : plarge) test(p);\n\n  int a,\
    \ b;\n  in(a, b);\n  out(a + b);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/mod-sqrt.hpp
  - math/util.hpp
  isVerificationFile: true
  path: verify/modint/UNIT_mod_sqrt.test.cpp
  requiredBy: []
  timestamp: '2025-12-29 01:13:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/modint/UNIT_mod_sqrt.test.cpp
layout: document
redirect_from:
- /verify/verify/modint/UNIT_mod_sqrt.test.cpp
- /verify/verify/modint/UNIT_mod_sqrt.test.cpp.html
title: verify/modint/UNIT_mod_sqrt.test.cpp
---
