---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/segment-tree-util.md
    document_title: "\u3088\u304F\u4F7F\u3046 Segment Tree"
    links: []
  bundledCode: "#line 2 \"segment-tree/segment-tree.hpp\"\n\ntemplate <class T, T\
    \ (*op)(T, T), T (*e)()>\nstruct SegmentTree {\n private:\n  int _n, size, log;\n\
    \  vector<T> d;\n  void update(int p) { d[p] = op(d[2 * p], d[2 * p + 1]); }\n\
    \n public:\n  SegmentTree() : SegmentTree(0) {}\n  explicit SegmentTree(int sz)\
    \ : SegmentTree(vector<T>(sz, e())) {}\n  explicit SegmentTree(const vector<T>&\
    \ v) : _n(v.size()) {\n    size = 1, log = 0;\n    while (size < _n) size <<=\
    \ 1, log++;\n    d.assign(2 * size, e());\n    for (int i = 0; i < v.size(); i++)\
    \ d[size + i] = v[i];\n    for (int i = size - 1; i > 0; i--) update(i);\n  }\n\
    \  void clear() { fill(d.begin(), d.end(), e()); }\n\n  void set_without_update(int\
    \ p, T v) { d[p + size] = v; }\n  void all_update() {\n    for (int i = size -\
    \ 1; i > 0; i--) update(i);\n  }\n  T get(int p) {\n    assert(0 <= p && p <=\
    \ _n);\n    return d[p + size];\n  }\n  void set(int p, T v) {\n    assert(0 <=\
    \ p && p <= _n);\n    p += size;\n    d[p] = v;\n    for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n  }\n  void apply(int p, T v) {\n    assert(0 <= p &&\
    \ p <= _n);\n    p += size;\n    d[p] = op(d[p], v);\n    for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n  }\n  T all_prod() { return d[1]; }\n  T prod(int\
    \ l, int r) {\n    if (l >= r) return e();\n    assert(0 <= l && l <= r && r <=\
    \ _n);\n    T sl = e(), sr = e();\n    l += size, r += size;\n    while (l < r)\
    \ {\n      if ((l & 1) != 0) sl = op(sl, d[l++]);\n      if ((r & 1) != 0) sr\
    \ = op(d[--r], sr);\n      l >>= 1, r >>= 1;\n    }\n    return op(sl, sr);\n\
    \  }\n\n  template <bool (*f)(T)>\n  int max_right(int l) const {\n    return\
    \ max_right(l, [](T x) { return f(x); });\n  }\n  template <class F>\n  int max_right(int\
    \ l, F f) const {\n    assert(0 <= l && l <= size);\n    assert(f(e()));\n   \
    \ if (l == _n) return _n;\n    l += size;\n    T s = e();\n    do {\n      while\
    \ (l % 2 == 0) l >>= 1;\n      if (!f(op(s, d[l]))) {\n        while (l < size)\
    \ {\n          l <<= 1;\n          if (f(op(s, d[l]))) s = op(s, d[l++]);\n  \
    \      }\n        return l - size;\n      }\n      s = op(s, d[l++]);\n    } while\
    \ ((l & -l) != l);\n    return _n;\n  }\n\n  template <bool (*f)(T)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](T x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(e()));\n    if (r == 0) return 0;\n    r += size;\n    T s = e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!f(op(d[r],\
    \ s))) {\n        while (r < size) {\n          r <<= 1, r++;\n          if (f(op(d[r],\
    \ s))) s = op(d[r--], s);\n        }\n        return r + 1 - size;\n      }\n\
    \      s = op(d[r], s);\n    } while ((r & -r) != r);\n    return 0;\n  }\n};\n\
    \n/**\n * @brief Segment Tree\n * @docs docs/segment-tree/segment-tree.md\n */\n\
    #line 3 \"segment-tree/segment-tree-util.hpp\"\n\nnamespace SegmentTreeUtil {\n\
    template <class T>\nT Zero() { return T{}; }\ntemplate <class T>\nT One() { return\
    \ T{1}; }\ntemplate <class T, T e>\nT Const() { return e; }\ntemplate <class T>\n\
    T Add(T x, T y) { return x + y; }\ntemplate <class T>\nT Mul(T x, T y) { return\
    \ x * y; }\ntemplate <class T>\nT Max(T x, T y) { return x > y ? x : y; }\ntemplate\
    \ <class T>\nT Min(T x, T y) { return x < y ? x : y; }\n\ntemplate <class T>\n\
    struct SegmentTreeSum : SegmentTree<T, Add<T>, Zero<T>> {\n  using base = SegmentTree<T,\
    \ Add<T>, Zero<T>>;\n  SegmentTreeSum(const vector<T>& a) : base(a) {}\n};\ntemplate\
    \ <class T>\nstruct SegmentTreeProd : SegmentTree<T, Mul<T>, One<T>> {\n  using\
    \ base = SegmentTree<T, Mul<T>, One<T>>;\n  SegmentTreeProd(const vector<T>& a)\
    \ : base(a) {}\n};\ntemplate <class T, T e>\nstruct SegmentTreeMax : SegmentTree<T,\
    \ Max<T>, Const<T, e>> {\n  using base = SegmentTree<T, Max<T>, Const<T, e>>;\n\
    \  SegmentTreeMax(const vector<T>& a) : base(a) {}\n};\ntemplate <class T, T e>\n\
    struct SegmentTreeMin : SegmentTree<T, Min<T>, Const<T, e>> {\n  using base =\
    \ SegmentTree<T, Min<T>, Const<T, e>>;\n  SegmentTreeMin(const vector<T>& a) :\
    \ base(a) {}\n};\n};  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::SegmentTreeMax;\n\
    using SegmentTreeUtil::SegmentTreeMin;\nusing SegmentTreeUtil::SegmentTreeProd;\n\
    using SegmentTreeUtil::SegmentTreeSum;\n/**\n * @brief \u3088\u304F\u4F7F\u3046\
    \ Segment Tree\n * @docs docs/segment-tree/segment-tree-util.md\n */\n"
  code: "#pragma once\n#include \"segment-tree/segment-tree.hpp\"\n\nnamespace SegmentTreeUtil\
    \ {\ntemplate <class T>\nT Zero() { return T{}; }\ntemplate <class T>\nT One()\
    \ { return T{1}; }\ntemplate <class T, T e>\nT Const() { return e; }\ntemplate\
    \ <class T>\nT Add(T x, T y) { return x + y; }\ntemplate <class T>\nT Mul(T x,\
    \ T y) { return x * y; }\ntemplate <class T>\nT Max(T x, T y) { return x > y ?\
    \ x : y; }\ntemplate <class T>\nT Min(T x, T y) { return x < y ? x : y; }\n\n\
    template <class T>\nstruct SegmentTreeSum : SegmentTree<T, Add<T>, Zero<T>> {\n\
    \  using base = SegmentTree<T, Add<T>, Zero<T>>;\n  SegmentTreeSum(const vector<T>&\
    \ a) : base(a) {}\n};\ntemplate <class T>\nstruct SegmentTreeProd : SegmentTree<T,\
    \ Mul<T>, One<T>> {\n  using base = SegmentTree<T, Mul<T>, One<T>>;\n  SegmentTreeProd(const\
    \ vector<T>& a) : base(a) {}\n};\ntemplate <class T, T e>\nstruct SegmentTreeMax\
    \ : SegmentTree<T, Max<T>, Const<T, e>> {\n  using base = SegmentTree<T, Max<T>,\
    \ Const<T, e>>;\n  SegmentTreeMax(const vector<T>& a) : base(a) {}\n};\ntemplate\
    \ <class T, T e>\nstruct SegmentTreeMin : SegmentTree<T, Min<T>, Const<T, e>>\
    \ {\n  using base = SegmentTree<T, Min<T>, Const<T, e>>;\n  SegmentTreeMin(const\
    \ vector<T>& a) : base(a) {}\n};\n};  // namespace SegmentTreeUtil\nusing SegmentTreeUtil::SegmentTreeMax;\n\
    using SegmentTreeUtil::SegmentTreeMin;\nusing SegmentTreeUtil::SegmentTreeProd;\n\
    using SegmentTreeUtil::SegmentTreeSum;\n/**\n * @brief \u3088\u304F\u4F7F\u3046\
    \ Segment Tree\n * @docs docs/segment-tree/segment-tree-util.md\n */"
  dependsOn:
  - segment-tree/segment-tree.hpp
  isVerificationFile: false
  path: segment-tree/segment-tree-util.hpp
  requiredBy: []
  timestamp: '2025-11-20 21:02:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/segment-tree-util.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree-util.hpp
- /library/segment-tree/segment-tree-util.hpp.html
title: "\u3088\u304F\u4F7F\u3046 Segment Tree"
---
- `SegmentTreeSum` : 和
- `SegmentTreeProd` : 積
- `SegmentTreeMax` : max
- `SegmentTreeMin` : min