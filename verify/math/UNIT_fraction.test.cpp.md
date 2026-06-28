---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fraction.hpp
    title: "\u6709\u7406\u6570"
  - icon: ':heavy_check_mark:'
    path: math/simple-fraction.hpp
    title: "\u6709\u7406\u6570 (\u7D04\u5206\u306A\u3057)"
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
  bundledCode: "#line 1 \"verify/math/UNIT_fraction.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"template/macro.hpp\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"math/fraction.hpp\"\n\ntemplate\
    \ <class T>\nstruct Fraction {\n  T a, b;\n  Fraction() : a(0), b(1) {}\n  Fraction(T\
    \ _a) : a(_a), b(1) {}\n  Fraction(T _a, T _b) { init(_a, _b); }\n  T floor()\
    \ const { return a >= 0 ? a / b : (a + 1) / b - 1; }\n  T ceil() const { return\
    \ a > 0 ? (a - 1) / b + 1 : a / b; }\n  template <class V>\n  V get() const {\
    \ return V(a) / b; }\n  using frac = Fraction;\n  static frac raw(T _a, T _b)\
    \ {\n    frac x;\n    x.a = _a, x.b = _b;\n    return x;\n  }\n  frac& init(T\
    \ _a, T _b) {\n    T g = gcd(_a, _b);\n    a = _a / g, b = _b / g;\n    if (b\
    \ < 0) a = -a, b = -b;\n    return *this;\n  }\n  frac inv() const { return a\
    \ >= 0 ? raw(b, a) : raw(-b, -a); }\n  frac operator-() const { return frac(-a,\
    \ b); }\n  frac& operator+=(const frac& x) { return init(a * x.b + x.a * b, b\
    \ * x.b); }\n  frac& operator-=(const frac& x) { return init(a * x.b - x.a * b,\
    \ b * x.b); }\n  frac& operator*=(const frac& x) { return init(a * x.a, b * x.b);\
    \ }\n  frac& operator/=(const frac& x) { return init(a * x.b, b * x.a); }\n  frac\
    \ operator+(const frac& x) const { return frac(*this) += x; }\n  frac operator-(const\
    \ frac& x) const { return frac(*this) -= x; }\n  frac operator*(const frac& x)\
    \ const { return frac(*this) *= x; }\n  frac operator/(const frac& x) const {\
    \ return frac(*this) /= x; }\n  bool operator<(const frac& x) const { return a\
    \ * x.b < b * x.a; }\n  bool operator>(const frac& x) const { return a * x.b >\
    \ b * x.a; }\n  bool operator<=(const frac& x) const { return a * x.b <= b * x.a;\
    \ }\n  bool operator>=(const frac& x) const { return a * x.b >= b * x.a; }\n \
    \ bool operator==(const frac& x) const { return a * x.b == b * x.a; }\n  bool\
    \ operator!=(const frac& x) const { return a * x.b != b * x.a; }\n  friend istream&\
    \ operator>>(istream& is, frac& x) { return is >> x.a >> x.b; }\n  friend ostream&\
    \ operator<<(ostream& os, const frac& x) { return os << x.a << '/' << x.b; }\n\
    };\n\n/**\n * @brief \u6709\u7406\u6570\n */\n#line 2 \"math/simple-fraction.hpp\"\
    \n\ntemplate <class T>\nstruct SimpleFraction {\n  T a, b;\n  SimpleFraction()\
    \ : a(0), b(1) {}\n  SimpleFraction(T _a) : a(_a), b(1) {}\n  SimpleFraction(T\
    \ _a, T _b) { init(_a, _b); }\n  template <class V>\n  V get() const { return\
    \ V(a) / b; }\n  using frac = SimpleFraction;\n  frac &init(T _a, T _b) {\n  \
    \  a = _a, b = _b;\n    if (b < 0) a = -a, b = -b;\n    if (a == 0) b = 1;\n \
    \   return *this;\n  }\n  frac operator-() const { return frac(-a, b); }\n  frac\
    \ &operator+=(const frac &x) { return init(a * x.b + x.a * b, b * x.b); }\n  frac\
    \ &operator-=(const frac &x) { return init(a * x.b - x.a * b, b * x.b); }\n  frac\
    \ &operator*=(const frac &x) { return init(a * x.a, b * x.b); }\n  frac &operator/=(const\
    \ frac &x) { return init(a * x.b, b * x.a); }\n  frac operator+(const frac &x)\
    \ const { return frac(*this) += x; }\n  frac operator-(const frac &x) const {\
    \ return frac(*this) -= x; }\n  frac operator*(const frac &x) const { return frac(*this)\
    \ *= x; }\n  frac operator/(const frac &x) const { return frac(*this) /= x; }\n\
    \  bool operator<(const frac &x) const { return a * x.b < b * x.a; }\n  bool operator>(const\
    \ frac &x) const { return a * x.b > b * x.a; }\n  bool operator<=(const frac &x)\
    \ const { return a * x.b <= b * x.a; }\n  bool operator>=(const frac &x) const\
    \ { return a * x.b >= b * x.a; }\n  bool operator==(const frac &x) const { return\
    \ a * x.b == b * x.a; }\n  bool operator!=(const frac &x) const { return a * x.b\
    \ != b * x.a; }\n  friend istream &operator>>(istream &is, frac &x) { return is\
    \ >> x.a >> x.b; }\n  friend ostream &operator<<(ostream &os, const frac &x) {\
    \ return os << x.a << '/' << x.b; }\n};\n\n/**\n * @brief \u6709\u7406\u6570 (\u7D04\
    \u5206\u306A\u3057)\n */\n#line 6 \"verify/math/UNIT_fraction.test.cpp\"\n\nvoid\
    \ check_fraction(Fraction<ll> x) {\n  assert(x.b > 0);\n  assert(gcd(abs(x.a),\
    \ abs(x.b)) == 1);\n}\n\nvoid test_fraction() {\n  rep(a, -20, 21) rep(b, 1, 21)\
    \ {\n    Fraction<ll> x(a, b);\n    check_fraction(x);\n    assert(x == Fraction<ll>(a\
    \ * 3, b * 3));\n    if (a != 0) assert(x * x.inv() == Fraction<ll>(1));\n\n \
    \   Fraction<ll> y(b - 10, b + 1);\n    check_fraction(x + y);\n    check_fraction(x\
    \ - y);\n    check_fraction(x * y);\n    if (y.a != 0) check_fraction(x / y);\n\
    \n    long double v = x.get<long double>();\n    assert(x.floor() <= v && v <\
    \ x.floor() + 1);\n    assert(x.ceil() - 1 < v && v <= x.ceil());\n  }\n}\n\n\
    void test_simple_fraction() {\n  SimpleFraction<ll> x(1, 2), y(1, 3);\n  assert(x\
    \ + y == SimpleFraction<ll>(5, 6));\n  assert(x - y == SimpleFraction<ll>(1, 6));\n\
    \  assert(x * y == SimpleFraction<ll>(1, 6));\n  assert(x / y == SimpleFraction<ll>(3,\
    \ 2));\n  assert(SimpleFraction<ll>(-1, -2) == SimpleFraction<ll>(1, 2));\n  assert(SimpleFraction<ll>(0,\
    \ 100).b == 1);\n}\n\nint main() {\n  test_fraction();\n  test_simple_fraction();\n\
    \n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"math/fraction.hpp\"\n#include \"math/simple-fraction.hpp\"\
    \n\nvoid check_fraction(Fraction<ll> x) {\n  assert(x.b > 0);\n  assert(gcd(abs(x.a),\
    \ abs(x.b)) == 1);\n}\n\nvoid test_fraction() {\n  rep(a, -20, 21) rep(b, 1, 21)\
    \ {\n    Fraction<ll> x(a, b);\n    check_fraction(x);\n    assert(x == Fraction<ll>(a\
    \ * 3, b * 3));\n    if (a != 0) assert(x * x.inv() == Fraction<ll>(1));\n\n \
    \   Fraction<ll> y(b - 10, b + 1);\n    check_fraction(x + y);\n    check_fraction(x\
    \ - y);\n    check_fraction(x * y);\n    if (y.a != 0) check_fraction(x / y);\n\
    \n    long double v = x.get<long double>();\n    assert(x.floor() <= v && v <\
    \ x.floor() + 1);\n    assert(x.ceil() - 1 < v && v <= x.ceil());\n  }\n}\n\n\
    void test_simple_fraction() {\n  SimpleFraction<ll> x(1, 2), y(1, 3);\n  assert(x\
    \ + y == SimpleFraction<ll>(5, 6));\n  assert(x - y == SimpleFraction<ll>(1, 6));\n\
    \  assert(x * y == SimpleFraction<ll>(1, 6));\n  assert(x / y == SimpleFraction<ll>(3,\
    \ 2));\n  assert(SimpleFraction<ll>(-1, -2) == SimpleFraction<ll>(1, 2));\n  assert(SimpleFraction<ll>(0,\
    \ 100).b == 1);\n}\n\nint main() {\n  test_fraction();\n  test_simple_fraction();\n\
    \n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - math/fraction.hpp
  - math/simple-fraction.hpp
  isVerificationFile: true
  path: verify/math/UNIT_fraction.test.cpp
  requiredBy: []
  timestamp: '2026-06-28 19:44:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/UNIT_fraction.test.cpp
layout: document
redirect_from:
- /verify/verify/math/UNIT_fraction.test.cpp
- /verify/verify/math/UNIT_fraction.test.cpp.html
title: verify/math/UNIT_fraction.test.cpp
---
