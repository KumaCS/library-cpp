#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "geometry/halfplane-intersection.hpp"

Polygon halfplane_cut_naive(const Polygon& P, const Line& l) {
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
  {
    Lines ls{{{0, 0}, {2, 0}},
             {{2, 2}, {0, 2}},
             {{0, 2}, {0, 0}},
             {{2, 0}, {2, 2}},
             {{-1, -1}, {3, -1}}};
    Polygon P = halfplane_intersection(ls);
    assert(P.size() == 4);
    assert(abs(area(P) - 4) < EPS);
  }
  {
    Lines empty{{{1, 1}, {1, 0}}, {{0, 0}, {0, 1}}};
    Lines unbounded{{{0, 0}, {1, 0}}, {{0, 1}, {0, 0}}};
    assert(halfplane_intersection(empty).empty());
    assert(halfplane_intersection(unbounded).empty());
  }
  mt19937 rng(7654321);
  uniform_int_distribution<int> coord(-50, 50);
  for (int tc = 0; tc < 1000; ++tc) {
    vector<Point> ps(30);
    for (auto& p : ps) p = Point{(Real)coord(rng), (Real)coord(rng)};
    Polygon C = convex_hull(ps);
    if (C.size() < 3) continue;
    Lines ls;
    for (int i = 0; i < (int)C.size(); ++i)
      ls.emplace_back(C[i], C[(i + 1) % C.size()]);
    shuffle(ls.begin(), ls.end(), rng);
    Polygon P = halfplane_intersection(ls);
    assert(P.size() == C.size());
    assert(abs(area(P) - area(C)) < 1e-8);
  }
  uniform_int_distribution<int> small(-80, 80);
  for (int tc = 0; tc < 2000; ++tc) {
    Polygon want{{-100, -100}, {100, -100}, {100, 100}, {-100, 100}};
    Lines ls{{{-100, -100}, {100, -100}},
             {{100, -100}, {100, 100}},
             {{100, 100}, {-100, 100}},
             {{-100, 100}, {-100, -100}}};
    for (int i = 0; i < 12; ++i) {
      Point a{(Real)small(rng), (Real)small(rng)};
      Point b{(Real)small(rng), (Real)small(rng)};
      if (a == b) b.x += 1;
      ls.emplace_back(a, b);
      if (!want.empty()) want = halfplane_cut_naive(want, ls.back());
    }
    shuffle(ls.begin(), ls.end(), rng);
    Polygon got = halfplane_intersection(ls);
    Real want_area = want.empty() ? 0 : area(want);
    Real got_area = got.empty() ? 0 : area(got);
    assert(abs(want_area - got_area) < 1e-7);
  }
  int a, b;
  in(a, b);
  out(a + b);
}
