---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
  - icon: ':heavy_check_mark:'
    path: union-find/potentialized-union-find.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"verify/union-find/LC_unionfind_with_potential.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"modint/modint.hpp\"\n\ntemplate\
    \ <unsigned int m = 998244353>\nstruct ModInt {\n  using mint = ModInt;\n  unsigned\
    \ int _v;\n  static constexpr unsigned int get_mod() { return m; }\n  static mint\
    \ raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n  ModInt() : _v(0)\
    \ {}\n  ModInt(int64_t v) {\n    long long x = (long long)(v % (long long)(umod()));\n\
    \    if (x < 0) x += umod();\n    _v = (unsigned int)(x);\n  }\n  unsigned int\
    \ val() const { return _v; }\n  mint &operator++() {\n    _v++;\n    if (_v ==\
    \ umod()) _v = 0;\n    return *this;\n  }\n  mint &operator--() {\n    if (_v\
    \ == 0) _v = umod();\n    _v--;\n    return *this;\n  }\n  mint operator++(int)\
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
    \ private:\n  static constexpr unsigned int umod() { return m; }\n};\n#line 5\
    \ \"verify/union-find/LC_unionfind_with_potential.test.cpp\"\nusing mint = ModInt<998244353>;\n\
    #line 2 \"union-find/potentialized-union-find.hpp\"\n\ntemplate <class T>\nstruct\
    \ PotentializedUnionFind {\n private:\n  vector<int> a;\n  vector<T> p;\n\n public:\n\
    \  PotentializedUnionFind(int n) : a(n, -1), p(n, 0) {}\n  int find(int v) {\n\
    \    if (a[v] < 0) return v;\n    int r = find(a[v]);\n    p[v] += p[a[v]];\n\
    \    return a[v] = r;\n  }\n  int size(int v) { return -a[find(v)]; }\n  bool\
    \ same(int u, int v) { return find(u) == find(v); }\n  // p[u]-p[v]=w\n  bool\
    \ unite(int u, int v, T w) {\n    int x = find(u), y = find(v);\n    if (x ==\
    \ y) return p[u] - p[v] == w;\n    w -= p[u], w += p[v];\n    if (a[x] < a[y])\
    \ {\n      p[y] = p[x] - w;\n      a[x] += a[y];\n      a[y] = x;\n    } else\
    \ {\n      p[x] = p[y] + w;\n      a[y] += a[x];\n      a[x] = y;\n    }\n   \
    \ return true;\n  }\n  // p[u]-p[v]\n  T diff(int u, int v) { return p[u] - p[v];\
    \ }\n};\n/**\n * @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union\
    \ Find\n * @docs docs/union-find/potentialized-union-find.md\n */\n#line 7 \"\
    verify/union-find/LC_unionfind_with_potential.test.cpp\"\n\nint main() {\n  int\
    \ n, q;\n  in(n, q);\n  PotentializedUnionFind<mint> uf(n);\n  while (q--) {\n\
    \    int type, u, v;\n    in(type, u, v);\n    if (type == 0) {\n      mint w;\n\
    \      in(w);\n      out(uf.unite(u, v, w));\n    } else {\n      if (uf.same(u,\
    \ v))\n        out(uf.diff(u, v));\n      else\n        out(-1);\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing\
    \ mint = ModInt<998244353>;\n#include \"union-find/potentialized-union-find.hpp\"\
    \n\nint main() {\n  int n, q;\n  in(n, q);\n  PotentializedUnionFind<mint> uf(n);\n\
    \  while (q--) {\n    int type, u, v;\n    in(type, u, v);\n    if (type == 0)\
    \ {\n      mint w;\n      in(w);\n      out(uf.unite(u, v, w));\n    } else {\n\
    \      if (uf.same(u, v))\n        out(uf.diff(u, v));\n      else\n        out(-1);\n\
    \    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - union-find/potentialized-union-find.hpp
  isVerificationFile: true
  path: verify/union-find/LC_unionfind_with_potential.test.cpp
  requiredBy: []
  timestamp: '2025-10-24 10:50:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/union-find/LC_unionfind_with_potential.test.cpp
layout: document
redirect_from:
- /verify/verify/union-find/LC_unionfind_with_potential.test.cpp
- /verify/verify/union-find/LC_unionfind_with_potential.test.cpp.html
title: verify/union-find/LC_unionfind_with_potential.test.cpp
---
