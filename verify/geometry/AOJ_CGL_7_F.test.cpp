#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/circle.hpp"

int main() {
  Point p, c;
  Real r;
  in(p, c, r);
  auto [a, b] = tangent_points(Circle{c, r}, p);
  if (b < a) swap(a, b);
  cout << fixed << setprecision(10);
  out(a);
  out(b);
}
