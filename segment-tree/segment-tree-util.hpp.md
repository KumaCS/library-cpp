---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/magma.hpp
    title: algebraic-structure/magma.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/monoid.hpp
    title: algebraic-structure/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/util.hpp
    title: algebraic-structure/util.hpp
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
  bundledCode: "#line 2 \"algebraic-structure/util.hpp\"\n#ifdef __cpp_concepts\n\
    #define REQUIRES(...) requires __VA_ARGS__\n#else\n#define REQUIRES(...)\n#endif\n\
    #line 3 \"algebraic-structure/magma.hpp\"\n\n#ifdef __cpp_concepts\ntemplate <class\
    \ M>\nconcept Magma = requires(typename M::value_type x, typename M::value_type\
    \ y) {\n  typename M::value_type;\n  { M::op(x, y) } -> same_as<typename M::value_type>;\n\
    };\n#endif\n\ntemplate <class T>\nstruct AddMagma {\n  using value_type = T;\n\
    \  static T op(T x, T y) { return x + y; }\n};\ntemplate <class T>\nstruct MulMagma\
    \ {\n  using value_type = T;\n  static T op(T x, T y) { return x * y; }\n};\n\
    template <class T, T id>\nstruct MaxMagma {\n  using value_type = T;\n  static\
    \ T op(T x, T y) { return x > y ? x : y; }\n};\ntemplate <class T, T id>\nstruct\
    \ MinMagma {\n  using value_type = T;\n  static T op(T x, T y) { return x < y\
    \ ? x : y; }\n};\n#line 3 \"algebraic-structure/monoid.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class M>\nconcept Monoid = Magma<M> && requires {\n  { M::e() } -> same_as<typename\
    \ M::value_type>;\n};\n#endif\n\ntemplate <class T>\nstruct AddMonoid {\n  using\
    \ value_type = T;\n  static T op(T x, T y) { return x + y; }\n  static T e() {\
    \ return T(0); }\n};\ntemplate <class T>\nstruct MulMonoid {\n  using value_type\
    \ = T;\n  static T op(T x, T y) { return x * y; }\n  static T e() { return T(1);\
    \ }\n};\ntemplate <class T, T id>\nstruct MaxMonoid {\n  using value_type = T;\n\
    \  static T op(T x, T y) { return x > y ? x : y; }\n  static T e() { return id;\
    \ }\n};\ntemplate <class T, T id>\nstruct MinMonoid {\n  using value_type = T;\n\
    \  static T op(T x, T y) { return x < y ? x : y; }\n  static T e() { return id;\
    \ }\n};\n#line 3 \"segment-tree/segment-tree.hpp\"\n\ntemplate <class M>\nREQUIRES(Monoid<M>)\n\
    struct SegmentTree {\n  using T = typename M::value_type;\n\n private:\n  int\
    \ _n, size, log;\n  vector<T> d;\n  void update(int p) { d[p] = M::op(d[2 * p],\
    \ d[2 * p + 1]); }\n\n public:\n  SegmentTree() : SegmentTree(0) {}\n  explicit\
    \ SegmentTree(int sz) : SegmentTree(vector<T>(sz, M::e())) {}\n  explicit SegmentTree(const\
    \ vector<T>& v) : _n(v.size()) {\n    size = 1, log = 0;\n    while (size < _n)\
    \ size <<= 1, log++;\n    d.assign(2 * size, M::e());\n    for (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n  void clear() { fill(d.begin(), d.end(), M::e()); }\n\n  void set_without_update(int\
    \ p, T v) { d[p + size] = v; }\n  void all_update() {\n    for (int i = size -\
    \ 1; i > 0; i--) update(i);\n  }\n  T get(int p) {\n    assert(0 <= p && p <=\
    \ _n);\n    return d[p + size];\n  }\n  void set(int p, T v) {\n    assert(0 <=\
    \ p && p <= _n);\n    p += size;\n    d[p] = v;\n    for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n  }\n  void apply(int p, T v) {\n    assert(0 <= p &&\
    \ p <= _n);\n    p += size;\n    d[p] = M::op(d[p], v);\n    for (int i = 1; i\
    \ <= log; i++) update(p >> i);\n  }\n  T all_prod() { return d[1]; }\n  T prod(int\
    \ l, int r) {\n    if (l >= r) return M::e();\n    assert(0 <= l && l <= r &&\
    \ r <= _n);\n    T sl = M::e(), sr = M::e();\n    l += size, r += size;\n    while\
    \ (l < r) {\n      if ((l & 1) != 0) sl = M::op(sl, d[l++]);\n      if ((r & 1)\
    \ != 0) sr = M::op(d[--r], sr);\n      l >>= 1, r >>= 1;\n    }\n    return M::op(sl,\
    \ sr);\n  }\n\n  template <bool (*f)(T)>\n  int max_right(int l) const {\n   \
    \ return max_right(l, [](T x) { return f(x); });\n  }\n  template <class F>\n\
    \  int max_right(int l, F f) const {\n    assert(0 <= l && l <= size);\n    assert(f(M::e()));\n\
    \    if (l == _n) return _n;\n    l += size;\n    T s = M::e();\n    do {\n  \
    \    while (l % 2 == 0) l >>= 1;\n      if (!f(M::op(s, d[l]))) {\n        while\
    \ (l < size) {\n          l <<= 1;\n          if (f(M::op(s, d[l]))) s = M::op(s,\
    \ d[l++]);\n        }\n        return l - size;\n      }\n      s = M::op(s, d[l++]);\n\
    \    } while ((l & -l) != l);\n    return _n;\n  }\n\n  template <bool (*f)(T)>\n\
    \  int min_left(int r) const {\n    return min_left(r, [](T x) { return f(x);\
    \ });\n  }\n  template <class F>\n  int min_left(int r, F f) const {\n    assert(0\
    \ <= r && r <= _n);\n    assert(f(M::e()));\n    if (r == 0) return 0;\n    r\
    \ += size;\n    T s = M::e();\n    do {\n      r--;\n      while (r > 1 && (r\
    \ % 2)) r >>= 1;\n      if (!f(M::op(d[r], s))) {\n        while (r < size) {\n\
    \          r <<= 1, r++;\n          if (f(M::op(d[r], s))) s = M::op(d[r--], s);\n\
    \        }\n        return r + 1 - size;\n      }\n      s = M::op(d[r], s);\n\
    \    } while ((r & -r) != r);\n    return 0;\n  }\n};\n\n/**\n * @brief Segment\
    \ Tree\n * @docs docs/segment-tree/segment-tree.md\n */\n#line 3 \"segment-tree/segment-tree-util.hpp\"\
    \n\nnamespace SegmentTreeUtil {\ntemplate <class T>\nstruct SegmentTreeSum : SegmentTree<AddMonoid<T>>\
    \ {\n  using base = SegmentTree<AddMonoid<T>>;\n  SegmentTreeSum(const vector<T>&\
    \ a) : base(a) {}\n  SegmentTreeSum(int n) : base(n) {}\n};\ntemplate <class T>\n\
    struct SegmentTreeProd : SegmentTree<MulMonoid<T>> {\n  using base = SegmentTree<MulMonoid<T>>;\n\
    \  SegmentTreeProd(const vector<T>& a) : base(a) {}\n  SegmentTreeProd(int n)\
    \ : base(n) {}\n};\ntemplate <class T, T e>\nstruct SegmentTreeMax : SegmentTree<MaxMonoid<T,\
    \ e>> {\n  using base = SegmentTree<MaxMonoid<T, e>>;\n  SegmentTreeMax(const\
    \ vector<T>& a) : base(a) {}\n  SegmentTreeMax(int n) : base(n) {}\n};\ntemplate\
    \ <class T, T e>\nstruct SegmentTreeMin : SegmentTree<MinMonoid<T, e>> {\n  using\
    \ base = SegmentTree<MinMonoid<T, e>>;\n  SegmentTreeMin(const vector<T>& a) :\
    \ base(a) {}\n  SegmentTreeMin(int n) : base(n) {}\n};\n};  // namespace SegmentTreeUtil\n\
    using SegmentTreeUtil::SegmentTreeMax;\nusing SegmentTreeUtil::SegmentTreeMin;\n\
    using SegmentTreeUtil::SegmentTreeProd;\nusing SegmentTreeUtil::SegmentTreeSum;\n\
    /**\n * @brief \u3088\u304F\u4F7F\u3046 Segment Tree\n * @docs docs/segment-tree/segment-tree-util.md\n\
    \ */\n"
  code: "#pragma once\n#include \"segment-tree/segment-tree.hpp\"\n\nnamespace SegmentTreeUtil\
    \ {\ntemplate <class T>\nstruct SegmentTreeSum : SegmentTree<AddMonoid<T>> {\n\
    \  using base = SegmentTree<AddMonoid<T>>;\n  SegmentTreeSum(const vector<T>&\
    \ a) : base(a) {}\n  SegmentTreeSum(int n) : base(n) {}\n};\ntemplate <class T>\n\
    struct SegmentTreeProd : SegmentTree<MulMonoid<T>> {\n  using base = SegmentTree<MulMonoid<T>>;\n\
    \  SegmentTreeProd(const vector<T>& a) : base(a) {}\n  SegmentTreeProd(int n)\
    \ : base(n) {}\n};\ntemplate <class T, T e>\nstruct SegmentTreeMax : SegmentTree<MaxMonoid<T,\
    \ e>> {\n  using base = SegmentTree<MaxMonoid<T, e>>;\n  SegmentTreeMax(const\
    \ vector<T>& a) : base(a) {}\n  SegmentTreeMax(int n) : base(n) {}\n};\ntemplate\
    \ <class T, T e>\nstruct SegmentTreeMin : SegmentTree<MinMonoid<T, e>> {\n  using\
    \ base = SegmentTree<MinMonoid<T, e>>;\n  SegmentTreeMin(const vector<T>& a) :\
    \ base(a) {}\n  SegmentTreeMin(int n) : base(n) {}\n};\n};  // namespace SegmentTreeUtil\n\
    using SegmentTreeUtil::SegmentTreeMax;\nusing SegmentTreeUtil::SegmentTreeMin;\n\
    using SegmentTreeUtil::SegmentTreeProd;\nusing SegmentTreeUtil::SegmentTreeSum;\n\
    /**\n * @brief \u3088\u304F\u4F7F\u3046 Segment Tree\n * @docs docs/segment-tree/segment-tree-util.md\n\
    \ */\n"
  dependsOn:
  - segment-tree/segment-tree.hpp
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: segment-tree/segment-tree-util.hpp
  requiredBy: []
  timestamp: '2026-06-28 15:32:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment-tree/segment-tree-util.hpp
layout: document
redirect_from:
- /library/segment-tree/segment-tree-util.hpp
- /library/segment-tree/segment-tree-util.hpp.html
title: "\u3088\u304F\u4F7F\u3046 Segment Tree"
---
よく使う Segment Tree の型エイリアス集．

`SegmentTree` に渡す演算を毎回定義せずに使えるようにするための utility．

- `SegmentTreeSum<T>`：区間和を管理する．単位元は `T{}`．
- `SegmentTreeProd<T>`：区間積を管理する．単位元は `T{1}`．
- `SegmentTreeMax<T, e>`：区間最大値を管理する．単位元は `e`．
- `SegmentTreeMin<T, e>`：区間最小値を管理する．単位元は `e`．

構築後の操作は基底クラス `SegmentTree` と同じ．
`set`, `apply`, `get`, `prod`, `max_right`, `min_left` などを使える．
