#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/circle.hpp"

int main() {
  Point p1, p2;
  Real r1, r2;
  in(p1, r1, p2, r2);
  Lines ls = common_tangents(Circle{p1, r1}, Circle{p2, r2});
  Points ps;
  for (const Line& l : ls) ps.push_back(l.a);
  sort(begin(ps), end(ps));
  cout << fixed << setprecision(10);
  for (const Point& p : ps) out(p);
}
