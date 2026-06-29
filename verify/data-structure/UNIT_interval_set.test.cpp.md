---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/interval-set.hpp
    title: "\u533A\u9593\u96C6\u5408"
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
  bundledCode: "#line 1 \"verify/data-structure/UNIT_interval_set.test.cpp\"\n#define\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"data-structure/interval-set.hpp\"\
    \n\ntemplate <class T>\nstruct IntervalSet {\n  using value_type = pair<T, T>;\n\
    \  IntervalSet() = default;\n  bool contains(T x) const {\n    auto it = LR.upper_bound({x,\
    \ INF});\n    if (it == LR.begin()) return false;\n    --it;\n    return it->first\
    \ <= x && x < it->second;\n  }\n  bool contains(T l, T r) const {\n    assert(l\
    \ <= r);\n    if (l == r) return true;\n    auto it = LR.upper_bound({l, INF});\n\
    \    if (it == LR.begin()) return false;\n    --it;\n    return it->first <= l\
    \ && r <= it->second;\n  }\n\n  optional<value_type> get(T x) const {\n    auto\
    \ it = LR.upper_bound({x, INF});\n    if (it == LR.begin()) return nullopt;\n\
    \    --it;\n    if (it->first <= x && x < it->second) return *it;\n    return\
    \ nullopt;\n  }\n\n  void add(T x) {\n    assert(x < INF);\n    add(x, x + 1);\n\
    \  }\n  void add(T l, T r) {\n    assert(l <= r);\n    if (l == r) return;\n\n\
    \    auto it = LR.upper_bound({l, INF});\n    if (it != LR.begin()) {\n      auto\
    \ pre = prev(it);\n      if (l <= pre->second) {\n        l = pre->first;\n  \
    \      r = max(r, pre->second);\n        it = LR.erase(pre);\n      }\n    }\n\
    \    while (it != LR.end() && it->first <= r) {\n      r = max(r, it->second);\n\
    \      it = LR.erase(it);\n    }\n    LR.insert({l, r});\n  }\n\n  void remove(T\
    \ x) {\n    assert(x < INF);\n    remove(x, x + 1);\n  }\n  void remove(T l, T\
    \ r) {\n    assert(l <= r);\n    if (l == r) return;\n\n    auto it = LR.upper_bound({l,\
    \ INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n      if (l\
    \ < pre->second) {\n        T l1 = pre->first, r1 = pre->second;\n        LR.erase(pre);\n\
    \        if (l1 < l) LR.insert({l1, l});\n        if (r < r1) {\n          LR.insert({r,\
    \ r1});\n          return;\n        }\n      }\n    }\n    while (it != LR.end()\
    \ && it->first < r) {\n      T r1 = it->second;\n      it = LR.erase(it);\n  \
    \    if (r < r1) {\n        LR.insert({r, r1});\n        break;\n      }\n   \
    \ }\n  }\n\n  vector<value_type> enumerate(T l, T r) const {\n    assert(l <=\
    \ r);\n    vector<value_type> ret;\n    if (l == r) return ret;\n\n    auto it\
    \ = LR.upper_bound({l, INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n\
    \      if (l < pre->second) it = pre;\n    }\n    while (it != LR.end() && it->first\
    \ < r) {\n      ret.push_back({max(l, it->first), min(r, it->second)});\n    \
    \  ++it;\n    }\n    return ret;\n  }\n\n  T mex(T x = 0) const {\n    auto it\
    \ = LR.upper_bound({x, INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n\
    \      if (pre->first <= x && x < pre->second) x = pre->second;\n    }\n    while\
    \ (it != LR.end() && it->first <= x) {\n      if (x < it->second) x = it->second;\n\
    \      ++it;\n    }\n    return x;\n  }\n\n  bool empty() const { return LR.empty();\
    \ }\n  void clear() { LR.clear(); }\n\n  auto begin() const { return LR.begin();\
    \ }\n  auto end() const { return LR.end(); }\n\n private:\n  static constexpr\
    \ T INF = numeric_limits<T>::max();\n  set<value_type> LR;\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u96C6\u5408\n * @docs docs/data-structure/interval-set.md\n */\n\
    #line 2 \"util/xorshift.hpp\"\n\nnamespace XORShift {\nunsigned int xor32() {\n\
    \  static unsigned int x = 123456789u;\n  x ^= x << 13, x ^= x >> 17, x ^= x <<\
    \ 5;\n  return x;\n}\nunsigned long long xor64() {\n  static unsigned long long\
    \ x = 123456789ull;\n  x ^= x << 13, x ^= x >> 7, x ^= x << 17;\n  return x;\n\
    }\n};  // namespace XORShift\n\n/**\n * @brief XOR shift\n */\n#line 6 \"verify/data-structure/UNIT_interval_set.test.cpp\"\
    \n\nconstexpr int L = -20;\nconstexpr int R = 80;\n\nvector<pair<int, int>> enumerate_naive(const\
    \ vector<bool>& a, int l, int r) {\n  vector<pair<int, int>> ret;\n  l = max(l,\
    \ L);\n  r = min(r, R);\n  for (int x = l; x < r;) {\n    if (!a[x - L]) {\n \
    \     x++;\n      continue;\n    }\n    int y = x;\n    while (y < r && a[y -\
    \ L]) y++;\n    ret.push_back({x, y});\n    x = y;\n  }\n  return ret;\n}\n\n\
    void check_points(const IntervalSet<int>& s, const vector<bool>& a) {\n  rep(x,\
    \ L, R) assert(s.contains(x) == a[x - L]);\n  vector<pair<int, int>> intervals(s.begin(),\
    \ s.end());\n  assert(intervals == enumerate_naive(a, L, R));\n  assert(s.empty()\
    \ == intervals.empty());\n}\n\nvoid check_query(const IntervalSet<int>& s, const\
    \ vector<bool>& a, int l, int r) {\n  bool ok = true;\n  rep(x, l, r) ok &= a[x\
    \ - L];\n  assert(s.contains(l, r) == ok);\n  assert(s.enumerate(l, r) == enumerate_naive(a,\
    \ l, r));\n}\n\nvoid check_full(const IntervalSet<int>& s, const vector<bool>&\
    \ a) {\n  check_points(s, a);\n  rep(l, L, R + 1) rep(r, l, R + 1) {\n    check_query(s,\
    \ a, l, r);\n  }\n\n  rep(x, L, R) {\n    auto itv = s.get(x);\n    if (!a[x -\
    \ L]) {\n      assert(!itv);\n    } else {\n      int l = x, r = x + 1;\n    \
    \  while (L < l && a[l - 1 - L]) l--;\n      while (r < R && a[r - L]) r++;\n\
    \      assert(itv);\n      assert(*itv == make_pair(l, r));\n    }\n  }\n\n  rep(x,\
    \ L, R + 1) {\n    int expected = x;\n    while (expected < R && a[expected -\
    \ L]) expected++;\n    assert(s.mex(x) == expected);\n  }\n}\n\nvoid check_random_queries(const\
    \ IntervalSet<int>& s, const vector<bool>& a) {\n  check_points(s, a);\n  rep(_,\
    \ 0, 20) {\n    int l = L + (int)(XORShift::xor32() % (R - L + 1));\n    int r\
    \ = L + (int)(XORShift::xor32() % (R - L + 1));\n    if (l > r) swap(l, r);\n\
    \    check_query(s, a, l, r);\n  }\n  rep(_, 0, 20) {\n    int x = L + (int)(XORShift::xor32()\
    \ % (R - L));\n    auto itv = s.get(x);\n    if (!a[x - L]) {\n      assert(!itv);\n\
    \    } else {\n      int l = x, r = x + 1;\n      while (L < l && a[l - 1 - L])\
    \ l--;\n      while (r < R && a[r - L]) r++;\n      assert(itv);\n      assert(*itv\
    \ == make_pair(l, r));\n    }\n  }\n  rep(_, 0, 20) {\n    int x = L + (int)(XORShift::xor32()\
    \ % (R - L + 1));\n    int expected = x;\n    while (expected < R && a[expected\
    \ - L]) expected++;\n    assert(s.mex(x) == expected);\n  }\n}\n\nvoid test_fixed()\
    \ {\n  IntervalSet<int> s;\n  vector<bool> a(R - L, false);\n  check_full(s, a);\n\
    \n  s.add(1, 3);\n  s.add(3, 5);\n  rep(x, 1, 5) a[x - L] = true;\n  check_full(s,\
    \ a);\n\n  s.remove(2, 4);\n  rep(x, 2, 4) a[x - L] = false;\n  check_full(s,\
    \ a);\n\n  s.add(10);\n  a[10 - L] = true;\n  check_full(s, a);\n\n  s.remove(10);\n\
    \  a[10 - L] = false;\n  check_full(s, a);\n\n  s.clear();\n  fill(a.begin(),\
    \ a.end(), false);\n  check_full(s, a);\n}\n\nvoid test_random() {\n  IntervalSet<int>\
    \ s;\n  vector<bool> a(R - L, false);\n  rep(_, 0, 20000) {\n    int op = XORShift::xor32()\
    \ % 6;\n    int l = L + (int)(XORShift::xor32() % (R - L + 1));\n    int r = L\
    \ + (int)(XORShift::xor32() % (R - L + 1));\n    if (l > r) swap(l, r);\n    if\
    \ (op == 0) {\n      s.add(l, r);\n      rep(x, l, r) a[x - L] = true;\n    }\
    \ else if (op == 1) {\n      s.remove(l, r);\n      rep(x, l, r) a[x - L] = false;\n\
    \    } else if (op == 2) {\n      int x = L + (int)(XORShift::xor32() % (R - L));\n\
    \      s.add(x);\n      a[x - L] = true;\n    } else if (op == 3) {\n      int\
    \ x = L + (int)(XORShift::xor32() % (R - L));\n      s.remove(x);\n      a[x -\
    \ L] = false;\n    }\n    check_random_queries(s, a);\n  }\n}\n\nint main() {\n\
    \  test_fixed();\n  test_random();\n\n  int a, b;\n  in(a, b);\n  out(a + b);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"data-structure/interval-set.hpp\"\n#include\
    \ \"util/xorshift.hpp\"\n\nconstexpr int L = -20;\nconstexpr int R = 80;\n\nvector<pair<int,\
    \ int>> enumerate_naive(const vector<bool>& a, int l, int r) {\n  vector<pair<int,\
    \ int>> ret;\n  l = max(l, L);\n  r = min(r, R);\n  for (int x = l; x < r;) {\n\
    \    if (!a[x - L]) {\n      x++;\n      continue;\n    }\n    int y = x;\n  \
    \  while (y < r && a[y - L]) y++;\n    ret.push_back({x, y});\n    x = y;\n  }\n\
    \  return ret;\n}\n\nvoid check_points(const IntervalSet<int>& s, const vector<bool>&\
    \ a) {\n  rep(x, L, R) assert(s.contains(x) == a[x - L]);\n  vector<pair<int,\
    \ int>> intervals(s.begin(), s.end());\n  assert(intervals == enumerate_naive(a,\
    \ L, R));\n  assert(s.empty() == intervals.empty());\n}\n\nvoid check_query(const\
    \ IntervalSet<int>& s, const vector<bool>& a, int l, int r) {\n  bool ok = true;\n\
    \  rep(x, l, r) ok &= a[x - L];\n  assert(s.contains(l, r) == ok);\n  assert(s.enumerate(l,\
    \ r) == enumerate_naive(a, l, r));\n}\n\nvoid check_full(const IntervalSet<int>&\
    \ s, const vector<bool>& a) {\n  check_points(s, a);\n  rep(l, L, R + 1) rep(r,\
    \ l, R + 1) {\n    check_query(s, a, l, r);\n  }\n\n  rep(x, L, R) {\n    auto\
    \ itv = s.get(x);\n    if (!a[x - L]) {\n      assert(!itv);\n    } else {\n \
    \     int l = x, r = x + 1;\n      while (L < l && a[l - 1 - L]) l--;\n      while\
    \ (r < R && a[r - L]) r++;\n      assert(itv);\n      assert(*itv == make_pair(l,\
    \ r));\n    }\n  }\n\n  rep(x, L, R + 1) {\n    int expected = x;\n    while (expected\
    \ < R && a[expected - L]) expected++;\n    assert(s.mex(x) == expected);\n  }\n\
    }\n\nvoid check_random_queries(const IntervalSet<int>& s, const vector<bool>&\
    \ a) {\n  check_points(s, a);\n  rep(_, 0, 20) {\n    int l = L + (int)(XORShift::xor32()\
    \ % (R - L + 1));\n    int r = L + (int)(XORShift::xor32() % (R - L + 1));\n \
    \   if (l > r) swap(l, r);\n    check_query(s, a, l, r);\n  }\n  rep(_, 0, 20)\
    \ {\n    int x = L + (int)(XORShift::xor32() % (R - L));\n    auto itv = s.get(x);\n\
    \    if (!a[x - L]) {\n      assert(!itv);\n    } else {\n      int l = x, r =\
    \ x + 1;\n      while (L < l && a[l - 1 - L]) l--;\n      while (r < R && a[r\
    \ - L]) r++;\n      assert(itv);\n      assert(*itv == make_pair(l, r));\n   \
    \ }\n  }\n  rep(_, 0, 20) {\n    int x = L + (int)(XORShift::xor32() % (R - L\
    \ + 1));\n    int expected = x;\n    while (expected < R && a[expected - L]) expected++;\n\
    \    assert(s.mex(x) == expected);\n  }\n}\n\nvoid test_fixed() {\n  IntervalSet<int>\
    \ s;\n  vector<bool> a(R - L, false);\n  check_full(s, a);\n\n  s.add(1, 3);\n\
    \  s.add(3, 5);\n  rep(x, 1, 5) a[x - L] = true;\n  check_full(s, a);\n\n  s.remove(2,\
    \ 4);\n  rep(x, 2, 4) a[x - L] = false;\n  check_full(s, a);\n\n  s.add(10);\n\
    \  a[10 - L] = true;\n  check_full(s, a);\n\n  s.remove(10);\n  a[10 - L] = false;\n\
    \  check_full(s, a);\n\n  s.clear();\n  fill(a.begin(), a.end(), false);\n  check_full(s,\
    \ a);\n}\n\nvoid test_random() {\n  IntervalSet<int> s;\n  vector<bool> a(R -\
    \ L, false);\n  rep(_, 0, 20000) {\n    int op = XORShift::xor32() % 6;\n    int\
    \ l = L + (int)(XORShift::xor32() % (R - L + 1));\n    int r = L + (int)(XORShift::xor32()\
    \ % (R - L + 1));\n    if (l > r) swap(l, r);\n    if (op == 0) {\n      s.add(l,\
    \ r);\n      rep(x, l, r) a[x - L] = true;\n    } else if (op == 1) {\n      s.remove(l,\
    \ r);\n      rep(x, l, r) a[x - L] = false;\n    } else if (op == 2) {\n     \
    \ int x = L + (int)(XORShift::xor32() % (R - L));\n      s.add(x);\n      a[x\
    \ - L] = true;\n    } else if (op == 3) {\n      int x = L + (int)(XORShift::xor32()\
    \ % (R - L));\n      s.remove(x);\n      a[x - L] = false;\n    }\n    check_random_queries(s,\
    \ a);\n  }\n}\n\nint main() {\n  test_fixed();\n  test_random();\n\n  int a, b;\n\
    \  in(a, b);\n  out(a + b);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - data-structure/interval-set.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: verify/data-structure/UNIT_interval_set.test.cpp
  requiredBy: []
  timestamp: '2026-06-30 02:52:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/UNIT_interval_set.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/UNIT_interval_set.test.cpp
- /verify/verify/data-structure/UNIT_interval_set.test.cpp.html
title: verify/data-structure/UNIT_interval_set.test.cpp
---
