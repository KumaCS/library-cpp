#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<1000000007>;
#include "convolution/intmod.hpp"

int main() {
  int n, m;
  in(n, m);
  vector<mint> a(n), b(m);
  in(a, b);
  auto c = ConvolutionIntMod::multiply(a, b);
  out(c);
}