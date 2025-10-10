#pragma once

#include "../modint/modint.hpp"
#include "../fft/ntt.hpp"

namespace ConvolutionIntMod {
const int Mod1 = 754974721;
const int Mod2 = 167772161;
const int Mod3 = 469762049;
const long long M1invM2 = 95869806;
const long long M12invM3 = 187290749;
using M1 = ModInt<Mod1>;
using M2 = ModInt<Mod2>;
using M3 = ModInt<Mod2>;
NTT<M1> ntt1;
NTT<M2> ntt2;
NTT<M3> ntt3;

template <class mint>
vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
  if (a.empty() || b.empty()) return {};
  int mod = mint::get_mod();
  long long M12mod = (long long)Mod1 * Mod2 % mod;
  vector<long long> u(a.size()), v(b.size());
  for (int i = 0; i < a.size(); i++) u[i] = a[i].val();
  for (int i = 0; i < b.size(); i++) v[i] = b[i].val();

  vector<M1> a1(a.begin(), a.end()), b1(b.begin(), b.end()),
      c1 = N1.mult(a1, b1);
  vector<M2> a2(a.begin(), a.end()), b2(b.begin(), b.end()),
      c2 = N2.mult(a2, b2);
  vector<M3> a3(a.begin(), a.end()), b3(b.begin(), b.end()),
      c3 = N3.mult(a3, b3);

  vector<mint> c(a.size() + b.size() - 1, 0);
  for (int i = 0; i < c.size(); i++) {
    auto v1 = (c2[i] - c1[i]) * M1invM2 % Mod2;
    if (v1 < 0) v1 += Mod2;
    auto v2 = (c3[i] - (c1[i] + Mod1 * v1) % Mod3) * M12invM3 % Mod3;
    if (v2 < 0) v2 += Mod3;
    auto v3 = (c1[i] + Mod1 * v1 + M12mod * v2) % mod;
    if (v3 < 0) v3 += mod;
    c[i] = v3;
  }
  return c;
}
};  // namespace ConvolutionIntMod

/**
 * @brief 任意 mod 畳み込み
 * @docs docs/convolution/intmod.md
 */