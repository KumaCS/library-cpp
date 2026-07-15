#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include "template/template.hpp"
#include "geometry/polygon.hpp"

int main() {
  int n;
  in(n);
  Polygon P(n);
  in(P);
  int q;
  in(q);
  while (q--) {
    Point p;
    in(p);
    out(contains_polygon(P, p));
  }
}
