#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include "template/template.hpp"
#include "geometry/line.hpp"

int main() {
  int q;
  in(q);
  while (q--) {
    Line l, m;
    in(l, m);
    out(is_parallel(l, m) ? 2 : is_orthogonal(l, m) ? 1 : 0);
  }
}
