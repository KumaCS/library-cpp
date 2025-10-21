---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number-theory/prime-count.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8"
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"verify/number-theory/LC_counting_primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"number-theory/prime-count.hpp\"\n\
    \nnamespace PrimeCount {\nusing i64 = int64_t;\nstatic inline i64 div(i64 a, i64\
    \ b) { return double(a) / b; }\n#define FUNC()                               \
    \                        \\\n  vector<i64> xs{0};                            \
    \                     \\\n  for (i64 i = N; i > 0; i = div(N, div(N, i) + 1))\
    \ xs.push_back(i); \\\n  vector<i64> cnt(xs);                                \
    \               \\\n  for (auto &x : cnt) --x;                               \
    \            \\\n  for (i64 x = 2, sq = sqrtl(N), xsz = xs.size(); x <= sq; ++x)\
    \ {    \\\n    if (cnt[xsz - x] == cnt[xsz - x + 1]) continue;               \
    \   \\\n    i64 x2 = x * x, pi = cnt[xsz - x + 1];                           \\\
    \n    for (i64 i = 1, n = xs[i]; i < xsz && n >= x2; n = xs[++i])      \\\n  \
    \    cnt[i] -= cnt[i * x <= sq ? i * x : xsz - div(n, x)] - pi;     \\\n  }\n\
    pair<vector<i64>, vector<i64>> table(i64 N) {\n  FUNC()\n  return {xs, cnt};\n\
    }\ni64 count(i64 N) {\n  if (N < 2) return 0;\n  FUNC()\n  return cnt[1];\n}\n\
    #undef FUNC\n};  // namespace PrimeCount\n\n/**\n * @brief \u7D20\u6570\u30AB\u30A6\
    \u30F3\u30C8\n * @docs docs/number-theory/prime-count.md\n */\n#line 5 \"verify/number-theory/LC_counting_primes.test.cpp\"\
    \n\nint main() {\n  ll n;\n  in(n);\n  out(PrimeCount::count(n));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"number-theory/prime-count.hpp\"\n\nint\
    \ main() {\n  ll n;\n  in(n);\n  out(PrimeCount::count(n));\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - number-theory/prime-count.hpp
  isVerificationFile: true
  path: verify/number-theory/LC_counting_primes.test.cpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/number-theory/LC_counting_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/number-theory/LC_counting_primes.test.cpp
- /verify/verify/number-theory/LC_counting_primes.test.cpp.html
title: verify/number-theory/LC_counting_primes.test.cpp
---
