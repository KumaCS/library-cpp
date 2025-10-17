#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "convolution/lcm.hpp"

int main() {
  int n;
  in(n);
  vector<mint> a(n + 1), b(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  rep(i, 1, n + 1) cin >> b[i];
  auto c = LcmConvolution(a, b);
  rep(i, 1, n + 1) cout << c[i] << " \n"[i == n];
}