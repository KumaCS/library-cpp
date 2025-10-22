#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "set/or-convolution.hpp"

int main() {
  int n;
  in(n);
  vector<mint> a(1 << n), b(1 << n);
  in(a, b);
  reverse(ALL(a));
  reverse(ALL(b));
  auto c = OrConvolution(a, b);
  reverse(ALL(c));
  out(c);
}