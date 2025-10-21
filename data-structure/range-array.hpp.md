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
  bundledCode: "#line 2 \"data-structure/range-array.hpp\"\n\n// \u533A\u9593\u306B\
    \u5024\u3092\u5BFE\u5FDC\u3065\u3051\u308B\n// range set point get + enumerate\n\
    template <class T>\nstruct RangeArray {\n private:\n  int n;\n  set<int> s;\n\
    \  vector<T> data;\n  T e;\n\n public:\n  RangeArray(int size, T e) : n(size),\
    \ e(e) {\n    s.insert(0);\n    s.insert(n);\n    data = vector<T>(n, e);\n  }\n\
    \  T get(int x) {\n    auto it = s.lower_bound(x + 1);\n    it--;\n    return\
    \ data[*it];\n  }\n  vector<pair<int, int>> enumerate_intersect(int l, int r)\
    \ {\n    vector<pair<int, int>> ret;\n    auto it = s.lower_bound(l + 1);\n  \
    \  it--;\n    while (it != s.end()) {\n      int l1 = *it;\n      if (r <= l1)\
    \ break;\n      it++;\n      int r1 = *it;\n      ret.push_back({l1, r1});\n \
    \   }\n    return ret;\n  }\n  void set(int l, int r, T v) {\n    for (auto it\
    \ = s.lower_bound(l); it != s.end();) {\n      int l1 = *it;\n      if (r <= l1)\
    \ break;\n      it++;\n      int r1 = *it;\n      it--;\n      it = s.erase(it);\n\
    \      if (r < r1) {\n        s.insert(r);\n        data[r] = data[l1];\n    \
    \    break;\n      }\n    }\n    s.insert(l);\n    data[l] = v;\n  }\n};\n"
  code: "#pragma once\n\n// \u533A\u9593\u306B\u5024\u3092\u5BFE\u5FDC\u3065\u3051\
    \u308B\n// range set point get + enumerate\ntemplate <class T>\nstruct RangeArray\
    \ {\n private:\n  int n;\n  set<int> s;\n  vector<T> data;\n  T e;\n\n public:\n\
    \  RangeArray(int size, T e) : n(size), e(e) {\n    s.insert(0);\n    s.insert(n);\n\
    \    data = vector<T>(n, e);\n  }\n  T get(int x) {\n    auto it = s.lower_bound(x\
    \ + 1);\n    it--;\n    return data[*it];\n  }\n  vector<pair<int, int>> enumerate_intersect(int\
    \ l, int r) {\n    vector<pair<int, int>> ret;\n    auto it = s.lower_bound(l\
    \ + 1);\n    it--;\n    while (it != s.end()) {\n      int l1 = *it;\n      if\
    \ (r <= l1) break;\n      it++;\n      int r1 = *it;\n      ret.push_back({l1,\
    \ r1});\n    }\n    return ret;\n  }\n  void set(int l, int r, T v) {\n    for\
    \ (auto it = s.lower_bound(l); it != s.end();) {\n      int l1 = *it;\n      if\
    \ (r <= l1) break;\n      it++;\n      int r1 = *it;\n      it--;\n      it =\
    \ s.erase(it);\n      if (r < r1) {\n        s.insert(r);\n        data[r] = data[l1];\n\
    \        break;\n      }\n    }\n    s.insert(l);\n    data[l] = v;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range-array.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/range-array.hpp
layout: document
redirect_from:
- /library/data-structure/range-array.hpp
- /library/data-structure/range-array.hpp.html
title: data-structure/range-array.hpp
---
