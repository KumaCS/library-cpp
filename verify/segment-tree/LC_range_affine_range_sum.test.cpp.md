---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/segment-tree/LC_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"template/macro.hpp\"\n#define rep(i, a, b) for (int i = (a);\
    \ i < (int)(b); i++)\n#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (a);\
    \ i--)\n#define ALL(v) (v).begin(), (v).end()\n#define UNIQUE(v) sort(ALL(v)),\
    \ (v).erase(unique(ALL(v)), (v).end())\n#define SZ(v) (int)v.size()\n#define MIN(v)\
    \ *min_element(ALL(v))\n#define MAX(v) *max_element(ALL(v))\n#define LB(v, x)\
    \ int(lower_bound(ALL(v), (x)) - (v).begin())\n#define UB(v, x) int(upper_bound(ALL(v),\
    \ (x)) - (v).begin())\n#define YN(b) cout << ((b) ? \"YES\" : \"NO\") << \"\\\
    n\";\n#define Yn(b) cout << ((b) ? \"Yes\" : \"No\") << \"\\n\";\n#define yn(b)\
    \ cout << ((b) ? \"yes\" : \"no\") << \"\\n\";\n#line 6 \"template/template.hpp\"\
    \n\n#line 2 \"template/util.hpp\"\nusing uint = unsigned int;\nusing ll = long\
    \ long int;\nusing ull = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <class T, class S = T>\nS SUM(const vector<T>\
    \ &a) {\n  return accumulate(ALL(a), S(0));\n}\ntemplate <class T>\ninline bool\
    \ chmin(T &a, T b) {\n  if (a > b) {\n    a = b;\n    return true;\n  }\n  return\
    \ false;\n}\ntemplate <class T>\ninline bool chmax(T &a, T b) {\n  if (a < b)\
    \ {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\ntemplate <class\
    \ T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n}\ntemplate <class\
    \ T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n}\n\
    template <class T>\nint lowbit(T x) {\n  return (x == 0 ? -1 : __builtin_ctzll(x));\n\
    }\n#line 8 \"template/template.hpp\"\n\n#line 2 \"template/inout.hpp\"\nstruct\
    \ Fast {\n  Fast() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n  }\n} fast;\n\ntemplate <class T1, class\
    \ T2>\nistream &operator>>(istream &is, pair<T1, T2> &p) {\n  return is >> p.first\
    \ >> p.second;\n}\ntemplate <class T1, class T2>\nostream &operator<<(ostream\
    \ &os, const pair<T1, T2> &p) {\n  return os << p.first << \" \" << p.second;\n\
    }\ntemplate <class T>\nistream &operator>>(istream &is, vector<T> &a) {\n  for\
    \ (auto &v : a) is >> v;\n  return is;\n}\ntemplate <class T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &a) {\n  for (auto it = a.begin(); it != a.end();) {\n\
    \    os << *it;\n    if (++it != a.end()) os << \" \";\n  }\n  return os;\n}\n\
    template <class T>\nostream &operator<<(ostream &os, const set<T> &st) {\n  os\
    \ << \"{\";\n  for (auto it = st.begin(); it != st.end();) {\n    os << *it;\n\
    \    if (++it != st.end()) os << \",\";\n  }\n  os << \"}\";\n  return os;\n}\n\
    template <class T1, class T2>\nostream &operator<<(ostream &os, const map<T1,\
    \ T2> &mp) {\n  os << \"{\";\n  for (auto it = mp.begin(); it != mp.end();) {\n\
    \    os << it->first << \":\" << it->second;\n    if (++it != mp.end()) os <<\
    \ \",\";\n  }\n  os << \"}\";\n  return os;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &...u) {\n  cin >> t;\n  in(u...);\n}\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &...u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n#line 10 \"template/template.hpp\"\n\n#line 2 \"template/debug.hpp\"\
    \n#ifdef LOCAL\n#define debug 1\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\n\
    #else\n#define debug 0\n#define show(...) true\n#endif\ntemplate <class T>\nvoid\
    \ _show(int i, T name) {\n  cerr << '\\n';\n}\ntemplate <class T1, class T2, class...\
    \ T3>\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c) {\n  for (;\
    \ a[i] != ',' && a[i] != '\\0'; i++) cerr << a[i];\n  cerr << \":\" << b << \"\
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"segment-tree/lazy-segment-tree.hpp\"\
    \n\ntemplate <class T, T (*op)(T, T), T (*e)(), class F, T (*mapping)(F, T), F\
    \ (*composition)(F, F), F (*id)()>\nstruct LazySegmentTree {\n private:\n  int\
    \ _n, size, log;\n  vector<T> d;\n  vector<F> lz;\n\n  void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n  void all_apply(int k, F f) {\n    d[k] =\
    \ mapping(f, d[k]);\n    if (k < size) lz[k] = composition(f, lz[k]);\n  }\n \
    \ void push(int k) {\n    all_apply(2 * k, lz[k]);\n    all_apply(2 * k + 1, lz[k]);\n\
    \    lz[k] = id();\n  }\n\n public:\n  LazySegmentTree() : LazySegmentTree(0)\
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
    \ Tree\n * @docs docs/segment-tree/lazy-segment-tree.md\n */\n#line 2 \"modint/modint.hpp\"\
    \n\ntemplate <unsigned int m = 998244353>\nstruct ModInt {\n  using mint = ModInt;\n\
    \  unsigned int _v;\n  static constexpr unsigned int get_mod() { return m; }\n\
    \  static mint raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n\
    \  ModInt() : _v(0) {}\n  ModInt(int64_t v) {\n    long long x = (long long)(v\
    \ % (long long)(umod()));\n    if (x < 0) x += umod();\n    _v = (unsigned int)(x);\n\
    \  }\n  unsigned int val() const { return _v; }\n  mint &operator++() {\n    _v++;\n\
    \    if (_v == umod()) _v = 0;\n    return *this;\n  }\n  mint &operator--() {\n\
    \    if (_v == 0) _v = umod();\n    _v--;\n    return *this;\n  }\n  mint operator++(int)\
    \ {\n    mint result = *this;\n    ++*this;\n    return result;\n  }\n  mint operator--(int)\
    \ {\n    mint result = *this;\n    --*this;\n    return result;\n  }\n\n  mint\
    \ &operator+=(const mint &rhs) {\n    _v += rhs._v;\n    if (_v >= umod()) _v\
    \ -= umod();\n    return *this;\n  }\n  mint &operator-=(const mint &rhs) {\n\
    \    _v -= rhs._v;\n    if (_v >= umod()) _v += umod();\n    return *this;\n \
    \ }\n  mint &operator*=(const mint &rhs) {\n    unsigned long long z = _v;\n \
    \   z *= rhs._v;\n    _v = (unsigned int)(z % umod());\n    return *this;\n  }\n\
    \  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }\n\n\
    \  mint operator+() const { return *this; }\n  mint operator-() const { return\
    \ mint() - *this; }\n\n  mint pow(long long n) const {\n    assert(0 <= n);\n\
    \    mint x = *this, r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n     \
    \ x *= x;\n      n >>= 1;\n    }\n    return r;\n  }\n  mint inv() const {\n \
    \   assert(_v);\n    return pow(umod() - 2);\n  }\n\n  friend mint operator+(const\
    \ mint &lhs, const mint &rhs) {\n    return mint(lhs) += rhs;\n  }\n  friend mint\
    \ operator-(const mint &lhs, const mint &rhs) {\n    return mint(lhs) -= rhs;\n\
    \  }\n  friend mint operator*(const mint &lhs, const mint &rhs) {\n    return\
    \ mint(lhs) *= rhs;\n  }\n  friend mint operator/(const mint &lhs, const mint\
    \ &rhs) {\n    return mint(lhs) /= rhs;\n  }\n  friend bool operator==(const mint\
    \ &lhs, const mint &rhs) {\n    return lhs._v == rhs._v;\n  }\n  friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) {\n    return lhs._v != rhs._v;\n  }\n  friend istream\
    \ &operator>>(istream &is, mint &x) {\n    return is >> x._v;\n  }\n  friend ostream\
    \ &operator<<(ostream &os, const mint &x) {\n    return os << x.val();\n  }\n\n\
    \ private:\n  static constexpr unsigned int umod() { return m; }\n};\n#line 6\
    \ \"verify/segment-tree/LC_range_affine_range_sum.test.cpp\"\nusing mint = ModInt<998244353>;\n\
    struct T {\n  mint c, s;\n};\nstruct F {\n  mint a, b;\n  mint eval(mint x) {\
    \ return a * x + b; }\n};\nT op(T x, T y) { return {x.c + y.c, x.s + y.s}; }\n\
    T e() { return {0, 0}; }\nT mapping(F f, T x) { return {x.c, f.a * x.s + f.b *\
    \ x.c}; }\nF composition(F f, F g) { return {f.a * g.a, f.a * g.b + f.b}; }\n\
    F id() { return {1, 0}; }\n\nint main() {\n  int n, q;\n  in(n, q);\n  vector<T>\
    \ a(n, {1, 0});\n  rep(i, 0, n) cin >> a[i].s;\n  LazySegmentTree<T, op, e, F,\
    \ mapping, composition, id> seg(a);\n  while (q--) {\n    int t;\n    in(t);\n\
    \    if (t == 0) {\n      int l, r;\n      mint b, c;\n      in(l, r, b, c);\n\
    \      seg.apply(l, r, {b, c});\n    } else {\n      int l, r;\n      in(l, r);\n\
    \      out(seg.prod(l, r).s);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"template/template.hpp\"\n#include \"segment-tree/lazy-segment-tree.hpp\"\
    \n#include \"modint/modint.hpp\"\nusing mint = ModInt<998244353>;\nstruct T {\n\
    \  mint c, s;\n};\nstruct F {\n  mint a, b;\n  mint eval(mint x) { return a *\
    \ x + b; }\n};\nT op(T x, T y) { return {x.c + y.c, x.s + y.s}; }\nT e() { return\
    \ {0, 0}; }\nT mapping(F f, T x) { return {x.c, f.a * x.s + f.b * x.c}; }\nF composition(F\
    \ f, F g) { return {f.a * g.a, f.a * g.b + f.b}; }\nF id() { return {1, 0}; }\n\
    \nint main() {\n  int n, q;\n  in(n, q);\n  vector<T> a(n, {1, 0});\n  rep(i,\
    \ 0, n) cin >> a[i].s;\n  LazySegmentTree<T, op, e, F, mapping, composition, id>\
    \ seg(a);\n  while (q--) {\n    int t;\n    in(t);\n    if (t == 0) {\n      int\
    \ l, r;\n      mint b, c;\n      in(l, r, b, c);\n      seg.apply(l, r, {b, c});\n\
    \    } else {\n      int l, r;\n      in(l, r);\n      out(seg.prod(l, r).s);\n\
    \    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - segment-tree/lazy-segment-tree.hpp
  - modint/modint.hpp
  isVerificationFile: true
  path: verify/segment-tree/LC_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree/LC_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree/LC_range_affine_range_sum.test.cpp
- /verify/verify/segment-tree/LC_range_affine_range_sum.test.cpp.html
title: verify/segment-tree/LC_range_affine_range_sum.test.cpp
---
