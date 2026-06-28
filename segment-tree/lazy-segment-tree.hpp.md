---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/magma.hpp
    title: algebraic-structure/magma.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/monoid-action.hpp
    title: algebraic-structure/monoid-action.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/monoid.hpp
    title: algebraic-structure/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic-structure/util.hpp
    title: algebraic-structure/util.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment-tree/lazy-segment-tree-util.hpp
    title: "\u3088\u304F\u4F7F\u3046 Lazy Segment Tree"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/segment-tree/LC_range_affine_range_sum.test.cpp
    title: verify/segment-tree/LC_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segment-tree/lazy-segment-tree.md
    document_title: Lazy Segment Tree
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
    \ }\n};\n#line 3 \"algebraic-structure/monoid-action.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class A>\nconcept MonoidAction = Monoid<typename A::value_monoid> &&\
    \ Monoid<typename A::operator_monoid> && requires(typename A::value_monoid::value_type\
    \ x, typename A::operator_monoid::value_type f) {\n  typename A::value_monoid;\n\
    \  typename A::operator_monoid;\n  { A::mapping(f, x) } -> same_as<typename A::value_monoid::value_type>;\n\
    };\n#endif\n#line 3 \"segment-tree/lazy-segment-tree.hpp\"\n\ntemplate <class\
    \ A>\nREQUIRES(MonoidAction<A>)\nstruct LazySegmentTree {\n  using VM = typename\
    \ A::value_monoid;\n  using OM = typename A::operator_monoid;\n  using T = typename\
    \ VM::value_type;\n  using F = typename OM::value_type;\n\n private:\n  int _n,\
    \ size, log;\n  vector<T> d;\n  vector<F> lz;\n\n  void update(int k) { d[k] =\
    \ VM::op(d[2 * k], d[2 * k + 1]); }\n  void all_apply(int k, F f) {\n    d[k]\
    \ = A::mapping(f, d[k]);\n    if (k < size) lz[k] = OM::op(f, lz[k]);\n  }\n \
    \ void push(int k) {\n    all_apply(2 * k, lz[k]);\n    all_apply(2 * k + 1, lz[k]);\n\
    \    lz[k] = OM::e();\n  }\n\n public:\n  LazySegmentTree() : LazySegmentTree(0)\
    \ {}\n  explicit LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, VM::e()))\
    \ {}\n  explicit LazySegmentTree(const vector<T>& v) : _n(int(v.size())) {\n \
    \   size = 1, log = 0;\n    while (size < _n) size <<= 1, log++;\n    d = vector<T>(2\
    \ * size, VM::e());\n    lz = vector<F>(size, OM::e());\n    for (int i = 0; i\
    \ < _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n\n  void set(int p, T x) {\n    assert(0 <= p && p < _n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n  }\n  T get(int p) {\n    assert(0 <=\
    \ p && p < _n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return d[p];\n  }\n  T prod(int l, int r) {\n    assert(0 <= l && l\
    \ <= r && r <= _n);\n    if (l == r) return VM::e();\n    l += size, r += size;\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    T sml\
    \ = VM::e(), smr = VM::e();\n    while (l < r) {\n      if (l & 1) sml = VM::op(sml,\
    \ d[l++]);\n      if (r & 1) smr = VM::op(d[--r], smr);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    return VM::op(sml, smr);\n  }\n  T all_prod() { return d[1];\
    \ }\n  void apply(int p, F f) {\n    assert(0 <= p && p < _n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] = A::mapping(f, d[p]);\n\
    \    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void apply(int l,\
    \ int r, F f) {\n    assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n\
    \    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n   \
    \     if (l & 1) all_apply(l++, f);\n        if (r & 1) all_apply(--r, f);\n \
    \       l >>= 1, r >>= 1;\n      }\n      l = l2, r = r2;\n    }\n    for (int\
    \ i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n \
    \     if (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n  template\
    \ <bool (*g)(T)>\n  int max_right(int l) {\n    return max_right(l, [](T x) {\
    \ return g(x); });\n  }\n  template <class G>\n  int max_right(int l, G g) {\n\
    \    assert(0 <= l && l <= _n);\n    assert(g(VM::e()));\n    if (l == _n) return\
    \ _n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n    T\
    \ sm = VM::e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!g(VM::op(sm,\
    \ d[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (g(VM::op(sm, d[l]))) sm = VM::op(sm, d[l++]);\n       \
    \ }\n        return l - size;\n      }\n      sm = VM::op(sm, d[l++]);\n    }\
    \ while ((l & -l) != l);\n    return _n;\n  }\n\n  template <bool (*g)(T)>\n \
    \ int min_left(int r) {\n    return min_left(r, [](T x) { return g(x); });\n \
    \ }\n  template <class G>\n  int min_left(int r, G g) {\n    assert(0 <= r &&\
    \ r <= _n);\n    assert(g(VM::e()));\n    if (r == 0) return 0;\n    r += size;\n\
    \    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    T sm = VM::e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!g(VM::op(d[r],\
    \ sm))) {\n        while (r < size) {\n          push(r);\n          r = (2 *\
    \ r + 1);\n          if (g(VM::op(d[r], sm))) sm = VM::op(d[r--], sm);\n     \
    \   }\n        return r + 1 - size;\n      }\n      sm = VM::op(d[r], sm);\n \
    \   } while ((r & -r) != r);\n    return 0;\n  }\n};\n\n/**\n * @brief Lazy Segment\
    \ Tree\n * @docs docs/segment-tree/lazy-segment-tree.md\n */\n"
  code: "#pragma once\n#include \"algebraic-structure/monoid-action.hpp\"\n\ntemplate\
    \ <class A>\nREQUIRES(MonoidAction<A>)\nstruct LazySegmentTree {\n  using VM =\
    \ typename A::value_monoid;\n  using OM = typename A::operator_monoid;\n  using\
    \ T = typename VM::value_type;\n  using F = typename OM::value_type;\n\n private:\n\
    \  int _n, size, log;\n  vector<T> d;\n  vector<F> lz;\n\n  void update(int k)\
    \ { d[k] = VM::op(d[2 * k], d[2 * k + 1]); }\n  void all_apply(int k, F f) {\n\
    \    d[k] = A::mapping(f, d[k]);\n    if (k < size) lz[k] = OM::op(f, lz[k]);\n\
    \  }\n  void push(int k) {\n    all_apply(2 * k, lz[k]);\n    all_apply(2 * k\
    \ + 1, lz[k]);\n    lz[k] = OM::e();\n  }\n\n public:\n  LazySegmentTree() : LazySegmentTree(0)\
    \ {}\n  explicit LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, VM::e()))\
    \ {}\n  explicit LazySegmentTree(const vector<T>& v) : _n(int(v.size())) {\n \
    \   size = 1, log = 0;\n    while (size < _n) size <<= 1, log++;\n    d = vector<T>(2\
    \ * size, VM::e());\n    lz = vector<F>(size, OM::e());\n    for (int i = 0; i\
    \ < _n; i++) d[size + i] = v[i];\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n\n  void set(int p, T x) {\n    assert(0 <= p && p < _n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n  }\n  T get(int p) {\n    assert(0 <=\
    \ p && p < _n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return d[p];\n  }\n  T prod(int l, int r) {\n    assert(0 <= l && l\
    \ <= r && r <= _n);\n    if (l == r) return VM::e();\n    l += size, r += size;\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    T sml\
    \ = VM::e(), smr = VM::e();\n    while (l < r) {\n      if (l & 1) sml = VM::op(sml,\
    \ d[l++]);\n      if (r & 1) smr = VM::op(d[--r], smr);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    return VM::op(sml, smr);\n  }\n  T all_prod() { return d[1];\
    \ }\n  void apply(int p, F f) {\n    assert(0 <= p && p < _n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] = A::mapping(f, d[p]);\n\
    \    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void apply(int l,\
    \ int r, F f) {\n    assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n\
    \    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n   \
    \     if (l & 1) all_apply(l++, f);\n        if (r & 1) all_apply(--r, f);\n \
    \       l >>= 1, r >>= 1;\n      }\n      l = l2, r = r2;\n    }\n    for (int\
    \ i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n \
    \     if (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n  template\
    \ <bool (*g)(T)>\n  int max_right(int l) {\n    return max_right(l, [](T x) {\
    \ return g(x); });\n  }\n  template <class G>\n  int max_right(int l, G g) {\n\
    \    assert(0 <= l && l <= _n);\n    assert(g(VM::e()));\n    if (l == _n) return\
    \ _n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n    T\
    \ sm = VM::e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!g(VM::op(sm,\
    \ d[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (g(VM::op(sm, d[l]))) sm = VM::op(sm, d[l++]);\n       \
    \ }\n        return l - size;\n      }\n      sm = VM::op(sm, d[l++]);\n    }\
    \ while ((l & -l) != l);\n    return _n;\n  }\n\n  template <bool (*g)(T)>\n \
    \ int min_left(int r) {\n    return min_left(r, [](T x) { return g(x); });\n \
    \ }\n  template <class G>\n  int min_left(int r, G g) {\n    assert(0 <= r &&\
    \ r <= _n);\n    assert(g(VM::e()));\n    if (r == 0) return 0;\n    r += size;\n\
    \    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    T sm = VM::e();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!g(VM::op(d[r],\
    \ sm))) {\n        while (r < size) {\n          push(r);\n          r = (2 *\
    \ r + 1);\n          if (g(VM::op(d[r], sm))) sm = VM::op(d[r--], sm);\n     \
    \   }\n        return r + 1 - size;\n      }\n      sm = VM::op(d[r], sm);\n \
    \   } while ((r & -r) != r);\n    return 0;\n  }\n};\n\n/**\n * @brief Lazy Segment\
    \ Tree\n * @docs docs/segment-tree/lazy-segment-tree.md\n */\n"
  dependsOn:
  - algebraic-structure/monoid-action.hpp
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: false
  path: segment-tree/lazy-segment-tree.hpp
  requiredBy:
  - segment-tree/lazy-segment-tree-util.hpp
  timestamp: '2026-06-28 15:32:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/segment-tree/LC_range_affine_range_sum.test.cpp
documentation_of: segment-tree/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/segment-tree/lazy-segment-tree.hpp
- /library/segment-tree/lazy-segment-tree.hpp.html
title: Lazy Segment Tree
---
モノイド $(T,\cdot,e),(F,\circ,\mathrm{id})$ があり，$F$ は $T$ に左から作用するとする．

- 実際には各種演算は計算で出てくる範囲で定義されていれば構わない．

`LazySegmentTree<A>` として使う．
`A` は `value_monoid`, `operator_monoid`, `mapping(f,x)` を持つ作用を表す型．
`value_monoid` は列の値のモノイド，`operator_monoid` は作用素の合成モノイドを表す．

長さ $N$ の $T$ の列 $A=(A_0,A_1,\dots,A_{N-1})$ に対し，空間計算量 $\Theta(N)$ のもとで以下の操作を行える．

- `set(p, x)`：$A_p \gets x$ とする．$O(\log N)$ 時間．
- `get(p)`：$A_p$ を取得する．$O(\log N)$ 時間．
- `apply(l, r, f)`：$i=l,l+1,\dots,r-1$ に対し $A_i \gets f A_i$ とする．$O(\log N)$ 時間．
- `prod(l, r)`：$A_l\cdot A_{l+1}\cdot\cdots\cdot A_{r-1}$ を取得する．$O(\log N)$ 時間．
- 二分探索：$O(\log N)$ 時間．$\mathrm{cond}(e)=\mathrm{true}$ を要求する．
  - `max_right(l, cond)`：$\mathrm{cond}(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最大の $r$ を返す．
  - `min_left(r, cond)`：$\mathrm{cond}(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最小の $l$ を返す．
