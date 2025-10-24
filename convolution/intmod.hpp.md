---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fft/ntt.hpp
    title: "NTT (\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/convolution/LC_convolution_mod_1000000007.test.cpp
    title: verify/convolution/LC_convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/intmod.md
    document_title: "\u4EFB\u610F mod \u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "#line 2 \"convolution/intmod.hpp\"\n\n#line 2 \"modint/modint.hpp\"\
    \n\ntemplate <unsigned int m = 998244353>\nstruct ModInt {\n  using mint = ModInt;\n\
    \  unsigned int _v;\n  static constexpr unsigned int get_mod() { return m; }\n\
    \  static mint raw(int v) {\n    mint x;\n    x._v = v;\n    return x;\n  }\n\
    \  ModInt() : _v(0) {}\n  ModInt(int64_t v) {\n    long long x = (long long)(v\
    \ % (long long)(umod()));\n    if (x < 0) x += umod();\n    _v = (unsigned int)(x);\n\
    \  }\n  unsigned int val() const { return _v; }\n  mint &operator++() {\n    _v++;\n\
    \    if (_v == umod()) _v = 0;\n    return *this;\n  }\n  mint &operator--() {\n\
    \    if (_v == 0) _v = umod();\n    _v--;\n    return *this;\n  }\n  mint operator++(int)\
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
    \ private:\n  static constexpr unsigned int umod() { return m; }\n};\n#line 2\
    \ \"fft/ntt.hpp\"\n\ntemplate <class mint>\nstruct NTT {\n  static constexpr unsigned\
    \ int mod = mint::get_mod();\n  static constexpr unsigned long long pow_constexpr(unsigned\
    \ long long x, unsigned long long n, unsigned long long m) {\n    unsigned long\
    \ long y = 1;\n    while (n) {\n      if (n & 1) y = y * x % m;\n      x = x *\
    \ x % m;\n      n >>= 1;\n    }\n    return y;\n  }\n  static constexpr unsigned\
    \ int get_g() {\n    unsigned long long x = 2;\n    while (pow_constexpr(x, (mod\
    \ - 1) >> 1, mod) == 1) x += 1;\n    return x;\n  }\n  static constexpr unsigned\
    \ int g = get_g();\n  static constexpr int rank2 = __builtin_ctzll(mod - 1);\n\
    \  array<mint, rank2 + 1> root;\n  array<mint, rank2 + 1> iroot;\n  array<mint,\
    \ max(0, rank2 - 2 + 1)> rate2;\n  array<mint, max(0, rank2 - 2 + 1)> irate2;\n\
    \  array<mint, max(0, rank2 - 3 + 1)> rate3;\n  array<mint, max(0, rank2 - 3 +\
    \ 1)> irate3;\n\n  NTT() {\n    root[rank2] = mint(g).pow((mod - 1) >> rank2);\n\
    \    iroot[rank2] = root[rank2].inv();\n    for (int i = rank2 - 1; i >= 0; i--)\
    \ {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i + 1]\
    \ * iroot[i + 1];\n    }\n    {\n      mint prod = 1, iprod = 1;\n      for (int\
    \ i = 0; i <= rank2 - 2; i++) {\n        rate2[i] = root[i + 2] * prod;\n    \
    \    irate2[i] = iroot[i + 2] * iprod;\n        prod *= iroot[i + 2];\n      \
    \  iprod *= root[i + 2];\n      }\n    }\n    {\n      mint prod = 1, iprod =\
    \ 1;\n      for (int i = 0; i <= rank2 - 3; i++) {\n        rate3[i] = root[i\
    \ + 3] * prod;\n        irate3[i] = iroot[i + 3] * iprod;\n        prod *= iroot[i\
    \ + 3];\n        iprod *= root[i + 3];\n      }\n    }\n  }\n  void ntt(vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = __builtin_ctzll((unsigned int)n);\n\
    \    a.resize(1 << h);\n    int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..]\
    \ is transformed\n    while (len < h) {\n      if (h - len == 1) {\n        int\
    \ p = 1 << (h - len - 1);\n        mint rot = 1;\n        for (int s = 0; s <\
    \ (1 << len); s++) {\n          int offset = s << (h - len);\n          for (int\
    \ i = 0; i < p; i++) {\n            auto l = a[i + offset];\n            auto\
    \ r = a[i + offset + p] * rot;\n            a[i + offset] = l + r;\n         \
    \   a[i + offset + p] = l - r;\n          }\n          if (s + 1 != (1 << len))\
    \ rot *= rate2[__builtin_ctzll(~(unsigned int)(s))];\n        }\n        len++;\n\
    \      } else {\n        // 4-base\n        int p = 1 << (h - len - 2);\n    \
    \    mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len); s++)\
    \ {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n   \
    \       int offset = s << (h - len);\n          for (int i = 0; i < p; i++) {\n\
    \            auto mod2 = 1ULL * mint::get_mod() * mint::get_mod();\n         \
    \   auto a0 = 1ULL * a[i + offset].val();\n            auto a1 = 1ULL * a[i +\
    \ offset + p].val() * rot.val();\n            auto a2 = 1ULL * a[i + offset +\
    \ 2 * p].val() * rot2.val();\n            auto a3 = 1ULL * a[i + offset + 3 *\
    \ p].val() * rot3.val();\n            auto a1na3imag = 1ULL * mint(a1 + mod2 -\
    \ a3).val() * imag.val();\n            auto na2 = mod2 - a2;\n            a[i\
    \ + offset] = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2\
    \ + (2 * mod2 - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n\
    \            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n        \
    \  }\n          if (s + 1 != (1 << len)) rot *= rate3[__builtin_ctzll(~(unsigned\
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
    \ 5 \"convolution/intmod.hpp\"\n\nnamespace ConvolutionIntMod {\nusing ll = long\
    \ long;\nconst ll Mod1 = 754974721;\nconst ll Mod2 = 167772161;\nconst ll Mod3\
    \ = 469762049;\nconst ll M1invM2 = 95869806;\nconst ll M12invM3 = 187290749;\n\
    using M1 = ModInt<Mod1>;\nusing M2 = ModInt<Mod2>;\nusing M3 = ModInt<Mod3>;\n\
    NTT<M1> ntt1;\nNTT<M2> ntt2;\nNTT<M3> ntt3;\n\ntemplate <class mint>\nvector<mint>\
    \ multiply(const vector<mint>& a, const vector<mint>& b) {\n  if (a.empty() ||\
    \ b.empty()) return {};\n  int mod = mint::get_mod();\n  ll M12mod = Mod1 * Mod2\
    \ % mod;\n  vector<unsigned int> a0(a.size()), b0(b.size());\n  for (int i = 0;\
    \ i < a.size(); i++) a0[i] = a[i].val();\n  for (int i = 0; i < b.size(); i++)\
    \ b0[i] = b[i].val();\n\n  vector<M1> a1(a0.begin(), a0.end()), b1(b0.begin(),\
    \ b0.end()), c1 = ntt1.multiply(a1, b1);\n  vector<M2> a2(a0.begin(), a0.end()),\
    \ b2(b0.begin(), b0.end()), c2 = ntt2.multiply(a2, b2);\n  vector<M3> a3(a0.begin(),\
    \ a0.end()), b3(b0.begin(), b0.end()), c3 = ntt3.multiply(a3, b3);\n  vector<mint>\
    \ c(a.size() + b.size() - 1, 0);\n  for (int i = 0; i < c.size(); i++) {\n   \
    \ ll v1 = ((ll)c2[i].val() - (ll)c1[i].val()) * M1invM2 % Mod2;\n    if (v1 <\
    \ 0) v1 += Mod2;\n    ll v2 = ((ll)c3[i].val() - ((ll)c1[i].val() + Mod1 * v1)\
    \ % Mod3) * M12invM3 % Mod3;\n    if (v2 < 0) v2 += Mod3;\n    ll v3 = ((ll)c1[i].val()\
    \ + Mod1 * v1 + M12mod * v2) % mod;\n    if (v3 < 0) v3 += mod;\n    c[i] = v3;\n\
    \  }\n  return c;\n}\ntemplate <class mint>\nvector<mint> middle_product(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  if (b.empty() || a.size() > b.size())\
    \ return {};\n  int mod = mint::get_mod();\n  ll M12mod = Mod1 * Mod2 % mod;\n\
    \  vector<unsigned int> a0(a.size()), b0(b.size());\n  for (int i = 0; i < a.size();\
    \ i++) a0[i] = a[i].val();\n  for (int i = 0; i < b.size(); i++) b0[i] = b[i].val();\n\
    \n  vector<M1> a1(a0.begin(), a0.end()), b1(b0.begin(), b0.end()), c1 = ntt1.middle_product(a1,\
    \ b1);\n  vector<M2> a2(a0.begin(), a0.end()), b2(b0.begin(), b0.end()), c2 =\
    \ ntt2.middle_product(a2, b2);\n  vector<M3> a3(a0.begin(), a0.end()), b3(b0.begin(),\
    \ b0.end()), c3 = ntt3.middle_product(a3, b3);\n  vector<mint> c(c1.size(), 0);\n\
    \  for (int i = 0; i < c.size(); i++) {\n    ll v1 = ((ll)c2[i].val() - (ll)c1[i].val())\
    \ * M1invM2 % Mod2;\n    if (v1 < 0) v1 += Mod2;\n    ll v2 = ((ll)c3[i].val()\
    \ - ((ll)c1[i].val() + Mod1 * v1) % Mod3) * M12invM3 % Mod3;\n    if (v2 < 0)\
    \ v2 += Mod3;\n    ll v3 = ((ll)c1[i].val() + Mod1 * v1 + M12mod * v2) % mod;\n\
    \    if (v3 < 0) v3 += mod;\n    c[i] = v3;\n  }\n  return c;\n}\n};  // namespace\
    \ ConvolutionIntMod\n\n/**\n * @brief \u4EFB\u610F mod \u7573\u307F\u8FBC\u307F\
    \n * @docs docs/convolution/intmod.md\n */\n"
  code: "#pragma once\n\n#include \"../modint/modint.hpp\"\n#include \"../fft/ntt.hpp\"\
    \n\nnamespace ConvolutionIntMod {\nusing ll = long long;\nconst ll Mod1 = 754974721;\n\
    const ll Mod2 = 167772161;\nconst ll Mod3 = 469762049;\nconst ll M1invM2 = 95869806;\n\
    const ll M12invM3 = 187290749;\nusing M1 = ModInt<Mod1>;\nusing M2 = ModInt<Mod2>;\n\
    using M3 = ModInt<Mod3>;\nNTT<M1> ntt1;\nNTT<M2> ntt2;\nNTT<M3> ntt3;\n\ntemplate\
    \ <class mint>\nvector<mint> multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  if (a.empty() || b.empty()) return {};\n  int mod = mint::get_mod();\n\
    \  ll M12mod = Mod1 * Mod2 % mod;\n  vector<unsigned int> a0(a.size()), b0(b.size());\n\
    \  for (int i = 0; i < a.size(); i++) a0[i] = a[i].val();\n  for (int i = 0; i\
    \ < b.size(); i++) b0[i] = b[i].val();\n\n  vector<M1> a1(a0.begin(), a0.end()),\
    \ b1(b0.begin(), b0.end()), c1 = ntt1.multiply(a1, b1);\n  vector<M2> a2(a0.begin(),\
    \ a0.end()), b2(b0.begin(), b0.end()), c2 = ntt2.multiply(a2, b2);\n  vector<M3>\
    \ a3(a0.begin(), a0.end()), b3(b0.begin(), b0.end()), c3 = ntt3.multiply(a3, b3);\n\
    \  vector<mint> c(a.size() + b.size() - 1, 0);\n  for (int i = 0; i < c.size();\
    \ i++) {\n    ll v1 = ((ll)c2[i].val() - (ll)c1[i].val()) * M1invM2 % Mod2;\n\
    \    if (v1 < 0) v1 += Mod2;\n    ll v2 = ((ll)c3[i].val() - ((ll)c1[i].val()\
    \ + Mod1 * v1) % Mod3) * M12invM3 % Mod3;\n    if (v2 < 0) v2 += Mod3;\n    ll\
    \ v3 = ((ll)c1[i].val() + Mod1 * v1 + M12mod * v2) % mod;\n    if (v3 < 0) v3\
    \ += mod;\n    c[i] = v3;\n  }\n  return c;\n}\ntemplate <class mint>\nvector<mint>\
    \ middle_product(const vector<mint>& a, const vector<mint>& b) {\n  if (b.empty()\
    \ || a.size() > b.size()) return {};\n  int mod = mint::get_mod();\n  ll M12mod\
    \ = Mod1 * Mod2 % mod;\n  vector<unsigned int> a0(a.size()), b0(b.size());\n \
    \ for (int i = 0; i < a.size(); i++) a0[i] = a[i].val();\n  for (int i = 0; i\
    \ < b.size(); i++) b0[i] = b[i].val();\n\n  vector<M1> a1(a0.begin(), a0.end()),\
    \ b1(b0.begin(), b0.end()), c1 = ntt1.middle_product(a1, b1);\n  vector<M2> a2(a0.begin(),\
    \ a0.end()), b2(b0.begin(), b0.end()), c2 = ntt2.middle_product(a2, b2);\n  vector<M3>\
    \ a3(a0.begin(), a0.end()), b3(b0.begin(), b0.end()), c3 = ntt3.middle_product(a3,\
    \ b3);\n  vector<mint> c(c1.size(), 0);\n  for (int i = 0; i < c.size(); i++)\
    \ {\n    ll v1 = ((ll)c2[i].val() - (ll)c1[i].val()) * M1invM2 % Mod2;\n    if\
    \ (v1 < 0) v1 += Mod2;\n    ll v2 = ((ll)c3[i].val() - ((ll)c1[i].val() + Mod1\
    \ * v1) % Mod3) * M12invM3 % Mod3;\n    if (v2 < 0) v2 += Mod3;\n    ll v3 = ((ll)c1[i].val()\
    \ + Mod1 * v1 + M12mod * v2) % mod;\n    if (v3 < 0) v3 += mod;\n    c[i] = v3;\n\
    \  }\n  return c;\n}\n};  // namespace ConvolutionIntMod\n\n/**\n * @brief \u4EFB\
    \u610F mod \u7573\u307F\u8FBC\u307F\n * @docs docs/convolution/intmod.md\n */"
  dependsOn:
  - modint/modint.hpp
  - fft/ntt.hpp
  isVerificationFile: false
  path: convolution/intmod.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/convolution/LC_convolution_mod_1000000007.test.cpp
documentation_of: convolution/intmod.hpp
layout: document
redirect_from:
- /library/convolution/intmod.hpp
- /library/convolution/intmod.hpp.html
title: "\u4EFB\u610F mod \u7573\u307F\u8FBC\u307F"
---
必ずしも NTT friendly でない一般の (32 bit の) mod において $O(N\log N)$ 時間で畳み込みが計算できる．

3 つの NTT friendly な素数について畳み込み，それらの結果から本来の mod での値を復元する．
