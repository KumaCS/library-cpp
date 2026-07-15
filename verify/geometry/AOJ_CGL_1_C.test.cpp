#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include "template/template.hpp"
#include "geometry/geometry-base.hpp"

int main() {
  Point a, b;
  in(a, b);
  int q;
  in(q);
  const array<string, 5> ans = {"ONLINE_FRONT", "CLOCKWISE", "ON_SEGMENT",
                                "COUNTER_CLOCKWISE", "ONLINE_BACK"};
  while (q--) {
    Point c;
    in(c);
    out(ans[ccw(a, b, c) + 2]);
  }
}
