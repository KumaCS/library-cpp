---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree-pow2.hpp
    title: "Segment Tree (\u9577\u3055\u30922\u51AA\u306B\u3059\u308B)"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/segment-tree/LC_point_add_range_sum.pow2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ <class T, class S = T>\nS SUM(const vector<T> &a) {\n  return accumulate(ALL(a),\
    \ S(0));\n}\ntemplate <class T>\ninline bool chmin(T &a, T b) {\n  if (a > b)\
    \ {\n    a = b;\n    return true;\n  }\n  return false;\n}\ntemplate <class T>\n\
    inline bool chmax(T &a, T b) {\n  if (a < b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\n\ntemplate <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n\
    }\ntemplate <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
    }\ntemplate <class T>\nint lowbit(T x) {\n  return (x == 0 ? -1 : __builtin_ctzll(x));\n\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"segment-tree/segment-tree-pow2.hpp\"\
    \n\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct SegmentTree {\n private:\n\
    \  int _n, size, log;\n  vector<T> d;\n  void update(int p) { d[p] = op(d[2 *\
    \ p], d[2 * p + 1]); }\n\n public:\n  SegmentTree() : SegmentTree(0) {}\n  explicit\
    \ SegmentTree(int sz) : SegmentTree(vector<T>(sz, e())) {}\n  explicit SegmentTree(const\
    \ vector<T>& v) : _n(v.size()) {\n    size = 1, log = 0;\n    while (size < _n)\
    \ size <<= 1, log++;\n    d.assign(2 * size, e());\n    for (int i = 0; i < v.size();\
    \ i++) d[size + i] = v[i];\n    for (int i = size - 1; i > 0; i--) update(i);\n\
    \  }\n  void clear() { fill(d.begin(), d.end(), e()); }\n\n  void set_without_update(int\
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
    \n/**\n * @brief Segment Tree (\u9577\u3055\u30922\u51AA\u306B\u3059\u308B)\n\
    \ * @docs docs/segment-tree/segment-tree.md\n */\n#line 5 \"verify/segment-tree/LC_point_add_range_sum.pow2.test.cpp\"\
    \n\nll op(ll x, ll y) { return x + y; }\nll e() { return 0; }\n\nint main() {\n\
    \  int n, q;\n  in(n, q);\n  vector<ll> a(n);\n  in(a);\n  SegmentTree<ll, op,\
    \ e> seg(a);\n  while (q--) {\n    int t;\n    in(t);\n    if (t == 0) {\n   \
    \   int p, x;\n      in(p, x);\n      seg.apply(p, x);\n    } else {\n      int\
    \ l, r;\n      in(l, r);\n      out(seg.prod(l, r));\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"template/template.hpp\"\n#include \"segment-tree/segment-tree-pow2.hpp\"\
    \n\nll op(ll x, ll y) { return x + y; }\nll e() { return 0; }\n\nint main() {\n\
    \  int n, q;\n  in(n, q);\n  vector<ll> a(n);\n  in(a);\n  SegmentTree<ll, op,\
    \ e> seg(a);\n  while (q--) {\n    int t;\n    in(t);\n    if (t == 0) {\n   \
    \   int p, x;\n      in(p, x);\n      seg.apply(p, x);\n    } else {\n      int\
    \ l, r;\n      in(l, r);\n      out(seg.prod(l, r));\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - segment-tree/segment-tree-pow2.hpp
  isVerificationFile: true
  path: verify/segment-tree/LC_point_add_range_sum.pow2.test.cpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree/LC_point_add_range_sum.pow2.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree/LC_point_add_range_sum.pow2.test.cpp
- /verify/verify/segment-tree/LC_point_add_range_sum.pow2.test.cpp.html
title: verify/segment-tree/LC_point_add_range_sum.pow2.test.cpp
---
