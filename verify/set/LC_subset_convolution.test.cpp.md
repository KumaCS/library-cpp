---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':question:'
    path: set/subset-convolution.hpp
    title: Subset Convolution
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
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"verify/set/LC_subset_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \"verify/set/LC_subset_convolution.test.cpp\"\nusing mint = ModInt<998244353>;\n\
    #line 2 \"set/subset-convolution.hpp\"\n\ntemplate <class mint, int n_>\nstruct\
    \ SubsetConvolution {\n  static constexpr int n = n_;\n  using poly = array<mint,\
    \ n_ + 1>;\n  vector<int> pc;\n  SubsetConvolution() {\n    pc.assign(1 << n,\
    \ 0);\n    for (int i = 1; i < pc.size(); i++) pc[i] = pc[i >> 1] + (i & 1);\n\
    \  }\n  void poly_add(poly& p, const poly& q, int d) {\n    for (int i = 0; i\
    \ < d; i++) p[i] += q[i];\n  }\n  void poly_sub(poly& p, const poly& q, int d)\
    \ {\n    for (int i = d; i <= n; i++) p[i] -= q[i];\n  }\n  void poly_mul(poly&\
    \ p, const poly& q) {\n    poly r{};\n    for (int i = 0; i <= n; i++)\n     \
    \ for (int j = 0; j <= n - i; j++)\n        r[i + j] += p[i] * q[j];\n    swap(p,\
    \ r);\n  }\n  vector<poly> lift(const vector<mint>& a) {\n    int n = a.size();\n\
    \    assert(n == (n & -n));\n    vector<poly> b(n);\n    for (int i = 0; i < n;\
    \ i++) {\n      b[i].fill(0);\n      b[i][pc[i]] = a[i];\n    }\n    return b;\n\
    \  }\n  vector<mint> unlift(const vector<poly>& b) {\n    int n = b.size();\n\
    \    assert(n == (n & -n));\n    vector<mint> a(n);\n    for (int i = 0; i < n;\
    \ i++) a[i] = b[i][pc[i]];\n    return a;\n  }\n  void ranked_zeta(vector<poly>&\
    \ a) {\n    int n = a.size();\n    for (int i = 1; i < n; i <<= 1)\n      for\
    \ (int j = 0; j < n; j += i * 2)\n        for (int k = 0; k < i; k++)\n      \
    \    poly_add(a[i + j + k], a[j + k], pc[i + j + k]);\n  }\n  void ranked_mobius(vector<poly>&\
    \ a) {\n    int n = a.size();\n    for (int i = 1; i < n; i <<= 1)\n      for\
    \ (int j = 0; j < n; j += i * 2)\n        for (int k = 0; k < i; k++)\n      \
    \    poly_sub(a[i + j + k], a[j + k], pc[i + j + k]);\n  }\n  void ranked_mul(vector<poly>&\
    \ a, const vector<poly>& b) {\n    for (int i = 0; i < a.size(); i++) poly_mul(a[i],\
    \ b[i]);\n  }\n  vector<mint> multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n    auto p = lift(a);\n    auto q = lift(b);\n    ranked_zeta(p);\n  \
    \  ranked_zeta(q);\n    ranked_mul(p, q);\n    ranked_mobius(p);\n    return unlift(p);\n\
    \  }\n};\n\n/**\n * @brief Subset Convolution\n * @docs docs/set/subset-convolution.md\n\
    \ */\n#line 7 \"verify/set/LC_subset_convolution.test.cpp\"\n\nint main() {\n\
    \  int n;\n  in(n);\n  vector<mint> a(1 << n), b(1 << n);\n  in(a, b);\n  SubsetConvolution<mint,\
    \ 20> sc;\n  auto c = sc.multiply(a, b);\n  out(c);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing mint\
    \ = ModInt<998244353>;\n#include \"set/subset-convolution.hpp\"\n\nint main()\
    \ {\n  int n;\n  in(n);\n  vector<mint> a(1 << n), b(1 << n);\n  in(a, b);\n \
    \ SubsetConvolution<mint, 20> sc;\n  auto c = sc.multiply(a, b);\n  out(c);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - set/subset-convolution.hpp
  isVerificationFile: true
  path: verify/set/LC_subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-10-29 02:30:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/set/LC_subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/set/LC_subset_convolution.test.cpp
- /verify/verify/set/LC_subset_convolution.test.cpp.html
title: verify/set/LC_subset_convolution.test.cpp
---
