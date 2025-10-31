#pragma once
#include "fps/formal-power-series.hpp"

namespace polynomial_gcd {
template <class mint>
using FPS = FormalPowerSeries<mint>;
template <class mint>
using P = pair<FPS<mint>, FPS<mint>>;
template <class mint>
struct Mat {
  using fps = FPS<mint>;
  fps a00, a01, a10, a11;
  Mat() = default;
  Mat(const fps& a00_, const fps& a01_, const fps& a10_, const fps& a11_) : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}
  Mat& operator*=(const Mat& r) {
    fps b00 = a00 * r.a00 + a01 * r.a10;
    fps b01 = a00 * r.a01 + a01 * r.a11;
    fps b10 = a10 * r.a00 + a11 * r.a10;
    fps b11 = a10 * r.a01 + a11 * r.a11;
    swap(a00, b00);
    swap(a01, b01);
    swap(a10, b10);
    swap(a11, b11);
    a00.shrink();
    a01.shrink();
    a10.shrink();
    a11.shrink();
    return *this;
  }
  static Mat I() { return Mat(fps{mint(1)}, fps(), fps(), fps{mint(1)}); }
  Mat operator*(const Mat& r) const { return Mat(*this) *= r; }
};
template <typename mint>
P<mint> operator*(const Mat<mint>& m, const P<mint>& a) {
  using fps = FPS<mint>;
  fps b0 = m.a00 * a.first + m.a01 * a.second;
  fps b1 = m.a10 * a.first + m.a11 * a.second;
  b0.shrink();
  b1.shrink();
  return {b0, b1};
};

template <class mint>
void StepGCD(Mat<mint>& mat, P<mint>& p) {
  auto q = p.first / p.second;
  mat.a00 -= mat.a10 * q, mat.a00.shrink();
  mat.a01 -= mat.a11 * q, mat.a01.shrink();
  swap(mat.a00, mat.a10);
  swap(mat.a01, mat.a11);
  p.first -= p.second * q, p.first.shrink();
  swap(p.first, p.second);
}
template <class mint>
Mat<mint> HalfGCD(P<mint> p) {
  int n = (int)p.first.size() - 1, m = (int)p.second.size() - 1;
  int k = n / 2 + 1;
  if (m < k) return Mat<mint>::I();
  auto mat = HalfGCD(P<mint>{p.first >> k, p.second >> k});
  p = mat * p;
  if (p.second.size() <= k) return mat;
  StepGCD(mat, p);
  if (p.second.size() <= k) return mat;
  int l = 2 * k - ((int)p.first.size() - 1);
  return HalfGCD(P<mint>{p.first >> l, p.second >> l}) * mat;
}
template <class mint>
Mat<mint> ExtGCD(const FPS<mint>& f, const FPS<mint>& g) {
  P<mint> p{f, g};
  p.first.shrink();
  p.second.shrink();
  if (p.first.size() < p.second.size()) {
    auto mat = ExtGCD(p.second, p.first);
    swap(mat.a00, mat.a01);
    swap(mat.a10, mat.a11);
    return mat;
  }
  auto res = Mat<mint>::I();
  if (p.second.empty()) return res;
  while (true) {
    Mat<mint> mat = HalfGCD(p);
    p = mat * p;
    if (p.second.empty()) return mat * res;
    StepGCD(mat, p);
    if (p.second.empty()) return mat * res;
    res = mat * res;
  }
}

template <class mint>
FPS<mint> PolynomialGcd(FPS<mint> f, FPS<mint> g) {
  auto m = ExtGCD(f, g);
  auto h = m.a00 * f + m.a01 * g;
  h.shrink();
  if (!h.empty()) {
    mint c = h.back().inv();
    for (auto& v : h) v *= c;
  }
  return h;
}
// f*h=1 (mod g)
template <class mint>
optional<FPS<mint>> PolynomialInv(FPS<mint> f, FPS<mint> g) {
  auto m = ExtGCD(f, g);
  auto gcd = m.a00 * f + m.a01 * g;
  gcd.shrink();
  if (gcd.size() != 1) return nullopt;
  mint c = gcd[0].inv();
  auto h = m.a00;
  for (auto& v : h) v *= c;
  return h;
}
};  // namespace polynomial_gcd
using polynomial_gcd::PolynomialGcd;
using polynomial_gcd::PolynomialInv;
/**
 * @brief Polynomial Gcd
 * @docs docs/fps/polynomial-gcd.md
 */