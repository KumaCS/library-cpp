---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/simple-queue.hpp
    title: data-structure/simple-queue.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/flow/AOJ_GRL_6_A.test.cpp
    title: verify/flow/AOJ_GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/max-flow.md
    document_title: Max Flow
    links: []
  bundledCode: "#line 2 \"flow/max-flow.hpp\"\n\n#line 2 \"data-structure/simple-queue.hpp\"\
    \n\ntemplate <class T>\nstruct SimpleQueue {\n private:\n  vector<T> a;\n  int\
    \ p;\n\n public:\n  SimpleQueue() {}\n  SimpleQueue(int n) { a.reserve(n); }\n\
    \  void reserve(int n) { a.reserve(n); }\n  int size() { return a.size() - p;\
    \ }\n  bool empty() { return a.size() == p; }\n  void push(const T& v) { a.push_back(v);\
    \ }\n  T& front() { return a[p]; }\n  void pop() { p++; }\n  void clear() {\n\
    \    a.clear();\n    p = 0;\n  }\n};\n#line 4 \"flow/max-flow.hpp\"\n\ntemplate\
    \ <class Cap = long long>\nstruct MaxFlow {\n public:\n  MaxFlow() : _n(0) {}\n\
    \  explicit MaxFlow(int n) : _n(n), g(n) {}\n\n  int add_edge(int from, int to,\
    \ Cap cap) {\n    assert(0 <= from && from < _n);\n    assert(0 <= to && to <\
    \ _n);\n    assert(0 <= cap);\n    int m = int(pos.size());\n    pos.push_back({from,\
    \ int(g[from].size())});\n    int from_id = int(g[from].size());\n    int to_id\
    \ = int(g[to].size());\n    if (from == to) to_id++;\n    g[from].push_back(_edge{to,\
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
    \ g;\n};\n\n/**\n * @brief Max Flow\n * @docs docs/flow/max-flow.md\n */\n"
  code: "#pragma once\n\n#include \"data-structure/simple-queue.hpp\"\n\ntemplate\
    \ <class Cap = long long>\nstruct MaxFlow {\n public:\n  MaxFlow() : _n(0) {}\n\
    \  explicit MaxFlow(int n) : _n(n), g(n) {}\n\n  int add_edge(int from, int to,\
    \ Cap cap) {\n    assert(0 <= from && from < _n);\n    assert(0 <= to && to <\
    \ _n);\n    assert(0 <= cap);\n    int m = int(pos.size());\n    pos.push_back({from,\
    \ int(g[from].size())});\n    int from_id = int(g[from].size());\n    int to_id\
    \ = int(g[to].size());\n    if (from == to) to_id++;\n    g[from].push_back(_edge{to,\
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
    \ g;\n};\n\n/**\n * @brief Max Flow\n * @docs docs/flow/max-flow.md\n */"
  dependsOn:
  - data-structure/simple-queue.hpp
  isVerificationFile: false
  path: flow/max-flow.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/flow/AOJ_GRL_6_A.test.cpp
documentation_of: flow/max-flow.hpp
layout: document
redirect_from:
- /library/flow/max-flow.hpp
- /library/flow/max-flow.hpp.html
title: Max Flow
---
最大流問題を解く．

push-relabel algorithm により $n$ 頂点 $m$ 辺のとき $O(n^2m)$ 時間．

## push-relabel algorithm (概要)

- preflow とは flow において各頂点で (流入量)≥(流出量) であることを許したもの．
  - $\sum_{v\in V}f(v,u)-\sum_{v\in V}f(u,v)\geq 0$
- 頂点 $u$ の excess flow とは $e(u)=\sum_{v\in V}f(v,u)-\sum_{v\in V}f(u,v)$ のこと．
- 頂点 $u$ が overflow しているとは $e(u)\gt 0$ であること．
- height function $h:V\to\mathbb{N}$ は $h(s)=|V|,h(t)=0$ およびすべての残余辺 $(u,v)\in E_f$ に対し $h(u)\leq h(v)+1$ を満たすもの．

preflow を更新する push，height function を更新する relabel を組み合わせたアルゴリズム．

### push

以下の条件を満たす残余辺 $(u,v)$ についての操作．

- $h(u)=h(v)+1$
- $c_f(u,v)\gt 0$
- $e(u)\gt 0$

```
Push(u, v):
  df = min(e[u], c_f[u, v])
  if (u, v) in E:
    f[u, v] += df
  else:
    f[v, u] -= df
  e[u] -= df
  e[v] += df
```

push 後に $c_f(u,v)=0$ となる push を saturating push と呼ぶ．

### relabel

$e(u)\gt 0$ かつ $(u,\forall v)\in E_f,h(u)\leq h(v)$ なる $u$ に対する操作．

```
Relabel(u):
  h[u] = 1 + min(h[v] for (u, v) in E_f)
```

### 基本アルゴリズム

以下のアルゴリズムで最大フローが求められる．

```
GenericPushRelabel(G):
  for v in V:
    h[v] = 0
    e[v] = 0
  for (u, v) in E:
    f[u, v] = 0
  h(s) = |V|
  for v in G[s]:
    f[s, v] = c(s, v)
    e[v] = c(s, v)
    e[s] -= c(s, v)
  while (push または relabel ができる):
    (push または relabel を任意に選んで行う)
```

最大フローを返すこと，また停止して時間計算量が $O(|V|^2|E|)$ であることの証明は省略． 

### push/relabel の操作順

`GenericPushRelabel` では push/relabel を行う順序に自由度がある．

順序を適切に決めることで $O(|V|^3)$ 時間や $O(|V|^2\sqrt{|E|})$ 時間などになる．

## 資料

- Cormen, T.H., Leiserson, C.E., Rivest, R.L. and Stein, C. (2009) Introduction to Algorithms. The MIT Press. https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/
- [Push-Relabel による最大フローアルゴリズム - 宇宙ツイッタラーXの憂鬱](https://kenkoooo.hatenablog.com/entry/2016/12/22/143638)