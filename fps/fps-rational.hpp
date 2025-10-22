#pragma once
#include "fps/formal-power-series.hpp"

template <class mint>
struct FPSRational {
  using F = FormalPowerSeries<mint>;
  using R = FPSRational;
  F num, den;
  R& operator+=(const R& r) {
    num *= r.den;
    num += den * r.num;
    den *= r.den;
    return *this;
  }
  R& operator-=(const R& r) {
    num *= r.den;
    num -= den * r.num;
    den *= r.den;
    return *this;
  }
  R& operator*=(const R& r) {
    num *= r.num;
    den *= r.den;
    return *this;
  }
  R& operator/=(const R& r) {
    num *= r.den;
    den *= r.num;
    return *this;
  }
  R operator+(const R& r) const { return R(*this) += r; }
  R operator-(const R& r) const { return R(*this) -= r; }
  R operator*(const R& r) const { return R(*this) *= r; }
  R operator/(const R& r) const { return R(*this) /= r; }
  R inv() const { return {den, num}; }
  F approx(int deg) const { return (den * num.inv(deg)).pre(deg); }
};