---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/stern-brocot-tree.hpp
    title: Stern-Brocot Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"verify/math/LC_stern_brocot_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"template/macro.hpp\"\
    \n#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)\n#define rrep(i, a,\
    \ b) for (int i = (int)(b) - 1; i >= (a); i--)\n#define ALL(v) (v).begin(), (v).end()\n\
    #define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\n#define\
    \ SZ(v) (int)v.size()\n#define MIN(v) *min_element(ALL(v))\n#define MAX(v) *max_element(ALL(v))\n\
    #define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())\n#define UB(v, x)\
    \ int(upper_bound(ALL(v), (x)) - (v).begin())\n#define YN(b) cout << ((b) ? \"\
    YES\" : \"NO\") << \"\\n\";\n#define Yn(b) cout << ((b) ? \"Yes\" : \"No\") <<\
    \ \"\\n\";\n#define yn(b) cout << ((b) ? \"yes\" : \"no\") << \"\\n\";\n#line\
    \ 6 \"template/template.hpp\"\n\n#line 2 \"template/util.hpp\"\nusing uint = unsigned\
    \ int;\nusing ll = long long int;\nusing ull = unsigned long long;\nusing i128\
    \ = __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <class T, class S = T>\n\
    S SUM(const vector<T> &a) {\n  return accumulate(ALL(a), S(0));\n}\ntemplate <class\
    \ T>\ninline bool chmin(T &a, T b) {\n  if (a > b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <class T>\ninline bool chmax(T &a, T b) {\n\
    \  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\ntemplate\
    \ <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n}\ntemplate\
    \ <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"math/stern-brocot-tree.hpp\"\n\n\
    template <class T>\nstruct SternBrocotTreeNode {\n  using Node = SternBrocotTreeNode;\n\
    \  T la, lb, a, b, ra, rb;\n  vector<T> seq;\n  SternBrocotTreeNode() : la(0),\
    \ lb(1), a(1), b(1), ra(1), rb(0) {}\n  SternBrocotTreeNode(T x, T y) : SternBrocotTreeNode()\
    \ {\n    assert(x > 0 && y > 0);\n    T g = gcd(x, y);\n    x /= g, y /= g;\n\
    \    bool is_right = true;\n    while (x > 0 && y > 0) {\n      T d = x / y;\n\
    \      x -= d * y;\n      if (is_right)\n        go_right(d - (x == 0 ? 1 : 0));\n\
    \      else\n        go_left(d - (x == 0 ? 1 : 0));\n      swap(x, y);\n     \
    \ is_right = !is_right;\n    }\n  }\n  SternBrocotTreeNode(pair<T, T> p) : SternBrocotTreeNode(p.first,\
    \ p.second) {}\n  SternBrocotTreeNode(const vector<T> seq_) {\n    for (auto&\
    \ v : seq_) {\n      assert(v != 0);\n      if (v > 0)\n        go_right(v);\n\
    \      else\n        go_left(v);\n    }\n    assert(seq == seq_);\n  }\n  pair<T,\
    \ T> get() const { return {a, b}; }\n  pair<T, T> lower_bound() const { return\
    \ {la, lb}; }\n  pair<T, T> upper_bound() const { return {ra, rb}; }\n\n  void\
    \ go_left(const T d = 1) {\n    if (d <= 0) return;\n    if (seq.empty() || seq.back()\
    \ > 0) seq.push_back(0);\n    seq.back() -= d;\n    ra += la * d, rb += lb * d;\n\
    \    a = la + ra, b = lb + rb;\n  }\n  void go_right(const T d = 1) {\n    if\
    \ (d <= 0) return;\n    if (seq.empty() || seq.back() < 0) seq.push_back(0);\n\
    \    seq.back() += d;\n    la += ra * d, lb += rb * d;\n    a = la + ra, b = lb\
    \ + rb;\n  }\n  T depth() const {\n    T d = 0;\n    for (auto& v : seq) d +=\
    \ abs(v);\n    return d;\n  }\n  static Node lca(const Node& x, const Node& y)\
    \ {\n    Node res;\n    for (int i = 0; i < min(x.seq.size(), y.seq.size()); i++)\
    \ {\n      T d1 = x.seq[i], d2 = y.seq[i];\n      if ((d1 > 0) != (d2 > 0)) break;\n\
    \      if (d1 > 0)\n        res.go_right(min(d1, d2));\n      else\n        res.go_left(min(-d1,\
    \ -d2));\n      if (d1 != d2) break;\n    }\n    return res;\n  }\n  bool go_parent(T\
    \ d = 1) {\n    if (d <= 0) return true;\n    while (d > 0) {\n      if (seq.empty())\
    \ return false;\n      T d1 = min(d, abs(seq.back()));\n      if (seq.back() >\
    \ 0) {\n        la -= ra * d1, lb -= rb * d1;\n        seq.back() -= d1;\n   \
    \   } else {\n        ra -= la * d1, rb -= lb * d1;\n        seq.back() += d1;\n\
    \      }\n      a = la + ra, b = lb + rb;\n      if (seq.back() <= 0) seq.pop_back();\n\
    \      d -= d1;\n    }\n    return true;\n  }\n  template <class F>\n  static\
    \ Node binary_search(T n, F f) {\n    Node res;\n    while (true) {\n      if\
    \ (!f(res.a, res.b)) {\n        T ok = 0, ng = min(res.la > 0 ? (n - res.ra) /\
    \ res.la : n, res.lb > 0 ? (n - res.rb) / res.lb : n) + 1;\n        while (ng\
    \ - ok > 1) {\n          T mid = (ok + ng) / 2;\n          (!f(mid * res.la +\
    \ res.ra, mid * res.lb + res.rb) ? ok : ng) = mid;\n        }\n        if (ok\
    \ == 0) return res;\n        res.go_left(ok);\n      } else {\n        T ok =\
    \ 0, ng = min(res.ra > 0 ? (n - res.la) / res.ra : n, res.rb > 0 ? (n - res.lb)\
    \ / res.rb : n) + 1;\n        while (ng - ok > 1) {\n          T mid = (ok + ng)\
    \ / 2;\n          (f(res.la + mid * res.ra, res.lb + mid * res.rb) ? ok : ng)\
    \ = mid;\n        }\n        if (ok == 0) return res;\n        res.go_left(ok);\n\
    \      }\n    }\n  }\n};\n\n/**\n * @brief Stern-Brocot Tree\n * @docs docs/math/stern-brocot-tree.md\n\
    \ */\n#line 5 \"verify/math/LC_stern_brocot_tree.test.cpp\"\nusing sbt = SternBrocotTreeNode<ll>;\n\
    \nint main() {\n  int t;\n  in(t);\n  while (t--) {\n    string s;\n    in(s);\n\
    \    if (s == \"ENCODE_PATH\") {\n      ll a, b;\n      in(a, b);\n      sbt x(a,\
    \ b);\n      cout << x.seq.size();\n      for (auto v : x.seq) cout << \" \" <<\
    \ \"LR\"[v > 0] << \" \" << abs(v);\n      cout << \"\\n\";\n    } else if (s\
    \ == \"DECODE_PATH\") {\n      sbt x;\n      int k;\n      in(k);\n      rep(i,\
    \ 0, k) {\n        char dir;\n        ll n;\n        in(dir, n);\n        if (dir\
    \ == 'L')\n          x.go_left(n);\n        else\n          x.go_right(n);\n \
    \     }\n      out(x.a, x.b);\n    } else if (s == \"LCA\") {\n      ll a, b,\
    \ c, d;\n      in(a, b, c, d);\n      sbt x = sbt::lca(sbt(a, b), sbt(c, d));\n\
    \      out(x.a, x.b);\n    } else if (s == \"ANCESTOR\") {\n      ll k, a, b;\n\
    \      in(k, a, b);\n      sbt x(a, b);\n      ll d = x.depth() - k;\n      if\
    \ (d >= 0 && x.go_parent(d))\n        out(x.a, x.b);\n      else\n        out(-1);\n\
    \    } else if (s == \"RANGE\") {\n      ll a, b;\n      in(a, b);\n      sbt\
    \ x(a, b);\n      out(x.lower_bound(), x.upper_bound());\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"template/template.hpp\"\n#include \"math/stern-brocot-tree.hpp\"\n\
    using sbt = SternBrocotTreeNode<ll>;\n\nint main() {\n  int t;\n  in(t);\n  while\
    \ (t--) {\n    string s;\n    in(s);\n    if (s == \"ENCODE_PATH\") {\n      ll\
    \ a, b;\n      in(a, b);\n      sbt x(a, b);\n      cout << x.seq.size();\n  \
    \    for (auto v : x.seq) cout << \" \" << \"LR\"[v > 0] << \" \" << abs(v);\n\
    \      cout << \"\\n\";\n    } else if (s == \"DECODE_PATH\") {\n      sbt x;\n\
    \      int k;\n      in(k);\n      rep(i, 0, k) {\n        char dir;\n       \
    \ ll n;\n        in(dir, n);\n        if (dir == 'L')\n          x.go_left(n);\n\
    \        else\n          x.go_right(n);\n      }\n      out(x.a, x.b);\n    }\
    \ else if (s == \"LCA\") {\n      ll a, b, c, d;\n      in(a, b, c, d);\n    \
    \  sbt x = sbt::lca(sbt(a, b), sbt(c, d));\n      out(x.a, x.b);\n    } else if\
    \ (s == \"ANCESTOR\") {\n      ll k, a, b;\n      in(k, a, b);\n      sbt x(a,\
    \ b);\n      ll d = x.depth() - k;\n      if (d >= 0 && x.go_parent(d))\n    \
    \    out(x.a, x.b);\n      else\n        out(-1);\n    } else if (s == \"RANGE\"\
    ) {\n      ll a, b;\n      in(a, b);\n      sbt x(a, b);\n      out(x.lower_bound(),\
    \ x.upper_bound());\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - math/stern-brocot-tree.hpp
  isVerificationFile: true
  path: verify/math/LC_stern_brocot_tree.test.cpp
  requiredBy: []
  timestamp: '2025-10-26 03:52:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/LC_stern_brocot_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/math/LC_stern_brocot_tree.test.cpp
- /verify/verify/math/LC_stern_brocot_tree.test.cpp.html
title: verify/math/LC_stern_brocot_tree.test.cpp
---
