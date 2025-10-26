---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: set/and-convolution.hpp
    title: set/and-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: set/zeta-mobius-transform.hpp
    title: set/zeta-mobius-transform.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"verify/set/LC_bitwise_and_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\n#line\
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
    \ \"verify/set/LC_bitwise_and_convolution.test.cpp\"\nusing mint = ModInt<998244353>;\n\
    #line 2 \"set/and-convolution.hpp\"\n\n#line 2 \"set/zeta-mobius-transform.hpp\"\
    \n\ntemplate <class T>\nvoid SupsetZetaTransform(vector<T>& f) {\n  int n = f.size();\n\
    \  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] += f[j | i];\n\
    \      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid SupsetMobiusTransform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <class T>\n\
    void SubsetZetaTransform(vector<T>& f) {\n  int n = f.size();\n  assert((n & (n\
    \ - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n;\
    \ j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n    }\n\
    \  }\n}\n\ntemplate <class T>\nvoid SubsetMobiusTransform(vector<T>& f) {\n  int\
    \ n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<=\
    \ 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n       \
    \ f[j | i] -= f[j];\n      }\n    }\n  }\n}\n#line 4 \"set/and-convolution.hpp\"\
    \n\ntemplate <class T>\nvector<T> AndConvolution(vector<T> a, vector<T> b) {\n\
    \  assert(a.size() == b.size());\n  SupsetZetaTransform(a);\n  SupsetZetaTransform(b);\n\
    \  for (int i = 0; i < a.size(); i++) a[i] *= b[i];\n  SupsetMobiusTransform(a);\n\
    \  return a;\n}\n#line 7 \"verify/set/LC_bitwise_and_convolution.test.cpp\"\n\n\
    int main() {\n  int n;\n  in(n);\n  vector<mint> a(1 << n), b(1 << n);\n  in(a,\
    \ b);\n  auto c = AndConvolution(a, b);\n  out(c);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing\
    \ mint = ModInt<998244353>;\n#include \"set/and-convolution.hpp\"\n\nint main()\
    \ {\n  int n;\n  in(n);\n  vector<mint> a(1 << n), b(1 << n);\n  in(a, b);\n \
    \ auto c = AndConvolution(a, b);\n  out(c);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - set/and-convolution.hpp
  - set/zeta-mobius-transform.hpp
  isVerificationFile: true
  path: verify/set/LC_bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-10-25 18:30:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/set/LC_bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/set/LC_bitwise_and_convolution.test.cpp
- /verify/verify/set/LC_bitwise_and_convolution.test.cpp.html
title: verify/set/LC_bitwise_and_convolution.test.cpp
---
