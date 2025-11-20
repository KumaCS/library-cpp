#pragma once

template <class mint>
struct FormalDirichletSeries : vector<mint> {
  using vector<mint>::vector;
  using FDS = FormalDirichletSeries;
  FDS& operator+=(const mint& v) {
    if (1 < this->size()) (*this)[1] += v;
    return *this;
  }
  FDS& operator+=(const FDS& r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 1; i < (int)r.size(); i++) (*this)[i] += r[i];
    return *this;
  }
  FDS& operator-=(const mint& v) {
    if (1 < this->size()) (*this)[1] -= v;
    return *this;
  }
  FDS& operator-=(const FDS& r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 1; i < (int)r.size(); i++) (*this)[i] -= r[i];
    return *this;
  }
  FDS& operator*=(const mint& v) {
    for (int i = 1; i < (int)this->size(); i++) (*this)[i] *= v;
    return *this;
  }
  FDS& operator*=(const FDS& r) {
    FDS p(this->size(), 0);
    for (int i = 1; i < (int)r.size(); i++)
      for (int j = 1; i * j < (int)p.size(); j++)
        p[i * j] += r[i] * (*this)[j];
    return *this = p;
  }
  FDS& operator/=(const FDS& r) {
    mint c = r[1].inv();
    for (int i = 1; i < (int)this->size(); i++) {
      (*this)[i] *= c;
      for (int j = 2; j < (int)r.size() && i * j < (int)this->size(); j++)
        (*this)[i * j] -= (*this)[i] * r[j];
    }
    return *this;
  }
  FDS operator+(const mint& v) const { return FDS(*this) += v; }
  FDS operator+(const FDS& r) const { return FDS(*this) += r; }
  FDS operator-(const mint& v) const { return FDS(*this) -= v; }
  FDS operator-(const FDS& r) const { return FDS(*this) -= r; }
  FDS operator*(const mint& v) const { return FDS(*this) *= v; }
  FDS operator*(const FDS& r) const { return FDS(*this) *= r; }
  FDS operator/(const FDS& r) const { return FDS(*this) /= r; }
  FDS operator-() const {
    FDS ret(this->size());
    for (int i = 1; i < (int)this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  static vector<mint> inv;
  static void init_inv() {
    if (inv.empty()) {
      inv.assign(33, 0);
      inv[1] = mint(1);
      auto mod = mint::get_mod();
      for (int i = 2; i < (int)inv.size(); i++) inv[i] = (-inv[mod % i]) * (mod / i);
    }
  }
  FDS integral() const {
    int n = this->size();
    if (n <= 1) return FDS(n);
    calc_lpf(n);
    FDS ret(n);
    init_inv();
    for (int i = 2; i < ret.size(); i++) ret[i] = (*this)[i] * inv[npf[i]];
    return ret;
  }
  FDS diff() const {
    calc_lpf(this->size());
    FDS ret(this->size());
    for (int i = 1; i < (int)this->size(); i++) ret[i] = (*this)[i] * npf[i];
    return ret;
  }
  FDS log(int n = -1) const {
    if (n == -1) n = (int)this->size();
    if (n <= 1) return FDS(n);
    assert((*this)[1] == mint(1));
    FDS f = *this;
    f.resize(n);
    return (f.diff() / f).integral();
  }
  FDS exp(int n = -1) const {
    if (n == -1) n = (int)this->size();
    if (n <= 1) return FDS(n);
    assert((*this)[1] == mint(0));
    auto df = this->diff();
    FDS ret(n);
    if (1 < n) ret[1] = 1;
    init_inv();
    for (int i = 1; i < n; i++) {
      if (i > 1) ret[i] *= inv[npf[i]];
      for (int j = 2; j < df.size() && i * j < n; j++) ret[i * j] += df[j] * ret[i];
    }
    return ret;
  }

  static vector<int> npf;
  static vector<int> lpf;
  static void calc_lpf(int n) {
    if (lpf.empty()) {
      lpf = {0, 1, 2, 3, 2, 5, 2, 7};
      npf = {0, 0, 1, 1, 2, 1, 2, 1};
    }
    int l = lpf.size(), r = l;
    while (r <= n) r <<= 1;
    if (l == r) return;
    lpf.resize(r);
    npf.resize(r);
    for (int i = 2; i < l; i++) {
      if (lpf[i] != i) continue;
      for (int j = i * 2; j < r; j += i)
        if (lpf[j] == 0) lpf[j] = i;
    }
    for (int i = l; i < r; i++) {
      if (lpf[i] != 0) continue;
      lpf[i] = i;
      for (int j = i * 2; j < r; j += i)
        if (lpf[j] == 0) lpf[j] = i;
    }
    for (int i = l; i < r; i++)
      npf[i] = npf[i / lpf[i]] + 1;
  }
};
template <typename mint>
vector<mint> FormalDirichletSeries<mint>::inv = {};
template <typename mint>
vector<int> FormalDirichletSeries<mint>::npf = {};
template <typename mint>
vector<int> FormalDirichletSeries<mint>::lpf = {};
/**
 * @brief 形式的 Dirichlet 級数
 * @docs docs/number-theory/formal-dirichlet-series.md
 */
