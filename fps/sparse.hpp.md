---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: fps/formal-power-series.hpp
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':heavy_check_mark:'
    path: modint/factorial.hpp
    title: "\u968E\u4E57, \u4E8C\u9805\u4FC2\u6570"
  - icon: ':heavy_check_mark:'
    path: modint/mod-sqrt.hpp
    title: modint/mod-sqrt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_exp_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_exp_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_inv_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_inv_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
    title: verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/sparse.md
    document_title: "Sparse \u306A FPS \u6F14\u7B97"
    links: []
  bundledCode: "#line 2 \"modint/factorial.hpp\"\n\ntemplate <class mint>\nstruct\
    \ Factorial {\n  static void reserve(int n) {\n    inv(n);\n    fact(n);\n   \
    \ fact_inv(n);\n  }\n  static mint inv(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> buf({0, 1});\n    assert(n != 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      buf = vector<mint>({0, 1});\n    }\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size(), q = (mod + k - 1)\
    \ / k;\n      buf.push_back(q * buf[k * q - mod]);\n    }\n    return buf[n];\n\
    \  }\n  static mint fact(int n) {\n    static long long mod = mint::get_mod();\n\
    \    static vector<mint> buf({1, 1});\n    assert(n >= 0);\n    if (mod != mint::get_mod())\
    \ {\n      mod = mint::get_mod();\n      buf = vector<mint>({1, 1});\n    }\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back()\
    \ * k);\n    }\n    return buf[n];\n  }\n  static mint fact_inv(int n) {\n   \
    \ static long long mod = mint::get_mod();\n    static vector<mint> buf({1, 1});\n\
    \    assert(n >= 0);\n    if (mod != mint::get_mod()) {\n      mod = mint::get_mod();\n\
    \      buf = vector<mint>({1, 1});\n    }\n    if ((int)buf.size() <= n) inv(n);\n\
    \    while ((int)buf.capacity() <= n) buf.reserve(buf.capacity() * 2);\n    while\
    \ ((int)buf.size() <= n) {\n      long long k = buf.size();\n      buf.push_back(buf.back()\
    \ * inv(k));\n    }\n    return buf[n];\n  }\n  static mint binom(int n, int r)\
    \ {\n    if (r < 0 || r > n) return 0;\n    return fact(n) * fact_inv(r) * fact_inv(n\
    \ - r);\n  }\n  static mint binom_naive(int n, int r) {\n    if (r < 0 || r >\
    \ n) return 0;\n    mint res = fact_inv(r);\n    for (int i = 0; i < r; i++) res\
    \ *= n - i;\n    return res;\n  }\n  static mint multinom(const vector<int>& r)\
    \ {\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return 0;\n   \
    \   n += x;\n    }\n    mint res = fact(n);\n    for (auto& x : r) res *= fact_inv(x);\n\
    \    return res;\n  }\n  static mint P(int n, int r) {\n    if (r < 0 || r > n)\
    \ return 0;\n    return fact(n) * fact_inv(n - r);\n  }\n  // partition n items\
    \ to r groups (allow empty group)\n  static mint H(int n, int r) {\n    if (n\
    \ < 0 || r < 0) return 0;\n    return r == 0 ? 1 : binom(n + r - 1, r);\n  }\n\
    };\n/**\n * @brief \u968E\u4E57, \u4E8C\u9805\u4FC2\u6570\n */\n#line 2 \"modint/mod-sqrt.hpp\"\
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
    \ 1;\n    x -= b0 * q;\n    y += a0 * q;\n  }\n  return a;\n}\nlong long inv_mod(long\
    \ long x, long long m) {\n  x %= m;\n  if (x < 0) x += m;\n  long long a = m,\
    \ b = x;\n  long long y0 = 0, y1 = 1;\n  while (b > 0) {\n    long long q = a\
    \ / b;\n    swap(a -= q * b, b);\n    swap(y0 -= q * y1, y1);\n  }\n  if (y0 <\
    \ 0) y0 += m / a;\n  return y0;\n}\nlong long pow_mod(long long x, long long n,\
    \ long long m) {\n  x = (x % m + m) % m;\n  long long y = 1;\n  while (n) {\n\
    \    if (n & 1) y = y * x % m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return\
    \ y;\n}\nconstexpr long long pow_mod_constexpr(long long x, long long n, int m)\
    \ {\n  if (m == 1) return 0;\n  unsigned int _m = (unsigned int)(m);\n  unsigned\
    \ long long r = 1;\n  unsigned long long y = x % m;\n  if (y >= m) y += m;\n \
    \ while (n) {\n    if (n & 1) r = (r * y) % _m;\n    y = (y * y) % _m;\n    n\
    \ >>= 1;\n  }\n  return r;\n}\nconstexpr bool is_prime_constexpr(int n) {\n  if\
    \ (n <= 1) return false;\n  if (n == 2 || n == 7 || n == 61) return true;\n  if\
    \ (n % 2 == 0) return false;\n  long long d = n - 1;\n  while (d % 2 == 0) d /=\
    \ 2;\n  constexpr long long bases[3] = {2, 7, 61};\n  for (long long a : bases)\
    \ {\n    long long t = d;\n    long long y = pow_mod_constexpr(a, t, n);\n   \
    \ while (t != n - 1 && y != 1 && y != n - 1) {\n      y = y * y % n;\n      t\
    \ <<= 1;\n    }\n    if (y != n - 1 && t % 2 == 0) {\n      return false;\n  \
    \  }\n  }\n  return true;\n}\ntemplate <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\
    };  // namespace Math\n#line 4 \"modint/mod-sqrt.hpp\"\n\nlong long ModSqrt(long\
    \ long a, long long p) {\n  if (a >= p) a %= p;\n  if (p == 2) return a & 1;\n\
    \  if (a == 0) return 0;\n  if (Math::pow_mod(a, (p - 1) / 2, p) != 1) return\
    \ -1;\n  if (p % 4 == 3) return Math::pow_mod(a, (3 * p - 1) / 4, p);\n  unsigned\
    \ int z = 2, q = p - 1;\n  while (Math::pow_mod(z, (p - 1) / 2, p) == 1) z++;\n\
    \  int s = 0;\n  while (!(q & 1)) {\n    s++;\n    q >>= 1;\n  }\n  int m = s;\n\
    \  unsigned int c = Math::pow_mod(z, q, p);\n  unsigned int t = Math::pow_mod(a,\
    \ q, p);\n  unsigned int r = Math::pow_mod(a, (q + 1) / 2, p);\n  while (true)\
    \ {\n    if (t == 1) return r;\n    unsigned int pow = t;\n    int j = 1;\n  \
    \  for (; j < m; j++) {\n      pow = 1ll * pow * pow % p;\n      if (pow == 1)\
    \ break;\n    }\n    unsigned int b = c;\n    for (int i = 0; i < m - j - 1; i++)\
    \ b = 1ll * b * b % p;\n    m = j;\n    c = 1ll * b * b % p;\n    t = 1ll * t\
    \ * c % p;\n    r = 1ll * r * b % p;\n  }\n}\n#line 2 \"fps/formal-power-series.hpp\"\
    \n\ntemplate <class mint>\nstruct FormalPowerSeries : vector<mint> {\n  using\
    \ vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n  FormalPowerSeries(const\
    \ vector<mint>& r) : vector<mint>(r) {}\n  FormalPowerSeries(vector<mint>&& r)\
    \ : vector<mint>(std::move(r)) {}\n  FPS& operator=(const vector<mint>& r) {\n\
    \    vector<mint>::operator=(r);\n    return *this;\n  }\n  FPS& operator+=(const\
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
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto& v : *this) r += w * v, w\
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
    \  static void* ntt_ptr;\n  static void set_ntt();\n  FPS& operator*=(const FPS&\
    \ r);\n  FPS middle_product(const FPS& r) const;\n  void ntt();\n  void intt();\n\
    \  void ntt_doubling();\n  static int ntt_root();\n  FPS inv(int deg = -1) const;\n\
    \  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\nvoid* FormalPowerSeries<mint>::ntt_ptr\
    \ = nullptr;\n#line 5 \"fps/sparse.hpp\"\n\nnamespace FPSSparse {\ntemplate <class\
    \ mint>\nFormalPowerSeries<mint> inv(map<int, mint> f, int n) {\n  assert(f[0]\
    \ != 0);\n  if (n == 0) return {};\n  mint c = f[0].inv();\n  FormalPowerSeries<mint>\
    \ g(n);\n  g[0] = c;\n  for (int i = 1; i < n; i++) {\n    for (auto [j, v] :\
    \ f)\n      if (j <= i) g[i] -= v * g[i - j];\n    g[i] *= c;\n  }\n  return g;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint> exp(map<int, mint> f, int n)\
    \ {\n  assert(f[0] == 0);\n  if (n == 0) return {};\n  FormalPowerSeries<mint>\
    \ g(n);\n  g[0] = 1;\n  for (int i = 1; i < n; i++) {\n    for (auto [j, v] :\
    \ f)\n      if (j <= i) g[i] += j * v * g[i - j];\n    g[i] *= Factorial<mint>::inv(i);\n\
    \  }\n  return g;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> log(map<int,\
    \ mint> f, int n) {\n  assert(f[0] == 1);\n  if (n == 0) return {};\n  FormalPowerSeries<mint>\
    \ g(n);\n  g[0] = 0;\n  for (auto [j, v] : f)\n    if (0 < j && j < n) g[j - 1]\
    \ = v * j;\n  for (int i = 1; i < n; i++) {\n    for (auto [j, v] : f)\n     \
    \ if (0 < j && j <= i) g[i] -= v * g[i - j];\n  }\n  for (int i = n - 1; i > 0;\
    \ i--) g[i] = g[i - 1] * Factorial<mint>::inv(i);\n  g[0] = 0;\n  return g;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint> pow(map<int, mint> f, long long\
    \ m, int n) {\n  if (n == 0) return {};\n  FormalPowerSeries<mint> g(n, 0);\n\
    \  if (m == 0) {\n    g[0] = 1;\n    return g;\n  }\n  if (!f.contains(0) || f[0]\
    \ == 0) {\n    if (m >= n) return g;\n    int s = n;\n    for (auto [i, v] : f)\n\
    \      if (v != 0 && i < s) s = i;\n    if (s * m >= n) return g;\n    map<int,\
    \ mint> f1;\n    for (auto [i, v] : f) f1[i - s] = v;\n    auto g1 = pow(f1, m,\
    \ int(n - s * m));\n    copy(g1.begin(), g1.end(), g.begin() + int(s * m));\n\
    \    return g;\n  }\n  g[0] = f[0].pow(m);\n  mint c = f[0].inv();\n  for (int\
    \ i = 1; i < n; i++) {\n    for (auto [j, v] : f) {\n      if (0 < j && j <= i)\
    \ g[i] += j * f[j] * g[i - j] * m;\n      if (0 < j && j < i) g[i] -= f[j] * (i\
    \ - j) * g[i - j];\n    }\n    g[i] *= c * Factorial<mint>::inv(i);\n  }\n  return\
    \ g;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> sqrt(map<int, mint> f,\
    \ int n) {\n  if (n == 0) return {};\n  if (f.empty()) return FormalPowerSeries<mint>(n,\
    \ 0);\n  FormalPowerSeries<mint> g(n, 0);\n  if (f[0] == 0) {\n    int s = n *\
    \ 2;\n    for (auto [i, v] : f)\n      if (v != 0 && i < s) s = i;\n    if (s\
    \ & 1) return {};\n    s /= 2;\n    if (s >= n) return g;\n    map<int, mint>\
    \ f1;\n    for (auto [i, v] : f) f1[i - s * 2] = v;\n    auto g1 = sqrt(f1, int(n\
    \ - s));\n    if (g1.empty()) return {};\n    copy(g1.begin(), g1.end(), g.begin()\
    \ + s);\n    return g;\n  }\n  long long sq = ModSqrt(f[0].val(), mint::get_mod());\n\
    \  if (sq < 0) return {};\n  g[0] = sq;\n  mint c = f[0].inv(), inv2 = mint(2).inv();\n\
    \  for (int i = 1; i < n; i++) {\n    for (auto [j, v] : f) {\n      if (0 < j\
    \ && j <= i) g[i] += j * f[j] * g[i - j] * inv2;\n      if (0 < j && j < i) g[i]\
    \ -= f[j] * (i - j) * g[i - j];\n    }\n    g[i] *= c * Factorial<mint>::inv(i);\n\
    \  }\n  return g;\n}\n};  // namespace FPSSparse\n\n/**\n * @brief Sparse \u306A\
    \ FPS \u6F14\u7B97\n * @docs docs/fps/sparse.md\n */\n"
  code: "#pragma once\n#include \"modint/factorial.hpp\"\n#include \"modint/mod-sqrt.hpp\"\
    \n#include \"fps/formal-power-series.hpp\"\n\nnamespace FPSSparse {\ntemplate\
    \ <class mint>\nFormalPowerSeries<mint> inv(map<int, mint> f, int n) {\n  assert(f[0]\
    \ != 0);\n  if (n == 0) return {};\n  mint c = f[0].inv();\n  FormalPowerSeries<mint>\
    \ g(n);\n  g[0] = c;\n  for (int i = 1; i < n; i++) {\n    for (auto [j, v] :\
    \ f)\n      if (j <= i) g[i] -= v * g[i - j];\n    g[i] *= c;\n  }\n  return g;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint> exp(map<int, mint> f, int n)\
    \ {\n  assert(f[0] == 0);\n  if (n == 0) return {};\n  FormalPowerSeries<mint>\
    \ g(n);\n  g[0] = 1;\n  for (int i = 1; i < n; i++) {\n    for (auto [j, v] :\
    \ f)\n      if (j <= i) g[i] += j * v * g[i - j];\n    g[i] *= Factorial<mint>::inv(i);\n\
    \  }\n  return g;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> log(map<int,\
    \ mint> f, int n) {\n  assert(f[0] == 1);\n  if (n == 0) return {};\n  FormalPowerSeries<mint>\
    \ g(n);\n  g[0] = 0;\n  for (auto [j, v] : f)\n    if (0 < j && j < n) g[j - 1]\
    \ = v * j;\n  for (int i = 1; i < n; i++) {\n    for (auto [j, v] : f)\n     \
    \ if (0 < j && j <= i) g[i] -= v * g[i - j];\n  }\n  for (int i = n - 1; i > 0;\
    \ i--) g[i] = g[i - 1] * Factorial<mint>::inv(i);\n  g[0] = 0;\n  return g;\n\
    }\ntemplate <class mint>\nFormalPowerSeries<mint> pow(map<int, mint> f, long long\
    \ m, int n) {\n  if (n == 0) return {};\n  FormalPowerSeries<mint> g(n, 0);\n\
    \  if (m == 0) {\n    g[0] = 1;\n    return g;\n  }\n  if (!f.contains(0) || f[0]\
    \ == 0) {\n    if (m >= n) return g;\n    int s = n;\n    for (auto [i, v] : f)\n\
    \      if (v != 0 && i < s) s = i;\n    if (s * m >= n) return g;\n    map<int,\
    \ mint> f1;\n    for (auto [i, v] : f) f1[i - s] = v;\n    auto g1 = pow(f1, m,\
    \ int(n - s * m));\n    copy(g1.begin(), g1.end(), g.begin() + int(s * m));\n\
    \    return g;\n  }\n  g[0] = f[0].pow(m);\n  mint c = f[0].inv();\n  for (int\
    \ i = 1; i < n; i++) {\n    for (auto [j, v] : f) {\n      if (0 < j && j <= i)\
    \ g[i] += j * f[j] * g[i - j] * m;\n      if (0 < j && j < i) g[i] -= f[j] * (i\
    \ - j) * g[i - j];\n    }\n    g[i] *= c * Factorial<mint>::inv(i);\n  }\n  return\
    \ g;\n}\ntemplate <class mint>\nFormalPowerSeries<mint> sqrt(map<int, mint> f,\
    \ int n) {\n  if (n == 0) return {};\n  if (f.empty()) return FormalPowerSeries<mint>(n,\
    \ 0);\n  FormalPowerSeries<mint> g(n, 0);\n  if (f[0] == 0) {\n    int s = n *\
    \ 2;\n    for (auto [i, v] : f)\n      if (v != 0 && i < s) s = i;\n    if (s\
    \ & 1) return {};\n    s /= 2;\n    if (s >= n) return g;\n    map<int, mint>\
    \ f1;\n    for (auto [i, v] : f) f1[i - s * 2] = v;\n    auto g1 = sqrt(f1, int(n\
    \ - s));\n    if (g1.empty()) return {};\n    copy(g1.begin(), g1.end(), g.begin()\
    \ + s);\n    return g;\n  }\n  long long sq = ModSqrt(f[0].val(), mint::get_mod());\n\
    \  if (sq < 0) return {};\n  g[0] = sq;\n  mint c = f[0].inv(), inv2 = mint(2).inv();\n\
    \  for (int i = 1; i < n; i++) {\n    for (auto [j, v] : f) {\n      if (0 < j\
    \ && j <= i) g[i] += j * f[j] * g[i - j] * inv2;\n      if (0 < j && j < i) g[i]\
    \ -= f[j] * (i - j) * g[i - j];\n    }\n    g[i] *= c * Factorial<mint>::inv(i);\n\
    \  }\n  return g;\n}\n};  // namespace FPSSparse\n\n/**\n * @brief Sparse \u306A\
    \ FPS \u6F14\u7B97\n * @docs docs/fps/sparse.md\n */"
  dependsOn:
  - modint/factorial.hpp
  - modint/mod-sqrt.hpp
  - math/util.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/sparse.hpp
  requiredBy: []
  timestamp: '2025-11-01 12:35:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/LC_inv_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_sqrt_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_exp_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_pow_of_formal_power_series_sparse.test.cpp
  - verify/fps/LC_log_of_formal_power_series_sparse.test.cpp
documentation_of: fps/sparse.hpp
layout: document
redirect_from:
- /library/fps/sparse.hpp
- /library/fps/sparse.hpp.html
title: "Sparse \u306A FPS \u6F14\u7B97"
---
sparse な FPS についての各種 FPS 演算．
与えられた FPS で非ゼロの項が $K$ 項で，$N$ 次まで求めるとき $O(NK)$ 時間．

以下の等式から係数についての sparse な漸化式が得られる．

- inv : $fg=1$
- exp : $g'=f'g$
- log : $fg'=f'$
- pow : $fg'=Mf'g$
- sqrt : $f=g^2$