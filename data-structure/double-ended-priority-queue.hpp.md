---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/LC_double_ended_priority_queue.test.cpp
    title: verify/data-structure/LC_double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/double-ended-priority-queue.md
    document_title: Double Ended Priority Queue
    links: []
  bundledCode: "#line 2 \"data-structure/double-ended-priority-queue.hpp\"\n\ntemplate\
    \ <class T>\nstruct DoubleEndedPriorityQueue {\n  vector<T> d;\n  DoubleEndedPriorityQueue()\
    \ {}\n  DoubleEndedPriorityQueue(const vector<T>& _d) : d(_d) { make_heap(); }\n\
    \  template <class Iter>\n  DoubleEndedPriorityQueue(Iter first, Iter last) :\
    \ d(first, last) { make_heap(); }\n\n  int size() const { return d.size(); }\n\
    \  bool empty() const { return d.empty(); }\n  void push(const T& x) { d.push_back(x),\
    \ up(d.size() - 1); }\n  void pop_min() {\n    if (d.size() <= 2u)\n      d.pop_back();\n\
    \    else {\n      swap(d[1], d.back());\n      d.pop_back();\n      up(down(1));\n\
    \    }\n  }\n  void pop_max() {\n    if (d.size() <= 1u)\n      d.pop_back();\n\
    \    else {\n      swap(d[0], d.back());\n      d.pop_back();\n      up(down(0));\n\
    \    }\n  }\n  const T& get_min() const { return d.size() <= 1u ? d[0] : d[1];\
    \ }\n  const T& get_max() const { return d[0]; }\n\n private:\n  void make_heap()\
    \ {\n    for (int i = d.size() - 1; i >= 0; i--) {\n      if ((i & 1) && d[i -\
    \ 1] < d[i]) swap(d[i - 1], d[i]);\n      up(down(i), i);\n    }\n  }\n  inline\
    \ int parent(int k) const { return ((k >> 1) - 1) & ~1; }\n  int down(int k) {\n\
    \    int n = d.size();\n    if (k & 1) {  // min heap\n      while (2 * k + 1\
    \ < n) {\n        int c = 2 * k + 1;\n        if (c + 2 < n && d[c] > d[c + 2])\
    \ c += 2;\n        if (d[k] > d[c])\n          swap(d[k], d[c]), k = c;\n    \
    \    else\n          break;\n      }\n    } else {  // max heap\n      while (2\
    \ * k + 2 < n) {\n        int c = 2 * k + 2;\n        if (c + 2 < n && d[c] <\
    \ d[c + 2]) c += 2;\n        if (d[k] < d[c])\n          swap(d[k], d[c]), k =\
    \ c;\n        else\n          break;\n      }\n    }\n    return k;\n  }\n  int\
    \ up(int k, int root = 1) {\n    if ((k | 1) < (int)d.size() && d[k & ~1] < d[k\
    \ | 1]) swap(d[k & ~1], d[k | 1]), k ^= 1;\n    int p;\n    while (root < k &&\
    \ d[p = parent(k)] < d[k]) swap(d[p], d[k]), k = p;        // max heap\n    while\
    \ (root < k && d[k] < d[p = (parent(k) | 1)]) swap(d[p], d[k]), k = p;  // min\
    \ heap\n    return k;\n  }\n};\n\n/**\n * @brief Double Ended Priority Queue\n\
    \ * @docs docs/data-structure/double-ended-priority-queue.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct DoubleEndedPriorityQueue {\n \
    \ vector<T> d;\n  DoubleEndedPriorityQueue() {}\n  DoubleEndedPriorityQueue(const\
    \ vector<T>& _d) : d(_d) { make_heap(); }\n  template <class Iter>\n  DoubleEndedPriorityQueue(Iter\
    \ first, Iter last) : d(first, last) { make_heap(); }\n\n  int size() const {\
    \ return d.size(); }\n  bool empty() const { return d.empty(); }\n  void push(const\
    \ T& x) { d.push_back(x), up(d.size() - 1); }\n  void pop_min() {\n    if (d.size()\
    \ <= 2u)\n      d.pop_back();\n    else {\n      swap(d[1], d.back());\n     \
    \ d.pop_back();\n      up(down(1));\n    }\n  }\n  void pop_max() {\n    if (d.size()\
    \ <= 1u)\n      d.pop_back();\n    else {\n      swap(d[0], d.back());\n     \
    \ d.pop_back();\n      up(down(0));\n    }\n  }\n  const T& get_min() const {\
    \ return d.size() <= 1u ? d[0] : d[1]; }\n  const T& get_max() const { return\
    \ d[0]; }\n\n private:\n  void make_heap() {\n    for (int i = d.size() - 1; i\
    \ >= 0; i--) {\n      if ((i & 1) && d[i - 1] < d[i]) swap(d[i - 1], d[i]);\n\
    \      up(down(i), i);\n    }\n  }\n  inline int parent(int k) const { return\
    \ ((k >> 1) - 1) & ~1; }\n  int down(int k) {\n    int n = d.size();\n    if (k\
    \ & 1) {  // min heap\n      while (2 * k + 1 < n) {\n        int c = 2 * k +\
    \ 1;\n        if (c + 2 < n && d[c] > d[c + 2]) c += 2;\n        if (d[k] > d[c])\n\
    \          swap(d[k], d[c]), k = c;\n        else\n          break;\n      }\n\
    \    } else {  // max heap\n      while (2 * k + 2 < n) {\n        int c = 2 *\
    \ k + 2;\n        if (c + 2 < n && d[c] < d[c + 2]) c += 2;\n        if (d[k]\
    \ < d[c])\n          swap(d[k], d[c]), k = c;\n        else\n          break;\n\
    \      }\n    }\n    return k;\n  }\n  int up(int k, int root = 1) {\n    if ((k\
    \ | 1) < (int)d.size() && d[k & ~1] < d[k | 1]) swap(d[k & ~1], d[k | 1]), k ^=\
    \ 1;\n    int p;\n    while (root < k && d[p = parent(k)] < d[k]) swap(d[p], d[k]),\
    \ k = p;        // max heap\n    while (root < k && d[k] < d[p = (parent(k) |\
    \ 1)]) swap(d[p], d[k]), k = p;  // min heap\n    return k;\n  }\n};\n\n/**\n\
    \ * @brief Double Ended Priority Queue\n * @docs docs/data-structure/double-ended-priority-queue.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/double-ended-priority-queue.hpp
  requiredBy: []
  timestamp: '2026-06-28 14:52:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/LC_double_ended_priority_queue.test.cpp
documentation_of: data-structure/double-ended-priority-queue.hpp
layout: document
redirect_from:
- /library/data-structure/double-ended-priority-queue.hpp
- /library/data-structure/double-ended-priority-queue.hpp.html
title: Double Ended Priority Queue
---
C++ の `priority_queue` では max のみ取得できるが，min も取得できるようにしたデータ構造．


https://natsugiri.hatenablog.com/entry/2016/10/10/035445

Interval-heap



stack を 2 本持って deque を作る手法を応用しても作れるが，分割で priority queue 内部を見ないと線形にできないのが面倒．