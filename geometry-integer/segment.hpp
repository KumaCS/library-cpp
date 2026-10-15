#pragma once

#include "geometry-integer/line.hpp"

struct Segment : Line {
  Segment() = default;
  using Line::Line;
};

using Segments = std::vector<Segment>;

bool is_intersect_sp(const Segment& s, const Point& p) {
  return cross(s.b - s.a, p - s.a) == 0 && dot(p - s.a, p - s.b) <= 0;
}

bool is_intersect_ss(const Segment& s, const Segment& t) {
  int sa = sign(cross(s.b - s.a, t.a - s.a));
  int sb = sign(cross(s.b - s.a, t.b - s.a));
  int ta = sign(cross(t.b - t.a, s.a - t.a));
  int tb = sign(cross(t.b - t.a, s.b - t.a));
  if (sa == 0 && is_intersect_sp(s, t.a)) return true;
  if (sb == 0 && is_intersect_sp(s, t.b)) return true;
  if (ta == 0 && is_intersect_sp(t, s.a)) return true;
  if (tb == 0 && is_intersect_sp(t, s.b)) return true;
  return sa * sb < 0 && ta * tb < 0;
}

/**
 * @brief 整数座標上の線分
 * @docs docs/geometry-integer/segment.md
 */
