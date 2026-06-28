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
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/segment-tree/LC_point_add_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line\
    \ 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#line 2 \"template/macro.hpp\"\n#define rep(i, a, b) for (int i = (a); i < (int)(b);\
    \ i++)\n#define rrep(i, a, b) for (int i = (int)(b) - 1; i >= (a); i--)\n#define\
    \ ALL(v) (v).begin(), (v).end()\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\n#define SZ(v) (int)v.size()\n#define MIN(v) *min_element(ALL(v))\n\
    #define MAX(v) *max_element(ALL(v))\n#define LB(v, x) int(lower_bound(ALL(v),\
    \ (x)) - (v).begin())\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\n\
    #define YN(b) cout << ((b) ? \"YES\" : \"NO\") << \"\\n\";\n#define Yn(b) cout\
    \ << ((b) ? \"Yes\" : \"No\") << \"\\n\";\n#define yn(b) cout << ((b) ? \"yes\"\
    \ : \"no\") << \"\\n\";\n#line 6 \"template/template.hpp\"\n\n#line 2 \"template/util.hpp\"\
    \nusing uint = unsigned int;\nusing ll = long long int;\nusing ull = unsigned\
    \ long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\ntemplate\
    \ <class T, class S = T>\nS SUM(const vector<T>& a) {\n  return accumulate(ALL(a),\
    \ S(0));\n}\ntemplate <class T>\ninline bool chmin(T& a, T b) {\n  if (a > b)\
    \ {\n    a = b;\n    return true;\n  }\n  return false;\n}\ntemplate <class T>\n\
    inline bool chmax(T& a, T b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\n\ntemplate <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n\
    }\ntemplate <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
    }\ntemplate <class T>\nint lowbit(T x) {\n  return (x == 0 ? -1 : __builtin_ctzll(x));\n\
    }\n#line 8 \"template/template.hpp\"\n\n#line 2 \"template/inout.hpp\"\nstruct\
    \ Fast {\n  Fast() {\n    cin.tie(nullptr);\n    ios_base::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n  }\n} fast;\n\nostream& operator<<(ostream&\
    \ os, __uint128_t x) {\n  char buf[40];\n  size_t k = 0;\n  while (x > 0) buf[k++]\
    \ = (char)(x % 10 + '0'), x /= 10;\n  if (k == 0) buf[k++] = '0';\n  while (k)\
    \ os << buf[--k];\n  return os;\n}\nostream& operator<<(ostream& os, __int128_t\
    \ x) {\n  return x < 0 ? (os << '-' << (__uint128_t)(-x)) : (os << (__uint128_t)x);\n\
    }\ntemplate <class T1, class T2>\nistream& operator>>(istream& is, pair<T1, T2>&\
    \ p) {\n  return is >> p.first >> p.second;\n}\ntemplate <class T1, class T2>\n\
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) {\n  return os << p.first\
    \ << \" \" << p.second;\n}\ntemplate <class T>\nistream& operator>>(istream& is,\
    \ vector<T>& a) {\n  for (auto& v : a) is >> v;\n  return is;\n}\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& a) {\n  for (auto it =\
    \ a.begin(); it != a.end();) {\n    os << *it;\n    if (++it != a.end()) os <<\
    \ \" \";\n  }\n  return os;\n}\ntemplate <class T>\nostream& operator<<(ostream&\
    \ os, const set<T>& st) {\n  os << \"{\";\n  for (auto it = st.begin(); it !=\
    \ st.end();) {\n    os << *it;\n    if (++it != st.end()) os << \",\";\n  }\n\
    \  os << \"}\";\n  return os;\n}\ntemplate <class T1, class T2>\nostream& operator<<(ostream&\
    \ os, const map<T1, T2>& mp) {\n  os << \"{\";\n  for (auto it = mp.begin(); it\
    \ != mp.end();) {\n    os << it->first << \":\" << it->second;\n    if (++it !=\
    \ mp.end()) os << \",\";\n  }\n  os << \"}\";\n  return os;\n}\n\nvoid in() {}\n\
    template <typename T, class... U>\nvoid in(T& t, U&... u) {\n  cin >> t;\n  in(u...);\n\
    }\nvoid out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep\
    \ = ' '>\nvoid out(const T& t, const U&... u) {\n  cout << t;\n  if (sizeof...(u))\
    \ cout << sep;\n  out(u...);\n}\n\nnamespace IO {\nnamespace Graph {\nvector<vector<int>>\
    \ unweighted(int n, int m, bool directed = false, int offset = 1) {\n  vector<vector<int>>\
    \ g(n);\n  for (int i = 0; i < m; i++) {\n    int u, v;\n    cin >> u >> v;\n\
    \    u -= offset, v -= offset;\n    g[u].push_back(v);\n    if (!directed) g[v].push_back(u);\n\
    \  }\n  return g;\n}\ntemplate <class T>\nvector<vector<pair<int, T>>> weighted(int\
    \ n, int m, bool directed = false, int offset = 1) {\n  vector<vector<pair<int,\
    \ T>>> g(n);\n  for (int i = 0; i < m; i++) {\n    int u, v;\n    T w;\n    cin\
    \ >> u >> v >> w;\n    u -= offset, v -= offset;\n    g[u].push_back({v, w});\n\
    \    if (!directed) g[v].push_back({u, w});\n  }\n  return g;\n}\n}  // namespace\
    \ Graph\nnamespace Tree {\nvector<vector<int>> unweighted(int n, bool directed\
    \ = false, int offset = 1) {\n  return Graph::unweighted(n, n - 1, directed, offset);\n\
    }\ntemplate <class T>\nvector<vector<pair<int, T>>> weighted(int n, bool directed\
    \ = false, int offset = 1) {\n  return Graph::weighted<T>(n, n - 1, directed,\
    \ offset);\n}\nvector<vector<int>> rooted(int n, bool to_root = true, bool to_leaf\
    \ = true, int offset = 1) {\n  vector<vector<int>> g(n);\n  for (int i = 1; i\
    \ < n; i++) {\n    int p;\n    cin >> p;\n    p -= offset;\n    if (to_root) g[i].push_back(p);\n\
    \    if (to_leaf) g[p].push_back(i);\n  }\n  return g;\n}\n}  // namespace Tree\n\
    }  // namespace IO\n#line 10 \"template/template.hpp\"\n\n#line 2 \"template/debug.hpp\"\
    \n#ifdef LOCAL\n#define debug 1\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\n\
    #else\n#define debug 0\n#define show(...) true\n#endif\ntemplate <class T>\nvoid\
    \ _show(int i, T name) {\n  cerr << '\\n';\n}\ntemplate <class T1, class T2, class...\
    \ T3>\nvoid _show(int i, const T1& a, const T2& b, const T3&... c) {\n  for (;\
    \ a[i] != ',' && a[i] != '\\0'; i++) cerr << a[i];\n  cerr << \":\" << b << \"\
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"algebraic-structure/util.hpp\"\n\
    #ifdef __cpp_concepts\n#define REQUIRES(...) requires __VA_ARGS__\n#else\n#define\
    \ REQUIRES(...)\n#endif\n#line 3 \"algebraic-structure/magma.hpp\"\n\n#ifdef __cpp_concepts\n\
    template <class M>\nconcept Magma = requires(typename M::value_type x, typename\
    \ M::value_type y) {\n  typename M::value_type;\n  { M::op(x, y) } -> same_as<typename\
    \ M::value_type>;\n};\n#endif\n\ntemplate <class T>\nstruct AddMagma {\n  using\
    \ value_type = T;\n  static T op(T x, T y) { return x + y; }\n};\ntemplate <class\
    \ T>\nstruct MulMagma {\n  using value_type = T;\n  static T op(T x, T y) { return\
    \ x * y; }\n};\ntemplate <class T, T id>\nstruct MaxMagma {\n  using value_type\
    \ = T;\n  static T op(T x, T y) { return x > y ? x : y; }\n};\ntemplate <class\
    \ T, T id>\nstruct MinMagma {\n  using value_type = T;\n  static T op(T x, T y)\
    \ { return x < y ? x : y; }\n};\n#line 3 \"algebraic-structure/monoid.hpp\"\n\n\
    #ifdef __cpp_concepts\ntemplate <class M>\nconcept Monoid = Magma<M> && requires\
    \ {\n  { M::e() } -> same_as<typename M::value_type>;\n};\n#endif\n\ntemplate\
    \ <class T>\nstruct AddMonoid {\n  using value_type = T;\n  static T op(T x, T\
    \ y) { return x + y; }\n  static T e() { return T(0); }\n};\ntemplate <class T>\n\
    struct MulMonoid {\n  using value_type = T;\n  static T op(T x, T y) { return\
    \ x * y; }\n  static T e() { return T(1); }\n};\ntemplate <class T, T id>\nstruct\
    \ MaxMonoid {\n  using value_type = T;\n  static T op(T x, T y) { return x > y\
    \ ? x : y; }\n  static T e() { return id; }\n};\ntemplate <class T, T id>\nstruct\
    \ MinMonoid {\n  using value_type = T;\n  static T op(T x, T y) { return x < y\
    \ ? x : y; }\n  static T e() { return id; }\n};\n#line 3 \"segment-tree/segment-tree.hpp\"\
    \n\ntemplate <class M>\nREQUIRES(Monoid<M>)\nstruct SegmentTree {\n  using T =\
    \ typename M::value_type;\n\n private:\n  int _n, size, log;\n  vector<T> d;\n\
    \  void update(int p) { d[p] = M::op(d[2 * p], d[2 * p + 1]); }\n\n public:\n\
    \  SegmentTree() : SegmentTree(0) {}\n  explicit SegmentTree(int sz) : SegmentTree(vector<T>(sz,\
    \ M::e())) {}\n  explicit SegmentTree(const vector<T>& v) : _n(v.size()) {\n \
    \   size = 1, log = 0;\n    while (size < _n) size <<= 1, log++;\n    d.assign(2\
    \ * size, M::e());\n    for (int i = 0; i < _n; i++) d[size + i] = v[i];\n   \
    \ for (int i = size - 1; i > 0; i--) update(i);\n  }\n  void clear() { fill(d.begin(),\
    \ d.end(), M::e()); }\n\n  void set_without_update(int p, T v) { d[p + size] =\
    \ v; }\n  void all_update() {\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n  T get(int p) {\n    assert(0 <= p && p <= _n);\n    return d[p + size];\n\
    \  }\n  void set(int p, T v) {\n    assert(0 <= p && p <= _n);\n    p += size;\n\
    \    d[p] = v;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void\
    \ apply(int p, T v) {\n    assert(0 <= p && p <= _n);\n    p += size;\n    d[p]\
    \ = M::op(d[p], v);\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\
    \  T all_prod() { return d[1]; }\n  T prod(int l, int r) {\n    if (l >= r) return\
    \ M::e();\n    assert(0 <= l && l <= r && r <= _n);\n    T sl = M::e(), sr = M::e();\n\
    \    l += size, r += size;\n    while (l < r) {\n      if ((l & 1) != 0) sl =\
    \ M::op(sl, d[l++]);\n      if ((r & 1) != 0) sr = M::op(d[--r], sr);\n      l\
    \ >>= 1, r >>= 1;\n    }\n    return M::op(sl, sr);\n  }\n\n  template <bool (*f)(T)>\n\
    \  int max_right(int l) const {\n    return max_right(l, [](T x) { return f(x);\
    \ });\n  }\n  template <class F>\n  int max_right(int l, F f) const {\n    assert(0\
    \ <= l && l <= size);\n    assert(f(M::e()));\n    if (l == _n) return _n;\n \
    \   l += size;\n    T s = M::e();\n    do {\n      while (l % 2 == 0) l >>= 1;\n\
    \      if (!f(M::op(s, d[l]))) {\n        while (l < size) {\n          l <<=\
    \ 1;\n          if (f(M::op(s, d[l]))) s = M::op(s, d[l++]);\n        }\n    \
    \    return l - size;\n      }\n      s = M::op(s, d[l++]);\n    } while ((l &\
    \ -l) != l);\n    return _n;\n  }\n\n  template <bool (*f)(T)>\n  int min_left(int\
    \ r) const {\n    return min_left(r, [](T x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int min_left(int r, F f) const {\n    assert(0 <= r && r <= _n);\n\
    \    assert(f(M::e()));\n    if (r == 0) return 0;\n    r += size;\n    T s =\
    \ M::e();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n   \
    \   if (!f(M::op(d[r], s))) {\n        while (r < size) {\n          r <<= 1,\
    \ r++;\n          if (f(M::op(d[r], s))) s = M::op(d[r--], s);\n        }\n  \
    \      return r + 1 - size;\n      }\n      s = M::op(d[r], s);\n    } while ((r\
    \ & -r) != r);\n    return 0;\n  }\n};\n\n/**\n * @brief Segment Tree\n * @docs\
    \ docs/segment-tree/segment-tree.md\n */\n#line 5 \"verify/segment-tree/LC_point_add_range_sum.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  in(n, q);\n  vector<ll> a(n);\n  in(a);\n  SegmentTree<AddMonoid<ll>>\
    \ seg(a);\n  while (q--) {\n    int t;\n    in(t);\n    if (t == 0) {\n      int\
    \ p, x;\n      in(p, x);\n      seg.apply(p, x);\n    } else {\n      int l, r;\n\
    \      in(l, r);\n      out(seg.prod(l, r));\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"template/template.hpp\"\n#include \"segment-tree/segment-tree.hpp\"\
    \n\nint main() {\n  int n, q;\n  in(n, q);\n  vector<ll> a(n);\n  in(a);\n  SegmentTree<AddMonoid<ll>>\
    \ seg(a);\n  while (q--) {\n    int t;\n    in(t);\n    if (t == 0) {\n      int\
    \ p, x;\n      in(p, x);\n      seg.apply(p, x);\n    } else {\n      int l, r;\n\
    \      in(l, r);\n      out(seg.prod(l, r));\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - segment-tree/segment-tree.hpp
  - algebraic-structure/monoid.hpp
  - algebraic-structure/magma.hpp
  - algebraic-structure/util.hpp
  isVerificationFile: true
  path: verify/segment-tree/LC_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-06-28 15:32:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree/LC_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree/LC_point_add_range_sum.test.cpp
- /verify/verify/segment-tree/LC_point_add_range_sum.test.cpp.html
title: verify/segment-tree/LC_point_add_range_sum.test.cpp
---
