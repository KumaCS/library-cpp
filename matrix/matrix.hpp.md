---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/matrix.hpp\"\n\ntemplate <class T>\nstruct Matrix\
    \ {\n  int h, w;\n  vector<T> a;\n  Matrix() {}\n  Matrix(int n) : h(n), w(n),\
    \ a(n * n, T{}) {}\n  Matrix(int h_, int w_) : h(h_), w(w_), a(h * w, T{}) {}\n\
    \  inline T get(int i, int j) const { return a[w * i + j]; }\n  inline void set(int\
    \ i, int j, T v) { a[w * i + j] = v; }\n  inline void add(int i, int j, T v) {\
    \ a[w * i + j] += v; }\n  inline void sub(int i, int j, T v) { a[w * i + j] -=\
    \ v; }\n  static Matrix id(int n) {\n    Matrix mat(n);\n    for (int i = 0; i\
    \ < n; i++) mat.a[n * i + i] = T(1);\n    return mat;\n  }\n  Matrix operator+=(const\
    \ Matrix& r) {\n    assert(h == r.h && w == r.w);\n    for (int i = 0; i < h *\
    \ w; i++) a[i] += r.a[i];\n    return *this;\n  }\n  Matrix operator-=(const Matrix&\
    \ r) {\n    assert(h == r.h && w == r.w);\n    for (int i = 0; i < h * w; i++)\
    \ a[i] -= r.a[i];\n    return *this;\n  }\n  Matrix operator+(const Matrix& r)\
    \ { return Matrix(*this) += r; }\n  Matrix operator-(const Matrix& r) { return\
    \ Matrix(*this) -= r; }\n  Matrix operator*(const Matrix& r) {\n    assert(w ==\
    \ r.h);\n    cerr.flush();\n    Matrix ret(h, r.w);\n    for (int i = 0; i < h;\
    \ i++)\n      for (int j = 0; j < r.w; j++)\n        for (int k = 0; k < w; k++)\n\
    \          ret.add(i, j, get(i, k) * r.get(k, j));\n    return ret;\n  }\n  Matrix\
    \ pow(long long n) const {\n    Matrix ret = id(h);\n    Matrix mat(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret = ret * mat;\n      mat = mat * mat;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n\n  T det() const {\n    assert(h\
    \ == w);\n    Matrix mat(*this);\n    T zero{}, det(1);\n    for (int k = 0; k\
    \ < h; k++) {\n      {\n        int i = k;\n        while (i < h && mat.get(i,\
    \ k) == zero) i++;\n        if (i == h) return zero;\n        if (i != k) {\n\
    \          mat.swap_row(i, k);\n          det = -det;\n        }\n      }\n  \
    \    for (int i = k + 1; i < h; i++)\n        mat.mul_add_row(i, k, -mat.get(i,\
    \ k) / mat.get(k, k));\n      det *= mat.a[h * k + k];\n    }\n    return det;\n\
    \  }\n  Matrix inv() const {\n    assert(h == w);\n    Matrix mat(*this);\n  \
    \  Matrix imat = id(h);\n    T zero{}, det(1);\n    for (int k = 0; k < h; k++)\
    \ {\n      {\n        int i = k;\n        while (i < h && mat.get(i, k) == zero)\
    \ i++;\n        assert(i < h);\n        if (i != k) {\n          mat.swap_row(i,\
    \ k);\n          imat.swap_row(i, k);\n        }\n      }\n      {\n        T\
    \ v = T(1) / mat.get(k, k);\n        mat.mul_row(k, v);\n        imat.mul_row(k,\
    \ v);\n      }\n      for (int i = 0; i < h; i++) {\n        if (i == k) continue;\n\
    \        T v = -mat.get(i, k);\n        mat.mul_add_row(i, k, v);\n        imat.mul_add_row(i,\
    \ k, v);\n      }\n    }\n    return imat;\n  }\n  void swap_row(int i, int j)\
    \ {\n    for (int k = 0; k < w; k++) swap(a[w * i + k], a[w * j + k]);\n  }\n\
    \  void mul_row(int i, T v) {\n    for (int k = 0; k < w; k++) a[w * i + k] *=\
    \ v;\n  }\n  // row i += row j * v\n  void mul_add_row(int i, int j, T v) {\n\
    \    for (int k = 0; k < w; k++) a[w * i + k] += a[w * j + k] * v;\n  }\n  friend\
    \ ostream& operator<<(ostream& os, const Matrix& mat) {\n    for (int i = 0; i\
    \ < mat.h; i++) {\n      for (int j = 0; j < mat.w; j++) {\n        os << mat.get(i,\
    \ j);\n        if (j + 1 < mat.w) os << \" \";\n      }\n      if (i + 1 < mat.h)\
    \ os << \"\\n\";\n    }\n    return os;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct Matrix {\n  int h, w;\n  vector<T>\
    \ a;\n  Matrix() {}\n  Matrix(int n) : h(n), w(n), a(n * n, T{}) {}\n  Matrix(int\
    \ h_, int w_) : h(h_), w(w_), a(h * w, T{}) {}\n  inline T get(int i, int j) const\
    \ { return a[w * i + j]; }\n  inline void set(int i, int j, T v) { a[w * i + j]\
    \ = v; }\n  inline void add(int i, int j, T v) { a[w * i + j] += v; }\n  inline\
    \ void sub(int i, int j, T v) { a[w * i + j] -= v; }\n  static Matrix id(int n)\
    \ {\n    Matrix mat(n);\n    for (int i = 0; i < n; i++) mat.a[n * i + i] = T(1);\n\
    \    return mat;\n  }\n  Matrix operator+=(const Matrix& r) {\n    assert(h ==\
    \ r.h && w == r.w);\n    for (int i = 0; i < h * w; i++) a[i] += r.a[i];\n   \
    \ return *this;\n  }\n  Matrix operator-=(const Matrix& r) {\n    assert(h ==\
    \ r.h && w == r.w);\n    for (int i = 0; i < h * w; i++) a[i] -= r.a[i];\n   \
    \ return *this;\n  }\n  Matrix operator+(const Matrix& r) { return Matrix(*this)\
    \ += r; }\n  Matrix operator-(const Matrix& r) { return Matrix(*this) -= r; }\n\
    \  Matrix operator*(const Matrix& r) {\n    assert(w == r.h);\n    cerr.flush();\n\
    \    Matrix ret(h, r.w);\n    for (int i = 0; i < h; i++)\n      for (int j =\
    \ 0; j < r.w; j++)\n        for (int k = 0; k < w; k++)\n          ret.add(i,\
    \ j, get(i, k) * r.get(k, j));\n    return ret;\n  }\n  Matrix pow(long long n)\
    \ const {\n    Matrix ret = id(h);\n    Matrix mat(*this);\n    while (n > 0)\
    \ {\n      if (n & 1) ret = ret * mat;\n      mat = mat * mat;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n\n  T det() const {\n    assert(h == w);\n    Matrix\
    \ mat(*this);\n    T zero{}, det(1);\n    for (int k = 0; k < h; k++) {\n    \
    \  {\n        int i = k;\n        while (i < h && mat.get(i, k) == zero) i++;\n\
    \        if (i == h) return zero;\n        if (i != k) {\n          mat.swap_row(i,\
    \ k);\n          det = -det;\n        }\n      }\n      for (int i = k + 1; i\
    \ < h; i++)\n        mat.mul_add_row(i, k, -mat.get(i, k) / mat.get(k, k));\n\
    \      det *= mat.a[h * k + k];\n    }\n    return det;\n  }\n  Matrix inv() const\
    \ {\n    assert(h == w);\n    Matrix mat(*this);\n    Matrix imat = id(h);\n \
    \   T zero{}, det(1);\n    for (int k = 0; k < h; k++) {\n      {\n        int\
    \ i = k;\n        while (i < h && mat.get(i, k) == zero) i++;\n        assert(i\
    \ < h);\n        if (i != k) {\n          mat.swap_row(i, k);\n          imat.swap_row(i,\
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
    \    return os;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy: []
  timestamp: '2026-02-28 01:08:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: matrix/matrix.hpp
---
