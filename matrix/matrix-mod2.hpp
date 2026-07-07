#pragma once

#include "data-structure/dynamic-bitset.hpp"

struct MatrixMod2 {
  using BS = DynamicBitset;
  int h, w;
  vector<BS> a;
  MatrixMod2() : h(0), w(0) {}
  MatrixMod2(int n) : h(n), w(n), a(n, BS(n)) {}
  MatrixMod2(int h_, int w_) : h(h_), w(w_), a(h, BS(w)) {}

  bool get(int i, int j) const { return a[i][j]; }
  void set(int i, int j, bool v = true) { a[i].set(j, v); }
  void add(int i, int j, bool v = true) {
    if (v) a[i].flip(j);
  }
  void sub(int i, int j, bool v = true) { add(i, j, v); }
  static MatrixMod2 id(int n) {
    MatrixMod2 mat(n);
    for (int i = 0; i < n; i++) mat.set(i, i);
    return mat;
  }
  MatrixMod2& operator+=(const MatrixMod2& r) {
    assert(h == r.h && w == r.w);
    for (int i = 0; i < h; i++) a[i] ^= r.a[i];
    return *this;
  }
  MatrixMod2& operator-=(const MatrixMod2& r) { return *this += r; }
  MatrixMod2 operator+(const MatrixMod2& r) const { return MatrixMod2(*this) += r; }
  MatrixMod2 operator-(const MatrixMod2& r) const { return MatrixMod2(*this) -= r; }
  MatrixMod2 operator*(const MatrixMod2& r) const {
    if (w <= 256) return multiply_sparse(r);
    return multiply_four_russians(r);
  }
  MatrixMod2 multiply_sparse(const MatrixMod2& r) const {
    assert(w == r.h);
    MatrixMod2 ret(h, r.w);
    for (int i = 0; i < h; i++)
      for (int k = a[i].find_first(); k < w; k = a[i].find_next(k))
        ret.a[i] ^= r.a[k];
    return ret;
  }
  MatrixMod2 multiply_four_russians(const MatrixMod2& r, int block = 0) const {
    assert(w == r.h);
    if (block == 0) block = four_russians_block_size(w);
    assert(block > 0);
    MatrixMod2 ret(h, r.w);
    for (int l = 0; l < w; l += block) {
      int len = min(block, w - l);
      vector<BS> table(1 << len, BS(r.w));
      for (int mask = 1; mask < (1 << len); mask++) {
        int b = __builtin_ctz(mask);
        table[mask] = table[mask ^ (1 << b)];
        table[mask] ^= r.a[l + b];
      }
      for (int i = 0; i < h; i++) {
        int mask = 0;
        for (int j = 0; j < len; j++)
          if (get(i, l + j)) mask |= 1 << j;
        ret.a[i] ^= table[mask];
      }
    }
    return ret;
  }
  static int four_russians_block_size(int n) {
    if (n <= 512) return 4;
    if (n <= 1024) return 5;
    if (n <= 2048) return 6;
    return 7;
  }
  MatrixMod2& operator*=(const MatrixMod2& r) { return *this = *this * r; }

  MatrixMod2 pow(long long n) const {
    assert(h == w);
    MatrixMod2 ret = id(h);
    MatrixMod2 mat(*this);
    while (n > 0) {
      if (n & 1) ret *= mat;
      mat *= mat;
      n >>= 1;
    }
    return ret;
  }
  int rank() const {
    MatrixMod2 mat(*this);
    int r = 0;
    for (int c = 0; c < w && r < h; c++) {
      int p = r;
      while (p < h && !mat.get(p, c)) p++;
      if (p == h) continue;
      mat.swap_row(r, p);
      for (int i = 0; i < h; i++)
        if (i != r && mat.get(i, c)) mat.add_row(i, r);
      r++;
    }
    return r;
  }
  int det() const {
    assert(h == w);
    MatrixMod2 mat(*this);
    for (int c = 0; c < w; c++) {
      int p = c;
      while (p < h && !mat.get(p, c)) p++;
      if (p == h) return 0;
      mat.swap_row(c, p);
      for (int i = c + 1; i < h; i++) {
        if (mat.get(i, c)) mat.add_row(i, c);
      }
    }
    return 1;
  }
  optional<MatrixMod2> inv() const {
    assert(h == w);
    MatrixMod2 mat(*this);
    MatrixMod2 imat = id(h);
    for (int c = 0; c < w; c++) {
      int p = c;
      while (p < h && !mat.get(p, c)) p++;
      if (p == h) return nullopt;
      mat.swap_row(c, p);
      imat.swap_row(c, p);
      for (int i = 0; i < h; i++) {
        if (i == c || !mat.get(i, c)) continue;
        mat.add_row(i, c);
        imat.add_row(i, c);
      }
    }
    return imat;
  }

  void swap_row(int i, int j) {
    if (i == j) return;
    swap(a[i], a[j]);
  }
  void add_row(int i, int j) { a[i] ^= a[j]; }
  void set_row(int i, const string& s) {
    assert((int)s.size() == w);
    a[i].reset();
    for (int j = 0; j < w; j++) {
      assert(s[j] == '0' || s[j] == '1');
      if (s[j] == '1') a[i].set(j);
    }
  }
  string row_string(int i) const {
    string s(w, '0');
    for (int j = 0; j < w; j++)
      if (get(i, j)) s[j] = '1';
    return s;
  }
  friend ostream& operator<<(ostream& os, const MatrixMod2& mat) {
    for (int i = 0; i < mat.h; i++) {
      os << mat.row_string(i);
      if (i + 1 < mat.h) os << "\n";
    }
    return os;
  }
};

/**
 * @brief Matrix Mod 2
 * @docs docs/matrix/matrix-mod2.md
 */
