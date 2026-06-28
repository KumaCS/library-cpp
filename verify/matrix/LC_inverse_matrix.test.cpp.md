---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/util.hpp
    title: math/util.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/matrix.hpp
    title: matrix/matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"verify/matrix/LC_inverse_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#line 2 \"template/template.hpp\"\
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
    \ (x * x > n) x--;\n  return x;\n}\nlong long floor_root(long long n, int k) {\n\
    \  assert(n >= 0);\n  if (n == 0) return 0;\n  assert(k >= 1);\n  if (k == 1)\
    \ return n;\n  if (k > 64) return 1;\n  long long x = round(pow((long double)n,\
    \ 1.0L / k));\n  auto check = [&](long long a) {\n    if (a <= 0) return true;\n\
    \    __int128_t p = 1;\n    for (int i = 0; i < k; ++i)\n      if ((p *= a) >\
    \ n) return false;\n    return true;\n  };\n  while (check(x + 1)) x++;\n  while\
    \ (!check(x)) x--;\n  return x;\n}\n// return g=gcd(a,b)\n// a*x+b*y=g\n// - b!=0\
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
    };\nusing ModInt998244353 = ModInt<998244353>;\nusing ModInt1000000007 = ModInt<1000000007>;\n\
    #line 5 \"verify/matrix/LC_inverse_matrix.test.cpp\"\nusing mint = ModInt<998244353>;\n\
    #line 2 \"matrix/matrix.hpp\"\n\ntemplate <class T>\nstruct Matrix {\n  int h,\
    \ w;\n  vector<T> a;\n  Matrix() {}\n  Matrix(int n) : h(n), w(n), a(n * n, T{})\
    \ {}\n  Matrix(int h_, int w_) : h(h_), w(w_), a(h * w, T{}) {}\n  inline T get(int\
    \ i, int j) const { return a[w * i + j]; }\n  inline void set(int i, int j, T\
    \ v) { a[w * i + j] = v; }\n  inline void add(int i, int j, T v) { a[w * i + j]\
    \ += v; }\n  inline void sub(int i, int j, T v) { a[w * i + j] -= v; }\n  static\
    \ Matrix id(int n) {\n    Matrix mat(n);\n    for (int i = 0; i < n; i++) mat.a[n\
    \ * i + i] = T(1);\n    return mat;\n  }\n  Matrix operator+=(const Matrix& r)\
    \ {\n    assert(h == r.h && w == r.w);\n    for (int i = 0; i < h * w; i++) a[i]\
    \ += r.a[i];\n    return *this;\n  }\n  Matrix operator-=(const Matrix& r) {\n\
    \    assert(h == r.h && w == r.w);\n    for (int i = 0; i < h * w; i++) a[i] -=\
    \ r.a[i];\n    return *this;\n  }\n  Matrix operator+(const Matrix& r) { return\
    \ Matrix(*this) += r; }\n  Matrix operator-(const Matrix& r) { return Matrix(*this)\
    \ -= r; }\n  Matrix operator*(const Matrix& r) {\n    assert(w == r.h);\n    Matrix\
    \ ret(h, r.w);\n    for (int i = 0; i < h; i++)\n      for (int j = 0; j < r.w;\
    \ j++)\n        for (int k = 0; k < w; k++)\n          ret.add(i, j, get(i, k)\
    \ * r.get(k, j));\n    return ret;\n  }\n  Matrix& operator*=(const Matrix& r)\
    \ { return *this = *this * r; }\n  Matrix pow(long long n) const {\n    Matrix\
    \ ret = id(h);\n    Matrix mat(*this);\n    while (n > 0) {\n      if (n & 1)\
    \ ret = ret * mat;\n      mat = mat * mat;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  T det() const {\n    assert(h == w);\n    Matrix mat(*this);\n\
    \    T zero{}, det(1);\n    for (int k = 0; k < h; k++) {\n      {\n        int\
    \ i = k;\n        while (i < h && mat.get(i, k) == zero) i++;\n        if (i ==\
    \ h) return zero;\n        if (i != k) {\n          mat.swap_row(i, k);\n    \
    \      det = -det;\n        }\n      }\n      for (int i = k + 1; i < h; i++)\n\
    \        mat.mul_add_row(i, k, -mat.get(i, k) / mat.get(k, k));\n      det *=\
    \ mat.a[h * k + k];\n    }\n    return det;\n  }\n  Matrix inv() const {\n   \
    \ assert(h == w);\n    Matrix mat(*this);\n    Matrix imat = id(h);\n    T zero{},\
    \ det(1);\n    for (int k = 0; k < h; k++) {\n      {\n        int i = k;\n  \
    \      while (i < h && mat.get(i, k) == zero) i++;\n        assert(i < h);\n \
    \       if (i != k) {\n          mat.swap_row(i, k);\n          imat.swap_row(i,\
    \ k);\n        }\n      }\n      {\n        T v = T(1) / mat.get(k, k);\n    \
    \    mat.mul_row(k, v);\n        imat.mul_row(k, v);\n      }\n      for (int\
    \ i = 0; i < h; i++) {\n        if (i == k) continue;\n        T v = -mat.get(i,\
    \ k);\n        mat.mul_add_row(i, k, v);\n        imat.mul_add_row(i, k, v);\n\
    \      }\n    }\n    return imat;\n  }\n  void swap_row(int i, int j) {\n    for\
    \ (int k = 0; k < w; k++) swap(a[w * i + k], a[w * j + k]);\n  }\n  void mul_row(int\
    \ i, T v) {\n    for (int k = 0; k < w; k++) a[w * i + k] *= v;\n  }\n  // row\
    \ i += row j * v\n  void mul_add_row(int i, int j, T v) {\n    for (int k = 0;\
    \ k < w; k++) a[w * i + k] += a[w * j + k] * v;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const Matrix& mat) {\n    for (int i = 0; i < mat.h; i++) {\n      for (int\
    \ j = 0; j < mat.w; j++) {\n        os << mat.get(i, j);\n        if (j + 1 <\
    \ mat.w) os << \" \";\n      }\n      if (i + 1 < mat.h) os << \"\\n\";\n    }\n\
    \    return os;\n  }\n};\n#line 7 \"verify/matrix/LC_inverse_matrix.test.cpp\"\
    \n\nint main() {\n  int n;\n  in(n);\n  Matrix<mint> a(n);\n  rep(i, 0, n) rep(j,\
    \ 0, n) {\n    mint x;\n    in(x);\n    a.set(i, j, x);\n  }\n  if (a.det() ==\
    \ mint(0)) {\n    out(-1);\n  } else {\n    out(a.inv());\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"modint/modint.hpp\"\nusing mint = ModInt<998244353>;\n\
    #include \"matrix/matrix.hpp\"\n\nint main() {\n  int n;\n  in(n);\n  Matrix<mint>\
    \ a(n);\n  rep(i, 0, n) rep(j, 0, n) {\n    mint x;\n    in(x);\n    a.set(i,\
    \ j, x);\n  }\n  if (a.det() == mint(0)) {\n    out(-1);\n  } else {\n    out(a.inv());\n\
    \  }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/util.hpp
  - template/inout.hpp
  - template/debug.hpp
  - modint/modint.hpp
  - math/util.hpp
  - matrix/matrix.hpp
  isVerificationFile: true
  path: verify/matrix/LC_inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2026-06-28 16:21:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/matrix/LC_inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/matrix/LC_inverse_matrix.test.cpp
- /verify/verify/matrix/LC_inverse_matrix.test.cpp.html
title: verify/matrix/LC_inverse_matrix.test.cpp
---
