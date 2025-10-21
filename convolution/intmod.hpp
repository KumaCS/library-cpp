#pragma once

#include "../modint/modint.hpp"
#include "../fft/ntt.hpp"

namespace ConvolutionIntMod {
using ll = long long;
const ll Mod1 = 754974721;
const ll Mod2 = 167772161;
const ll Mod3 = 469762049;
const ll M1invM2 = 95869806;
const ll M12invM3 = 187290749;
using M1 = ModInt<Mod1>;
using M2 = ModInt<Mod2>;
using M3 = ModInt<Mod3>;
NTT<M1> ntt1;
NTT<M2> ntt2;
NTT<M3> ntt3;

template <class mint>
vector<mint> multiply(const vector<mint>& a, const vector<mint>& b) {
  if (a.empty() || b.empty()) return {};
  int mod = mint::get_mod();
  ll M12mod = Mod1 * Mod2 % mod;
  vector<unsigned int> a0(a.size()), b0(b.size());
  for (int i = 0; i < a.size(); i++) a0[i] = a[i].val();
  for (int i = 0; i < b.size(); i++) b0[i] = b[i].val();

  vector<M1> a1(a0.begin(), a0.end()), b1(b0.begin(), b0.end()), c1 = ntt1.multiply(a1, b1);
  vector<M2> a2(a0.begin(), a0.end()), b2(b0.begin(), b0.end()), c2 = ntt2.multiply(a2, b2);
  vector<M3> a3(a0.begin(), a0.end()), b3(b0.begin(), b0.end()), c3 = ntt3.multiply(a3, b3);
  vector<mint> c(a.size() + b.size() - 1, 0);
  for (int i = 0; i < c.size(); i++) {
    ll v1 = ((ll)c2[i].val() - (ll)c1[i].val()) * M1invM2 % Mod2;
    if (v1 < 0) v1 += Mod2;
    ll v2 = ((ll)c3[i].val() - ((ll)c1[i].val() + Mod1 * v1) % Mod3) * M12invM3 % Mod3;
    if (v2 < 0) v2 += Mod3;
    ll v3 = ((ll)c1[i].val() + Mod1 * v1 + M12mod * v2) % mod;
    if (v3 < 0) v3 += mod;
    c[i] = v3;
  }
  return c;
}
template <class mint>
vector<mint> middle_product(const vector<mint>& a, const vector<mint>& b) {
  if (b.empty() || a.size() > b.size()) return {};
  int mod = mint::get_mod();
  ll M12mod = Mod1 * Mod2 % mod;
  vector<unsigned int> a0(a.size()), b0(b.size());
  for (int i = 0; i < a.size(); i++) a0[i] = a[i].val();
  for (int i = 0; i < b.size(); i++) b0[i] = b[i].val();

  vector<M1> a1(a0.begin(), a0.end()), b1(b0.begin(), b0.end()), c1 = ntt1.middle_product(a1, b1);
  vector<M2> a2(a0.begin(), a0.end()), b2(b0.begin(), b0.end()), c2 = ntt2.middle_product(a2, b2);
  vector<M3> a3(a0.begin(), a0.end()), b3(b0.begin(), b0.end()), c3 = ntt3.middle_product(a3, b3);
  vector<mint> c(c1.size(), 0);
  for (int i = 0; i < c.size(); i++) {
    ll v1 = ((ll)c2[i].val() - (ll)c1[i].val()) * M1invM2 % Mod2;
    if (v1 < 0) v1 += Mod2;
    ll v2 = ((ll)c3[i].val() - ((ll)c1[i].val() + Mod1 * v1) % Mod3) * M12invM3 % Mod3;
    if (v2 < 0) v2 += Mod3;
    ll v3 = ((ll)c1[i].val() + Mod1 * v1 + M12mod * v2) % mod;
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