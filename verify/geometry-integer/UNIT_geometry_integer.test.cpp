#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "geometry-integer/segment.hpp"
#include "geometry-integer/polygon.hpp"

int main() {
  {
    Point a{4000000000LL, 4000000000LL};
    Point b{-4000000000LL, 4000000000LL};
    assert(cross(a, b) == (WideInteger)32 * 1000000000000000000LL);
  }
  {
    Segment point{{2, 0}, {2, 0}};
    Segment line{{0, 0}, {1, 0}};
    assert(is_intersect_sp(point, {2, 0}));
    assert(!is_intersect_sp(point, {3, 0}));
    assert(!is_intersect_ss(point, line));
    assert(is_intersect_ss(point, Segment{{1, 0}, {3, 0}}));
  }
  {
    Line l{{0, 0}, {2, 0}};
    assert(is_intersect_ll(l, Line{{1, -1}, {1, 1}}));
    assert(is_intersect_ll(l, Line{{1, 0}, {3, 0}}));
    assert(!is_intersect_ll(l, Line{{0, 1}, {2, 1}}));
  }
  Polygon C{{0, 0}, {4, 0}, {4, 3}, {0, 3}};
  assert(area2(C) == 24);
  assert(contains_convex(C, {2, 1}) == 2);
  assert(contains_convex(C, {4, 1}) == 1);
  assert(contains_convex(C, {5, 1}) == 0);
  assert(argmax_dot(C, {1, 0}) == 1);
  assert(argmax_dot(C, {-1, 0}) == 0);
  auto [di, dj] = convex_polygon_diameter(C);
  assert(norm(C[di] - C[dj]) == 25);
  mt19937 rng(1234567);
  uniform_int_distribution<int> coord(-30, 30);
  for (int tc = 0; tc < 2000; ++tc) {
    Points ps(20);
    for (Point& p : ps) p = Point{coord(rng), coord(rng)};
    Polygon P = convex_hull(ps);
    if (P.empty()) continue;
    auto [i, j] = convex_polygon_diameter(P);
    WideInteger want = 0;
    for (const Point& p : P) {
      for (const Point& q : P) want = max(want, norm(p - q));
    }
    assert(norm(P[i] - P[j]) == want);
    if (P.size() >= 3) {
      Point dir{coord(rng), coord(rng)};
      if (dir == Point{}) dir.x = 1;
      int got = argmax_dot(P, dir), expected = 0;
      for (int k = 1; k < (int)P.size(); ++k) {
        if (dot(P[k], dir) > dot(P[expected], dir)) expected = k;
      }
      assert(got == expected);
      Point p{coord(rng), coord(rng)};
      assert(contains_convex(P, p) == contains_polygon(P, p));
    }
  }
  int a, b;
  in(a, b);
  out(a + b);
}
