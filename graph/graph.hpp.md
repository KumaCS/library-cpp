---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.hpp\"\n\nstruct Graph {\n  int n;\n  vector<vector<int>>\
    \ g;\n  Graph() : Graph(0) {}\n  Graph(int size) : n(size), g(size) {}\n  void\
    \ add_edge(int x, int y) {\n    g[x].push_back(y);\n    g[y].push_back(x);\n \
    \ }\n  void add_edge_directed(int from, int to) {\n    g[from].push_back(to);\n\
    \  }\n};\n"
  code: "#pragma once\n\nstruct Graph {\n  int n;\n  vector<vector<int>> g;\n  Graph()\
    \ : Graph(0) {}\n  Graph(int size) : n(size), g(size) {}\n  void add_edge(int\
    \ x, int y) {\n    g[x].push_back(y);\n    g[y].push_back(x);\n  }\n  void add_edge_directed(int\
    \ from, int to) {\n    g[from].push_back(to);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:22:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
