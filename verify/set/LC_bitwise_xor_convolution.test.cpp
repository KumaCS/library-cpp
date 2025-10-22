#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/xor-convolution.hpp"

int main() {
  int n;
  in(n);
  vector<mint> a(1 << n), b(1 << n);
  in(a, b);
  auto c = XorConvolution(a, b);
  out(c);
}