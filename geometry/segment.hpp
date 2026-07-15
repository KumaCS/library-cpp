#pragma once

#include "geometry/line.hpp"

struct Segment : Line {
  Segment() = default;
  using Line::Line;
};

using Segments = vector<Segment>;

bool is_intersect_sp(const Segment& s, const Point& p) {
  return ccw(s.a, s.b, p) == 0;
}

bool is_intersect_ss(const Segment& s, const Segment& t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Point cross_point_ss(const Segment& s, const Segment& t) {
  assert(is_intersect_ss(s, t));
  if (is_parallel(s, t)) {
    if (is_intersect_sp(s, t.a)) return t.a;
    if (is_intersect_sp(s, t.b)) return t.b;
    return s.a;
  }
  return cross_point_ll(s, t);
}

Real distance_sp(const Segment& s, const Point& p) {
  if (abs(s.b - s.a) < EPS) return abs(p - s.a);
  if (dot(s.b - s.a, p - s.a) < 0) return abs(p - s.a);
  if (dot(s.a - s.b, p - s.b) < 0) return abs(p - s.b);
  return distance_lp(s, p);
}

Real distance_ss(const Segment& s, const Segment& t) {
  if (is_intersect_ss(s, t)) return 0;
  return min({distance_sp(s, t.a), distance_sp(s, t.b), distance_sp(t, s.a), distance_sp(t, s.b)});
}

/**
 * @brief 線分
 * @docs docs/geometry/segment.md
 */
