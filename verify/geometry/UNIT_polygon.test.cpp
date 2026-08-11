#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "geometry/line.hpp"

Polygon convex_polygon_cut_naive(const Polygon& P, const Line& l) {
  Polygon ret;
  for (int i = 0; i < (int)P.size(); ++i) {
    Point a = P[i], b = P[(i + 1) % P.size()];
    int sa = sign(cross(l.b - l.a, a - l.a));
    int sb = sign(cross(l.b - l.a, b - l.a));
    if (sa >= 0) ret.push_back(a);
    if (sa * sb < 0) ret.push_back(cross_point_ll(Line{a, b}, l));
  }
  return ret;
}

int main() {
  Polygon C{{0, 0}, {2, 0}, {2, 2}, {0, 2}};
  assert(argmax_dot(C, {1, 0}) == 1);
  assert(argmax_dot(C, {0, -1}) == 0);
  assert(argmax_dot(C, {-1, 0}) == 0);
  {
    Line l{{1, 1}, {1, 0}};
    auto cut = convex_polygon_cut_info(C, l);
    assert(cut.first == 1 && cut.last == 3);
    assert(cut.front && cut.back);
    assert(abs(*cut.front - Point{1, 0}) < EPS);
    assert(abs(*cut.back - Point{1, 2}) < EPS);
    assert(abs(area(cut.to_polygon(C)) - 2) < EPS);
  }
  {
    auto full = convex_polygon_cut_info(C, Line{{-1, 1}, {-1, 0}});
    auto empty = convex_polygon_cut_info(C, Line{{3, 1}, {3, 0}});
    auto edge = convex_polygon_cut_info(C, Line{{2, 1}, {2, 0}});
    assert(full.first == 0 && full.last == 4 && !full.empty());
    assert(empty.empty());
    assert(edge.to_polygon(C).size() == 2);
  }
  mt19937 rng(1234567);
  uniform_int_distribution<int> coord(-30, 30);
  for (int tc = 0; tc < 2000; ++tc) {
    vector<Point> ps(20);
    for (auto& p : ps) p = Point{(Real)coord(rng), (Real)coord(rng)};
    Polygon P = convex_hull(ps);
    if (P.size() < 3) continue;
    rotate(P.begin(), P.begin() + rng() % P.size(), P.end());
    Point dir{(Real)coord(rng), (Real)coord(rng)};
    if (dir == Point{}) dir.x = 1;
    int got = argmax_dot(P, dir), want = 0;
    for (int i = 1; i < (int)P.size(); ++i) {
      if (dot(P[i], dir) > dot(P[want], dir)) want = i;
    }
    assert(got == want);
    Point a{(Real)coord(rng), (Real)coord(rng)};
    Point b{(Real)coord(rng), (Real)coord(rng)};
    if (a == b) b.x += 1;
    Line l{a, b};
    Polygon fast = convex_polygon_cut(P, l);
    Polygon naive = convex_polygon_cut_naive(P, l);
    assert(abs(area(fast) - area(naive)) < 1e-8);

  }
  int a, b;
  in(a, b);
  out(a + b);
}
