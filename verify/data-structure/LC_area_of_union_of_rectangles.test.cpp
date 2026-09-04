#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "template/template.hpp"
#include "data-structure/rectangle-union-area.hpp"

int main() {
  int n;
  in(n);
  RectangleUnionArea<> area;
  rep(i, 0, n) {
    long long l, d, r, u;
    in(l, d, r, u);
    area.add_rectangle(l, r, d, u);
  }
  out(area.calc());
}
