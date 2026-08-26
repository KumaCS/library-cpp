#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"

#include "template/template.hpp"
#include "data-structure/static-rectangle-add-rectangle-sum.hpp"
#include "modint/modint.hpp"

int main() {
  int n, q;
  in(n, q);
  StaticRectangleAddRectangleSum<ModInt998244353> rectangle_sum;
  rep(i, 0, n) {
    int l, d, r, u;
    ModInt998244353 w;
    in(l, d, r, u, w);
    rectangle_sum.query_add(l, r, d, u, w);
  }
  rep(i, 0, q) {
    int l, d, r, u;
    in(l, d, r, u);
    rectangle_sum.query_sum(l, r, d, u);
  }
  for (auto answer : rectangle_sum.calc()) out(answer);
}
