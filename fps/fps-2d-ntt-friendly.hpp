#pragma once

#include "fft/ntt.hpp"
#include "fps/fps-2d.hpp"

template <class mint>
void FormalPowerSeries2D<mint>::set_convolution() {
  if (!convolution_ptr) convolution_ptr = new NTT<mint>;
}

template <class mint>
vector<mint> FormalPowerSeries2D<mint>::convolution(const vector<mint>& a, const vector<mint>& b) {
  set_convolution();
  return static_cast<NTT<mint>*>(convolution_ptr)->multiply(a, b);
}

template <class mint>
FormalPowerSeries2D<mint>& FormalPowerSeries2D<mint>::operator*=(const FPS2D& r) {
  if (this->empty() || r.empty()) {
    this->clear();
    return *this;
  }
  int n = height(), m = width(), rn = r.height(), rm = r.width();
  for (const auto& row : *this) assert((int)row.size() == m);
  for (const auto& row : r) assert((int)row.size() == rm);
  int on = n + rn - 1, om = m + rm - 1;
  vector<mint> a((n - 1) * om + m), b((rn - 1) * om + rm);
  for (int i = 0; i < n; i++) copy((*this)[i].begin(), (*this)[i].end(), a.begin() + i * om);
  for (int i = 0; i < rn; i++) copy(r[i].begin(), r[i].end(), b.begin() + i * om);
  vector<mint> c = convolution(a, b);
  FPS2D ret(on, om);
  for (int i = 0; i < on; i++) copy_n(c.begin() + i * om, om, ret[i].begin());
  return *this = std::move(ret);
}

template <class mint>
FormalPowerSeries2D<mint> FormalPowerSeries2D<mint>::inv(int n, int m) const {
  assert(!this->empty() && width() > 0 && (*this)[0][0] != mint(0));
  if (n == -1) n = height();
  if (m == -1) m = width();
  assert(n >= 0 && m >= 0);
  if (n == 0 || m == 0) return {};
  FPS2D ret{{mint(1) / (*this)[0][0]}};
  int deg = 1;
  while (deg < n + m - 1) {
    deg <<= 1;
    int nn = min(n, deg), mm = min(m, deg);
    ret.resize(nn, mm);
    FPS2D c = (this->pre(nn, mm) * ret).pre(nn, mm);
    c = -c;
    c[0][0] += mint(2);
    ret = (ret * c).pre(nn, mm);
  }
  ret.resize(n, m);
  return ret;
}

template <class mint>
FormalPowerSeries2D<mint> FormalPowerSeries2D<mint>::exp(int n, int m) const {
  assert(!this->empty() && width() > 0 && (*this)[0][0] == mint(0));
  if (n == -1) n = height();
  if (m == -1) m = width();
  assert(n >= 0 && m >= 0);
  if (n == 0 || m == 0) return {};
  FPS2D ret{{mint(1)}};
  int deg = 1;
  while (deg < n + m - 1) {
    deg <<= 1;
    int nn = min(n, deg), mm = min(m, deg);
    ret.resize(nn, mm);
    FPS2D c = this->pre(nn, mm) - ret.log(nn, mm) + mint(1);
    ret = (ret * c).pre(nn, mm);
  }
  ret.resize(n, m);
  return ret;
}
