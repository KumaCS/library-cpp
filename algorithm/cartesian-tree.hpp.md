---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/algorithm/LC_cartesian_tree.test.cpp
    title: verify/algorithm/LC_cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/cartesian-tree.hpp\"\n\n// min\n// (root, nodes)\n\
    // node: (parent, left, right)\ntemplate <class T>\npair<int, vector<array<int,\
    \ 3>>> CartesianTree(const vector<T>& v) {\n  int root = 0;\n  vector<array<int,\
    \ 3>> nodes(v.size(), {-1, -1, -1});\n  vector<int> st(v.size(), 0);\n  int top\
    \ = 0;\n  for (int i = 1; i < v.size(); ++i) {\n    if (v[st[top]] > v[i]) {\n\
    \      while (top >= 1 && v[st[top - 1]] > v[i]) --top;\n      nodes[nodes[i][1]\
    \ = st[top]][0] = i;\n      (top == 0 ? root : nodes[nodes[i][0] = st[top - 1]][2])\
    \ = i;\n      st[top] = i;\n    } else {\n      nodes[nodes[i][0] = st[top]][2]\
    \ = i;\n      st[++top] = i;\n    }\n  }\n  return {root, nodes};\n}\n"
  code: "#pragma once\n\n// min\n// (root, nodes)\n// node: (parent, left, right)\n\
    template <class T>\npair<int, vector<array<int, 3>>> CartesianTree(const vector<T>&\
    \ v) {\n  int root = 0;\n  vector<array<int, 3>> nodes(v.size(), {-1, -1, -1});\n\
    \  vector<int> st(v.size(), 0);\n  int top = 0;\n  for (int i = 1; i < v.size();\
    \ ++i) {\n    if (v[st[top]] > v[i]) {\n      while (top >= 1 && v[st[top - 1]]\
    \ > v[i]) --top;\n      nodes[nodes[i][1] = st[top]][0] = i;\n      (top == 0\
    \ ? root : nodes[nodes[i][0] = st[top - 1]][2]) = i;\n      st[top] = i;\n   \
    \ } else {\n      nodes[nodes[i][0] = st[top]][2] = i;\n      st[++top] = i;\n\
    \    }\n  }\n  return {root, nodes};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/cartesian-tree.hpp
  requiredBy: []
  timestamp: '2026-06-28 14:52:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/algorithm/LC_cartesian_tree.test.cpp
documentation_of: algorithm/cartesian-tree.hpp
layout: document
redirect_from:
- /library/algorithm/cartesian-tree.hpp
- /library/algorithm/cartesian-tree.hpp.html
title: algorithm/cartesian-tree.hpp
---
