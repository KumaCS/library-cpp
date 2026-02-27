---
data:
  _extendedDependsOn:
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
    _deprecated_at_docs: docs/tree/lca-auxiliary-tree.md
    document_title: "LCA \u30D9\u30FC\u30B9\u306E Auxiliary Tree"
    links: []
  bundledCode: "#line 2 \"data-structure/sparse-table.hpp\"\n\ntemplate <class T,\
    \ T (*op)(T, T)>\nstruct SparseTable {\n private:\n  int n;\n  vector<vector<T>>\
    \ st;\n\n public:\n  SparseTable() {}\n  SparseTable(const vector<T> &arr) {\n\
    \    n = arr.size();\n    int log = 1;\n    while (n >> log) log++;\n    st =\
    \ vector<vector<T>>(log);\n    st[0] = vector<T>(arr.begin(), arr.end());\n  \
    \  for (int k = 1; k < log; k++) {\n      auto stp = st[k - 1];\n      auto sti\
    \ = vector<T>(n - (1 << k) + 1);\n      for (int i = 0; i < sti.size(); i++)\n\
    \        sti[i] = op(stp[i], stp[i + (1 << (k - 1))]);\n      st[k] = sti;\n \
    \   }\n  }\n  T prod(int l, int r)  // [l,r)\n  {\n    assert(0 <= l && l < r\
    \ && r <= n);\n    int j = 0;\n    while ((2 << j) <= r - l) j++;\n    return\
    \ op(st[j][l], st[j][r - (1 << j)]);\n  }\n};\n#line 3 \"tree/lowest-common-ancestor.hpp\"\
    \n\nstruct LowestCommonAncestor {\n  using P = pair<int, int>;\n  static P lca_st_op(P\
    \ x, P y) { return x.second <= y.second ? x : y; }\n\n protected:\n  int n, r;\n\
    \  vector<vector<int>> g;\n  SparseTable<P, lca_st_op> st;\n  vector<int> in_time,\
    \ depth, parent, euler_tour;\n\n public:\n  const int size() { return n; }\n \
    \ const int root() { return r; }\n  LowestCommonAncestor() {}\n  LowestCommonAncestor(int\
    \ size, int root = 0) : n(size), r(root), g(n) {}\n  LowestCommonAncestor(const\
    \ vector<vector<int>>& graph, int root = 0) : n(graph.size()), r(root), g(graph)\
    \ {\n    build();\n  }\n  void add_edge(int u, int v) {\n    g[u].push_back(v);\n\
    \    g[v].push_back(u);\n  }\n  void build() {\n    parent.resize(n, -1);\n  \
    \  depth.resize(n, 0);\n    in_time.resize(n, 0);\n    euler_tour.reserve(2 *\
    \ n - 1);\n    {\n      stack<int> st;\n      st.push(r);\n      vector<int> idx(n);\n\
    \      while (!st.empty()) {\n        int x = st.top();\n        st.pop();\n \
    \       if (idx[x] == 0) in_time[x] = euler_tour.size();\n        euler_tour.push_back(x);\n\
    \        if (idx[x] < g[x].size()) {\n          st.push(x);\n          int y =\
    \ g[x][idx[x]++];\n          if (y != parent[x]) {\n            parent[y] = x;\n\
    \            depth[y] = depth[x] + 1;\n            st.push(y);\n          }\n\
    \        }\n      }\n    }\n    vector<P> data;\n    data.reserve(euler_tour.size());\n\
    \    for (auto v : euler_tour)\n      data.push_back({v, depth[v]});\n    st =\
    \ SparseTable<P, lca_st_op>(data);\n  }\n  int lca(int u, int v) {\n    assert(0\
    \ <= u && u < n);\n    assert(0 <= v && v < n);\n    int x = in_time[u], y = in_time[v];\n\
    \    if (x > y) swap(x, y);\n    return st.prod(x, y + 1).first;\n  }\n};\n/**\n\
    \ * @brief Lowest Common Ancestor\n * @docs docs/tree/lowest-common-ancestor.md\n\
    \ */\n#line 3 \"tree/lca-auxiliary-tree.hpp\"\n\nstruct LCAAuxiliaryTree : LowestCommonAncestor\
    \ {\n  using base = LowestCommonAncestor;\n  LCAAuxiliaryTree(int size, int root\
    \ = 0) : base(size, root) {}\n  LCAAuxiliaryTree(vector<vector<int>>& graph, int\
    \ root = 0) : base(graph, root) {}\n  pair<int, vector<int>> calc(vector<int>\
    \ vs, vector<vector<int>>& g) {\n    if (vs.empty()) return {-1, vector<int>{}};\n\
    \    int n = vs.size();\n    sort(vs.begin(), vs.end(), [&](int x, int y) { return\
    \ in_time[x] < in_time[y]; });\n    stack<int> st;\n    st.push(vs[0]);\n    g[vs[0]]\
    \ = {};\n    for (int i = 0; i < n - 1; i++) {\n      int x = vs[i], y = vs[i\
    \ + 1];\n      int w = lca(x, y);\n      if (w != x) {\n        int last = st.top();\n\
    \        st.pop();\n        while (!st.empty() && depth[w] < depth[st.top()])\
    \ {\n          g[st.top()].push_back(last);\n          last = st.top();\n    \
    \      st.pop();\n        }\n        if (st.empty() || st.top() != w) {\n    \
    \      st.push(w);\n          vs.push_back(w);\n          g[w] = {last};\n   \
    \     } else\n          g[w].push_back(last);\n      }\n      st.push(y);\n  \
    \    g[y] = {};\n    }\n    int prv = st.top();\n    st.pop();\n    while (!st.empty())\
    \ {\n      g[st.top()].push_back(prv);\n      prv = st.top();\n      st.pop();\n\
    \    }\n    sort(vs.begin(), vs.end(), [&](int x, int y) { return in_time[x] <\
    \ in_time[y]; });\n    return {prv, vs};\n  }\n};\n/**\n * @brief LCA \u30D9\u30FC\
    \u30B9\u306E Auxiliary Tree\n * @docs docs/tree/lca-auxiliary-tree.md\n */\n"
  code: "#pragma once\n#include \"tree/lowest-common-ancestor.hpp\"\n\nstruct LCAAuxiliaryTree\
    \ : LowestCommonAncestor {\n  using base = LowestCommonAncestor;\n  LCAAuxiliaryTree(int\
    \ size, int root = 0) : base(size, root) {}\n  LCAAuxiliaryTree(vector<vector<int>>&\
    \ graph, int root = 0) : base(graph, root) {}\n  pair<int, vector<int>> calc(vector<int>\
    \ vs, vector<vector<int>>& g) {\n    if (vs.empty()) return {-1, vector<int>{}};\n\
    \    int n = vs.size();\n    sort(vs.begin(), vs.end(), [&](int x, int y) { return\
    \ in_time[x] < in_time[y]; });\n    stack<int> st;\n    st.push(vs[0]);\n    g[vs[0]]\
    \ = {};\n    for (int i = 0; i < n - 1; i++) {\n      int x = vs[i], y = vs[i\
    \ + 1];\n      int w = lca(x, y);\n      if (w != x) {\n        int last = st.top();\n\
    \        st.pop();\n        while (!st.empty() && depth[w] < depth[st.top()])\
    \ {\n          g[st.top()].push_back(last);\n          last = st.top();\n    \
    \      st.pop();\n        }\n        if (st.empty() || st.top() != w) {\n    \
    \      st.push(w);\n          vs.push_back(w);\n          g[w] = {last};\n   \
    \     } else\n          g[w].push_back(last);\n      }\n      st.push(y);\n  \
    \    g[y] = {};\n    }\n    int prv = st.top();\n    st.pop();\n    while (!st.empty())\
    \ {\n      g[st.top()].push_back(prv);\n      prv = st.top();\n      st.pop();\n\
    \    }\n    sort(vs.begin(), vs.end(), [&](int x, int y) { return in_time[x] <\
    \ in_time[y]; });\n    return {prv, vs};\n  }\n};\n/**\n * @brief LCA \u30D9\u30FC\
    \u30B9\u306E Auxiliary Tree\n * @docs docs/tree/lca-auxiliary-tree.md\n */"
  dependsOn:
  - tree/lowest-common-ancestor.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: tree/lca-auxiliary-tree.hpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/lca-auxiliary-tree.hpp
layout: document
redirect_from:
- /library/tree/lca-auxiliary-tree.hpp
- /library/tree/lca-auxiliary-tree.hpp.html
title: "LCA \u30D9\u30FC\u30B9\u306E Auxiliary Tree"
---
