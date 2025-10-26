---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fft/ntt.hpp
    title: "NTT (\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':question:'
    path: fps/fps-ntt-friendly.hpp
    title: fps/fps-ntt-friendly.hpp
  - icon: ':heavy_check_mark:'
    path: fps/product-of-polynomials.hpp
    title: "\u591A\u9805\u5F0F\u306E\u7A4D"
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/product_of_polynomial_sequence
    links:
    - https://judge.yosupo.jp/problem/product_of_polynomial_sequence
  bundledCode: "#line 1 \"verify/fps/LC_product_of_polynomial_sequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\
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
    \ \"verify/fps/LC_product_of_polynomial_sequence.test.cpp\"\nusing mint = ModInt<998244353>;\n\
    #line 2 \"fps/fps-ntt-friendly.hpp\"\n\n#line 2 \"fft/ntt.hpp\"\n\ntemplate <class\
    \ mint>\nstruct NTT {\n  static constexpr unsigned int mod = mint::get_mod();\n\
    \  static constexpr unsigned long long pow_constexpr(unsigned long long x, unsigned\
    \ long long n, unsigned long long m) {\n    unsigned long long y = 1;\n    while\
    \ (n) {\n      if (n & 1) y = y * x % m;\n      x = x * x % m;\n      n >>= 1;\n\
    \    }\n    return y;\n  }\n  static constexpr unsigned int get_g() {\n    unsigned\
    \ long long x = 2;\n    while (pow_constexpr(x, (mod - 1) >> 1, mod) == 1) x +=\
    \ 1;\n    return x;\n  }\n  static constexpr unsigned int g = get_g();\n  static\
    \ constexpr int rank2 = __builtin_ctzll(mod - 1);\n  array<mint, rank2 + 1> root;\n\
    \  array<mint, rank2 + 1> iroot;\n  array<mint, max(0, rank2 - 2 + 1)> rate2;\n\
    \  array<mint, max(0, rank2 - 2 + 1)> irate2;\n  array<mint, max(0, rank2 - 3\
    \ + 1)> rate3;\n  array<mint, max(0, rank2 - 3 + 1)> irate3;\n\n  NTT() {\n  \
    \  root[rank2] = mint(g).pow((mod - 1) >> rank2);\n    iroot[rank2] = root[rank2].inv();\n\
    \    for (int i = rank2 - 1; i >= 0; i--) {\n      root[i] = root[i + 1] * root[i\
    \ + 1];\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\n    }\n    {\n      mint\
    \ prod = 1, iprod = 1;\n      for (int i = 0; i <= rank2 - 2; i++) {\n       \
    \ rate2[i] = root[i + 2] * prod;\n        irate2[i] = iroot[i + 2] * iprod;\n\
    \        prod *= iroot[i + 2];\n        iprod *= root[i + 2];\n      }\n    }\n\
    \    {\n      mint prod = 1, iprod = 1;\n      for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n        rate3[i] = root[i + 3] * prod;\n        irate3[i] = iroot[i\
    \ + 3] * iprod;\n        prod *= iroot[i + 3];\n        iprod *= root[i + 3];\n\
    \      }\n    }\n  }\n  void ntt(vector<mint>& a) {\n    int n = int(a.size());\n\
    \    int h = __builtin_ctzll((unsigned int)n);\n    a.resize(1 << h);\n    int\
    \ len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n    while (len\
    \ < h) {\n      if (h - len == 1) {\n        int p = 1 << (h - len - 1);\n   \
    \     mint rot = 1;\n        for (int s = 0; s < (1 << len); s++) {\n        \
    \  int offset = s << (h - len);\n          for (int i = 0; i < p; i++) {\n   \
    \         auto l = a[i + offset];\n            auto r = a[i + offset + p] * rot;\n\
    \            a[i + offset] = l + r;\n            a[i + offset + p] = l - r;\n\
    \          }\n          if (s + 1 != (1 << len)) rot *= rate2[__builtin_ctzll(~(unsigned\
    \ int)(s))];\n        }\n        len++;\n      } else {\n        // 4-base\n \
    \       int p = 1 << (h - len - 2);\n        mint rot = 1, imag = root[2];\n \
    \       for (int s = 0; s < (1 << len); s++) {\n          mint rot2 = rot * rot;\n\
    \          mint rot3 = rot2 * rot;\n          int offset = s << (h - len);\n \
    \         for (int i = 0; i < p; i++) {\n            auto mod2 = 1ULL * mint::get_mod()\
    \ * mint::get_mod();\n            auto a0 = 1ULL * a[i + offset].val();\n    \
    \        auto a1 = 1ULL * a[i + offset + p].val() * rot.val();\n            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n            auto a3 =\
    \ 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n            auto a1na3imag\
    \ = 1ULL * mint(a1 + mod2 - a3).val() * imag.val();\n            auto na2 = mod2\
    \ - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n            a[i + offset\
    \ + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n            a[i + offset + 2 *\
    \ p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3 * p] = a0 + na2 + (mod2\
    \ - a1na3imag);\n          }\n          if (s + 1 != (1 << len)) rot *= rate3[__builtin_ctzll(~(unsigned\
    \ int)(s))];\n        }\n        len += 2;\n      }\n    }\n  }\n  void intt(vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = __builtin_ctzll((unsigned int)n);\n\
    \    a.resize(1 << h);\n\n    int len = h;  // a[i, i+(n>>len), i+2*(n>>len),\
    \ ..] is transformed\n    while (len) {\n      if (len == 1) {\n        int p\
    \ = 1 << (h - len);\n        mint irot = 1;\n        for (int s = 0; s < (1 <<\
    \ (len - 1)); s++) {\n          int offset = s << (h - len + 1);\n          for\
    \ (int i = 0; i < p; i++) {\n            auto l = a[i + offset];\n           \
    \ auto r = a[i + offset + p];\n            a[i + offset] = l + r;\n          \
    \  a[i + offset + p] = (unsigned long long)(mint::get_mod() + l.val() - r.val())\
    \ * irot.val();\n          }\n          if (s + 1 != (1 << (len - 1))) irot *=\
    \ irate2[__builtin_ctzll(~(unsigned int)(s))];\n        }\n        len--;\n  \
    \    } else {\n        // 4-base\n        int p = 1 << (h - len);\n        mint\
    \ irot = 1, iimag = iroot[2];\n        for (int s = 0; s < (1 << (len - 2)); s++)\
    \ {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2 * irot;\n\
    \          int offset = s << (h - len + 2);\n          for (int i = 0; i < p;\
    \ i++) {\n            auto a0 = 1ULL * a[i + offset + 0 * p].val();\n        \
    \    auto a1 = 1ULL * a[i + offset + 1 * p].val();\n            auto a2 = 1ULL\
    \ * a[i + offset + 2 * p].val();\n            auto a3 = 1ULL * a[i + offset +\
    \ 3 * p].val();\n            auto a2na3iimag = 1ULL * mint((mint::get_mod() +\
    \ a2 - a3) * iimag.val()).val();\n            a[i + offset] = a0 + a1 + a2 + a3;\n\
    \            a[i + offset + 1 * p] = (a0 + (mint::get_mod() - a1) + a2na3iimag)\
    \ * irot.val();\n            a[i + offset + 2 * p] = (a0 + a1 + (mint::get_mod()\
    \ - a2) + (mint::get_mod() - a3)) * irot2.val();\n            a[i + offset + 3\
    \ * p] = (a0 + (mint::get_mod() - a1) + (mint::get_mod() - a2na3iimag)) * irot3.val();\n\
    \          }\n          if (s + 1 != (1 << (len - 2))) irot *= irate3[__builtin_ctzll(~(unsigned\
    \ int)(s))];\n        }\n        len -= 2;\n      }\n    }\n    mint e = mint(n).inv();\n\
    \    for (auto& x : a) x *= e;\n  }\n  vector<mint> multiply(const vector<mint>&\
    \ a, const vector<mint>& b) {\n    if (a.empty() || b.empty()) return vector<mint>();\n\
    \    int n = a.size(), m = b.size();\n    int sz = n + m - 1;\n    if (n <= 30\
    \ || m <= 30) {\n      if (n > 30) return multiply(b, a);\n      vector<mint>\
    \ res(sz);\n      for (int i = 0; i < n; i++)\n        for (int j = 0; j < m;\
    \ j++) res[i + j] += a[i] * b[j];\n      return res;\n    }\n    int sz1 = 1;\n\
    \    while (sz1 < sz) sz1 <<= 1;\n    vector<mint> res(sz1);\n    for (int i =\
    \ 0; i < n; i++) res[i] = a[i];\n    ntt(res);\n    if (a == b)\n      for (int\
    \ i = 0; i < sz1; i++) res[i] *= res[i];\n    else {\n      vector<mint> c(sz1);\n\
    \      for (int i = 0; i < m; i++) c[i] = b[i];\n      ntt(c);\n      for (int\
    \ i = 0; i < sz1; i++) res[i] *= c[i];\n    }\n    intt(res);\n    res.resize(sz);\n\
    \    return res;\n  }\n  // c[i]=sum[j]a[j]b[i+j]\n  vector<mint> middle_product(const\
    \ vector<mint>& a, const vector<mint>& b) {\n    if (b.empty() || a.size() > b.size())\
    \ return {};\n    int n = a.size(), m = b.size();\n    int sz = m - n + 1;\n \
    \   if (n <= 30 || sz <= 30) {\n      vector<mint> res(sz);\n      for (int i\
    \ = 0; i < sz; i++)\n        for (int j = 0; j < n; j++) res[i] += a[j] * b[i\
    \ + j];\n      return res;\n    }\n    int sz1 = 1;\n    while (sz1 < m) sz1 <<=\
    \ 1;\n    vector<mint> res(sz1), b2(sz1);\n    reverse_copy(a.begin(), a.end(),\
    \ res.begin());\n    copy(b.begin(), b.end(), b2.begin());\n    ntt(res);\n  \
    \  ntt(b2);\n    for (int i = 0; i < res.size(); i++) res[i] *= b2[i];\n    intt(res);\n\
    \    res.resize(m);\n    res.erase(res.begin(), res.begin() + n - 1);\n    return\
    \ res;\n  }\n  void ntt_doubling(vector<mint>& a) {\n    int n = (int)a.size();\n\
    \    auto b = a;\n    intt(b);\n    mint r = 1, zeta = mint(g).pow((mint::get_mod()\
    \ - 1) / (n << 1));\n    for (int i = 0; i < n; i++) b[i] *= r, r *= zeta;\n \
    \   ntt(b);\n    copy(b.begin(), b.end(), back_inserter(a));\n  }\n};\n/**\n *\
    \ @brief NTT (\u6570\u8AD6\u5909\u63DB)\n * @docs docs/fft/ntt.md\n */\n#line\
    \ 2 \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \  FPS &operator+=(const FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n  FPS &operator+=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n  FPS &operator-=(const FPS &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n \
    \ FPS &operator-=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n  FPS &operator*=(const mint &v)\
    \ {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return\
    \ *this;\n  }\n  FPS &operator/=(const FPS &r) {\n    if (this->size() < r.size())\
    \ {\n      this->clear();\n      return *this;\n    }\n    int n = this->size()\
    \ - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n\
    \      g.shrink();\n      mint coeff = g.at(g.size() - 1).inv();\n      for (auto\
    \ &x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n  \
    \    int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i >=\
    \ 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n  FPS &operator%=(const FPS &r) {\n  \
    \  *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n  FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n  FPS operator+(const mint &v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint &v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint &v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS &r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS &r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n  void shrink() {\n    while (this->size() && this->back() == mint(0)) this->pop_back();\n\
    \  }\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n\
    \    return ret;\n  }\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n  FPS operator>>=(int sz)\
    \ {\n    assert(sz >= 0);\n    if ((int)this->size() <= sz) return {};\n    this->erase(this->begin(),\
    \ this->begin() + sz);\n    return *this;\n  }\n  FPS operator>>(int sz) const\
    \ {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n    ret.erase(ret.begin(),\
    \ ret.begin() + sz);\n    return ret;\n  }\n  FPS operator<<=(int sz) {\n    assert(sz\
    \ >= 0);\n    this->insert(this->begin(), sz, mint(0));\n    return *this;\n \
    \ }\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n  FPS diff() const {\n    const int n =\
    \ (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n  FPS integral() const {\n \
    \   const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n  FPS log(int deg = -1) const {\n    assert((*this)[0]\
    \ == mint(1));\n    if (deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n  FPS pow(int64_t k, int deg\
    \ = -1) const {\n    const int n = (int)this->size();\n    if (deg == -1) deg\
    \ = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if (deg) ret[0] = 1;\n \
    \     return ret;\n    }\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i]\
    \ != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n  \
    \      ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n      if (__int128_t(i + 1) * k >=\
    \ deg) return FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n\n\
    \  static void *ntt_ptr;\n  static void set_ntt();\n  FPS &operator*=(const FPS\
    \ &r);\n  FPS middle_product(const FPS &r) const;\n  void ntt();\n  void intt();\n\
    \  void ntt_doubling();\n  static int ntt_root();\n  FPS inv(int deg = -1) const;\n\
    \  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr\
    \ = nullptr;\n#line 5 \"fps/fps-ntt-friendly.hpp\"\n\ntemplate <class mint>\n\
    void FormalPowerSeries<mint>::set_ntt() {\n  if (!ntt_ptr) ntt_ptr = new NTT<mint>;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(const\
    \ FormalPowerSeries<mint>& r) {\n  if (this->empty() || r.empty()) {\n    this->clear();\n\
    \    return *this;\n  }\n  set_ntt();\n  auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this,\
    \ r);\n  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\n\
    template <class mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::middle_product(const\
    \ FormalPowerSeries<mint>& r) const {\n  set_ntt();\n  auto ret = static_cast<NTT<mint>*>(ntt_ptr)->middle_product(*this,\
    \ r);\n  return FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\ntemplate\
    \ <class mint>\nvoid FormalPowerSeries<mint>::ntt() {\n  set_ntt();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);\n\
    }\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::intt() {\n  set_ntt();\n\
    \  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);\n}\ntemplate <class mint>\n\
    void FormalPowerSeries<mint>::ntt_doubling() {\n  set_ntt();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);\n\
    }\ntemplate <typename mint>\nint FormalPowerSeries<mint>::ntt_root() {\n  set_ntt();\n\
    \  return static_cast<NTT<mint>*>(ntt_ptr)->g;\n}\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {\n  assert((*this)[0]\
    \ != mint(0));\n  if (deg == -1) deg = (*this).size();\n  FPS ret{mint(1) / (*this)[0]};\n\
    \  for (int i = 1; i < deg; i <<= 1)\n    ret = (ret + ret - ret * ret * (*this).pre(i\
    \ << 1)).pre(i << 1);\n  return ret.pre(deg);\n}\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::exp(int deg) const {\n  assert((*this)[0] == mint(0));\n\
    \  if (deg == -1) deg = (*this).size();\n  FPS ret{mint(1)};\n  for (int i = 1;\
    \ i < deg; i <<= 1)\n    ret = (ret * ((*this).pre(i << 1) - ret.log(i << 1) +\
    \ 1)).pre(i << 1);\n  return ret.pre(deg);\n}\n#line 7 \"verify/fps/LC_product_of_polynomial_sequence.test.cpp\"\
    \nusing fps = FormalPowerSeries<mint>;\n#line 3 \"fps/product-of-polynomials.hpp\"\
    \n\ntemplate <class mint>\nFormalPowerSeries<mint> ProductOfPolynomials(vector<FormalPowerSeries<mint>>\
    \ fs) {\n  if (fs.empty()) return {1};\n  for (auto& f : fs) f.shrink();\n  for\
    \ (auto& f : fs)\n    if (f.empty()) return {};\n  const int B = 1 << 6;\n  for\
    \ (int i = 0, j = -1; i < fs.size(); i++) {\n    if (fs[i].size() > B) continue;\n\
    \    if (j == -1 || fs[i].size() + fs[j].size() - 1 > B) {\n      j = i;\n   \
    \   continue;\n    }\n    fs[j] *= fs[i];\n    swap(fs[i--], fs.back());\n   \
    \ fs.pop_back();\n  }\n  if (fs.size() == 1) return fs[0];\n  for (auto& f : fs)\
    \ {\n    int sz = B;\n    while (sz < f.size()) sz <<= 1;\n    f.resize(sz);\n\
    \    f.ntt();\n  }\n  for (int sz = B * 2; fs.size() > 1; sz <<= 1) {\n    for\
    \ (int i = 0, j = -1; i < fs.size(); i++) {\n      if (fs[i].size() >= sz) continue;\n\
    \      fs[i].ntt_doubling();\n      if (j == -1) {\n        j = i;\n      } else\
    \ {\n        for (int k = 0; k < sz; k++) fs[j][k] *= fs[i][k];\n        swap(fs[i--],\
    \ fs.back());\n        fs.pop_back();\n        j = -1;\n      }\n    }\n  }\n\
    \  fs[0].intt();\n  fs[0].shrink();\n  return fs[0];\n}\n/**\n * @brief \u591A\
    \u9805\u5F0F\u306E\u7A4D\n * @docs docs/fps/product-of-polynomials.md\n */\n#line\
    \ 9 \"verify/fps/LC_product_of_polynomial_sequence.test.cpp\"\n\nint main() {\n\
    \  int n;\n  in(n);\n  vector<fps> fs;\n  rep(i, 0, n) {\n    int d;\n    in(d);\n\
    \    fps f(d + 1);\n    in(f);\n    fs.push_back(f);\n  }\n  out(ProductOfPolynomials(fs));\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\
    \n\n#include \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing\
    \ mint = ModInt<998244353>;\n#include \"fps/fps-ntt-friendly.hpp\"\nusing fps\
    \ = FormalPowerSeries<mint>;\n#include \"fps/product-of-polynomials.hpp\"\n\n\
    int main() {\n  int n;\n  in(n);\n  vector<fps> fs;\n  rep(i, 0, n) {\n    int\
    \ d;\n    in(d);\n    fps f(d + 1);\n    in(f);\n    fs.push_back(f);\n  }\n \
    \ out(ProductOfPolynomials(fs));\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - fps/fps-ntt-friendly.hpp
  - fft/ntt.hpp
  - fps/formal-power-series.hpp
  - fps/product-of-polynomials.hpp
  isVerificationFile: true
  path: verify/fps/LC_product_of_polynomial_sequence.test.cpp
  requiredBy: []
  timestamp: '2025-10-23 01:57:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/fps/LC_product_of_polynomial_sequence.test.cpp
layout: document
redirect_from:
- /verify/verify/fps/LC_product_of_polynomial_sequence.test.cpp
- /verify/verify/fps/LC_product_of_polynomial_sequence.test.cpp.html
title: verify/fps/LC_product_of_polynomial_sequence.test.cpp
---
