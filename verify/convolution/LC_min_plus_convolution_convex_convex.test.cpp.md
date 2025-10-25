---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/monotone-minima.hpp
    title: monotone minima
  - icon: ':heavy_check_mark:'
    path: convolution/min-plus-convex.hpp
    title: "min-plus \u7573\u307F\u8FBC\u307F (convex)"
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
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
  bundledCode: "#line 1 \"verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"convolution/min-plus-convex.hpp\"\
    \n\n#line 2 \"algorithm/monotone-minima.hpp\"\n\nvector<int> MonotoneMinima(int\
    \ n, int m, const function<bool(int, int, int)> &f) {\n  vector<int> res(n);\n\
    \  auto dfs = [&](auto rc, int il, int ir, int l, int r) -> void {\n    if (il\
    \ == ir) return;\n    int i = (il + ir) / 2;\n    int m = l;\n    for (int k =\
    \ l + 1; k < r; k++)\n      if (!f(i, m, k)) m = k;\n    res[i] = m;\n    rc(rc,\
    \ il, i, l, m + 1);\n    rc(rc, i + 1, ir, m, r);\n  };\n  dfs(dfs, 0, n, 0, m);\n\
    \  return res;\n}\n\n// m_i := argmin_j (A_{i,j}) \u304C\u5358\u8ABF\u5897\u52A0\
    \u3067\u3042\u308B\u3068\u304D\u306B m_i \u3092\u5217\u6319\u3059\u308B\ntemplate\
    \ <class T>\nvector<int> MonotoneMinima(int N, int M, const function<T(int, int)>\
    \ &A) {\n  const auto f = [&](int i, int j, int k) -> bool {\n    return A(i,\
    \ j) <= A(i, k);\n  };\n  return MonotoneMinima(N, M, f);\n}\n\n/**\n * @brief\
    \ monotone minima\n * @docs docs/algorithm/monotone-minima.md\n */\n#line 4 \"\
    convolution/min-plus-convex.hpp\"\n\n// a : \u4E0B\u306B\u51F8, b : \u81EA\u7531\
    \ntemplate <class T>\nvector<T> MinPlusConvolutionConvexArbitrary(const vector<T>\
    \ &a, const vector<T> &b) {\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = a.size(), m = b.size();\n  auto argmin = MonotoneMinima(n + m - 1, m, [&](int\
    \ i, int j, int k) {\n    if (i < k) return true;\n    if (i - j >= n) return\
    \ false;\n    return a[i - j] + b[j] <= a[i - k] + b[k];\n  });\n  vector<T> c(n\
    \ + m - 1);\n  for (int i = 0; i < n + m - 1; i++) {\n    int j = argmin[i];\n\
    \    c[i] = a[i - j] + b[j];\n  }\n  return c;\n}\n\n// a,b : \u4E0B\u306B\u51F8\
    \ntemplate <class T>\nvector<T> MinPlusConvolutionConvexConvex(const vector<T>\
    \ &a, const vector<T> &b) {\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = a.size(), m = b.size();\n  vector<T> c(n + m - 1);\n  c[0] = a[0] + b[0];\n\
    \  for (int k = 0, i = 0; k < n + m - 2; k++) {\n    int j = k - i;\n    if (j\
    \ == m - 1 || (i < n - 1 && a[i + 1] + b[j] < a[i] + b[j + 1])) {\n      c[k +\
    \ 1] = a[++i] + b[j];\n    } else {\n      c[k + 1] = a[i] + b[++j];\n    }\n\
    \  }\n  return c;\n}\n\n/**\n * @brief min-plus \u7573\u307F\u8FBC\u307F (convex)\n\
    \ * @docs docs/convolution/min-plus-convex.md\n */\n#line 5 \"verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  in(n, m);\n  vector<int> a(n), b(m);\n  in(a,\
    \ b);\n  auto c = MinPlusConvolutionConvexConvex(a, b);\n  out(c);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex\"\
    \n\n#include \"template/template.hpp\"\n#include \"convolution/min-plus-convex.hpp\"\
    \n\nint main() {\n  int n, m;\n  in(n, m);\n  vector<int> a(n), b(m);\n  in(a,\
    \ b);\n  auto c = MinPlusConvolutionConvexConvex(a, b);\n  out(c);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - convolution/min-plus-convex.hpp
  - algorithm/monotone-minima.hpp
  isVerificationFile: true
  path: verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
- /verify/verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp.html
title: verify/convolution/LC_min_plus_convolution_convex_convex.test.cpp
---
