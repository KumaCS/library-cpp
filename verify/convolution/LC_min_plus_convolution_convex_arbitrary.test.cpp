#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include "template/template.hpp"
#include "convolution/min-plus-convex.hpp"

int main() {
  int n, m;
  in(n, m);
  vector<int> a(n), b(m);
  in(a, b);
  auto c = MinPlusConvolutionConvexArbitrary(a, b);
  out(c);
}