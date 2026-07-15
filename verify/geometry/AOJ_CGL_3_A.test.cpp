#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#define ERROR 1e-8

#include "template/template.hpp"
#include "geometry/polygon.hpp"

int main() {
  int n;
  in(n);
  Polygon P(n);
  in(P);
  cout << fixed << setprecision(1);
  out(area(P));
}
