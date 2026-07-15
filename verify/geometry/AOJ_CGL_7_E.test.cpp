#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/circle.hpp"

int main() {
  Point p1, p2;
  Real r1, r2;
  in(p1, r1, p2, r2);
  auto [a, b] = cross_point_cc(Circle{p1, r1}, Circle{p2, r2});
  if (b < a) swap(a, b);
  cout << fixed << setprecision(10);
  out(a, b);
}
