#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include "template/template.hpp"
#include "geometry/circle.hpp"

int main() {
  Point p1, p2;
  Real r1, r2;
  in(p1, r1, p2, r2);
  out(intersect(Circle{p1, r1}, Circle{p2, r2}));
}
