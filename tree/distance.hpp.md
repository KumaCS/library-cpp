---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/magma.hpp
    title: algebraic-structure/magma.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/util.hpp
    title: algebraic-structure/util.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: tree/lowest-common-ancestor.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/tree/distance.md
    document_title: "\u6728\u4E0A\u306E\u8DDD\u96E2"
    links: []
  bundledCode: "#line 2 \"algebraic-structure/util.hpp\"\n#ifdef __cpp_concepts\n\
    #define REQUIRES(...) requires __VA_ARGS__\n#else\n#define REQUIRES(...)\n#endif\n\
    #line 3 \"algebraic-structure/magma.hpp\"\n\n#ifdef __cpp_concepts\ntemplate <class\
    \ M>\nconcept Magma = requires(typename M::value_type x, typename M::value_type\
    \ y) {\n  typename M::value_type;\n  { M::op(x, y) } -> same_as<typename M::value_type>;\n\
    };\n#endif\n\ntemplate <class T>\nstruct AddMagma {\n  using value_type = T;\n\
    \  static T op(T x, T y) { return x + y; }\n};\ntemplate <class T>\nstruct MulMagma\
    \ {\n  using value_type = T;\n  static T op(T x, T y) { return x * y; }\n};\n\
    template <class T, T id>\nstruct MaxMagma {\n  using value_type = T;\n  static\
    \ T op(T x, T y) { return x > y ? x : y; }\n};\ntemplate <class T, T id>\nstruct\
    \ MinMagma {\n  using value_type = T;\n  static T op(T x, T y) { return x < y\
    \ ? x : y; }\n};\n#line 3 \"data-structure/sparse-table.hpp\"\n\ntemplate <class\
    \ M>\nREQUIRES(Magma<M>)\nstruct SparseTable {\n  using T = typename M::value_type;\n\
    \n private:\n  int n;\n  vector<vector<T>> st;\n\n public:\n  SparseTable() {}\n\
    \  SparseTable(const vector<T> &arr) {\n    n = arr.size();\n    int log = 1;\n\
    \    while (n >> log) log++;\n    st = vector<vector<T>>(log);\n    st[0] = vector<T>(arr.begin(),\
    \ arr.end());\n    for (int k = 1; k < log; k++) {\n      auto stp = st[k - 1];\n\
    \      auto sti = vector<T>(n - (1 << k) + 1);\n      for (int i = 0; i < (int)sti.size();\
    \ i++)\n        sti[i] = M::op(stp[i], stp[i + (1 << (k - 1))]);\n      st[k]\
    \ = sti;\n    }\n  }\n  T prod(int l, int r)  // [l,r)\n  {\n    assert(0 <= l\
    \ && l < r && r <= n);\n    int j = 0;\n    while ((2 << j) <= r - l) j++;\n \
    \   return M::op(st[j][l], st[j][r - (1 << j)]);\n  }\n};\n#line 3 \"tree/lowest-common-ancestor.hpp\"\
    \n\nstruct LowestCommonAncestor {\n  using P = pair<int, int>;\n  struct LcaMagma\
    \ {\n    using value_type = P;\n    static P op(P x, P y) { return x.second <=\
    \ y.second ? x : y; }\n  };\n\n protected:\n  int n, r;\n  vector<vector<int>>\
    \ g;\n  SparseTable<LcaMagma> st;\n  vector<int> in_time, depth, parent, euler_tour;\n\
    \n public:\n  const int size() { return n; }\n  const int root() { return r; }\n\
    \  LowestCommonAncestor() {}\n  LowestCommonAncestor(int size, int root = 0) :\
    \ n(size), r(root), g(n) {}\n  LowestCommonAncestor(const vector<vector<int>>&\
    \ graph, int root = 0) : n(graph.size()), r(root), g(graph) {\n    build();\n\
    \  }\n  void add_edge(int u, int v) {\n    g[u].push_back(v);\n    g[v].push_back(u);\n\
    \  }\n  void build() {\n    parent.resize(n, -1);\n    depth.resize(n, 0);\n \
    \   in_time.resize(n, 0);\n    euler_tour.reserve(2 * n - 1);\n    {\n      stack<int>\
    \ st;\n      st.push(r);\n      vector<int> idx(n);\n      while (!st.empty())\
    \ {\n        int x = st.top();\n        st.pop();\n        if (idx[x] == 0) in_time[x]\
    \ = euler_tour.size();\n        euler_tour.push_back(x);\n        if (idx[x] <\
    \ g[x].size()) {\n          st.push(x);\n          int y = g[x][idx[x]++];\n \
    \         if (y != parent[x]) {\n            parent[y] = x;\n            depth[y]\
    \ = depth[x] + 1;\n            st.push(y);\n          }\n        }\n      }\n\
    \    }\n    vector<P> data;\n    data.reserve(euler_tour.size());\n    for (auto\
    \ v : euler_tour)\n      data.push_back({v, depth[v]});\n    st = SparseTable<LcaMagma>(data);\n\
    \  }\n  int lca(int u, int v) {\n    assert(0 <= u && u < n);\n    assert(0 <=\
    \ v && v < n);\n    int x = in_time[u], y = in_time[v];\n    if (x > y) swap(x,\
    \ y);\n    return st.prod(x, y + 1).first;\n  }\n};\n/**\n * @brief Lowest Common\
    \ Ancestor\n * @docs docs/tree/lowest-common-ancestor.md\n */\n#line 3 \"tree/distance.hpp\"\
    \n\ntemplate <class T>\nstruct TreeDistance {\n private:\n  int n;\n  vector<vector<pair<int,\
    \ T>>> g;\n  LowestCommonAncestor lca;\n  vector<T> d;\n  void dfs(int x, int\
    \ p) {\n    for (auto [y, w] : g[x]) {\n      if (y == p) continue;\n      d[y]\
    \ = d[x] + w;\n      dfs(y, x);\n    }\n  }\n\n public:\n  const int size() {\
    \ return n; }\n  TreeDistance() {}\n  TreeDistance(int size) : n(size), g(n) {}\n\
    \  TreeDistance(const vector<vector<int>>& graph) : n(graph.size()), g(n) {\n\
    \    for (int x = 0; x < n; x++)\n      for (auto y : graph[x])\n        g[x].push_back({y,\
    \ (T)1});\n    build();\n  }\n  TreeDistance(const vector<vector<pair<int, T>>>&\
    \ graph) : n(graph.size()), g(graph) {\n    build();\n  }\n  void add_edge(int\
    \ u, int v, T w) {\n    g[u].push_back({v, w});\n    g[v].push_back({u, w});\n\
    \  }\n  void build() {\n    lca = LowestCommonAncestor(n, 0);\n    for (int u\
    \ = 0; u < n; u++)\n      for (auto [v, _] : g[u])\n        if (u < v) lca.add_edge(u,\
    \ v);\n    lca.build();\n    d = vector<T>(n);\n    dfs(0, -1);\n  }\n  int dist(int\
    \ u, int v) {\n    assert(0 <= u && u < n);\n    assert(0 <= v && v < n);\n  \
    \  return d[u] + d[v] - 2 * d[lca.lca(u, v)];\n  }\n};\n/**\n * @brief \u6728\u4E0A\
    \u306E\u8DDD\u96E2\n * @docs docs/tree/distance.md\n */\n"
  code: "#pragma once\n#include \"tree/lowest-common-ancestor.hpp\"\n\ntemplate <class\
    \ T>\nstruct TreeDistance {\n private:\n  int n;\n  vector<vector<pair<int, T>>>\
    \ g;\n  LowestCommonAncestor lca;\n  vector<T> d;\n  void dfs(int x, int p) {\n\
    \    for (auto [y, w] : g[x]) {\n      if (y == p) continue;\n      d[y] = d[x]\
    \ + w;\n      dfs(y, x);\n    }\n  }\n\n public:\n  const int size() { return\
    \ n; }\n  TreeDistance() {}\n  TreeDistance(int size) : n(size), g(n) {}\n  TreeDistance(const\
    \ vector<vector<int>>& graph) : n(graph.size()), g(n) {\n    for (int x = 0; x\
    \ < n; x++)\n      for (auto y : graph[x])\n        g[x].push_back({y, (T)1});\n\
    \    build();\n  }\n  TreeDistance(const vector<vector<pair<int, T>>>& graph)\
    \ : n(graph.size()), g(graph) {\n    build();\n  }\n  void add_edge(int u, int\
    \ v, T w) {\n    g[u].push_back({v, w});\n    g[v].push_back({u, w});\n  }\n \
    \ void build() {\n    lca = LowestCommonAncestor(n, 0);\n    for (int u = 0; u\
    \ < n; u++)\n      for (auto [v, _] : g[u])\n        if (u < v) lca.add_edge(u,\
    \ v);\n    lca.build();\n    d = vector<T>(n);\n    dfs(0, -1);\n  }\n  int dist(int\
    \ u, int v) {\n    assert(0 <= u && u < n);\n    assert(0 <= v && v < n);\n  \
    \  return d[u] + d[v] - 2 * d[lca.lca(u, v)];\n  }\n};\n/**\n * @brief \u6728\u4E0A\
    \u306E\u8DDD\u96E2\n * @docs docs/tree/distance.md\n */"
  dependsOn:
  - tree/lowest-common-ancestor.hpp
  - data-structure/sparse-table.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: tree/distance.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:41:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/distance.hpp
layout: document
redirect_from:
- /library/tree/distance.hpp
- /library/tree/distance.hpp.html
title: "\u6728\u4E0A\u306E\u8DDD\u96E2"
---
木上の距離を求めるデータ構造．

辺重み付きまたは重みなしの木を管理し，LCA を用いて 2 頂点間の距離を計算する．
重みなしの隣接リストを渡した場合は各辺の重みを $1$ として扱う．

- `add_edge(u, v, w)`：重み $w$ の無向辺 $uv$ を追加する．
- `build()`：頂点 $0$ を根として前処理する．
- `dist(u, v)`：頂点 $u,v$ 間の距離を返す．

コンストラクタに隣接リストを渡した場合は自動で `build()` される．
前処理は LCA の前処理時間，クエリは LCA 1 回分の時間．
