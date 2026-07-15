#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/segment.hpp"

int main() {
  int q;
  in(q);
  cout << fixed << setprecision(10);
  while (q--) {
    Segment s, t;
    in(s, t);
    out(distance_ss(s, t));
  }
}
