#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/polygon.hpp"

int main() {
  int n;
  in(n);
  Polygon C(n);
  in(C);
  auto [i, j] = convex_polygon_diameter(C);
  cout << fixed << setprecision(10);
  out(abs(C[i] - C[j]));
}
