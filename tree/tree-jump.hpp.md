---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/LC_jump_on_tree.test.cpp
    title: verify/tree/LC_jump_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/tree-jump.md
    document_title: Tree Jump
    links: []
  bundledCode: "#line 2 \"tree/tree-jump.hpp\"\n\nstruct TreeJump {\n  inline static\
    \ int topbit(int x) {\n    return (x == 0 ? -1 : 31 - __builtin_clz((unsigned\
    \ int)x));\n  }\n  int n;\n  vector<vector<int>> g;\n  vector<vector<int>> p;\n\
    \  vector<int> depth;\n  TreeJump(int size) : n(size), g(size), p(size), depth(size)\
    \ {}\n  TreeJump(const vector<vector<int>>& graph) : n(graph.size()), g(graph),\
    \ p(graph.size()), depth(graph.size()) {\n    build();\n  }\n  void add_edge(int\
    \ u, int v) {\n    g[u].push_back(v);\n    g[v].push_back(u);\n  }\n  void build()\
    \ {\n    stack<int> st;\n    st.push(0);\n    while (!st.empty()) {\n      int\
    \ x = st.top();\n      st.pop();\n      for (int k = 0; k < p[x].size(); k++)\
    \ {\n        int y = p[x][k];\n        if (k >= p[y].size()) break;\n        p[x].push_back(p[y][k]);\n\
    \      }\n      int par = p[x].empty() ? -1 : p[x][0];\n      for (auto y : g[x])\
    \ {\n        if (y == par) continue;\n        p[y].push_back(x);\n        depth[y]\
    \ = depth[x] + 1;\n        st.push(y);\n      }\n    }\n  }\n  int ancestor(int\
    \ x, int k = 1) {\n    assert(k >= 0);\n    if (depth[x] < k) return -1;\n   \
    \ while (k > 0) {\n      int l = topbit(k);\n      x = p[x][l];\n      k ^= 1\
    \ << l;\n    }\n    return x;\n  }\n  int lca(int x, int y) {\n    if (depth[x]\
    \ < depth[y]) y = ancestor(y, depth[y] - depth[x]);\n    if (depth[x] > depth[y])\
    \ x = ancestor(x, depth[x] - depth[y]);\n    if (x == y) return x;\n    for (int\
    \ l = topbit(depth[x]); l >= 0; l--) {\n      int ml = min((int)p[x].size(), (int)p[y].size())\
    \ - 1;\n      if (ml < l) l = ml;\n      int x1 = p[x][l];\n      int y1 = p[y][l];\n\
    \      if (x1 != y1) x = x1, y = y1;\n    }\n    return p[x][0];\n  }\n  int dist(int\
    \ x, int y) {\n    return depth[x] + depth[y] - depth[lca(x, y)] * 2;\n  }\n \
    \ int jump(int x, int y, int k = 1) {\n    assert(0 <= k);\n    int z = lca(x,\
    \ y);\n    int dx = depth[x] - depth[z];\n    int dy = depth[y] - depth[z];\n\
    \    if (k <= dx) return ancestor(x, k);\n    int d = dx + dy;\n    return k <=\
    \ d ? ancestor(y, d - k) : -1;\n  }\n};\n/**\n * @brief Tree Jump\n * @docs docs/tree/tree-jump.md\n\
    \ */\n"
  code: "#pragma once\n\nstruct TreeJump {\n  inline static int topbit(int x) {\n\
    \    return (x == 0 ? -1 : 31 - __builtin_clz((unsigned int)x));\n  }\n  int n;\n\
    \  vector<vector<int>> g;\n  vector<vector<int>> p;\n  vector<int> depth;\n  TreeJump(int\
    \ size) : n(size), g(size), p(size), depth(size) {}\n  TreeJump(const vector<vector<int>>&\
    \ graph) : n(graph.size()), g(graph), p(graph.size()), depth(graph.size()) {\n\
    \    build();\n  }\n  void add_edge(int u, int v) {\n    g[u].push_back(v);\n\
    \    g[v].push_back(u);\n  }\n  void build() {\n    stack<int> st;\n    st.push(0);\n\
    \    while (!st.empty()) {\n      int x = st.top();\n      st.pop();\n      for\
    \ (int k = 0; k < p[x].size(); k++) {\n        int y = p[x][k];\n        if (k\
    \ >= p[y].size()) break;\n        p[x].push_back(p[y][k]);\n      }\n      int\
    \ par = p[x].empty() ? -1 : p[x][0];\n      for (auto y : g[x]) {\n        if\
    \ (y == par) continue;\n        p[y].push_back(x);\n        depth[y] = depth[x]\
    \ + 1;\n        st.push(y);\n      }\n    }\n  }\n  int ancestor(int x, int k\
    \ = 1) {\n    assert(k >= 0);\n    if (depth[x] < k) return -1;\n    while (k\
    \ > 0) {\n      int l = topbit(k);\n      x = p[x][l];\n      k ^= 1 << l;\n \
    \   }\n    return x;\n  }\n  int lca(int x, int y) {\n    if (depth[x] < depth[y])\
    \ y = ancestor(y, depth[y] - depth[x]);\n    if (depth[x] > depth[y]) x = ancestor(x,\
    \ depth[x] - depth[y]);\n    if (x == y) return x;\n    for (int l = topbit(depth[x]);\
    \ l >= 0; l--) {\n      int ml = min((int)p[x].size(), (int)p[y].size()) - 1;\n\
    \      if (ml < l) l = ml;\n      int x1 = p[x][l];\n      int y1 = p[y][l];\n\
    \      if (x1 != y1) x = x1, y = y1;\n    }\n    return p[x][0];\n  }\n  int dist(int\
    \ x, int y) {\n    return depth[x] + depth[y] - depth[lca(x, y)] * 2;\n  }\n \
    \ int jump(int x, int y, int k = 1) {\n    assert(0 <= k);\n    int z = lca(x,\
    \ y);\n    int dx = depth[x] - depth[z];\n    int dy = depth[y] - depth[z];\n\
    \    if (k <= dx) return ancestor(x, k);\n    int d = dx + dy;\n    return k <=\
    \ d ? ancestor(y, d - k) : -1;\n  }\n};\n/**\n * @brief Tree Jump\n * @docs docs/tree/tree-jump.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree-jump.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:22:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/LC_jump_on_tree.test.cpp
documentation_of: tree/tree-jump.hpp
layout: document
redirect_from:
- /library/tree/tree-jump.hpp
- /library/tree/tree-jump.hpp.html
title: Tree Jump
---
根付き木上で ancestor, LCA, パス上の jump を処理するデータ構造．

木を与えて `build()` すると，doubling により祖先を管理する．
コンストラクタに隣接リストを渡した場合は自動で `build()` される．

- `add_edge(u, v)`：無向辺 $uv$ を追加する．
- `build()`：頂点 $0$ を根として前処理する．
- `ancestor(x, k)`：頂点 $x$ から $k$ 個親方向へ進んだ頂点を返す．存在しない場合は `-1` を返す．
- `lca(x, y)`：頂点 $x,y$ の LCA を返す．
- `dist(x, y)`：頂点 $x,y$ 間の距離を返す．
- `jump(x, y, k)`：$x$ から $y$ への単純パス上で，$x$ から $k$ 辺進んだ頂点を返す．存在しない場合は `-1` を返す．

前処理は $O(N\log N)$ 時間，クエリは $O(\log N)$ 時間．
