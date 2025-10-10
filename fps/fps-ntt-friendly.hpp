#pragma once

#include "../fft/ntt.hpp"
#include "./formal-power-series.hpp"

template <class mint>
void FormalPowerSeries<mint>::set_ntt() {
  if (!ntt_ptr) ntt_ptr = new NTT<mint>;
}
template <class mint>
FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(
    const FormalPowerSeries<mint>& r) {
  if (this->empty() || r.empty()) {
    this->clear();
    return *this;
  }
  set_ntt();
  auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this, r);
  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}
template <class mint>
void FormalPowerSeries<mint>::ntt() {
  set_ntt();
  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);
}
template <class mint>
void FormalPowerSeries<mint>::intt() {
  set_ntt();
  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);
}
template <class mint>
void FormalPowerSeries<mint>::ntt_doubling() {
  set_ntt();
  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);
}
template <typename mint>
int FormalPowerSeries<mint>::ntt_root() {
  set_ntt();
  return static_cast<NTT<mint>*>(ntt_ptr)->g;
}
template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {
  assert((*this)[0] != mint(0));
  if (deg == -1) deg = (*this).size();
  FPS ret{mint(1) / (*this)[0]};
  for (int i = 1; i < deg; i <<= 1)
    ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
  return ret.pre(deg);
}
template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg) const {
  assert((*this)[0] == mint(0));
  if (deg == -1) deg = (*this).size();
  FPS ret{mint(1)};
  for (int i = 1; i < deg; i <<= 1)
    ret = (ret * ((*this).pre(i << 1) - ret.log(i << 1) + 1)).pre(i << 1);
  return ret.pre(deg);
}