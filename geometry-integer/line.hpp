#pragma once

#include "geometry-integer/geometry-base.hpp"

struct Line {
  using P = Point;
  P a, b;

  Line() = default;
  Line(const P& _a, const P& _b) : a(_a), b(_b) {}

  friend std::istream& operator>>(std::istream& is, Line& l) {
    return is >> l.a >> l.b;
  }
  friend std::ostream& operator<<(std::ostream& os, const Line& l) {
    return os << l.a << " to " << l.b;
  }
};

using Lines = std::vector<Line>;

bool is_parallel(const Line& l, const Line& m) {
  return cross(l.b - l.a, m.b - m.a) == 0;
}

bool is_orthogonal(const Line& l, const Line& m) {
  return dot(l.b - l.a, m.b - m.a) == 0;
}

bool is_intersect_ll(const Line& l, const Line& m) {
  return !is_parallel(l, m) || cross(l.b - l.a, m.a - l.a) == 0;
}

/**
 * @brief 整数座標上の直線
 * @docs docs/geometry-integer/line.md
 */
