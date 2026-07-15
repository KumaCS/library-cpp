#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/circle.hpp"

int main() {
  Point p;
  Real r;
  in(p, r);
  Circle c{p, r};
  int q;
  in(q);
  cout << fixed << setprecision(10);
  while (q--) {
    Line l;
    in(l);
    auto [a, b] = cross_point_cl(c, l);
    if (b < a) swap(a, b);
    out(a, b);
  }
}
