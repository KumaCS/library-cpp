---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/data-structure/LC_staticrmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"data-structure/sparse-table.hpp\"\
    \n\ntemplate <class T, T (*op)(T, T)>\nstruct SparseTable {\n private:\n  int\
    \ n;\n  vector<vector<T>> st;\n\n public:\n  SparseTable() {}\n  SparseTable(const\
    \ vector<T> &arr) {\n    n = arr.size();\n    int log = 1;\n    while (n >> log)\
    \ log++;\n    st = vector<vector<T>>(log);\n    st[0] = vector<T>(arr.begin(),\
    \ arr.end());\n    for (int k = 1; k < log; k++) {\n      auto stp = st[k - 1];\n\
    \      auto sti = vector<T>(n - (1 << k) + 1);\n      for (int i = 0; i < sti.size();\
    \ i++)\n        sti[i] = op(stp[i], stp[i + (1 << (k - 1))]);\n      st[k] = sti;\n\
    \    }\n  }\n  T prod(int l, int r)  // [l,r)\n  {\n    assert(0 <= l && l < r\
    \ && r <= n);\n    int j = 0;\n    while ((1 << j) <= r - l) j++;\n    j--;\n\
    \    return op(st[j][l], st[j][r - (1 << j)]);\n  }\n};\n#line 5 \"verify/data-structure/LC_staticrmq.test.cpp\"\
    \n\nint op(int x, int y) { return min(x, y); }\n\nint main() {\n  int n, q;\n\
    \  in(n, q);\n  vector<int> a(n);\n  in(a);\n  SparseTable<int, op> st(a);\n \
    \ while (q--) {\n    int l, r;\n    in(l, r);\n    out(st.prod(l, r));\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"data-structure/sparse-table.hpp\"\n\n\
    int op(int x, int y) { return min(x, y); }\n\nint main() {\n  int n, q;\n  in(n,\
    \ q);\n  vector<int> a(n);\n  in(a);\n  SparseTable<int, op> st(a);\n  while (q--)\
    \ {\n    int l, r;\n    in(l, r);\n    out(st.prod(l, r));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: true
  path: verify/data-structure/LC_staticrmq.test.cpp
  requiredBy: []
  timestamp: '2025-10-23 01:57:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/LC_staticrmq.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/LC_staticrmq.test.cpp
- /verify/verify/data-structure/LC_staticrmq.test.cpp.html
title: verify/data-structure/LC_staticrmq.test.cpp
---
