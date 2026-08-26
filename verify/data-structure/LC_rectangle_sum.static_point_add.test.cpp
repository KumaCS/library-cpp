#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "template/template.hpp"
#include "data-structure/static-point-add-rectangle-sum.hpp"

int main() {
  int n, q;
  in(n, q);
  StaticPointAddRectangleSum<long long> rectangle_sum;
  rep(i, 0, n) {
    int x, y;
    long long w;
    in(x, y, w);
    rectangle_sum.query_add(x, y, w);
  }
  rep(i, 0, q) {
    int l, d, r, u;
    in(l, d, r, u);
    rectangle_sum.query_sum(l, r, d, u);
  }
  for (long long answer : rectangle_sum.calc()) out(answer);
}
