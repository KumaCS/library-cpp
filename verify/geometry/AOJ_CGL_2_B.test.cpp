#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include "template/template.hpp"
#include "geometry/segment.hpp"

int main() {
  int q;
  in(q);
  while (q--) {
    Segment s, t;
    in(s, t);
    out(is_intersect_ss(s, t));
  }
}
