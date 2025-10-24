---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
    \ */\n"
  code: "#pragma once\n\ntemplate <class T, T (*op)(T, T), T (*e)(), class F, T (*mapping)(F,\
    \ T), F (*composition)(F, F), F (*id)()>\nstruct LazySegmentTree {\n private:\n\
    \  int _n, size, log;\n  vector<T> d;\n  vector<F> lz;\n\n  void update(int k)\
    \ { d[k] = op(d[2 * k], d[2 * k + 1]); }\n  void all_apply(int k, F f) {\n   \
    \ d[k] = mapping(f, d[k]);\n    if (k < size) lz[k] = composition(f, lz[k]);\n\
    \  }\n  void push(int k) {\n    all_apply(2 * k, lz[k]);\n    all_apply(2 * k\
    \ + 1, lz[k]);\n    lz[k] = id();\n  }\n\n public:\n  LazySegmentTree() : LazySegmentTree(0)\
    \ {}\n  explicit LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, e())) {}\n\
    \  explicit LazySegmentTree(const vector<T>& v) : _n(int(v.size())) {\n    size\
    \ = 1, log = 0;\n    while (size < _n) size <<= 1, log++;\n    d = vector<T>(2\
    \ * size, e());\n    lz = vector<F>(size, id());\n    for (int i = 0; i < _n;\
    \ i++) d[size + i] = v[i];\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n\n  void set(int p, T x) {\n    assert(0 <= p && p < _n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    d[p] = x;\n    for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n  }\n  T get(int p) {\n    assert(0 <=\
    \ p && p < _n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return d[p];\n  }\n  T prod(int l, int r) {\n    assert(0 <= l && l\
    \ <= r && r <= _n);\n    if (l == r) return e();\n    l += size, r += size;\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    T sml\
    \ = e(), smr = e();\n    while (l < r) {\n      if (l & 1) sml = op(sml, d[l++]);\n\
    \      if (r & 1) smr = op(d[--r], smr);\n      l >>= 1, r >>= 1;\n    }\n   \
    \ return op(sml, smr);\n  }\n  T all_prod() { return d[1]; }\n  void apply(int\
    \ p, F f) {\n    assert(0 <= p && p < _n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    d[p] = mapping(f, d[p]);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n  void apply(int l, int r, F f) {\n   \
    \ assert(0 <= l && l <= r && r <= _n);\n    if (l == r) return;\n    l += size,\
    \ r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i)\
    \ != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n \
    \   }\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l\
    \ & 1) all_apply(l++, f);\n        if (r & 1) all_apply(--r, f);\n        l >>=\
    \ 1, r >>= 1;\n      }\n      l = l2, r = r2;\n    }\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n  template <bool (*g)(T)>\n\
    \  int max_right(int l) {\n    return max_right(l, [](T x) { return g(x); });\n\
    \  }\n  template <class G>\n  int max_right(int l, G g) {\n    assert(0 <= l &&\
    \ l <= _n);\n    assert(g(e()));\n    if (l == _n) return _n;\n    l += size;\n\
    \    for (int i = log; i >= 1; i--) push(l >> i);\n    T sm = e();\n    do {\n\
    \      while (l % 2 == 0) l >>= 1;\n      if (!g(op(sm, d[l]))) {\n        while\
    \ (l < size) {\n          push(l);\n          l = (2 * l);\n          if (g(op(sm,\
    \ d[l]))) sm = op(sm, d[l++]);\n        }\n        return l - size;\n      }\n\
    \      sm = op(sm, d[l++]);\n    } while ((l & -l) != l);\n    return _n;\n  }\n\
    \n  template <bool (*g)(T)>\n  int min_left(int r) {\n    return min_left(r, [](T\
    \ x) { return g(x); });\n  }\n  template <class G>\n  int min_left(int r, G g)\
    \ {\n    assert(0 <= r && r <= _n);\n    assert(g(e()));\n    if (r == 0) return\
    \ 0;\n    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \    T sm = e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!g(op(d[r], sm))) {\n        while (r < size) {\n          push(r);\n\
    \          r = (2 * r + 1);\n          if (g(op(d[r], sm))) sm = op(d[r--], sm);\n\
    \        }\n        return r + 1 - size;\n      }\n      sm = op(d[r], sm);\n\
    \    } while ((r & -r) != r);\n    return 0;\n  }\n};\n\n/**\n * @brief Lazy Segment\
    \ Tree\n * @docs docs/segment-tree/lazy-segment-tree.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: segment-tree/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2025-10-17 21:43:09+09:00'
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

長さ $N$ の $T$ の列 $A=(A_0,A_1,\dots,A_{N-1})$ に対し，空間計算量 $\Theta(N)$ のもとで以下の操作を行える．

- `set(p, x)`：$A_p \gets x$ とする．$O(\log N)$ 時間．
- `get(p)`：$A_p$ を取得する．$O(\log N)$ 時間．
- `apply(l, r, f)`：$i=l,l+1,\dots,r-1$ に対し $A_i \gets f A_i$ とする．$O(\log N)$ 時間．
- `prod(l, r)`：$A_l\cdot A_{l+1}\cdot\cdots\cdot A_{r-1}$ を取得する．$O(\log N)$ 時間．
- 二分探索：$O(\log N)$ 時間．$\mathrm{cond}(e)=\mathrm{true}$ を要求する．
  - `max_right(l, cond)`：$\mathrm{cond}(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最大の $r$ を返す．
  - `min_left(r, cond)`：$\mathrm{cond}(A_l \cdot A_{l+1} \cdot \cdots \cdot A_{r-1})$ が真となる最小の $l$ を返す．
