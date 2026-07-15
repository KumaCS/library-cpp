#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/line.hpp"

int main() {
  Line l;
  in(l);
  int q;
  in(q);
  cout << fixed << setprecision(10);
  while (q--) {
    Point p;
    in(p);
    out(reflection(l, p));
  }
}
