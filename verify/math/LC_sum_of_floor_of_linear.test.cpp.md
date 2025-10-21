---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor-sum.hpp
    title: Floor Sum
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
  bundledCode: "#line 1 \"verify/math/LC_sum_of_floor_of_linear.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#line\
    \ 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ <class T, class S = T>\nS SUM(const vector<T> &a) {\n  return accumulate(ALL(a),\
    \ S(0));\n}\ntemplate <class T>\ninline bool chmin(T &a, T b) {\n  if (a > b)\
    \ {\n    a = b;\n    return true;\n  }\n  return false;\n}\ntemplate <class T>\n\
    inline bool chmax(T &a, T b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\n\ntemplate <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n\
    }\ntemplate <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"math/floor-sum.hpp\"\n\n// sum{i=0}^{n-1}floor((a*i+b)/m)\n\
    template <class T>\nT FloorSumUnsigned(unsigned long long n, unsigned long long\
    \ m, unsigned long long a, unsigned long long b) {\n  assert(m != 0);\n  if (n\
    \ == 0) return 0;\n  T res = 0;\n  while (true) {\n    if (a >= m) {\n      unsigned\
    \ long long q = a / m;\n      res += T(q) * (n / 2) * ((n - 1) | 1);\n      a\
    \ -= m * q;\n    }\n    if (b >= m) {\n      unsigned long long q = b / m;\n \
    \     res += T(q) * n;\n      b -= m * q;\n    }\n    unsigned long long y = a\
    \ * n + b;\n    if (y < m) break;\n    n = y / m, b = y - m * n;\n    swap(a,\
    \ m);\n  }\n  return res;\n}\n\n// sum{i=0}^{n-1}floor((a*i+b)/m)\ntemplate <class\
    \ T>\nT FloorSum(long long n, long long m, long long a, long long b) {\n  assert(m\
    \ != 0);\n  if (n <= 0) return 0;\n  if (m < 0) a = -a, b = -b, m = -m;\n  T res\
    \ = 0;\n  if (a < 0) {\n    long long q = (a + 1) / m - 1;\n    res += T(q) *\
    \ (n / 2) * ((n - 1) | 1);\n    a -= m * q;\n  }\n  if (b < 0) {\n    long long\
    \ q = (b + 1) / m - 1;\n    res += T(q) * n;\n    b -= m * q;\n  }\n  return res\
    \ + FloorSumUnsigned<T>(n, m, a, b);\n}\n\n/**\n * @brief Floor Sum\n * @docs\
    \ docs/math/floor-sum.md\n */\n#line 5 \"verify/math/LC_sum_of_floor_of_linear.test.cpp\"\
    \n\nint main() {\n  int t;\n  in(t);\n  while (t--) {\n    ull n, m, a, b;\n \
    \   in(n, m, a, b);\n    ull us = FloorSumUnsigned<ull>(n, m, a, b);\n    ll s\
    \ = FloorSum<ll>(ll(n), ll(m), ll(a), ll(b));\n    assert(us == ull(s));\n   \
    \ cout << us << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/floor-sum.hpp\"\n\nint\
    \ main() {\n  int t;\n  in(t);\n  while (t--) {\n    ull n, m, a, b;\n    in(n,\
    \ m, a, b);\n    ull us = FloorSumUnsigned<ull>(n, m, a, b);\n    ll s = FloorSum<ll>(ll(n),\
    \ ll(m), ll(a), ll(b));\n    assert(us == ull(s));\n    cout << us << \"\\n\"\
    ;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - math/floor-sum.hpp
  isVerificationFile: true
  path: verify/math/LC_sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/LC_sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/verify/math/LC_sum_of_floor_of_linear.test.cpp
- /verify/verify/math/LC_sum_of_floor_of_linear.test.cpp.html
title: verify/math/LC_sum_of_floor_of_linear.test.cpp
---
