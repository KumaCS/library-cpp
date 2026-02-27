---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor-monoid-product.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u7248 Floor Sum"
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n\
    #line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#line 2 \"template/macro.hpp\"\n#define rep(i, a, b) for (int i = (a); i < (int)(b);\
    \ i++)\n#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (a); i--)\n#define\
    \ ALL(v) (v).begin(), (v).end()\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\n#define SZ(v) (int)v.size()\n#define MIN(v) *min_element(ALL(v))\n\
    #define MAX(v) *max_element(ALL(v))\n#define LB(v, x) int(lower_bound(ALL(v),\
    \ (x)) - (v).begin())\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\n\
    #define YN(b) cout << ((b) ? \"YES\" : \"NO\") << \"\\n\";\n#define Yn(b) cout\
    \ << ((b) ? \"Yes\" : \"No\") << \"\\n\";\n#define yn(b) cout << ((b) ? \"yes\"\
    \ : \"no\") << \"\\n\";\n#line 6 \"template/template.hpp\"\n\n#line 2 \"template/util.hpp\"\
    \nusing uint = unsigned int;\nusing ll = long long int;\nusing ull = unsigned\
    \ long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\ntemplate\
    \ <class T, class S = T>\nS SUM(const vector<T>& a) {\n  return accumulate(ALL(a),\
    \ S(0));\n}\ntemplate <class T>\ninline bool chmin(T& a, T b) {\n  if (a > b)\
    \ {\n    a = b;\n    return true;\n  }\n  return false;\n}\ntemplate <class T>\n\
    inline bool chmax(T& a, T b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\n\ntemplate <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n\
    }\ntemplate <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"math/floor-monoid-product.hpp\"\n\
    \ntemplate <class T, T (*op)(T, T), T (*e)(), std::unsigned_integral U = uint64_t>\n\
    T FloorMonoidProduct(U n, U m, U a, U b, T x, T y, function<T(T, U)> pow = nullptr)\
    \ {\n  if (!pow) {\n    pow = [](T t, U n) {\n      T p = e();\n      while (n)\
    \ {\n        if (n & 1) p = op(p, t);\n        t = op(t, t);\n        n >>= 1;\n\
    \      }\n      return p;\n    };\n  }\n  assert(m != 0);\n  T pl = e(), pr =\
    \ e();\n  while (true) {\n    if (a >= m) {\n      U q = a / m;\n      x = op(x,\
    \ pow(y, q));\n      a -= m * q;\n    }\n    if (b >= m) {\n      U q = b / m;\n\
    \      pl = op(pl, pow(y, q));\n      b -= m * q;\n    }\n    U c = a * n + b;\n\
    \    if (c < m) {\n      pl = op(pl, pow(x, n));\n      break;\n    }\n    pr\
    \ = op(op(y, pow(x, c % m / a)), pr);\n    n = c / m - 1;\n    b = m + a - b -\
    \ 1;\n    swap(a, m);\n    swap(x, y);\n  }\n  return op(pl, pr);\n}\n\n/**\n\
    \ * @brief \u30E2\u30CE\u30A4\u30C9\u7248 Floor Sum\n * @docs docs/math/floor-monoid-product.md\n\
    \ */\n#line 5 \"verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp\"\n\nstruct\
    \ T {\n  ull x, y, z;\n};\nT op(T a, T b) { return T{a.x + b.x, a.y + b.y, a.y\
    \ * b.x + a.z + b.z}; }\nT e() { return T{0, 0, 0}; }\n\nint main() {\n  int t;\n\
    \  in(t);\n  T x{1, 0, 0}, y{0, 1, 0};\n  while (t--) {\n    ull n, m, a, b;\n\
    \    in(n, m, a, b);\n    ull sum = FloorMonoidProduct<T, op, e>(n, m, a, b, x,\
    \ y).z;\n    cout << sum << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/floor-monoid-product.hpp\"\
    \n\nstruct T {\n  ull x, y, z;\n};\nT op(T a, T b) { return T{a.x + b.x, a.y +\
    \ b.y, a.y * b.x + a.z + b.z}; }\nT e() { return T{0, 0, 0}; }\n\nint main() {\n\
    \  int t;\n  in(t);\n  T x{1, 0, 0}, y{0, 1, 0};\n  while (t--) {\n    ull n,\
    \ m, a, b;\n    in(n, m, a, b);\n    ull sum = FloorMonoidProduct<T, op, e>(n,\
    \ m, a, b, x, y).z;\n    cout << sum << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - math/floor-monoid-product.hpp
  isVerificationFile: true
  path: verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp
layout: document
redirect_from:
- /verify/verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp
- /verify/verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp.html
title: verify/math/LC_sum_of_floor_of_linear.monoid.test.cpp
---
