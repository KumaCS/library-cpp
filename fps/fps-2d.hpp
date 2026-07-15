#pragma once

/**
 * @brief 二変数形式的冪級数
 * @docs docs/fps/fps-2d.md
 */
template <class mint>
struct FormalPowerSeries2D : vector<vector<mint>> {
  using Base = vector<vector<mint>>;
  using FPS2D = FormalPowerSeries2D;
  using Base::Base;

  FormalPowerSeries2D(int n, int m) : Base(n, vector<mint>(m)) {}
  FormalPowerSeries2D(const Base& r) : Base(r) {}
  FormalPowerSeries2D(Base&& r) : Base(std::move(r)) {}

  int height() const { return (int)this->size(); }
  int width() const { return this->empty() ? 0 : (int)(*this)[0].size(); }

  void resize(int n, int m) {
    assert(n >= 0 && m >= 0);
    if (n == 0 || m == 0) {
      this->clear();
      return;
    }
    Base::resize(n);
    for (auto& row : *this) row.resize(m);
  }

  FPS2D& operator=(const Base& r) {
    Base::operator=(r);
    return *this;
  }
  FPS2D& operator=(Base&& r) {
    Base::operator=(std::move(r));
    return *this;
  }
  FPS2D& operator+=(const FPS2D& r) {
    int n = max(height(), r.height()), m = max(width(), r.width());
    resize(n, m);
    for (int i = 0; i < r.height(); i++) {
      assert((int)r[i].size() == r.width());
      for (int j = 0; j < r.width(); j++) (*this)[i][j] += r[i][j];
    }
    return *this;
  }
  FPS2D& operator+=(const mint& r) {
    if (this->empty()) resize(1, 1);
    (*this)[0][0] += r;
    return *this;
  }
  FPS2D& operator-=(const FPS2D& r) {
    int n = max(height(), r.height()), m = max(width(), r.width());
    resize(n, m);
    for (int i = 0; i < r.height(); i++) {
      assert((int)r[i].size() == r.width());
      for (int j = 0; j < r.width(); j++) (*this)[i][j] -= r[i][j];
    }
    return *this;
  }
  FPS2D& operator-=(const mint& r) {
    if (this->empty()) resize(1, 1);
    (*this)[0][0] -= r;
    return *this;
  }
  FPS2D& operator*=(const mint& r) {
    for (auto& row : *this)
      for (auto& x : row) x *= r;
    return *this;
  }
  FPS2D& operator/=(const mint& r) { return *this *= r.inv(); }
  FPS2D& operator/=(const FPS2D& r) {
    int n = height(), m = width();
    assert(n > 0 && m > 0);
    return *this = ((*this) * r.inv(n, m)).pre(n, m);
  }

  FPS2D operator+(const FPS2D& r) const { return FPS2D(*this) += r; }
  FPS2D operator+(const mint& r) const { return FPS2D(*this) += r; }
  FPS2D operator-(const FPS2D& r) const { return FPS2D(*this) -= r; }
  FPS2D operator-(const mint& r) const { return FPS2D(*this) -= r; }
  FPS2D operator*(const FPS2D& r) const { return FPS2D(*this) *= r; }
  FPS2D operator*(const mint& r) const { return FPS2D(*this) *= r; }
  FPS2D operator/(const FPS2D& r) const { return FPS2D(*this) /= r; }
  FPS2D operator/(const mint& r) const { return FPS2D(*this) /= r; }
  FPS2D operator-() const {
    FPS2D ret(*this);
    for (auto& row : ret)
      for (auto& x : row) x = -x;
    return ret;
  }

  friend FPS2D operator+(const mint& l, const FPS2D& r) { return r + l; }
  friend FPS2D operator-(const mint& l, const FPS2D& r) { return -r + l; }
  friend FPS2D operator*(const mint& l, const FPS2D& r) { return r * l; }

  FPS2D shift(int di, int dj) const {
    assert(di >= 0 && dj >= 0);
    if (this->empty()) return {};
    int m = width();
    FPS2D ret(*this);
    for (auto& row : ret) {
      assert((int)row.size() == m);
      row.insert(row.begin(), dj, mint(0));
    }
    ret.insert(ret.begin(), di, vector<mint>(m + dj));
    return ret;
  }

  FPS2D pre(int n, int m) const {
    assert(n >= 0 && m >= 0);
    n = min(n, height()), m = min(m, width());
    if (n == 0 || m == 0) return {};
    FPS2D ret(n, m);
    for (int i = 0; i < n; i++) {
      assert((int)(*this)[i].size() == width());
      copy_n((*this)[i].begin(), m, ret[i].begin());
    }
    return ret;
  }

  FPS2D log(int n = -1, int m = -1) const {
    assert(!this->empty() && width() > 0 && (*this)[0][0] == mint(1));
    if (n == -1) n = height();
    if (m == -1) m = width();
    assert(n >= 0 && m >= 0);
    if (n == 0 || m == 0) return {};
    FPS2D d = this->pre(n, m);
    d.resize(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) d[i][j] *= mint(i + j);
    FPS2D ret = (d * this->inv(n, m)).pre(n, m);
    ret.resize(n, m);
    ret[0][0] = mint(0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (i + j > 0) ret[i][j] /= mint(i + j);
    return ret;
  }

  static void* convolution_ptr;
  static void set_convolution();
  static vector<mint> convolution(const vector<mint>& a, const vector<mint>& b);
  FPS2D& operator*=(const FPS2D& r);
  FPS2D inv(int n = -1, int m = -1) const;
  FPS2D exp(int n = -1, int m = -1) const;
};

template <class mint>
void* FormalPowerSeries2D<mint>::convolution_ptr = nullptr;
