---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/max-flow.hpp
    title: Max Flow
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/UNIT_simple_queue.test.cpp
    title: verify/data-structure/UNIT_simple_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/flow/AOJ_GRL_6_A.test.cpp
    title: verify/flow/AOJ_GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/simple-queue.hpp\"\n\ntemplate <class T>\n\
    struct SimpleQueue {\n private:\n  vector<T> a;\n  int p;\n\n public:\n  SimpleQueue()\
    \ : p(0) {}\n  SimpleQueue(int n) : p(0) { a.reserve(n); }\n  void reserve(int\
    \ n) { a.reserve(n); }\n  int size() { return a.size() - p; }\n  bool empty()\
    \ { return a.size() == p; }\n  void push(const T& v) { a.push_back(v); }\n  T&\
    \ front() { return a[p]; }\n  void pop() { p++; }\n  void clear() {\n    a.clear();\n\
    \    p = 0;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct SimpleQueue {\n private:\n  vector<T>\
    \ a;\n  int p;\n\n public:\n  SimpleQueue() : p(0) {}\n  SimpleQueue(int n) :\
    \ p(0) { a.reserve(n); }\n  void reserve(int n) { a.reserve(n); }\n  int size()\
    \ { return a.size() - p; }\n  bool empty() { return a.size() == p; }\n  void push(const\
    \ T& v) { a.push_back(v); }\n  T& front() { return a[p]; }\n  void pop() { p++;\
    \ }\n  void clear() {\n    a.clear();\n    p = 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/simple-queue.hpp
  requiredBy:
  - flow/max-flow.hpp
  timestamp: '2026-06-28 19:44:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/UNIT_simple_queue.test.cpp
  - verify/flow/AOJ_GRL_6_A.test.cpp
documentation_of: data-structure/simple-queue.hpp
layout: document
redirect_from:
- /library/data-structure/simple-queue.hpp
- /library/data-structure/simple-queue.hpp.html
title: data-structure/simple-queue.hpp
---
