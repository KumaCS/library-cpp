---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/simple-queue.hpp
    title: data-structure/simple-queue.hpp
  - icon: ':heavy_check_mark:'
    path: flow/max-flow.hpp
    title: Max Flow
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"verify/flow/AOJ_GRL_6_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"flow/max-flow.hpp\"\n\n#line 2 \"\
    data-structure/simple-queue.hpp\"\n\ntemplate <class T>\nstruct SimpleQueue {\n\
    \ private:\n  vector<T> a;\n  int p;\n\n public:\n  SimpleQueue() {}\n  SimpleQueue(int\
    \ n) { a.reserve(n); }\n  void reserve(int n) { a.reserve(n); }\n  int size()\
    \ { return a.size() - p; }\n  bool empty() { return a.size() == p; }\n  void push(const\
    \ T& v) { a.push_back(v); }\n  T& front() { return a[p]; }\n  void pop() { p++;\
    \ }\n  void clear() {\n    a.clear();\n    p = 0;\n  }\n};\n#line 4 \"flow/max-flow.hpp\"\
    \n\ntemplate <class Cap = long long>\nstruct MaxFlow {\n public:\n  MaxFlow()\
    \ : _n(0) {}\n  explicit MaxFlow(int n) : _n(n), g(n) {}\n\n  int add_edge(int\
    \ from, int to, Cap cap) {\n    assert(0 <= from && from < _n);\n    assert(0\
    \ <= to && to < _n);\n    assert(0 <= cap);\n    int m = int(pos.size());\n  \
    \  pos.push_back({from, int(g[from].size())});\n    int from_id = int(g[from].size());\n\
    \    int to_id = int(g[to].size());\n    if (from == to) to_id++;\n    g[from].push_back(_edge{to,\
    \ to_id, cap});\n    g[to].push_back(_edge{from, from_id, 0});\n    return m;\n\
    \  }\n\n  struct edge {\n    int from, to;\n    Cap cap, flow;\n  };\n\n  edge\
    \ get_edge(int i) {\n    int m = int(pos.size());\n    assert(0 <= i && i < m);\n\
    \    auto _e = g[pos[i].first][pos[i].second];\n    auto _re = g[_e.to][_e.rev];\n\
    \    return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};\n  }\n  vector<edge>\
    \ edges() {\n    int m = int(pos.size());\n    vector<edge> result;\n    for (int\
    \ i = 0; i < m; i++) {\n      result.push_back(get_edge(i));\n    }\n    return\
    \ result;\n  }\n  void change_edge(int i, Cap new_cap, Cap new_flow) {\n    int\
    \ m = int(pos.size());\n    assert(0 <= i && i < m);\n    assert(0 <= new_flow\
    \ && new_flow <= new_cap);\n    auto& _e = g[pos[i].first][pos[i].second];\n \
    \   auto& _re = g[_e.to][_e.rev];\n    _e.cap = new_cap - new_flow;\n    _re.cap\
    \ = new_flow;\n  }\n\n  Cap flow(int s, int t) {\n    return flow(s, t, numeric_limits<Cap>::max());\n\
    \  }\n  Cap flow(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n\
    \    assert(0 <= t && t < _n);\n    assert(s != t);\n\n    vector<int> level(_n),\
    \ iter(_n);\n    SimpleQueue<int> que;\n\n    auto bfs = [&]() {\n      fill(level.begin(),\
    \ level.end(), -1);\n      level[s] = 0;\n      que.clear();\n      que.push(s);\n\
    \      while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (auto& e : g[v]) {\n          if (e.cap == 0 || level[e.to] >= 0)\
    \ continue;\n          level[e.to] = level[v] + 1;\n          if (e.to == t) return;\n\
    \          que.push(e.to);\n        }\n      }\n    };\n    auto dfs = [&](auto\
    \ self, int v, Cap up) {\n      if (v == s) return up;\n      Cap res = 0;\n \
    \     int level_v = level[v];\n      for (int& i = iter[v]; i < int(g[v].size());\
    \ i++) {\n        _edge& e = g[v][i];\n        if (level_v <= level[e.to] || g[e.to][e.rev].cap\
    \ == 0) continue;\n        Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));\n\
    \        if (d <= 0) continue;\n        g[v][i].cap += d;\n        g[e.to][e.rev].cap\
    \ -= d;\n        res += d;\n        if (res == up) return res;\n      }\n    \
    \  level[v] = _n;\n      return res;\n    };\n\n    Cap flow = 0;\n    while (flow\
    \ < flow_limit) {\n      bfs();\n      if (level[t] == -1) break;\n      fill(iter.begin(),\
    \ iter.end(), 0);\n      Cap f = dfs(dfs, t, flow_limit - flow);\n      if (!f)\
    \ break;\n      flow += f;\n    }\n    return flow;\n  }\n\n  vector<bool> min_cut(int\
    \ s) {\n    vector<bool> visited(_n);\n    SimpleQueue<int> que;\n    que.push(s);\n\
    \    while (!que.empty()) {\n      int p = que.front();\n      que.pop();\n  \
    \    visited[p] = true;\n      for (auto& e : g[p]) {\n        if (e.cap && !visited[e.to])\
    \ {\n          visited[e.to] = true;\n          que.push(e.to);\n        }\n \
    \     }\n    }\n    return visited;\n  }\n\n private:\n  int _n;\n  struct _edge\
    \ {\n    int to, rev;\n    Cap cap;\n  };\n  vector<pair<int, int>> pos;\n  vector<vector<_edge>>\
    \ g;\n};\n\n/**\n * @brief Max Flow\n * @docs docs/flow/max-flow.md\n */\n#line\
    \ 5 \"verify/flow/AOJ_GRL_6_A.test.cpp\"\n\nint main() {\n  int n, m;\n  in(n,\
    \ m);\n  MaxFlow<int> g(n);\n  rep(i, 0, m) {\n    int u, v, w;\n    in(u, v,\
    \ w);\n    g.add_edge(u, v, w);\n  }\n  out(g.flow(0, n - 1));\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"template/template.hpp\"\n#include \"flow/max-flow.hpp\"\n\nint\
    \ main() {\n  int n, m;\n  in(n, m);\n  MaxFlow<int> g(n);\n  rep(i, 0, m) {\n\
    \    int u, v, w;\n    in(u, v, w);\n    g.add_edge(u, v, w);\n  }\n  out(g.flow(0,\
    \ n - 1));\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - flow/max-flow.hpp
  - data-structure/simple-queue.hpp
  isVerificationFile: true
  path: verify/flow/AOJ_GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/flow/AOJ_GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/verify/flow/AOJ_GRL_6_A.test.cpp
- /verify/verify/flow/AOJ_GRL_6_A.test.cpp.html
title: verify/flow/AOJ_GRL_6_A.test.cpp
---
