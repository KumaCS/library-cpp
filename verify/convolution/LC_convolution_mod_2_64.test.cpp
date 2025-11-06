#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"

#include "template/template.hpp"
#include "convolution/mod2_64.hpp"

int main() {
  int n, m;
  in(n, m);
  vector<ull> a(n), b(m);
  in(a, b);
  auto c = ConvolutionMod2_64::multiply(a, b);
  out(c);
}