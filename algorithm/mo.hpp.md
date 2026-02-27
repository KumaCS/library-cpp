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
  bundledCode: "#line 2 \"algorithm/mo.hpp\"\n\nstruct Mo {\n  using F = function<void(int)>;\n\
    \  int n;\n  vector<int> left, right;\n  Mo(int size) : n(size) {}\n  void add_query(int\
    \ l, int r) {  // [l,r)\n    left.emplace_back(l);\n    right.emplace_back(r);\n\
    \  }\n  void run(const F& add_left, const F& add_right, const F& del_left, const\
    \ F& del_right, const F& query) {\n    const int q = left.size();\n    if (q ==\
    \ 0) return;\n    const int width = max(1, (int)(n / sqrt(q)));\n    vector<int>\
    \ order(q);\n    iota(order.begin(), order.end(), 0);\n    sort(order.begin(),\
    \ order.end(), [&](int i, int j) {\n      if (left[i] / width != left[j] / width)\
    \ return left[i] < left[j];\n      return right[i] < right[j];\n    });\n    int\
    \ l = 0, r = 0;\n    for (int i : order) {\n      while (l > left[i]) add_left(--l);\n\
    \      while (r < right[i]) add_right(r++);\n      while (l < left[i]) del_left(l++);\n\
    \      while (r > right[i]) del_right(--r);\n      query(i);\n    }\n  }\n  void\
    \ run(const F& add, const F& del, const F& query) {\n    run(add, add, del, del,\
    \ query);\n  }\n};\n"
  code: "#pragma once\n\nstruct Mo {\n  using F = function<void(int)>;\n  int n;\n\
    \  vector<int> left, right;\n  Mo(int size) : n(size) {}\n  void add_query(int\
    \ l, int r) {  // [l,r)\n    left.emplace_back(l);\n    right.emplace_back(r);\n\
    \  }\n  void run(const F& add_left, const F& add_right, const F& del_left, const\
    \ F& del_right, const F& query) {\n    const int q = left.size();\n    if (q ==\
    \ 0) return;\n    const int width = max(1, (int)(n / sqrt(q)));\n    vector<int>\
    \ order(q);\n    iota(order.begin(), order.end(), 0);\n    sort(order.begin(),\
    \ order.end(), [&](int i, int j) {\n      if (left[i] / width != left[j] / width)\
    \ return left[i] < left[j];\n      return right[i] < right[j];\n    });\n    int\
    \ l = 0, r = 0;\n    for (int i : order) {\n      while (l > left[i]) add_left(--l);\n\
    \      while (r < right[i]) add_right(r++);\n      while (l < left[i]) del_left(l++);\n\
    \      while (r > right[i]) del_right(--r);\n      query(i);\n    }\n  }\n  void\
    \ run(const F& add, const F& del, const F& query) {\n    run(add, add, del, del,\
    \ query);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/mo.hpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/mo.hpp
layout: document
redirect_from:
- /library/algorithm/mo.hpp
- /library/algorithm/mo.hpp.html
title: algorithm/mo.hpp
---
