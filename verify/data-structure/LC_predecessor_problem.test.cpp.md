---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/integer-set.hpp
    title: "\u6574\u6570\u306E\u96C6\u5408(64\u5206\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/data-structure/LC_predecessor_problem.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n#line\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"data-structure/integer-set.hpp\"\
    \n\ntemplate <class T = int, class U = unsigned long long>\nclass IntegerSet {\n\
    \ private:\n  const static T B = 6, W = 64, MASK = W - 1;\n  T size;\n  vector<T>\
    \ start;\n  vector<U> data;\n  static T high_bit(U x) {\n    if (x == 0) return\
    \ 0;\n    return W - 1 - countl_zero(x);\n  }\n  static T low_bit(U x) {\n   \
    \ if (x == 0) return W;\n    return countr_zero(x);\n  }\n\n public:\n  IntegerSet(T\
    \ n) {\n    size = n;\n    vector<T> len;\n    do len.push_back((n >>= B) + 1);\n\
    \    while (n > 0);\n    start = vector<T>(1, 0);\n    start.reserve(len.size()\
    \ + 1);\n    for (auto v : len) start.push_back(start.back() + v);\n    data =\
    \ vector<U>(start.back());\n  }\n  IntegerSet(string s = \"\") {\n    size = s.size();\n\
    \    T n = size;\n    vector<T> len;\n    do len.push_back((n >>= B) + 1);\n \
    \   while (n > 0);\n    start = vector<T>(1, 0);\n    start.reserve(len.size()\
    \ + 1);\n    for (const auto v : len) start.push_back(start.back() + v);\n   \
    \ data = vector<U>(start.back());\n\n    for (T i = 0; i < s.size(); i++)\n  \
    \    if (s[i] == '1') data[i >> B] |= U(1) << (i & MASK);\n    for (T i = 0; i\
    \ + 1 < len.size(); i++)\n      for (T j = 0; j < len[i]; j++)\n        if (data[start[i]\
    \ + j])\n          data[start[i + 1] + (j >> B)] |= U(1) << (j & MASK);\n  }\n\
    \  void add(T x) {\n    for (T i = 0; i + 1 < start.size(); i++) {\n      data[start[i]\
    \ + (x >> B)] |= U(1) << (x & MASK);\n      x >>= B;\n    }\n  }\n  void remove(T\
    \ x) {\n    for (T i = 0; i + 1 < start.size(); i++) {\n      data[start[i] +\
    \ (x >> B)] &= ~(U(1) << (x & MASK));\n      if (data[start[i] + (x >> B)] !=\
    \ 0) return;\n      x >>= B;\n    }\n  }\n  bool contains(T x) const { return\
    \ (data[x >> B] >> (x & MASK)) & 1; }\n  T min(T x) const {\n    T d = 0, i =\
    \ x;\n    while (true) {\n      if (d + 1 >= start.size()) return -1;\n      if\
    \ ((i >> B) >= start[d + 1] - start[d]) return -1;\n      U m = data[start[d]\
    \ + (i >> B)] & ((~U(0)) << (i & MASK));\n      if (m == 0) {\n        d++;\n\
    \        i >>= B;\n        i++;\n      } else {\n        i = (i & ~MASK) + low_bit(m);\n\
    \        if (d == 0) break;\n        i <<= B;\n        d--;\n      }\n    }\n\
    \    return i;\n  }\n  T max(T x) const {\n    T d = 0, i = x;\n    while (true)\
    \ {\n      if (i < 0) return -1;\n      if (d >= data.size()) return -1;\n   \
    \   U m = data[start[d] + (i >> B)] & ~((~U(1)) << (i & MASK));\n      if (m ==\
    \ 0) {\n        d++;\n        i >>= B;\n        i--;\n      } else {\n       \
    \ i = (i & ~MASK) + high_bit(m);\n        if (d == 0) break;\n        i <<= B;\n\
    \        i |= MASK;\n        d--;\n      }\n    }\n    return i;\n  }\n};\n\n\
    /**\n * @brief \u6574\u6570\u306E\u96C6\u5408(64\u5206\u6728)\n */\n#line 5 \"\
    verify/data-structure/LC_predecessor_problem.test.cpp\"\n\nint main() {\n  int\
    \ n, q;\n  in(n, q);\n  string t;\n  in(t);\n  IntegerSet set(t);\n  while (q--)\
    \ {\n    int type, k;\n    in(type, k);\n    if (type == 0)\n      set.add(k);\n\
    \    else if (type == 1)\n      set.remove(k);\n    else if (type == 2)\n    \
    \  out(set.contains(k));\n    else if (type == 3)\n      out(set.min(k));\n  \
    \  else if (type == 4)\n      out(set.max(k));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"template/template.hpp\"\n#include \"data-structure/integer-set.hpp\"\
    \n\nint main() {\n  int n, q;\n  in(n, q);\n  string t;\n  in(t);\n  IntegerSet\
    \ set(t);\n  while (q--) {\n    int type, k;\n    in(type, k);\n    if (type ==\
    \ 0)\n      set.add(k);\n    else if (type == 1)\n      set.remove(k);\n    else\
    \ if (type == 2)\n      out(set.contains(k));\n    else if (type == 3)\n     \
    \ out(set.min(k));\n    else if (type == 4)\n      out(set.max(k));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - data-structure/integer-set.hpp
  isVerificationFile: true
  path: verify/data-structure/LC_predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2025-10-23 01:57:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/LC_predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/LC_predecessor_problem.test.cpp
- /verify/verify/data-structure/LC_predecessor_problem.test.cpp.html
title: verify/data-structure/LC_predecessor_problem.test.cpp
---
