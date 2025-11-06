#pragma once

#include "modint/modint.hpp"
#include "fft/ntt.hpp"
#include "math/util.hpp"

namespace ConvolutionMod2_64 {
using ull = unsigned long long;
static constexpr ull M1 = 645922817;
static constexpr ull M2 = 754974721;
static constexpr ull M3 = 880803841;
static constexpr ull M4 = 897581057;
static constexpr ull M5 = 998244353;
static constexpr ull M12M4 = M1 * M2 % M4;
static constexpr ull M12M5 = M1 * M2 % M5;
static constexpr ull M123M5 = M12M5 * M3 % M5;
static constexpr ull M12 = M1 * M2;
static constexpr ull M123 = M12 * M3;
static constexpr ull M1234 = M123 * M4;
static constexpr ull I2 = Math::inv_mod(M1, M2);
static constexpr ull I3 = Math::inv_mod(M1 * M2 % M3, M3);
static constexpr ull I4 = Math::inv_mod(M1 * M2 % M4 * M3 % M4, M4);
static constexpr ull I5 = Math::inv_mod(M1 * M2 % M5 * M3 % M5 * M4 % M5, M5);

using mint1 = ModInt<M1>;
using mint2 = ModInt<M2>;
using mint3 = ModInt<M3>;
using mint4 = ModInt<M4>;
using mint5 = ModInt<M5>;

NTT<mint1> ntt1;
NTT<mint2> ntt2;
NTT<mint3> ntt3;
NTT<mint4> ntt4;
NTT<mint5> ntt5;

template <class mint>
vector<mint> inner_mult(const vector<ull>& a, const vector<ull>& b, NTT<mint>& ntt) {
  constexpr unsigned int mod = mint::get_mod();
  vector<mint> a1(a.size()), b1(b.size());
  for (int i = 0; i < a.size(); i++) a1[i] = a[i] % mod;
  for (int i = 0; i < b.size(); i++) b1[i] = b[i] % mod;
  mint c = ntt.multiply(a1, b1)[0];
  return ntt.multiply(a1, b1);
}
template <class mint>
vector<mint> inner_middle_prod(const vector<ull>& a, const vector<ull>& b, NTT<mint>& ntt) {
  constexpr unsigned int mod = mint::get_mod();
  vector<mint> a1(a.size()), b1(b.size());
  for (int i = 0; i < a.size(); i++) a1[i] = a[i] % mod;
  for (int i = 0; i < b.size(); i++) b1[i] = b[i] % mod;
  return ntt.middle_product(a1, b1);
}
vector<ull> multiply(const vector<ull>& a, const vector<ull>& b) {
  if (a.empty() || b.empty()) return {};
  auto c1 = inner_mult(a, b, ntt1);
  auto c2 = inner_mult(a, b, ntt2);
  auto c3 = inner_mult(a, b, ntt3);
  auto c4 = inner_mult(a, b, ntt4);
  auto c5 = inner_mult(a, b, ntt5);
  vector<ull> c(a.size() + b.size() - 1, 0);
  for (int i = 0; i < c.size(); i++) {
    ull y1 = c1[i].val();
    ull y2 = (c2[i].val() + M2 - y1) * I2 % M2;
    ull y3 = (c3[i].val() + M3 - (y1 + y2 * M1) % M3) * I3 % M3;
    ull y4 = (c4[i].val() + M4 - (y1 + y2 * M1 + y3 * M12M4) % M4) * I4 % M4;
    ull y5 = (c5[i].val() + M5 - (y1 + y2 * M1 + y3 * M12M5 + y4 * M123M5) % M5) * I5 % M5;
    c[i] = y1 + y2 * M1 + y3 * M12 + y4 * M123 + y5 * M1234;
  }
  return c;
}
vector<ull> middle_product(const vector<ull>& a, const vector<ull>& b) {
  if (b.empty() || a.size() > b.size()) return {};
  auto c1 = inner_middle_prod(a, b, ntt1);
  auto c2 = inner_middle_prod(a, b, ntt2);
  auto c3 = inner_middle_prod(a, b, ntt3);
  auto c4 = inner_middle_prod(a, b, ntt4);
  auto c5 = inner_middle_prod(a, b, ntt5);
  vector<ull> c(c1.size(), 0);
  for (int i = 0; i < c.size(); i++) {
    ull y1 = c1[i].val();
    ull y2 = (c2[i].val() + M2 - y1) * I2 % M2;
    ull y3 = (c3[i].val() + M3 * 2 - (y1 + y2 * M1 % M3)) * I3 % M3;
    ull y4 = (c4[i].val() + M4 * 3 - (y1 + y2 * M1 + y3 * M12M4) % M4) * I4 % M4;
    ull y5 = (c5[i].val() + M5 * 4 - (y1 + y2 * M1 + y3 * M12M5 + y4 * M123M5) % M5) * I5 % M5;
    c[i] = y1 + y2 * M1 + y3 * M12 + y4 * M123 + y5 * M1234;
  }
  return c;
}
};  // namespace ConvolutionMod2_64

/**
 * @brief 畳み込み mod 2^64
 */