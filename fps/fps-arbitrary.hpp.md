---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/intmod.hpp
    title: "\u4EFB\u610F mod \u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: fft/ntt.hpp
    title: "NTT (\u6570\u8AD6\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps-arbitrary.hpp\"\n\n#line 2 \"convolution/intmod.hpp\"\
    \n\n#line 2 \"math/util.hpp\"\n\nnamespace Math {\ntemplate <class T>\nT safe_mod(T\
    \ a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  a %= b;\n  return\
    \ a >= 0 ? a : a + b;\n}\ntemplate <class T>\nT floor(T a, T b) {\n  assert(b\
    \ != 0);\n  if (b < 0) a = -a, b = -b;\n  return a >= 0 ? a / b : (a + 1) / b\
    \ - 1;\n}\ntemplate <class T>\nT ceil(T a, T b) {\n  assert(b != 0);\n  if (b\
    \ < 0) a = -a, b = -b;\n  return a > 0 ? (a - 1) / b + 1 : a / b;\n}\nlong long\
    \ isqrt(long long n) {\n  if (n <= 0) return 0;\n  long long x = sqrt(n);\n  while\
    \ ((x + 1) * (x + 1) <= n) x++;\n  while (x * x > n) x--;\n  return x;\n}\n//\
    \ return g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0 -> 0<=x<|b|/g\n// - b=0  -> ax=g\n\
    template <class T>\nT ext_gcd(T a, T b, T& x, T& y) {\n  T a0 = a, b0 = b;\n \
    \ bool sgn_a = a < 0, sgn_b = b < 0;\n  if (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n\
    \  if (b == 0) {\n    x = sgn_a ? -1 : 1;\n    y = 0;\n    return a;\n  }\n  T\
    \ x00 = 1, x01 = 0, x10 = 0, x11 = 1;\n  while (b != 0) {\n    T q = a / b, r\
    \ = a - b * q;\n    x00 -= q * x01;\n    x10 -= q * x11;\n    swap(x00, x01);\n\
    \    swap(x10, x11);\n    a = b, b = r;\n  }\n  x = x00, y = x10;\n  if (sgn_a)\
    \ x = -x;\n  if (sgn_b) y = -y;\n  if (b0 != 0) {\n    a0 /= a, b0 /= a;\n   \
    \ if (b0 < 0) a0 = -a0, b0 = -b0;\n    T q = x >= 0 ? x / b0 : (x + 1) / b0 -\
    \ 1;\n    x -= b0 * q;\n    y += a0 * q;\n  }\n  return a;\n}\nconstexpr long\
    \ long inv_mod(long long x, long long m) {\n  x %= m;\n  if (x < 0) x += m;\n\
    \  long long a = m, b = x;\n  long long y0 = 0, y1 = 1;\n  while (b > 0) {\n \
    \   long long q = a / b;\n    swap(a -= q * b, b);\n    swap(y0 -= q * y1, y1);\n\
    \  }\n  if (y0 < 0) y0 += m / a;\n  return y0;\n}\nlong long pow_mod(long long\
    \ x, long long n, long long m) {\n  x = (x % m + m) % m;\n  long long y = 1;\n\
    \  while (n) {\n    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n\
    \  }\n  return y;\n}\nconstexpr long long pow_mod_constexpr(long long x, long\
    \ long n, int m) {\n  if (m == 1) return 0;\n  unsigned int _m = (unsigned int)(m);\n\
    \  unsigned long long r = 1;\n  unsigned long long y = x % m;\n  if (y >= m) y\
    \ += m;\n  while (n) {\n    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n\
    \    n >>= 1;\n  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n\
    \  if (n <= 1) return false;\n  if (n == 2 || n == 7 || n == 61) return true;\n\
    \  if (n % 2 == 0) return false;\n  long long d = n - 1;\n  while (d % 2 == 0)\
    \ d /= 2;\n  constexpr long long bases[3] = {2, 7, 61};\n  for (long long a :\
    \ bases) {\n    long long t = d;\n    long long y = pow_mod_constexpr(a, t, n);\n\
    \    while (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n    \
    \  t <<= 1;\n    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n\
    \    }\n  }\n  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
    };  // namespace Math\n#line 3 \"modint/modint.hpp\"\n\ntemplate <unsigned int\
    \ m = 998244353>\nstruct ModInt {\n  using mint = ModInt;\n  static constexpr\
    \ unsigned int get_mod() { return m; }\n  static mint raw(int v) {\n    mint x;\n\
    \    x._v = v;\n    return x;\n  }\n  ModInt() : _v(0) {}\n  ModInt(int64_t v)\
    \ {\n    long long x = (long long)(v % (long long)(umod()));\n    if (x < 0) x\
    \ += umod();\n    _v = (unsigned int)(x);\n  }\n  unsigned int val() const { return\
    \ _v; }\n  mint& operator++() {\n    _v++;\n    if (_v == umod()) _v = 0;\n  \
    \  return *this;\n  }\n  mint& operator--() {\n    if (_v == 0) _v = umod();\n\
    \    _v--;\n    return *this;\n  }\n  mint operator++(int) {\n    mint result\
    \ = *this;\n    ++*this;\n    return result;\n  }\n  mint operator--(int) {\n\
    \    mint result = *this;\n    --*this;\n    return result;\n  }\n  mint& operator+=(const\
    \ mint& rhs) {\n    _v += rhs._v;\n    if (_v >= umod()) _v -= umod();\n    return\
    \ *this;\n  }\n  mint& operator-=(const mint& rhs) {\n    _v -= rhs._v;\n    if\
    \ (_v >= umod()) _v += umod();\n    return *this;\n  }\n  mint& operator*=(const\
    \ mint& rhs) {\n    unsigned long long z = _v;\n    z *= rhs._v;\n    _v = (unsigned\
    \ int)(z % umod());\n    return *this;\n  }\n  mint& operator/=(const mint& rhs)\
    \ { return *this *= rhs.inv(); }\n  mint operator+() const { return *this; }\n\
    \  mint operator-() const { return mint() - *this; }\n  mint pow(long long n)\
    \ const {\n    assert(0 <= n);\n    mint x = *this, r = 1;\n    while (n) {\n\
    \      if (n & 1) r *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return r;\n\
    \  }\n  mint inv() const {\n    if (is_prime) {\n      assert(_v);\n      return\
    \ pow(umod() - 2);\n    } else {\n      auto inv = Math::inv_mod(_v, umod());\n\
    \      return raw(inv);\n    }\n  }\n  friend mint operator+(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n  friend istream&\
    \ operator>>(istream& is, mint& x) {\n    int64_t v;\n    is >> v;\n    x = mint(v);\n\
    \    return is;\n  }\n  friend ostream& operator<<(ostream& os, const mint& x)\
    \ { return os << x.val(); }\n\n private:\n  unsigned int _v;\n  static constexpr\
    \ unsigned int umod() { return m; }\n  static constexpr bool is_prime = Math::is_prime<m>;\n\
    };\n#line 2 \"fft/ntt.hpp\"\n\ntemplate <class mint>\nstruct NTT {\n  static constexpr\
    \ unsigned int mod = mint::get_mod();\n  static constexpr unsigned long long pow_constexpr(unsigned\
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
    \ long;\nstatic constexpr ll Mod1 = 754974721;\nstatic constexpr ll Mod2 = 167772161;\n\
    static constexpr ll Mod3 = 469762049;\nstatic constexpr ll M1invM2 = 95869806;\n\
    static constexpr ll M12invM3 = 187290749;\nusing M1 = ModInt<Mod1>;\nusing M2\
    \ = ModInt<Mod2>;\nusing M3 = ModInt<Mod3>;\nNTT<M1> ntt1;\nNTT<M2> ntt2;\nNTT<M3>\
    \ ntt3;\n\ntemplate <class mint>\nvector<mint> multiply(const vector<mint>& a,\
    \ const vector<mint>& b) {\n  if (a.empty() || b.empty()) return {};\n  int mod\
    \ = mint::get_mod();\n  ll M12mod = Mod1 * Mod2 % mod;\n  vector<unsigned int>\
    \ a0(a.size()), b0(b.size());\n  for (int i = 0; i < a.size(); i++) a0[i] = a[i].val();\n\
    \  for (int i = 0; i < b.size(); i++) b0[i] = b[i].val();\n\n  vector<M1> a1(a0.begin(),\
    \ a0.end()), b1(b0.begin(), b0.end()), c1 = ntt1.multiply(a1, b1);\n  vector<M2>\
    \ a2(a0.begin(), a0.end()), b2(b0.begin(), b0.end()), c2 = ntt2.multiply(a2, b2);\n\
    \  vector<M3> a3(a0.begin(), a0.end()), b3(b0.begin(), b0.end()), c3 = ntt3.multiply(a3,\
    \ b3);\n  vector<mint> c(a.size() + b.size() - 1, 0);\n  for (int i = 0; i < c.size();\
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
    \u610F mod \u7573\u307F\u8FBC\u307F\n * @docs docs/convolution/intmod.md\n */\n\
    #line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <class mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \  FormalPowerSeries(const vector<mint>& r) : vector<mint>(r) {}\n  FormalPowerSeries(vector<mint>&&\
    \ r) : vector<mint>(std::move(r)) {}\n  FPS& operator=(const vector<mint>& r)\
    \ {\n    vector<mint>::operator=(r);\n    return *this;\n  }\n  FPS& operator+=(const\
    \ FPS& r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n  FPS& operator+=(const mint& r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n  FPS& operator-=(const FPS& r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n \
    \ FPS& operator-=(const mint& r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n  FPS& operator*=(const mint& v)\
    \ {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return\
    \ *this;\n  }\n  FPS& operator/=(const FPS& r) {\n    if (this->size() < r.size())\
    \ {\n      this->clear();\n      return *this;\n    }\n    int n = this->size()\
    \ - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n\
    \      g.shrink();\n      mint coeff = g.at(g.size() - 1).inv();\n      for (auto&\
    \ x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n   \
    \   int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i >=\
    \ 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n  FPS& operator%=(const FPS& r) {\n  \
    \  *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n  FPS operator+(const\
    \ FPS& r) const { return FPS(*this) += r; }\n  FPS operator+(const mint& v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS& r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint& v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS& r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint& v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS& r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS& r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n  void shrink() {\n    while (this->size() && this->back() == mint(0)) this->pop_back();\n\
    \  }\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n\
    \    return ret;\n  }\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n  FPS operator>>=(int sz)\
    \ {\n    assert(sz >= 0);\n    if ((int)this->size() <= sz)\n      this->clear();\n\
    \    else\n      this->erase(this->begin(), this->begin() + sz);\n    return *this;\n\
    \  }\n  FPS operator>>(int sz) const {\n    if ((int)this->size() <= sz) return\
    \ {};\n    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n  \
    \  return ret;\n  }\n  FPS operator<<=(int sz) {\n    assert(sz >= 0);\n    this->insert(this->begin(),\
    \ sz, mint(0));\n    return *this;\n  }\n  FPS operator<<(int sz) const {\n  \
    \  FPS ret(*this);\n    ret.insert(ret.begin(), sz, mint(0));\n    return ret;\n\
    \  }\n  FPS diff() const {\n    const int n = (int)this->size();\n    FPS ret(max(0,\
    \ n - 1));\n    mint one(1), coeff(1);\n    for (int i = 1; i < n; i++) {\n  \
    \    ret[i - 1] = (*this)[i] * coeff;\n      coeff += one;\n    }\n    return\
    \ ret;\n  }\n  FPS integral() const {\n    const int n = (int)this->size();\n\
    \    FPS ret(n + 1);\n    ret[0] = mint(0);\n    if (n > 0) ret[1] = mint(1);\n\
    \    auto mod = mint::get_mod();\n    for (int i = 2; i <= n; i++) ret[i] = (-ret[mod\
    \ % i]) * (mod / i);\n    for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n\
    \    return ret;\n  }\n  mint eval(mint x) const {\n    mint r = 0, w = 1;\n \
    \   for (auto& v : *this) r += w * v, w *= x;\n    return r;\n  }\n  FPS log(int\
    \ deg = -1) const {\n    assert((*this)[0] == mint(1));\n    if (deg == -1) deg\
    \ = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n\
    \  }\n  FPS pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n\
    \        FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret\
    \ *= (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if\
    \ ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return ret;\n   \
    \   }\n      if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \ }\n    return FPS(deg, mint(0));\n  }\n\n  static void* ntt_ptr;\n  static void\
    \ set_ntt();\n  FPS& operator*=(const FPS& r);\n  FPS middle_product(const FPS&\
    \ r) const;\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_root();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid* FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    #line 5 \"fps/fps-arbitrary.hpp\"\n\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::set_ntt()\
    \ { ntt_ptr = nullptr; }\ntemplate <class mint>\nFormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(const\
    \ FormalPowerSeries<mint>& r) {\n  if (this->empty() || r.empty()) {\n    this->clear();\n\
    \    return *this;\n  }\n  auto ret = ConvolutionIntMod::multiply(*this, r);\n\
    \  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\ntemplate\
    \ <class mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::middle_product(const\
    \ FormalPowerSeries<mint>& r) const {\n  auto ret = ConvolutionIntMod::middle_product(*this,\
    \ r);\n  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\n\
    template <class mint>\nvoid FormalPowerSeries<mint>::ntt() { exit(1); }\ntemplate\
    \ <class mint>\nvoid FormalPowerSeries<mint>::intt() { exit(1); }\ntemplate <class\
    \ mint>\nvoid FormalPowerSeries<mint>::ntt_doubling() { exit(1); }\ntemplate <typename\
    \ mint>\nint FormalPowerSeries<mint>::ntt_root() { exit(1); }\ntemplate <typename\
    \ mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {\n\
    \  assert((*this)[0] != mint(0));\n  if (deg == -1) deg = (*this).size();\n  FPS\
    \ ret{mint(1) / (*this)[0]};\n  for (int i = 1; i < deg; i <<= 1)\n    ret = (ret\
    \ + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);\n  return ret.pre(deg);\n\
    }\ntemplate <typename mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int\
    \ deg) const {\n  assert((*this)[0] == mint(0));\n  if (deg == -1) deg = (*this).size();\n\
    \  FPS ret{mint(1)};\n  for (int i = 1; i < deg; i <<= 1)\n    ret = (ret * ((*this).pre(i\
    \ << 1) - ret.log(i << 1) + 1)).pre(i << 1);\n  return ret.pre(deg);\n}\n"
  code: "#pragma once\n\n#include \"convolution/intmod.hpp\"\n#include \"fps/formal-power-series.hpp\"\
    \n\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::set_ntt() { ntt_ptr =\
    \ nullptr; }\ntemplate <class mint>\nFormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(const\
    \ FormalPowerSeries<mint>& r) {\n  if (this->empty() || r.empty()) {\n    this->clear();\n\
    \    return *this;\n  }\n  auto ret = ConvolutionIntMod::multiply(*this, r);\n\
    \  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\ntemplate\
    \ <class mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::middle_product(const\
    \ FormalPowerSeries<mint>& r) const {\n  auto ret = ConvolutionIntMod::middle_product(*this,\
    \ r);\n  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\n\
    template <class mint>\nvoid FormalPowerSeries<mint>::ntt() { exit(1); }\ntemplate\
    \ <class mint>\nvoid FormalPowerSeries<mint>::intt() { exit(1); }\ntemplate <class\
    \ mint>\nvoid FormalPowerSeries<mint>::ntt_doubling() { exit(1); }\ntemplate <typename\
    \ mint>\nint FormalPowerSeries<mint>::ntt_root() { exit(1); }\ntemplate <typename\
    \ mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {\n\
    \  assert((*this)[0] != mint(0));\n  if (deg == -1) deg = (*this).size();\n  FPS\
    \ ret{mint(1) / (*this)[0]};\n  for (int i = 1; i < deg; i <<= 1)\n    ret = (ret\
    \ + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);\n  return ret.pre(deg);\n\
    }\ntemplate <typename mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int\
    \ deg) const {\n  assert((*this)[0] == mint(0));\n  if (deg == -1) deg = (*this).size();\n\
    \  FPS ret{mint(1)};\n  for (int i = 1; i < deg; i <<= 1)\n    ret = (ret * ((*this).pre(i\
    \ << 1) - ret.log(i << 1) + 1)).pre(i << 1);\n  return ret.pre(deg);\n}"
  dependsOn:
  - convolution/intmod.hpp
  - modint/modint.hpp
  - math/util.hpp
  - fft/ntt.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/fps-arbitrary.hpp
  requiredBy: []
  timestamp: '2025-12-29 01:13:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps-arbitrary.hpp
layout: document
redirect_from:
- /library/fps/fps-arbitrary.hpp
- /library/fps/fps-arbitrary.hpp.html
title: fps/fps-arbitrary.hpp
---
