---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/simple-queue.hpp
    title: data-structure/simple-queue.hpp
  - icon: ':heavy_check_mark:'
    path: flow/max-flow.hpp
    title: Max Flow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/flow/project-selection-problem.md
    document_title: Project Selection Problem
    links: []
  bundledCode: "#line 2 \"flow/project-selection-problem.hpp\"\n\n#line 2 \"flow/max-flow.hpp\"\
    \n\n#line 2 \"data-structure/simple-queue.hpp\"\n\ntemplate <class T>\nstruct\
    \ SimpleQueue {\n private:\n  vector<T> a;\n  int p;\n\n public:\n  SimpleQueue()\
    \ : p(0) {}\n  SimpleQueue(int n) : p(0) { a.reserve(n); }\n  void reserve(int\
    \ n) { a.reserve(n); }\n  int size() { return a.size() - p; }\n  bool empty()\
    \ { return a.size() == p; }\n  void push(const T& v) { a.push_back(v); }\n  T&\
    \ front() { return a[p]; }\n  void pop() { p++; }\n  void clear() {\n    a.clear();\n\
    \    p = 0;\n  }\n};\n#line 4 \"flow/max-flow.hpp\"\n\ntemplate <class Cap = long\
    \ long>\nstruct MaxFlow {\n public:\n  MaxFlow() : _n(0) {}\n  explicit MaxFlow(int\
    \ n) : _n(n), g(n) {}\n\n  int add_edge(int from, int to, Cap cap) {\n    assert(0\
    \ <= from && from < _n);\n    assert(0 <= to && to < _n);\n    assert(0 <= cap);\n\
    \    int m = int(pos.size());\n    pos.push_back({from, int(g[from].size())});\n\
    \    int from_id = int(g[from].size());\n    int to_id = int(g[to].size());\n\
    \    if (from == to) to_id++;\n    g[from].push_back(_edge{to, to_id, cap});\n\
    \    g[to].push_back(_edge{from, from_id, 0});\n    return m;\n  }\n\n  struct\
    \ edge {\n    int from, to;\n    Cap cap, flow;\n  };\n\n  edge get_edge(int i)\
    \ {\n    int m = int(pos.size());\n    assert(0 <= i && i < m);\n    auto _e =\
    \ g[pos[i].first][pos[i].second];\n    auto _re = g[_e.to][_e.rev];\n    return\
    \ edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};\n  }\n  vector<edge> edges()\
    \ {\n    int m = int(pos.size());\n    vector<edge> result;\n    for (int i =\
    \ 0; i < m; i++) {\n      result.push_back(get_edge(i));\n    }\n    return result;\n\
    \  }\n  void change_edge(int i, Cap new_cap, Cap new_flow) {\n    int m = int(pos.size());\n\
    \    assert(0 <= i && i < m);\n    assert(0 <= new_flow && new_flow <= new_cap);\n\
    \    auto& _e = g[pos[i].first][pos[i].second];\n    auto& _re = g[_e.to][_e.rev];\n\
    \    _e.cap = new_cap - new_flow;\n    _re.cap = new_flow;\n  }\n\n  Cap flow(int\
    \ s, int t) {\n    return flow(s, t, numeric_limits<Cap>::max());\n  }\n  Cap\
    \ flow(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n    assert(0\
    \ <= t && t < _n);\n    assert(s != t);\n\n    vector<int> level(_n), iter(_n);\n\
    \    SimpleQueue<int> que;\n\n    auto bfs = [&]() {\n      fill(level.begin(),\
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
    \ 4 \"flow/project-selection-problem.hpp\"\n\ntemplate <class Cap = long long>\n\
    struct ProjectSelectionProblem {\n  ProjectSelectionProblem() : ProjectSelectionProblem(numeric_limits<Cap>::max()\
    \ / 4) {}\n  explicit ProjectSelectionProblem(Cap inf) : n(2), sum(0), inf(inf)\
    \ {}\n\n  int add_project() { return n++; }\n  void ban0(int x) { add_edge(x,\
    \ 1, inf); }\n  void lose0(int x, Cap w) { add_edge(x, 1, w); }\n  void gain0(int\
    \ x, Cap w) {\n    sum += w;\n    add_edge(0, x, w);\n  }\n  void ban1(int x)\
    \ { add_edge(0, x, inf); }\n  void lose1(int x, Cap w) { add_edge(0, x, w); }\n\
    \  void gain1(int x, Cap w) {\n    sum += w;\n    add_edge(x, 1, w);\n  }\n  void\
    \ ban01(int x, int y) { add_edge(x, y, inf); }\n  void lose01(int x, int y, Cap\
    \ w) { add_edge(x, y, w); }\n  void gain_same(int x, int y, Cap w) {\n    sum\
    \ += w;\n    add_edge(x, y, w);\n    add_edge(y, x, w);\n  }\n  void lose_diff(int\
    \ x, int y, Cap w) {\n    add_edge(x, y, w);\n    add_edge(y, x, w);\n  }\n  void\
    \ ban_diff(int x, int y) {\n    add_edge(x, y, inf);\n    add_edge(y, x, inf);\n\
    \  }\n  void gain00(int x, int y, Cap w) {\n    sum += w;\n    int z = add_project();\n\
    \    add_edge(0, z, w);\n    add_edge(z, x, inf);\n    add_edge(z, y, inf);\n\
    \  }\n  void gain11(int x, int y, Cap w) {\n    sum += w;\n    int z = add_project();\n\
    \    add_edge(z, 1, w);\n    add_edge(x, z, inf);\n    add_edge(y, z, inf);\n\
    \  }\n  template <class Container>\n  void gain_all0(const Container& xs, Cap\
    \ w) {\n    sum += w;\n    int y = add_project();\n    add_edge(0, y, w);\n  \
    \  for (int x : xs) add_edge(y, x, inf);\n  }\n  template <class Container>\n\
    \  void gain_all1(const Container& xs, Cap w) {\n    sum += w;\n    int y = add_project();\n\
    \    add_edge(y, 1, w);\n    for (int x : xs) add_edge(x, y, inf);\n  }\n  Cap\
    \ solve() const {\n    MaxFlow<Cap> mf(n);\n    for (auto [from, to, cap] : _edges)\
    \ mf.add_edge(from, to, cap);\n    return sum - mf.flow(0, 1);\n  }\n\n private:\n\
    \  void add_edge(int from, int to, Cap cap) {\n    assert(0 <= from && from <\
    \ n);\n    assert(0 <= to && to < n);\n    assert(0 <= cap);\n    _edges.push_back({from,\
    \ to, cap});\n  }\n  int n;\n  Cap sum, inf;\n  vector<tuple<int, int, Cap>> _edges;\n\
    };\n\n/**\n * @brief Project Selection Problem\n * @docs docs/flow/project-selection-problem.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"flow/max-flow.hpp\"\n\ntemplate <class Cap = long\
    \ long>\nstruct ProjectSelectionProblem {\n  ProjectSelectionProblem() : ProjectSelectionProblem(numeric_limits<Cap>::max()\
    \ / 4) {}\n  explicit ProjectSelectionProblem(Cap inf) : n(2), sum(0), inf(inf)\
    \ {}\n\n  int add_project() { return n++; }\n  void ban0(int x) { add_edge(x,\
    \ 1, inf); }\n  void lose0(int x, Cap w) { add_edge(x, 1, w); }\n  void gain0(int\
    \ x, Cap w) {\n    sum += w;\n    add_edge(0, x, w);\n  }\n  void ban1(int x)\
    \ { add_edge(0, x, inf); }\n  void lose1(int x, Cap w) { add_edge(0, x, w); }\n\
    \  void gain1(int x, Cap w) {\n    sum += w;\n    add_edge(x, 1, w);\n  }\n  void\
    \ ban01(int x, int y) { add_edge(x, y, inf); }\n  void lose01(int x, int y, Cap\
    \ w) { add_edge(x, y, w); }\n  void gain_same(int x, int y, Cap w) {\n    sum\
    \ += w;\n    add_edge(x, y, w);\n    add_edge(y, x, w);\n  }\n  void lose_diff(int\
    \ x, int y, Cap w) {\n    add_edge(x, y, w);\n    add_edge(y, x, w);\n  }\n  void\
    \ ban_diff(int x, int y) {\n    add_edge(x, y, inf);\n    add_edge(y, x, inf);\n\
    \  }\n  void gain00(int x, int y, Cap w) {\n    sum += w;\n    int z = add_project();\n\
    \    add_edge(0, z, w);\n    add_edge(z, x, inf);\n    add_edge(z, y, inf);\n\
    \  }\n  void gain11(int x, int y, Cap w) {\n    sum += w;\n    int z = add_project();\n\
    \    add_edge(z, 1, w);\n    add_edge(x, z, inf);\n    add_edge(y, z, inf);\n\
    \  }\n  template <class Container>\n  void gain_all0(const Container& xs, Cap\
    \ w) {\n    sum += w;\n    int y = add_project();\n    add_edge(0, y, w);\n  \
    \  for (int x : xs) add_edge(y, x, inf);\n  }\n  template <class Container>\n\
    \  void gain_all1(const Container& xs, Cap w) {\n    sum += w;\n    int y = add_project();\n\
    \    add_edge(y, 1, w);\n    for (int x : xs) add_edge(x, y, inf);\n  }\n  Cap\
    \ solve() const {\n    MaxFlow<Cap> mf(n);\n    for (auto [from, to, cap] : _edges)\
    \ mf.add_edge(from, to, cap);\n    return sum - mf.flow(0, 1);\n  }\n\n private:\n\
    \  void add_edge(int from, int to, Cap cap) {\n    assert(0 <= from && from <\
    \ n);\n    assert(0 <= to && to < n);\n    assert(0 <= cap);\n    _edges.push_back({from,\
    \ to, cap});\n  }\n  int n;\n  Cap sum, inf;\n  vector<tuple<int, int, Cap>> _edges;\n\
    };\n\n/**\n * @brief Project Selection Problem\n * @docs docs/flow/project-selection-problem.md\n\
    \ */\n"
  dependsOn:
  - flow/max-flow.hpp
  - data-structure/simple-queue.hpp
  isVerificationFile: false
  path: flow/project-selection-problem.hpp
  requiredBy: []
  timestamp: '2026-06-30 02:52:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/project-selection-problem.hpp
layout: document
redirect_from:
- /library/flow/project-selection-problem.hpp
- /library/flow/project-selection-problem.hpp.html
title: Project Selection Problem
---
Project Selection Problem を最大流に帰着して解く．

- `add_project()`: 新しい project を追加し、その番号を返す．
- `solve()`: 最大利益を返す．毎回新規に最大流を解く．

扱える制約

- `gain0(x, w)`: `x = 0` のとき `w` を得る．
- `gain1(x, w)`: `x = 1` のとき `w` を得る．
- `lose0(x, w)`: `x = 0` のとき `w` を失う．
- `lose1(x, w)`: `x = 1` のとき `w` を失う．
- `ban0(x)`: `x = 0` を禁止する．
- `ban1(x)`: `x = 1` を禁止する．
- `gain_same(x, y, w)`: `x = y` のとき `w` を得る．
- `lose_diff(x, y, w)`: `x != y` のとき `w` を失う．
