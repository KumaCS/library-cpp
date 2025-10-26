---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: Segment Tree
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"segment-tree/segment-tree.hpp\"\n\
    \ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct SegmentTree {\n private:\n\
    \  int n;\n  vector<T> d;\n  void update(int p) { d[p] = op(d[2 * p], d[2 * p\
    \ + 1]); }\n\n public:\n  SegmentTree() : SegmentTree(0) {}\n  explicit SegmentTree(int\
    \ sz) : SegmentTree(vector<T>(sz, e())) {}\n  explicit SegmentTree(const vector<T>&\
    \ v) : n(v.size()) {\n    d.assign(2 * n, e());\n    for (int i = 0; i < v.size();\
    \ i++) d[n + i] = v[i];\n    for (int i = n - 1; i > 0; i--) update(i);\n  }\n\
    \  void clear() { fill(d.begin(), d.end(), e()); }\n\n  void set_without_update(int\
    \ p, T v) { d[n + p] = v; }\n  void all_update() {\n    for (int i = n - 1; i\
    \ > 0; i--) update(i);\n  }\n  T get(int p) {\n    assert(0 <= p && p <= n);\n\
    \    return d[p + n];\n  }\n  void set(int p, T v) {\n    assert(0 <= p && p <=\
    \ n);\n    d[p += n] = v;\n    for (p >>= 1; p > 0; p >>= 1) update(p);\n  }\n\
    \  void apply(int p, T v) {\n    assert(0 <= p && p <= n);\n    p += n;\n    d[p]\
    \ = op(d[p], v);\n    for (p >>= 1; p > 0; p >>= 1) update(p);\n  }\n  T prod(int\
    \ l, int r) {\n    if (l >= r) return e();\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    T sl = e(), sr = e();\n    l += n, r += n;\n    while (l < r) {\n \
    \     if ((l & 1) != 0) sl = op(sl, d[l++]);\n      if ((r & 1) != 0) sr = op(d[--r],\
    \ sr);\n      l >>= 1, r >>= 1;\n    }\n    return op(sl, sr);\n  }\n  T all_prod()\
    \ { return prod(0, n); }\n\n  template <bool (*f)(T)>\n  int max_right(int l)\
    \ const {\n    return max_right(l, [](T x) { return f(x); });\n  }\n  template\
    \ <class F>\n  int max_right(int l, F f) const {\n    assert(0 <= l && l <= n);\n\
    \    assert(f(e()));\n    if (l == n) return n;\n    int x = n + l, w = 1;\n \
    \   T s = e();\n    for (; l + w <= n; x >>= 1, w <<= 1)\n      if (x & 1) {\n\
    \        if (!f(op(s, d[x]))) break;\n        s = op(s, d[x++]);\n        l +=\
    \ w;\n      }\n    while (x <<= 1, w >>= 1) {\n      if (l + w <= n && f(op(s,\
    \ d[x]))) {\n        s = op(s, d[l++]);\n        l += w;\n      }\n    }\n   \
    \ return l;\n  }\n\n  template <bool (*f)(T)>\n  int min_left(int r) const {\n\
    \    return min_left(r, [](T x) { return f(x); });\n  }\n  template <class F>\n\
    \  int min_left(int r, F f) const {\n    assert(0 <= r && r <= n);\n    assert(f(e()));\n\
    \    if (r == 0) return 0;\n    int x = n + r, w = 1;\n    T s = e();\n    for\
    \ (; r - w >= 0; x >>= 1, w <<= 1)\n      if (x & 1) {\n        if (!f(op(d[x\
    \ - 1], s))) break;\n        s = op(d[--x], s);\n        r -= w;\n      }\n  \
    \  while (x <<= 1, w >>= 1) {\n      if (r - w >= 0 && f(op(d[x - 1], s))) {\n\
    \        s = op(d[--x], s);\n        r -= w;\n      }\n    }\n    return r;\n\
    \  }\n};\n\n/**\n * @brief Segment Tree\n * @docs docs/segment-tree/segment-tree.md\n\
    \ */\n#line 5 \"verify/segment-tree/LC_point_add_range_sum.test.cpp\"\n\nll op(ll\
    \ x, ll y) { return x + y; }\nll e() { return 0; }\n\nint main() {\n  int n, q;\n\
    \  in(n, q);\n  vector<ll> a(n);\n  in(a);\n  SegmentTree<ll, op, e> seg(a);\n\
    \  while (q--) {\n    int t;\n    in(t);\n    if (t == 0) {\n      int p, x;\n\
    \      in(p, x);\n      seg.apply(p, x);\n    } else {\n      int l, r;\n    \
    \  in(l, r);\n      out(seg.prod(l, r));\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"template/template.hpp\"\n#include \"segment-tree/segment-tree.hpp\"\
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
  - segment-tree/segment-tree.hpp
  isVerificationFile: true
  path: verify/segment-tree/LC_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segment-tree/LC_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/segment-tree/LC_point_add_range_sum.test.cpp
- /verify/verify/segment-tree/LC_point_add_range_sum.test.cpp.html
title: verify/segment-tree/LC_point_add_range_sum.test.cpp
---
