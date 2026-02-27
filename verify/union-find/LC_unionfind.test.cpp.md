---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: union-find/union-find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/union-find/LC_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"union-find/union-find.hpp\"\n\n\
    struct UnionFind {\n private:\n  vector<int> a;\n\n public:\n  UnionFind(int n)\
    \ : a(n, -1) {}\n  int find(int x) { return a[x] < 0 ? x : a[x] = find(a[x]);\
    \ }\n  int size(int x) { return -a[find(x)]; }\n  bool same(int x, int y) { return\
    \ find(x) == find(y); }\n  bool unite(int x, int y) {\n    x = find(x), y = find(y);\n\
    \    if (x == y) return false;\n    if (a[x] > a[y]) swap(x, y);\n    a[x] +=\
    \ a[y];\n    a[y] = x;\n    return true;\n  }\n  template <class F>\n  bool unite(int\
    \ x, int y, F f) {\n    x = find(x), y = find(y);\n    if (x == y) return false;\n\
    \    if (a[x] > a[y]) swap(x, y);\n    a[x] += a[y];\n    a[y] = x;\n    f(x,\
    \ y);\n    return true;\n  }\n  vector<vector<int>> groups() {\n    vector<int>\
    \ root(a.size()), gsize(a.size());\n    for (int i = 0; i < a.size(); i++) gsize[root[i]\
    \ = find(i)]++;\n    vector<vector<int>> res(a.size());\n    for (int i = 0; i\
    \ < res.size(); i++) res[i].reserve(gsize[i]);\n    for (int i = 0; i < root.size();\
    \ i++) res[root[i]].push_back(i);\n    res.erase(remove_if(res.begin(), res.end(),\
    \ [&](const vector<int>& v) { return v.empty(); }), res.end());\n    return res;\n\
    \  }\n};\n/**\n * @brief Union Find\n * @docs docs/union-find/union-find.md\n\
    \ */\n#line 5 \"verify/union-find/LC_unionfind.test.cpp\"\n\nint main() {\n  int\
    \ n, q;\n  in(n, q);\n  UnionFind uf(n);\n  while (q--) {\n    int t, u, v;\n\
    \    in(t, u, v);\n    if (t == 0)\n      uf.unite(u, v);\n    else\n      out(uf.same(u,\
    \ v));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"union-find/union-find.hpp\"\n\nint main()\
    \ {\n  int n, q;\n  in(n, q);\n  UnionFind uf(n);\n  while (q--) {\n    int t,\
    \ u, v;\n    in(t, u, v);\n    if (t == 0)\n      uf.unite(u, v);\n    else\n\
    \      out(uf.same(u, v));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - union-find/union-find.hpp
  isVerificationFile: true
  path: verify/union-find/LC_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/union-find/LC_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/union-find/LC_unionfind.test.cpp
- /verify/verify/union-find/LC_unionfind.test.cpp.html
title: verify/union-find/LC_unionfind.test.cpp
---
