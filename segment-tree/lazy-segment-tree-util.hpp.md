---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/lazy-segment-tree-util.md
    document_title: "\u3088\u304F\u4F7F\u3046 Lazy Segment Tree"
    links: []
  bundledCode: "#line 2 \"segment-tree/lazy-segment-tree.hpp\"\n\ntemplate <class\
    \ T, T (*op)(T, T), T (*e)(), class F, T (*mapping)(F, T), F (*composition)(F,\
    \ F), F (*id)()>\nstruct LazySegmentTree {\n private:\n  int _n, size, log;\n\
    \  vector<T> d;\n  vector<F> lz;\n\n  void update(int k) { d[k] = op(d[2 * k],\
    \ d[2 * k + 1]); }\n  void all_apply(int k, F f) {\n    d[k] = mapping(f, d[k]);\n\
    \    if (k < size) lz[k] = composition(f, lz[k]);\n  }\n  void push(int k) {\n\
    \    all_apply(2 * k, lz[k]);\n    all_apply(2 * k + 1, lz[k]);\n    lz[k] = id();\n\
    \  }\n\n public:\n  LazySegmentTree() : LazySegmentTree(0) {}\n  explicit LazySegmentTree(int\
    \ n) : LazySegmentTree(vector<T>(n, e())) {}\n  explicit LazySegmentTree(const\
    \ vector<T>& v) : _n(int(v.size())) {\n    size = 1, log = 0;\n    while (size\
    \ < _n) size <<= 1, log++;\n    d = vector<T>(2 * size, e());\n    lz = vector<F>(size,\
    \ id());\n    for (int i = 0; i < _n; i++) d[size + i] = v[i];\n    for (int i\
    \ = size - 1; i > 0; i--) update(i);\n  }\n\n  void set(int p, T x) {\n    assert(0\
    \ <= p && p < _n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n    d[p] = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n\
    \  }\n  T get(int p) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n    return d[p];\n  }\n  T prod(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return\
    \ e();\n    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n    \
    \  if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n    T sml = e(), smr = e();\n    while (l < r) {\n     \
    \ if (l & 1) sml = op(sml, d[l++]);\n      if (r & 1) smr = op(d[--r], smr);\n\
    \      l >>= 1, r >>= 1;\n    }\n    return op(sml, smr);\n  }\n  T all_prod()\
    \ { return d[1]; }\n  void apply(int p, F f) {\n    assert(0 <= p && p < _n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] =\
    \ mapping(f, d[p]);\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\
    \  void apply(int l, int r, F f) {\n    assert(0 <= l && l <= r && r <= _n);\n\
    \    if (l == r) return;\n    l += size, r += size;\n    for (int i = log; i >=\
    \ 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n    }\n    {\n      int l2 = l, r2 = r;\n \
    \     while (l < r) {\n        if (l & 1) all_apply(l++, f);\n        if (r &\
    \ 1) all_apply(--r, f);\n        l >>= 1, r >>= 1;\n      }\n      l = l2, r =\
    \ r2;\n    }\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i)\
    \ != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n\
    \    }\n  }\n  template <bool (*g)(T)>\n  int max_right(int l) {\n    return max_right(l,\
    \ [](T x) { return g(x); });\n  }\n  template <class G>\n  int max_right(int l,\
    \ G g) {\n    assert(0 <= l && l <= _n);\n    assert(g(e()));\n    if (l == _n)\
    \ return _n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    T sm = e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!g(op(sm,\
    \ d[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (g(op(sm, d[l]))) sm = op(sm, d[l++]);\n        }\n    \
    \    return l - size;\n      }\n      sm = op(sm, d[l++]);\n    } while ((l &\
    \ -l) != l);\n    return _n;\n  }\n\n  template <bool (*g)(T)>\n  int min_left(int\
    \ r) {\n    return min_left(r, [](T x) { return g(x); });\n  }\n  template <class\
    \ G>\n  int min_left(int r, G g) {\n    assert(0 <= r && r <= _n);\n    assert(g(e()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    T sm = e();\n    do {\n      r--;\n      while (r >\
    \ 1 && (r % 2)) r >>= 1;\n      if (!g(op(d[r], sm))) {\n        while (r < size)\
    \ {\n          push(r);\n          r = (2 * r + 1);\n          if (g(op(d[r],\
    \ sm))) sm = op(d[r--], sm);\n        }\n        return r + 1 - size;\n      }\n\
    \      sm = op(d[r], sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\
    };\n\n/**\n * @brief Lazy Segment Tree\n * @docs docs/segment-tree/lazy-segment-tree.md\n\
    \ */\n#line 3 \"segment-tree/lazy-segment-tree-util.hpp\"\n\nnamespace LazySegmentTreeUtil\
    \ {\ntemplate <class T>\nT Zero() { return T{}; }\ntemplate <class T>\nT One()\
    \ { return T{1}; }\ntemplate <class T, T e>\nT Const() { return e; }\ntemplate\
    \ <class T>\nT Add(T x, T y) { return x + y; }\ntemplate <class T>\nT Mul(T x,\
    \ T y) { return x * y; }\ntemplate <class T>\nT Max(T x, T y) { return x > y ?\
    \ x : y; }\ntemplate <class T>\nT Min(T x, T y) { return x < y ? x : y; }\ntemplate\
    \ <class T>\nusing P = pair<T, T>;\ntemplate <class T>\nP<T> PAdd(P<T> x, P<T>\
    \ y) { return P<T>{x.first + y.first, x.second + y.second}; }\ntemplate <class\
    \ T>\nP<T> FPAdd(T f, P<T> x) { return P<T>{x.first, x.second + x.first * f};\
    \ }\ntemplate <class T>\nP<T> PZero() { return P<T>{T{}, T{}}; }\ntemplate <class\
    \ T>\nvector<P<T>> InitPair(const vector<T>& a) {\n  vector<P<T>> v(a.size());\n\
    \  for (int i = 0; i < (int)v.size(); i++) v[i] = P<T>{1, a[i]};\n  return v;\n\
    }\ntemplate <class T>\nstruct LazySegmentTreeAddSum : LazySegmentTree<P<T>, PAdd<T>,\
    \ PZero<T>, T, FPAdd<T>, Add<T>, Zero<T>> {\n  using base = LazySegmentTree<P<T>,\
    \ PAdd<T>, PZero<T>, T, PAdd<T>, Add<T>, Zero<T>>;\n  LazySegmentTreeAddSum(int\
    \ n) : base(vector<P<T>>(n, PZero<T>())) {}\n  LazySegmentTreeAddSum(const vector<T>&\
    \ a) : base(InitPair(a)) {}\n};\ntemplate <class T>\nstruct LazySegmentTreeMulSum\
    \ : LazySegmentTree<T, Add<T>, Zero<T>, T, Mul<T>, Mul<T>, One<T>> {\n  using\
    \ base = LazySegmentTree<T, Add<T>, Zero<T>, T, Mul<T>, Mul<T>, One<T>>;\n  LazySegmentTreeMulSum(int\
    \ n) : base(vector<T>(n, Zero<T>())) {}\n  LazySegmentTreeMulSum(const vector<T>&\
    \ a) : base(a) {}\n};\n};  // namespace LazySegmentTreeUtil\nusing LazySegmentTreeUtil::LazySegmentTreeAddSum;\n\
    using LazySegmentTreeUtil::LazySegmentTreeMulSum;\n/**\n * @brief \u3088\u304F\
    \u4F7F\u3046 Lazy Segment Tree\n * @docs docs/segment-tree/lazy-segment-tree-util.md\n\
    \ */\n"
  code: "#pragma once\n#include \"segment-tree/lazy-segment-tree.hpp\"\n\nnamespace\
    \ LazySegmentTreeUtil {\ntemplate <class T>\nT Zero() { return T{}; }\ntemplate\
    \ <class T>\nT One() { return T{1}; }\ntemplate <class T, T e>\nT Const() { return\
    \ e; }\ntemplate <class T>\nT Add(T x, T y) { return x + y; }\ntemplate <class\
    \ T>\nT Mul(T x, T y) { return x * y; }\ntemplate <class T>\nT Max(T x, T y) {\
    \ return x > y ? x : y; }\ntemplate <class T>\nT Min(T x, T y) { return x < y\
    \ ? x : y; }\ntemplate <class T>\nusing P = pair<T, T>;\ntemplate <class T>\n\
    P<T> PAdd(P<T> x, P<T> y) { return P<T>{x.first + y.first, x.second + y.second};\
    \ }\ntemplate <class T>\nP<T> FPAdd(T f, P<T> x) { return P<T>{x.first, x.second\
    \ + x.first * f}; }\ntemplate <class T>\nP<T> PZero() { return P<T>{T{}, T{}};\
    \ }\ntemplate <class T>\nvector<P<T>> InitPair(const vector<T>& a) {\n  vector<P<T>>\
    \ v(a.size());\n  for (int i = 0; i < (int)v.size(); i++) v[i] = P<T>{1, a[i]};\n\
    \  return v;\n}\ntemplate <class T>\nstruct LazySegmentTreeAddSum : LazySegmentTree<P<T>,\
    \ PAdd<T>, PZero<T>, T, FPAdd<T>, Add<T>, Zero<T>> {\n  using base = LazySegmentTree<P<T>,\
    \ PAdd<T>, PZero<T>, T, PAdd<T>, Add<T>, Zero<T>>;\n  LazySegmentTreeAddSum(int\
    \ n) : base(vector<P<T>>(n, PZero<T>())) {}\n  LazySegmentTreeAddSum(const vector<T>&\
    \ a) : base(InitPair(a)) {}\n};\ntemplate <class T>\nstruct LazySegmentTreeMulSum\
    \ : LazySegmentTree<T, Add<T>, Zero<T>, T, Mul<T>, Mul<T>, One<T>> {\n  using\
    \ base = LazySegmentTree<T, Add<T>, Zero<T>, T, Mul<T>, Mul<T>, One<T>>;\n  LazySegmentTreeMulSum(int\
    \ n) : base(vector<T>(n, Zero<T>())) {}\n  LazySegmentTreeMulSum(const vector<T>&\
    \ a) : base(a) {}\n};\n};  // namespace LazySegmentTreeUtil\nusing LazySegmentTreeUtil::LazySegmentTreeAddSum;\n\
    using LazySegmentTreeUtil::LazySegmentTreeMulSum;\n/**\n * @brief \u3088\u304F\
    \u4F7F\u3046 Lazy Segment Tree\n * @docs docs/segment-tree/lazy-segment-tree-util.md\n\
    \ */"
  dependsOn:
  - segment-tree/lazy-segment-tree.hpp
  isVerificationFile: false
  path: segment-tree/lazy-segment-tree-util.hpp
  requiredBy: []
  timestamp: '2025-11-20 21:02:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/lazy-segment-tree-util.hpp
layout: document
redirect_from:
- /library/segment-tree/lazy-segment-tree-util.hpp
- /library/segment-tree/lazy-segment-tree-util.hpp.html
title: "\u3088\u304F\u4F7F\u3046 Lazy Segment Tree"
---
