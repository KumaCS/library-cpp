---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: binary-search-tree/rbst-array.hpp
    title: "\u633F\u5165/\u524A\u9664\u306E\u53EF\u80FD\u306A\u914D\u5217 (\u4E71\u629E\
      \u4E8C\u5206\u63A2\u7D22\u6728)"
  - icon: ':heavy_check_mark:'
    path: binary-search-tree/rbst-base.hpp
    title: "Randomized Binary Search Tree (\u57FA\u5E95\u30AF\u30E9\u30B9)"
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
    path: util/xorshift.hpp
    title: XOR shift
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/binary-search-tree/UNIT_rbst_array.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
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
    S SUM(const vector<T>& a) {\n  return accumulate(ALL(a), S(0));\n}\ntemplate <class\
    \ T>\ninline bool chmin(T& a, T b) {\n  if (a > b) {\n    a = b;\n    return true;\n\
    \  }\n  return false;\n}\ntemplate <class T>\ninline bool chmax(T& a, T b) {\n\
    \  if (a < b) {\n    a = b;\n    return true;\n  }\n  return false;\n}\n\ntemplate\
    \ <class T>\nint popcnt(T x) {\n  return __builtin_popcountll(x);\n}\ntemplate\
    \ <class T>\nint topbit(T x) {\n  return (x == 0 ? -1 : 63 - __builtin_clzll(x));\n\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"binary-search-tree/rbst-base.hpp\"\
    \n\ntemplate <class Node>\nstruct RBSTBase {\n  using Ptr = Node*;\n  template\
    \ <typename... Args>\n  inline Ptr my_new(Args... args) {\n    return new Node(args...);\n\
    \  }\n  inline void my_del(Ptr t) { delete t; }\n  inline Ptr make_tree() const\
    \ { return nullptr; }\n\n  int size(Ptr t) const { return count(t); }\n  Ptr merge(Ptr\
    \ l, Ptr r) {\n    if (!l || !r) return l ? l : r;\n    if (int((rng() * (l->cnt\
    \ + r->cnt)) >> 32) < l->cnt) {\n      push(l);\n      l->r = merge(l->r, r);\n\
    \      return update(l);\n    } else {\n      push(r);\n      r->l = merge(l,\
    \ r->l);\n      return update(r);\n    }\n  }\n  pair<Ptr, Ptr> split(Ptr t, int\
    \ k) {\n    if (!t) return {nullptr, nullptr};\n    push(t);\n    if (k <= count(t->l))\
    \ {\n      auto s = split(t->l, k);\n      t->l = s.second;\n      return {s.first,\
    \ update(t)};\n    } else {\n      auto s = split(t->r, k - count(t->l) - 1);\n\
    \      t->r = s.first;\n      return {update(t), s.second};\n    }\n  }\n  Ptr\
    \ build(int l, int r, const vector<decltype(Node::key)>& v) {\n    if (l + 1 ==\
    \ r) return my_new(v[l]);\n    int m = (l + r) >> 1;\n    Ptr pm = my_new(v[m]);\n\
    \    if (l < m) pm->l = build(l, m, v);\n    if (m + 1 < r) pm->r = build(m +\
    \ 1, r, v);\n    return update(pm);\n  }\n  Ptr build(const vector<decltype(Node::key)>&\
    \ v) {\n    return build(0, (int)v.size(), v);\n  }\n  template <typename... Args>\n\
    \  void insert(Ptr& t, int k, const Args&... args) {\n    auto x = split(t, k);\n\
    \    t = merge(merge(x.first, my_new(args...)), x.second);\n  }\n  void erase(Ptr&\
    \ t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second, 1);\n \
    \   my_del(y.first);\n    t = merge(x.first, y.second);\n  }\n\n protected:\n\
    \  static uint64_t rng() {\n    static uint64_t x_ = 123456789ull;\n    return\
    \ x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n  }\n  inline int count(const\
    \ Ptr t) const { return t ? t->cnt : 0; }\n  virtual void push(Ptr) = 0;\n  virtual\
    \ Ptr update(Ptr) = 0;\n};\n\n/**\n * @brief Randomized Binary Search Tree (\u57FA\
    \u5E95\u30AF\u30E9\u30B9)\n * @docs docs/binary-search-tree/rbst-base.md\n */\n\
    #line 3 \"binary-search-tree/rbst-array.hpp\"\n\ntemplate <typename T>\nstruct\
    \ RBSTArrayNode {\n  typename RBSTBase<RBSTArrayNode>::Ptr l, r;\n  T key;\n \
    \ int cnt;\n  RBSTArrayNode(const T& t = T()) : l(), r(), key(t), cnt(1) {}\n\
    };\n\ntemplate <class T>\nstruct RBSTArray : RBSTBase<RBSTArrayNode<T>> {\n  using\
    \ Node = RBSTArrayNode<T>;\n  using base = RBSTBase<Node>;\n  using base::merge;\n\
    \  using base::split;\n  using typename base::Ptr;\n\n  RBSTArray() = default;\n\
    \  T get(Ptr& t, int k) {\n    auto x = split(t, k);\n    auto y = split(x.second,\
    \ 1);\n    T v = y.first->key;\n    t = merge(x.first, merge(y.first, y.second));\n\
    \    return v;\n  }\n  void set(Ptr& t, int k, T v) {\n    auto x = split(t, k);\n\
    \    auto y = split(x.second, 1);\n    y.first->key = v;\n    t = merge(x.first,\
    \ merge(y.first, y.second));\n  }\n\n protected:\n  Ptr update(Ptr t) override\
    \ {\n    t->cnt = 1;\n    if (t->l) t->cnt += t->l->cnt;\n    if (t->r) t->cnt\
    \ += t->r->cnt;\n    return t;\n  }\n  void push(Ptr t) override {}\n};\n\n/**\n\
    \ * @brief \u633F\u5165/\u524A\u9664\u306E\u53EF\u80FD\u306A\u914D\u5217 (\u4E71\
    \u629E\u4E8C\u5206\u63A2\u7D22\u6728)\n */\n#line 2 \"util/xorshift.hpp\"\n\n\
    namespace XORShift {\nunsigned int xor32() {\n  static unsigned int x = 123456789u;\n\
    \  x ^= x << 13, x ^= x >> 17, x ^= x << 5;\n  return x;\n}\nunsigned long long\
    \ xor64() {\n  static unsigned long long x = 123456789ull;\n  x ^= x << 13, x\
    \ ^= x >> 7, x ^= x << 17;\n  return x;\n}\n};  // namespace XORShift\n\n/**\n\
    \ * @brief XOR shift\n */\n#line 6 \"verify/binary-search-tree/UNIT_rbst_array.test.cpp\"\
    \n\nvoid test() {\n  vector<int> a;\n  RBSTArray<int> ar;\n  auto t = ar.make_tree();\n\
    \n  rep(loop, 0, 10000) {\n    int type = XORShift::xor32() % 3;\n    if (a.empty())\
    \ type = 0;\n    if (type == 0) {\n      int x = XORShift::xor32() % (a.size()\
    \ + 1);\n      int v = XORShift::xor32();\n      a.insert(a.begin() + x, v);\n\
    \      ar.insert(t, x, v);\n    } else if (type == 1) {\n      int x = XORShift::xor32()\
    \ % a.size();\n      int v = XORShift::xor32();\n      a[x] = v;\n      ar.set(t,\
    \ x, v);\n    } else {\n      int x = XORShift::xor32() % a.size();\n      a.erase(a.begin()\
    \ + x);\n      ar.erase(t, x);\n    }\n    assert(a.size() == ar.size(t));\n \
    \   rep(i, 0, a.size()) assert(a[i] == ar.get(t, i));\n  }\n}\n\nint main() {\n\
    \  test();\n\n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"binary-search-tree/rbst-array.hpp\"\n#include\
    \ \"util/xorshift.hpp\"\n\nvoid test() {\n  vector<int> a;\n  RBSTArray<int> ar;\n\
    \  auto t = ar.make_tree();\n\n  rep(loop, 0, 10000) {\n    int type = XORShift::xor32()\
    \ % 3;\n    if (a.empty()) type = 0;\n    if (type == 0) {\n      int x = XORShift::xor32()\
    \ % (a.size() + 1);\n      int v = XORShift::xor32();\n      a.insert(a.begin()\
    \ + x, v);\n      ar.insert(t, x, v);\n    } else if (type == 1) {\n      int\
    \ x = XORShift::xor32() % a.size();\n      int v = XORShift::xor32();\n      a[x]\
    \ = v;\n      ar.set(t, x, v);\n    } else {\n      int x = XORShift::xor32()\
    \ % a.size();\n      a.erase(a.begin() + x);\n      ar.erase(t, x);\n    }\n \
    \   assert(a.size() == ar.size(t));\n    rep(i, 0, a.size()) assert(a[i] == ar.get(t,\
    \ i));\n  }\n}\n\nint main() {\n  test();\n\n  int a, b;\n  in(a, b);\n  out(a\
    \ + b);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - binary-search-tree/rbst-array.hpp
  - binary-search-tree/rbst-base.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: verify/binary-search-tree/UNIT_rbst_array.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/binary-search-tree/UNIT_rbst_array.test.cpp
layout: document
redirect_from:
- /verify/verify/binary-search-tree/UNIT_rbst_array.test.cpp
- /verify/verify/binary-search-tree/UNIT_rbst_array.test.cpp.html
title: verify/binary-search-tree/UNIT_rbst_array.test.cpp
---
