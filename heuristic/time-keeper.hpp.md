---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: heuristic/beam-search.hpp
    title: Beam Search
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"heuristic/time-keeper.hpp\"\n\nclass TimeKeeper {\n private:\n\
    \  chrono::high_resolution_clock::time_point start_time_;\n  int time_threshold_;\n\
    \n public:\n  TimeKeeper(int time_threshold) : start_time_(chrono::high_resolution_clock::now()),\
    \ time_threshold_(time_threshold) {}\n  bool is_time_over() const {\n    auto\
    \ diff = chrono::high_resolution_clock::now() - this->start_time_;\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(diff).count() >= time_threshold_;\n\
    \  }\n};\n"
  code: "#pragma once\n\nclass TimeKeeper {\n private:\n  chrono::high_resolution_clock::time_point\
    \ start_time_;\n  int time_threshold_;\n\n public:\n  TimeKeeper(int time_threshold)\
    \ : start_time_(chrono::high_resolution_clock::now()), time_threshold_(time_threshold)\
    \ {}\n  bool is_time_over() const {\n    auto diff = chrono::high_resolution_clock::now()\
    \ - this->start_time_;\n    return chrono::duration_cast<chrono::milliseconds>(diff).count()\
    \ >= time_threshold_;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: heuristic/time-keeper.hpp
  requiredBy:
  - heuristic/beam-search.hpp
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heuristic/time-keeper.hpp
layout: document
redirect_from:
- /library/heuristic/time-keeper.hpp
- /library/heuristic/time-keeper.hpp.html
title: heuristic/time-keeper.hpp
---
