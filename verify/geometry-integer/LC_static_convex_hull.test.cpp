#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include "template/template.hpp"
#include "geometry-integer/polygon.hpp"

int main() {
  int t;
  in(t);
  while (t--) {
    int n;
    in(n);
    Points ps(n);
    in(ps);
    Polygon C = convex_hull(ps);
    out(C.size());
    for (const Point& p : C) out(p);
  }
}
