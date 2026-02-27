#pragma once

template <class T>
struct Matrix {
  int h, w;
  vector<T> a;
  Matrix() {}
  Matrix(int n) : h(n), w(n), a(n * n, T{}) {}
  Matrix(int h_, int w_) : h(h_), w(w_), a(h * w, T{}) {}
  inline T get(int i, int j) const { return a[w * i + j]; }
  inline void set(int i, int j, T v) { a[w * i + j] = v; }
  inline void add(int i, int j, T v) { a[w * i + j] += v; }
  inline void sub(int i, int j, T v) { a[w * i + j] -= v; }
  static Matrix id(int n) {
    Matrix mat(n);
    for (int i = 0; i < n; i++) mat.a[n * i + i] = T(1);
    return mat;
  }
  Matrix operator+=(const Matrix& r) {
    assert(h == r.h && w == r.w);
    for (int i = 0; i < h * w; i++) a[i] += r.a[i];
    return *this;
  }
  Matrix operator-=(const Matrix& r) {
    assert(h == r.h && w == r.w);
    for (int i = 0; i < h * w; i++) a[i] -= r.a[i];
    return *this;
  }
  Matrix operator+(const Matrix& r) { return Matrix(*this) += r; }
  Matrix operator-(const Matrix& r) { return Matrix(*this) -= r; }
  Matrix operator*(const Matrix& r) {
    assert(w == r.h);
    cerr.flush();
    Matrix ret(h, r.w);
    for (int i = 0; i < h; i++)
      for (int j = 0; j < r.w; j++)
        for (int k = 0; k < w; k++)
          ret.add(i, j, get(i, k) * r.get(k, j));
    return ret;
  }
  Matrix pow(long long n) const {
    Matrix ret = id(h);
    Matrix mat(*this);
    while (n > 0) {
      if (n & 1) ret = ret * mat;
      mat = mat * mat;
      n >>= 1;
    }
    return ret;
  }

  T det() const {
    assert(h == w);
    Matrix mat(*this);
    T zero{}, det(1);
    for (int k = 0; k < h; k++) {
      {
        int i = k;
        while (i < h && mat.get(i, k) == zero) i++;
        if (i == h) return zero;
        if (i != k) {
          mat.swap_row(i, k);
          det = -det;
        }
      }
      for (int i = k + 1; i < h; i++)
        mat.mul_add_row(i, k, -mat.get(i, k) / mat.get(k, k));
      det *= mat.a[h * k + k];
    }
    return det;
  }
  Matrix inv() const {
    assert(h == w);
    Matrix mat(*this);
    Matrix imat = id(h);
    T zero{}, det(1);
    for (int k = 0; k < h; k++) {
      {
        int i = k;
        while (i < h && mat.get(i, k) == zero) i++;
        assert(i < h);
        if (i != k) {
          mat.swap_row(i, k);
          imat.swap_row(i, k);
        }
      }
      {
        T v = T(1) / mat.get(k, k);
        mat.mul_row(k, v);
        imat.mul_row(k, v);
      }
      for (int i = 0; i < h; i++) {
        if (i == k) continue;
        T v = -mat.get(i, k);
        mat.mul_add_row(i, k, v);
        imat.mul_add_row(i, k, v);
      }
    }
    return imat;
  }
  void swap_row(int i, int j) {
    for (int k = 0; k < w; k++) swap(a[w * i + k], a[w * j + k]);
  }
  void mul_row(int i, T v) {
    for (int k = 0; k < w; k++) a[w * i + k] *= v;
  }
  // row i += row j * v
  void mul_add_row(int i, int j, T v) {
    for (int k = 0; k < w; k++) a[w * i + k] += a[w * j + k] * v;
  }
  friend ostream& operator<<(ostream& os, const Matrix& mat) {
    for (int i = 0; i < mat.h; i++) {
      for (int j = 0; j < mat.w; j++) {
        os << mat.get(i, j);
        if (j + 1 < mat.w) os << " ";
      }
      if (i + 1 < mat.h) os << "\n";
    }
    return os;
  }
};