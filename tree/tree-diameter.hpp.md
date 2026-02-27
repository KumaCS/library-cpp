---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/tree/LC_tree_diameter.test.cpp
    title: verify/tree/LC_tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/tree-diameter.md
    document_title: "\u6728\u306E\u76F4\u5F84"
    links: []
  bundledCode: "#line 2 \"tree/tree-diameter.hpp\"\n\ntemplate <class T>\npair<T,\
    \ vector<int>> TreeDiameter(const vector<vector<pair<int, T>>>& g) {\n  int n\
    \ = g.size();\n  assert(n > 0);\n  stack<pair<int, int>> st;\n  vector<T> d(n);\n\
    \  st.push({0, -1});\n  while (!st.empty()) {\n    auto [x, p] = st.top();\n \
    \   st.pop();\n    for (auto [y, w] : g[x]) {\n      if (y == p) continue;\n \
    \     d[y] = d[x] + w;\n      st.push({y, x});\n    }\n  }\n  int u = 0;\n  for\
    \ (int i = 1; i < n; i++)\n    if (d[i] > d[u]) u = i;\n  d[u] = T{};\n  st.push({u,\
    \ -1});\n  vector<int> prv(n, -1);\n  while (!st.empty()) {\n    auto [x, p] =\
    \ st.top();\n    st.pop();\n    for (auto [y, w] : g[x]) {\n      if (y == p)\
    \ continue;\n      prv[y] = x;\n      d[y] = d[x] + w;\n      st.push({y, x});\n\
    \    }\n  }\n  int v = 0;\n  for (int i = 1; i < n; i++)\n    if (d[i] > d[v])\
    \ v = i;\n  vector<int> path;\n  for (int x = v; x != -1; x = prv[x]) path.push_back(x);\n\
    \  return {d[v], path};\n}\npair<int, vector<int>> TreeDiameter(const vector<vector<int>>&\
    \ g) {\n  int n = g.size();\n  assert(n > 0);\n  stack<pair<int, int>> st;\n \
    \ vector<int> d(n);\n  st.push({0, -1});\n  while (!st.empty()) {\n    auto [x,\
    \ p] = st.top();\n    st.pop();\n    for (auto y : g[x]) {\n      if (y == p)\
    \ continue;\n      d[y] = d[x] + 1;\n      st.push({y, x});\n    }\n  }\n  int\
    \ u = 0;\n  for (int i = 1; i < n; i++)\n    if (d[i] > d[u]) u = i;\n  d[u] =\
    \ 0;\n  st.push({u, -1});\n  vector<int> prv(n, -1);\n  while (!st.empty()) {\n\
    \    auto [x, p] = st.top();\n    st.pop();\n    for (auto y : g[x]) {\n     \
    \ if (y == p) continue;\n      prv[y] = x;\n      d[y] = d[x] + 1;\n      st.push({y,\
    \ x});\n    }\n  }\n  int v = 0;\n  for (int i = 1; i < n; i++)\n    if (d[i]\
    \ > d[v]) v = i;\n  vector<int> path;\n  for (int x = v; x != -1; x = prv[x])\
    \ path.push_back(x);\n  return {d[v], path};\n}\n/**\n * @brief \u6728\u306E\u76F4\
    \u5F84\n * @docs docs/tree/tree-diameter.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\npair<T, vector<int>> TreeDiameter(const\
    \ vector<vector<pair<int, T>>>& g) {\n  int n = g.size();\n  assert(n > 0);\n\
    \  stack<pair<int, int>> st;\n  vector<T> d(n);\n  st.push({0, -1});\n  while\
    \ (!st.empty()) {\n    auto [x, p] = st.top();\n    st.pop();\n    for (auto [y,\
    \ w] : g[x]) {\n      if (y == p) continue;\n      d[y] = d[x] + w;\n      st.push({y,\
    \ x});\n    }\n  }\n  int u = 0;\n  for (int i = 1; i < n; i++)\n    if (d[i]\
    \ > d[u]) u = i;\n  d[u] = T{};\n  st.push({u, -1});\n  vector<int> prv(n, -1);\n\
    \  while (!st.empty()) {\n    auto [x, p] = st.top();\n    st.pop();\n    for\
    \ (auto [y, w] : g[x]) {\n      if (y == p) continue;\n      prv[y] = x;\n   \
    \   d[y] = d[x] + w;\n      st.push({y, x});\n    }\n  }\n  int v = 0;\n  for\
    \ (int i = 1; i < n; i++)\n    if (d[i] > d[v]) v = i;\n  vector<int> path;\n\
    \  for (int x = v; x != -1; x = prv[x]) path.push_back(x);\n  return {d[v], path};\n\
    }\npair<int, vector<int>> TreeDiameter(const vector<vector<int>>& g) {\n  int\
    \ n = g.size();\n  assert(n > 0);\n  stack<pair<int, int>> st;\n  vector<int>\
    \ d(n);\n  st.push({0, -1});\n  while (!st.empty()) {\n    auto [x, p] = st.top();\n\
    \    st.pop();\n    for (auto y : g[x]) {\n      if (y == p) continue;\n     \
    \ d[y] = d[x] + 1;\n      st.push({y, x});\n    }\n  }\n  int u = 0;\n  for (int\
    \ i = 1; i < n; i++)\n    if (d[i] > d[u]) u = i;\n  d[u] = 0;\n  st.push({u,\
    \ -1});\n  vector<int> prv(n, -1);\n  while (!st.empty()) {\n    auto [x, p] =\
    \ st.top();\n    st.pop();\n    for (auto y : g[x]) {\n      if (y == p) continue;\n\
    \      prv[y] = x;\n      d[y] = d[x] + 1;\n      st.push({y, x});\n    }\n  }\n\
    \  int v = 0;\n  for (int i = 1; i < n; i++)\n    if (d[i] > d[v]) v = i;\n  vector<int>\
    \ path;\n  for (int x = v; x != -1; x = prv[x]) path.push_back(x);\n  return {d[v],\
    \ path};\n}\n/**\n * @brief \u6728\u306E\u76F4\u5F84\n * @docs docs/tree/tree-diameter.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree-diameter.hpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/tree/LC_tree_diameter.test.cpp
documentation_of: tree/tree-diameter.hpp
layout: document
redirect_from:
- /library/tree/tree-diameter.hpp
- /library/tree/tree-diameter.hpp.html
title: "\u6728\u306E\u76F4\u5F84"
---
