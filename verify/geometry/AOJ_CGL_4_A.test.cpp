#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include "template/template.hpp"
#include "geometry/polygon.hpp"

int main() {
  int n;
  in(n);
  Points ps(n);
  in(ps);
  Polygon C = convex_hull<true>(ps);
  int s = min_element(begin(C), end(C), [](const Point& a, const Point& b) {
            return a.y != b.y ? a.y < b.y : a.x < b.x;
          }) - begin(C);
  rotate(begin(C), begin(C) + s, end(C));
  out(C.size());
  for (const Point& p : C) out((long long)round(p.x), (long long)round(p.y));
}
