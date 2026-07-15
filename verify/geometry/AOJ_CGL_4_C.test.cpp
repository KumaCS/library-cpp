#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/line.hpp"

int main() {
  int n;
  in(n);
  Polygon P(n);
  in(P);
  int q;
  in(q);
  cout << fixed << setprecision(10);
  while (q--) {
    Line l;
    in(l);
    out(area(convex_polygon_cut(P, l)));
  }
}
