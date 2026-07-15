#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include "template/template.hpp"
#include "geometry/polygon.hpp"

int main() {
  int n;
  in(n);
  Polygon P(n);
  in(P);
  out(is_convex(P));
}
