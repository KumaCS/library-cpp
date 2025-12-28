#pragma once

#include "convolution/intmod.hpp"
#include "fps/formal-power-series.hpp"

template <class mint>
void FormalPowerSeries<mint>::set_ntt() { ntt_ptr = nullptr; }
template <class mint>
FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(const FormalPowerSeries<mint>& r) {
  if (this->empty() || r.empty()) {
    this->clear();
    return *this;
  }
  auto ret = ConvolutionIntMod::multiply(*this, r);
  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}
template <class mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::middle_product(const FormalPowerSeries<mint>& r) const {
  auto ret = ConvolutionIntMod::middle_product(*this, r);
  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}
template <class mint>
void FormalPowerSeries<mint>::ntt() { exit(1); }
template <class mint>
void FormalPowerSeries<mint>::intt() { exit(1); }
template <class mint>
void FormalPowerSeries<mint>::ntt_doubling() { exit(1); }
template <typename mint>
int FormalPowerSeries<mint>::ntt_root() { exit(1); }
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