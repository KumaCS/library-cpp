#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/circle.hpp"

int main() {
  Point p1, p2;
  Real r1, r2;
  in(p1, r1, p2, r2);
  cout << fixed << setprecision(10);
  out(common_area(Circle{p1, r1}, Circle{p2, r2}));
}
