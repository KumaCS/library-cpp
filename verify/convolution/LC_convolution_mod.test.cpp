#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fft/ntt.hpp"
NTT<mint> ntt;

int main() {
  int n, m;
  in(n, m);
  vector<mint> a(n), b(m);
  in(a, b);
  auto c = ntt.multiply(a, b);
  out(c);
}