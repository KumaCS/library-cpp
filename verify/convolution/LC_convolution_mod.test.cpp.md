---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fft/ntt.hpp
    title: "NTT (\u6570\u8AD6\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/convolution/LC_convolution_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \";\n  _show(i + 1, a, c...);\n}\n#line 2 \"math/util.hpp\"\n\nnamespace Math\
    \ {\ntemplate <class T>\nT safe_mod(T a, T b) {\n  assert(b != 0);\n  if (b <\
    \ 0) a = -a, b = -b;\n  a %= b;\n  return a >= 0 ? a : a + b;\n}\ntemplate <class\
    \ T>\nT floor(T a, T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n \
    \ return a >= 0 ? a / b : (a + 1) / b - 1;\n}\ntemplate <class T>\nT ceil(T a,\
    \ T b) {\n  assert(b != 0);\n  if (b < 0) a = -a, b = -b;\n  return a > 0 ? (a\
    \ - 1) / b + 1 : a / b;\n}\nlong long isqrt(long long n) {\n  if (n <= 0) return\
    \ 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n) x++;\n  while\
    \ (x * x > n) x--;\n  return x;\n}\n// return g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0\
    \ -> 0<=x<|b|/g\n// - b=0  -> ax=g\ntemplate <class T>\nT ext_gcd(T a, T b, T&\
    \ x, T& y) {\n  T a0 = a, b0 = b;\n  bool sgn_a = a < 0, sgn_b = b < 0;\n  if\
    \ (sgn_a) a = -a;\n  if (sgn_b) b = -b;\n  if (b == 0) {\n    x = sgn_a ? -1 :\
    \ 1;\n    y = 0;\n    return a;\n  }\n  T x00 = 1, x01 = 0, x10 = 0, x11 = 1;\n\
    \  while (b != 0) {\n    T q = a / b, r = a - b * q;\n    x00 -= q * x01;\n  \
    \  x10 -= q * x11;\n    swap(x00, x01);\n    swap(x10, x11);\n    a = b, b = r;\n\
    \  }\n  x = x00, y = x10;\n  if (sgn_a) x = -x;\n  if (sgn_b) y = -y;\n  if (b0\
    \ != 0) {\n    a0 /= a, b0 /= a;\n    if (b0 < 0) a0 = -a0, b0 = -b0;\n    T q\
    \ = x >= 0 ? x / b0 : (x + 1) / b0 - 1;\n    x -= b0 * q;\n    y += a0 * q;\n\
    \  }\n  return a;\n}\nconstexpr long long inv_mod(long long x, long long m) {\n\
    \  x %= m;\n  if (x < 0) x += m;\n  long long a = m, b = x;\n  long long y0 =\
    \ 0, y1 = 1;\n  while (b > 0) {\n    long long q = a / b;\n    swap(a -= q * b,\
    \ b);\n    swap(y0 -= q * y1, y1);\n  }\n  if (y0 < 0) y0 += m / a;\n  return\
    \ y0;\n}\nlong long pow_mod(long long x, long long n, long long m) {\n  x = (x\
    \ % m + m) % m;\n  long long y = 1;\n  while (n) {\n    if (n & 1) y = y * x %\
    \ m;\n    x = x * x % m;\n    n >>= 1;\n  }\n  return y;\n}\nconstexpr long long\
    \ pow_mod_constexpr(long long x, long long n, int m) {\n  if (m == 1) return 0;\n\
    \  unsigned int _m = (unsigned int)(m);\n  unsigned long long r = 1;\n  unsigned\
    \ long long y = x % m;\n  if (y >= m) y += m;\n  while (n) {\n    if (n & 1) r\
    \ = (r * y) % _m;\n    y = (y * y) % _m;\n    n >>= 1;\n  }\n  return r;\n}\n\
    constexpr bool is_prime_constexpr(int n) {\n  if (n <= 1) return false;\n  if\
    \ (n == 2 || n == 7 || n == 61) return true;\n  if (n % 2 == 0) return false;\n\
    \  long long d = n - 1;\n  while (d % 2 == 0) d /= 2;\n  constexpr long long bases[3]\
    \ = {2, 7, 61};\n  for (long long a : bases) {\n    long long t = d;\n    long\
    \ long y = pow_mod_constexpr(a, t, n);\n    while (t != n - 1 && y != 1 && y !=\
    \ n - 1) {\n      y = y * y % n;\n      t <<= 1;\n    }\n    if (y != n - 1 &&\
    \ t % 2 == 0) {\n      return false;\n    }\n  }\n  return true;\n}\ntemplate\
    \ <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n};  // namespace\
    \ Math\n#line 3 \"modint/modint.hpp\"\n\ntemplate <unsigned int m = 998244353>\n\
    struct ModInt {\n  using mint = ModInt;\n  static constexpr unsigned int get_mod()\
    \ { return m; }\n  static mint raw(int v) {\n    mint x;\n    x._v = v;\n    return\
    \ x;\n  }\n  ModInt() : _v(0) {}\n  ModInt(int64_t v) {\n    long long x = (long\
    \ long)(v % (long long)(umod()));\n    if (x < 0) x += umod();\n    _v = (unsigned\
    \ int)(x);\n  }\n  unsigned int val() const { return _v; }\n  mint& operator++()\
    \ {\n    _v++;\n    if (_v == umod()) _v = 0;\n    return *this;\n  }\n  mint&\
    \ operator--() {\n    if (_v == 0) _v = umod();\n    _v--;\n    return *this;\n\
    \  }\n  mint operator++(int) {\n    mint result = *this;\n    ++*this;\n    return\
    \ result;\n  }\n  mint operator--(int) {\n    mint result = *this;\n    --*this;\n\
    \    return result;\n  }\n  mint& operator+=(const mint& rhs) {\n    _v += rhs._v;\n\
    \    if (_v >= umod()) _v -= umod();\n    return *this;\n  }\n  mint& operator-=(const\
    \ mint& rhs) {\n    _v -= rhs._v;\n    if (_v >= umod()) _v += umod();\n    return\
    \ *this;\n  }\n  mint& operator*=(const mint& rhs) {\n    unsigned long long z\
    \ = _v;\n    z *= rhs._v;\n    _v = (unsigned int)(z % umod());\n    return *this;\n\
    \  }\n  mint& operator/=(const mint& rhs) { return *this *= rhs.inv(); }\n  mint\
    \ operator+() const { return *this; }\n  mint operator-() const { return mint()\
    \ - *this; }\n  mint pow(long long n) const {\n    assert(0 <= n);\n    mint x\
    \ = *this, r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n      x *= x;\n\
    \      n >>= 1;\n    }\n    return r;\n  }\n  mint inv() const {\n    if (is_prime)\
    \ {\n      assert(_v);\n      return pow(umod() - 2);\n    } else {\n      auto\
    \ inv = Math::inv_mod(_v, umod());\n      return raw(inv);\n    }\n  }\n  friend\
    \ mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs;\
    \ }\n  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs)\
    \ -= rhs; }\n  friend mint operator*(const mint& lhs, const mint& rhs) { return\
    \ mint(lhs) *= rhs; }\n  friend mint operator/(const mint& lhs, const mint& rhs)\
    \ { return mint(lhs) /= rhs; }\n  friend bool operator==(const mint& lhs, const\
    \ mint& rhs) { return lhs._v == rhs._v; }\n  friend bool operator!=(const mint&\
    \ lhs, const mint& rhs) { return lhs._v != rhs._v; }\n  friend istream& operator>>(istream&\
    \ is, mint& x) {\n    int64_t v;\n    is >> v;\n    x = mint(v);\n    return is;\n\
    \  }\n  friend ostream& operator<<(ostream& os, const mint& x) { return os <<\
    \ x.val(); }\n\n private:\n  unsigned int _v;\n  static constexpr unsigned int\
    \ umod() { return m; }\n  static constexpr bool is_prime = Math::is_prime<m>;\n\
    };\n#line 5 \"verify/convolution/LC_convolution_mod.test.cpp\"\nusing mint = ModInt<998244353>;\n\
    #line 2 \"fft/ntt.hpp\"\n\ntemplate <class mint>\nstruct NTT {\n  static constexpr\
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
    \ 7 \"verify/convolution/LC_convolution_mod.test.cpp\"\nNTT<mint> ntt;\n\nint\
    \ main() {\n  int n, m;\n  in(n, m);\n  vector<mint> a(n), b(m);\n  in(a, b);\n\
    \  auto c = ntt.multiply(a, b);\n  out(c);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing mint = ModInt<998244353>;\n\
    #include \"fft/ntt.hpp\"\nNTT<mint> ntt;\n\nint main() {\n  int n, m;\n  in(n,\
    \ m);\n  vector<mint> a(n), b(m);\n  in(a, b);\n  auto c = ntt.multiply(a, b);\n\
    \  out(c);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - math/util.hpp
  - fft/ntt.hpp
  isVerificationFile: true
  path: verify/convolution/LC_convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution/LC_convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution/LC_convolution_mod.test.cpp
- /verify/verify/convolution/LC_convolution_mod.test.cpp.html
title: verify/convolution/LC_convolution_mod.test.cpp
---
