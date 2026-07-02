---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/range-add-range-positive-sum.hpp
    title: Range Add Range Positive Sum
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
  bundledCode: "#line 1 \"verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"data-structure/range-add-range-positive-sum.hpp\"\
    \n\ntemplate <class T>\nstruct RangeAddRangePositiveSum {\n  RangeAddRangePositiveSum()\
    \ {}\n  RangeAddRangePositiveSum(int n) : RangeAddRangePositiveSum(vector<T>(n))\
    \ {}\n  RangeAddRangePositiveSum(const vector<T>& a) : N(a.size()), B(max(1, (int)sqrt(N))),\
    \ M((N + B - 1) / B), data(a), sorted(a), sorted_sum(N + M), lazy(M) {\n    for\
    \ (int k = 0; k < M; k++) update_block(k);\n  }\n  void add(int l, int r, T v)\
    \ {\n    if (l >= r) return;\n    int bl = l / B, br = (r - 1) / B;\n    if (bl\
    \ == br) {\n      for (int i = l; i < r; i++) data[i] += v;\n      update_block(bl);\n\
    \    } else {\n      if (bl * B != l) {\n        bl++;\n        int l1 = bl *\
    \ B;\n        while (l < l1) data[l++] += v;\n        update_block(bl - 1);\n\
    \      }\n      if (r < min(N, (br + 1) * B)) {\n        int r1 = br * B;\n  \
    \      while (r1 < r) data[--r] += v;\n        update_block(br--);\n      }\n\
    \      for (int k = bl; k <= br; k++) lazy[k] += v;\n    }\n  }\n  T sum(int l,\
    \ int r) const {\n    if (l >= r) return 0;\n    T ret = 0;\n    int bl = l /\
    \ B, br = (r - 1) / B;\n    if (bl == br) {\n      for (int i = l; i < r; i++)\
    \ ret += sum_point(i);\n    } else {\n      if (bl * B != l) {\n        bl++;\n\
    \        int l1 = bl * B;\n        while (l < l1) ret += sum_point(l++);\n   \
    \   }\n      if (r < min(N, (br + 1) * B)) {\n        int r1 = br * B;\n     \
    \   while (r1 < r) ret += sum_point(--r);\n        br--;\n      }\n      for (int\
    \ k = bl; k <= br; k++) ret += sum_block(k);\n    }\n    return ret;\n  }\n\n\
    \ private:\n  int N, B, M;\n  vector<T> data, sorted, sorted_sum, lazy;\n  void\
    \ update_block(int k) {\n    int l = B * k, r = min(N, l + B);\n    int sz = r\
    \ - l;\n    copy(data.begin() + l, data.begin() + r, sorted.begin() + l);\n  \
    \  sort(sorted.begin() + l, sorted.begin() + r);\n    auto it = sorted_sum.begin()\
    \ + l + k;\n    *it = 0;\n    for (int i = 0; i < sz; i++)\n      *(it + i + 1)\
    \ = *(it + i) + sorted[l + i];\n  }\n  T sum_point(int x) const { return max<T>(0,\
    \ data[x] + lazy[x / B]); }\n  T sum_block(int k) const {\n    int l = B * k,\
    \ r = min(N, l + B);\n    int sz = r - l;\n    auto itl = sorted.begin() + l;\n\
    \    int i = lower_bound(itl, itl + sz, -lazy[k]) - itl;\n    int l1 = l + k,\
    \ r1 = l1 + sz;\n    return sorted_sum[r1] - sorted_sum[l1 + i] + lazy[k] * (sz\
    \ - i);\n  }\n};\n\n/**\n * @brief Range Add Range Positive Sum\n * @docs docs/data-structure/range-add-range-positive-sum.md\n\
    \ */\n#line 2 \"util/xorshift.hpp\"\n\nnamespace XORShift {\nunsigned int xor32()\
    \ {\n  static unsigned int x = 123456789u;\n  x ^= x << 13, x ^= x >> 17, x ^=\
    \ x << 5;\n  return x;\n}\nunsigned long long xor64() {\n  static unsigned long\
    \ long x = 123456789ull;\n  x ^= x << 13, x ^= x >> 7, x ^= x << 17;\n  return\
    \ x;\n}\n};  // namespace XORShift\n\n/**\n * @brief XOR shift\n */\n#line 6 \"\
    verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp\"\n\nlong long\
    \ naive_sum(const vector<long long>& a, int l, int r) {\n  long long ret = 0;\n\
    \  rep(i, l, r) ret += max(0LL, a[i]);\n  return ret;\n}\n\nvoid check_all(const\
    \ RangeAddRangePositiveSum<long long>& ds, const vector<long long>& a) {\n  int\
    \ n = a.size();\n  rep(l, 0, n + 1) rep(r, l, n + 1) {\n    assert(ds.sum(l, r)\
    \ == naive_sum(a, l, r));\n  }\n}\n\nvoid add_naive(vector<long long>& a, int\
    \ l, int r, long long v) {\n  rep(i, l, r) a[i] += v;\n}\n\npair<int, int> random_interval(int\
    \ n) {\n  int l = n == 0 ? 0 : XORShift::xor32() % (n + 1);\n  int r = n == 0\
    \ ? 0 : XORShift::xor32() % (n + 1);\n  if (l > r) swap(l, r);\n  return {l, r};\n\
    }\n\nvoid test_fixed() {\n  rep(n, 0, 80) {\n    vector<long long> a(n);\n   \
    \ rep(i, 0, n) a[i] = i % 7 - 3;\n    RangeAddRangePositiveSum<long long> ds(a);\n\
    \    check_all(ds, a);\n\n    vector<tuple<int, int, long long>> qs;\n    qs.push_back({0,\
    \ n, 5});\n    qs.push_back({0, min(n, 1), -10});\n    qs.push_back({n / 2, n,\
    \ 4});\n    qs.push_back({0, n / 2, -3});\n    qs.push_back({n, n, 100});\n  \
    \  if (n >= 2) qs.push_back({1, n - 1, 2});\n\n    for (auto [l, r, v] : qs) {\n\
    \      ds.add(l, r, v);\n      add_naive(a, l, r, v);\n      check_all(ds, a);\n\
    \    }\n  }\n}\n\nvoid test_random() {\n  rep(n, 0, 120) {\n    vector<long long>\
    \ a(n);\n    rep(i, 0, n) a[i] = (long long)(XORShift::xor32() % 21) - 10;\n \
    \   RangeAddRangePositiveSum<long long> ds(a);\n    check_all(ds, a);\n\n    rep(_,\
    \ 0, 500) {\n      auto [l, r] = random_interval(n);\n      if (XORShift::xor32()\
    \ % 2) {\n        long long v = (long long)(XORShift::xor32() % 41) - 20;\n  \
    \      ds.add(l, r, v);\n        add_naive(a, l, r, v);\n      } else {\n    \
    \    assert(ds.sum(l, r) == naive_sum(a, l, r));\n      }\n    }\n    check_all(ds,\
    \ a);\n  }\n}\n\nvoid test_random_large() {\n  for (int n : {128, 257, 511, 1000,\
    \ 2000}) {\n    vector<long long> a(n);\n    rep(i, 0, n) a[i] = (long long)(XORShift::xor32()\
    \ % 2001) - 1000;\n    RangeAddRangePositiveSum<long long> ds(a);\n\n    rep(_,\
    \ 0, 3000) {\n      auto [l, r] = random_interval(n);\n      if (XORShift::xor32()\
    \ % 2) {\n        long long v = (long long)(XORShift::xor32() % 2001) - 1000;\n\
    \        ds.add(l, r, v);\n        add_naive(a, l, r, v);\n      } else {\n  \
    \      assert(ds.sum(l, r) == naive_sum(a, l, r));\n      }\n    }\n\n    rep(_,\
    \ 0, 200) {\n      auto [l, r] = random_interval(n);\n      assert(ds.sum(l, r)\
    \ == naive_sum(a, l, r));\n    }\n  }\n}\n\nint main() {\n  test_fixed();\n  test_random();\n\
    \  test_random_large();\n\n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"data-structure/range-add-range-positive-sum.hpp\"\
    \n#include \"util/xorshift.hpp\"\n\nlong long naive_sum(const vector<long long>&\
    \ a, int l, int r) {\n  long long ret = 0;\n  rep(i, l, r) ret += max(0LL, a[i]);\n\
    \  return ret;\n}\n\nvoid check_all(const RangeAddRangePositiveSum<long long>&\
    \ ds, const vector<long long>& a) {\n  int n = a.size();\n  rep(l, 0, n + 1) rep(r,\
    \ l, n + 1) {\n    assert(ds.sum(l, r) == naive_sum(a, l, r));\n  }\n}\n\nvoid\
    \ add_naive(vector<long long>& a, int l, int r, long long v) {\n  rep(i, l, r)\
    \ a[i] += v;\n}\n\npair<int, int> random_interval(int n) {\n  int l = n == 0 ?\
    \ 0 : XORShift::xor32() % (n + 1);\n  int r = n == 0 ? 0 : XORShift::xor32() %\
    \ (n + 1);\n  if (l > r) swap(l, r);\n  return {l, r};\n}\n\nvoid test_fixed()\
    \ {\n  rep(n, 0, 80) {\n    vector<long long> a(n);\n    rep(i, 0, n) a[i] = i\
    \ % 7 - 3;\n    RangeAddRangePositiveSum<long long> ds(a);\n    check_all(ds,\
    \ a);\n\n    vector<tuple<int, int, long long>> qs;\n    qs.push_back({0, n, 5});\n\
    \    qs.push_back({0, min(n, 1), -10});\n    qs.push_back({n / 2, n, 4});\n  \
    \  qs.push_back({0, n / 2, -3});\n    qs.push_back({n, n, 100});\n    if (n >=\
    \ 2) qs.push_back({1, n - 1, 2});\n\n    for (auto [l, r, v] : qs) {\n      ds.add(l,\
    \ r, v);\n      add_naive(a, l, r, v);\n      check_all(ds, a);\n    }\n  }\n\
    }\n\nvoid test_random() {\n  rep(n, 0, 120) {\n    vector<long long> a(n);\n \
    \   rep(i, 0, n) a[i] = (long long)(XORShift::xor32() % 21) - 10;\n    RangeAddRangePositiveSum<long\
    \ long> ds(a);\n    check_all(ds, a);\n\n    rep(_, 0, 500) {\n      auto [l,\
    \ r] = random_interval(n);\n      if (XORShift::xor32() % 2) {\n        long long\
    \ v = (long long)(XORShift::xor32() % 41) - 20;\n        ds.add(l, r, v);\n  \
    \      add_naive(a, l, r, v);\n      } else {\n        assert(ds.sum(l, r) ==\
    \ naive_sum(a, l, r));\n      }\n    }\n    check_all(ds, a);\n  }\n}\n\nvoid\
    \ test_random_large() {\n  for (int n : {128, 257, 511, 1000, 2000}) {\n    vector<long\
    \ long> a(n);\n    rep(i, 0, n) a[i] = (long long)(XORShift::xor32() % 2001) -\
    \ 1000;\n    RangeAddRangePositiveSum<long long> ds(a);\n\n    rep(_, 0, 3000)\
    \ {\n      auto [l, r] = random_interval(n);\n      if (XORShift::xor32() % 2)\
    \ {\n        long long v = (long long)(XORShift::xor32() % 2001) - 1000;\n   \
    \     ds.add(l, r, v);\n        add_naive(a, l, r, v);\n      } else {\n     \
    \   assert(ds.sum(l, r) == naive_sum(a, l, r));\n      }\n    }\n\n    rep(_,\
    \ 0, 200) {\n      auto [l, r] = random_interval(n);\n      assert(ds.sum(l, r)\
    \ == naive_sum(a, l, r));\n    }\n  }\n}\n\nint main() {\n  test_fixed();\n  test_random();\n\
    \  test_random_large();\n\n  int a, b;\n  in(a, b);\n  out(a + b);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - data-structure/range-add-range-positive-sum.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp
  requiredBy: []
  timestamp: '2026-07-02 22:11:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp
- /verify/verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp.html
title: verify/data-structure/UNIT_range_add_range_positive_sum.test.cpp
---
