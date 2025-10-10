#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"

#include "template/template.hpp"
#include "convolution/min-plus-convex.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  cin >> a >> b;
  auto c = MinPlusConvolutionConvexConvex(a, b);
  cout << c << "\n";
}