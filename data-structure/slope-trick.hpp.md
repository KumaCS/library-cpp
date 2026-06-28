---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/slope-trick.md
    document_title: Slope Trick
    links: []
  bundledCode: "#line 2 \"data-structure/slope-trick.hpp\"\n\ntemplate <class T>\n\
    struct SlopeTrick {\n  const T INF = numeric_limits<T>::max() / 3;\n  T min_f;\n\
    \  priority_queue<T, vector<T>, less<> > pq_l;\n  priority_queue<T, vector<T>,\
    \ greater<> > pq_r;\n  T add_l, add_r;\n  SlopeTrick() : min_f(0), add_l(0), add_r(0)\
    \ {}\n  T get_min() const { return min_f; }\n  pair<T, T> get_min_range() const\
    \ { return {top_l(), top_r()}; }\n  // f(x) += a\n  void add_const(const T& a)\
    \ { min_f += a; }\n  // f(x) += max(0, x - a)\n  void add_x_minus_a(const T& a)\
    \ {\n    min_f += max(T(0), top_l() - a);\n    push_l(a);\n    push_r(pop_l());\n\
    \  }\n  // f(x) += max(a - x, 0)\n  void add_a_minus_x(const T& a) {\n    min_f\
    \ += max(T(0), a - top_r());\n    push_r(a);\n    push_l(pop_r());\n  }\n  //\
    \ f(x) += abs(x - a)\n  void add_abs(const T& a) {\n    add_a_minus_x(a);\n  \
    \  add_x_minus_a(a);\n  }\n  // f(x) <- min_{y <= x} f(y)\n  // \\/ -> \\_\n \
    \ void clear_right() {\n    while (!pq_r.empty()) pq_r.pop();\n  }\n  // f(x)\
    \ <- min_{x <= y} f(y)\n  // \\/ -> _/\n  void clear_left() {\n    while (!pq_l.empty())\
    \ pq_l.pop();\n  }\n  // f(x) <- min_{x-b <= y <= x-a} f(y)\n  // \\/ -> \\_/\n\
    \  void shift(const T& a, const T& b) {\n    assert(a <= b);\n    add_l += a;\n\
    \    add_r += b;\n  }\n\n  T get_destructive(const T& x) {\n    T ret = min_f;\n\
    \    while (!pq_l.empty()) ret += max(T(0), pop_l() - x);\n    while (!pq_r.empty())\
    \ ret += max(T(0), x - pop_r());\n    return ret;\n  }\n  void merge(SlopeTrick&\
    \ st) {\n    if (st.size() > size()) {\n      swap(st.pq_l, pq_l);\n      swap(st.pq_r,\
    \ pq_r);\n      swap(st.add_l, add_l);\n      swap(st.add_r, add_r);\n      swap(st.min_f,\
    \ min_f);\n    }\n    while (!st.pq_r.empty()) add_x_minus_a(st.pop_r());\n  \
    \  while (!st.pq_l.empty()) add_a_minus_x(st.pop_l());\n    min_f += st.min_f;\n\
    \  }\n\n private:\n  void push_r(const T& a) { pq_r.push(a - add_r); }\n  T top_r()\
    \ const { return pq_r.empty() ? INF : pq_r.top() + add_r; }\n  T pop_r() {\n \
    \   T val = top_r();\n    if (!pq_r.empty()) pq_r.pop();\n    return val;\n  }\n\
    \  void push_l(const T& a) { pq_l.push(a - add_l); }\n  T top_l() const { return\
    \ pq_l.empty() ? -INF : pq_l.top() + add_l; }\n  T pop_l() {\n    T val = top_l();\n\
    \    if (!pq_l.empty()) pq_l.pop();\n    return val;\n  }\n  size_t size() { return\
    \ pq_l.size() + pq_r.size(); }\n};\n\n/**\n * @brief Slope Trick\n * @docs docs/data-structure/slope-trick.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct SlopeTrick {\n  const T INF =\
    \ numeric_limits<T>::max() / 3;\n  T min_f;\n  priority_queue<T, vector<T>, less<>\
    \ > pq_l;\n  priority_queue<T, vector<T>, greater<> > pq_r;\n  T add_l, add_r;\n\
    \  SlopeTrick() : min_f(0), add_l(0), add_r(0) {}\n  T get_min() const { return\
    \ min_f; }\n  pair<T, T> get_min_range() const { return {top_l(), top_r()}; }\n\
    \  // f(x) += a\n  void add_const(const T& a) { min_f += a; }\n  // f(x) += max(0,\
    \ x - a)\n  void add_x_minus_a(const T& a) {\n    min_f += max(T(0), top_l() -\
    \ a);\n    push_l(a);\n    push_r(pop_l());\n  }\n  // f(x) += max(a - x, 0)\n\
    \  void add_a_minus_x(const T& a) {\n    min_f += max(T(0), a - top_r());\n  \
    \  push_r(a);\n    push_l(pop_r());\n  }\n  // f(x) += abs(x - a)\n  void add_abs(const\
    \ T& a) {\n    add_a_minus_x(a);\n    add_x_minus_a(a);\n  }\n  // f(x) <- min_{y\
    \ <= x} f(y)\n  // \\/ -> \\_\n  void clear_right() {\n    while (!pq_r.empty())\
    \ pq_r.pop();\n  }\n  // f(x) <- min_{x <= y} f(y)\n  // \\/ -> _/\n  void clear_left()\
    \ {\n    while (!pq_l.empty()) pq_l.pop();\n  }\n  // f(x) <- min_{x-b <= y <=\
    \ x-a} f(y)\n  // \\/ -> \\_/\n  void shift(const T& a, const T& b) {\n    assert(a\
    \ <= b);\n    add_l += a;\n    add_r += b;\n  }\n\n  T get_destructive(const T&\
    \ x) {\n    T ret = min_f;\n    while (!pq_l.empty()) ret += max(T(0), pop_l()\
    \ - x);\n    while (!pq_r.empty()) ret += max(T(0), x - pop_r());\n    return\
    \ ret;\n  }\n  void merge(SlopeTrick& st) {\n    if (st.size() > size()) {\n \
    \     swap(st.pq_l, pq_l);\n      swap(st.pq_r, pq_r);\n      swap(st.add_l, add_l);\n\
    \      swap(st.add_r, add_r);\n      swap(st.min_f, min_f);\n    }\n    while\
    \ (!st.pq_r.empty()) add_x_minus_a(st.pop_r());\n    while (!st.pq_l.empty())\
    \ add_a_minus_x(st.pop_l());\n    min_f += st.min_f;\n  }\n\n private:\n  void\
    \ push_r(const T& a) { pq_r.push(a - add_r); }\n  T top_r() const { return pq_r.empty()\
    \ ? INF : pq_r.top() + add_r; }\n  T pop_r() {\n    T val = top_r();\n    if (!pq_r.empty())\
    \ pq_r.pop();\n    return val;\n  }\n  void push_l(const T& a) { pq_l.push(a -\
    \ add_l); }\n  T top_l() const { return pq_l.empty() ? -INF : pq_l.top() + add_l;\
    \ }\n  T pop_l() {\n    T val = top_l();\n    if (!pq_l.empty()) pq_l.pop();\n\
    \    return val;\n  }\n  size_t size() { return pq_l.size() + pq_r.size(); }\n\
    };\n\n/**\n * @brief Slope Trick\n * @docs docs/data-structure/slope-trick.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slope-trick.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:22:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/slope-trick.hpp
layout: document
redirect_from:
- /library/data-structure/slope-trick.hpp
- /library/data-structure/slope-trick.hpp.html
title: Slope Trick
---

区分線形凸関数を管理するデータ構造．

最小値と，傾きが変わる点を 2 つの priority queue で管理する．
DP の遷移で $\max(0,x-a)$, $\max(0,a-x)$, $|x-a|$ を足したり，片側の累積 min を取ったりするときに使う．

- `get_min()`：現在の関数の最小値を返す．
- `get_min_range()`：最小値を取る区間を返す．
- `add_const(a)`：関数全体に定数 $a$ を足す．
- `add_x_minus_a(a)`：$\max(0,x-a)$ を足す．
- `add_a_minus_x(a)`：$\max(0,a-x)$ を足す．
- `add_abs(a)`：$|x-a|$ を足す．
- `clear_right()`：$f(x)\gets\min_{y\leq x} f(y)$ とする．
- `clear_left()`：$f(x)\gets\min_{x\leq y} f(y)$ とする．
- `shift(a, b)`：$f(x)\gets\min_{x-b\leq y\leq x-a} f(y)$ とする．

https://ei1333.github.io/library/structure/others/slope-trick.hpp.html
https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
