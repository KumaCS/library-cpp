#pragma once

#include "geometry/geometry-base.hpp"
#include "geometry/polygon.hpp"

struct Line {
  using P = Point;
  P a, b;

  Line() = default;
  Line(const P& _a, const P& _b) : a(_a), b(_b) {}

  // Ax + By = C
  Line(Real A, Real B, Real C) {
    assert(!equals(A, 0) || !equals(B, 0));
    if (!equals(B, 0)) {
      a = P{0, C / B};
      b = P{1, (C - A) / B};
    } else {
      a = P{C / A, 0};
      b = P{C / A, 1};
    }
  }

  friend istream& operator>>(istream& is, Line& l) { return is >> l.a >> l.b; }
  friend ostream& operator<<(ostream& os, const Line& l) {
    return os << l.a << " to " << l.b;
  }
};

using Lines = vector<Line>;

bool is_parallel(const Line& l, const Line& m) {
  return equals(cross(l.b - l.a, m.b - m.a), 0);
}

bool is_orthogonal(const Line& l, const Line& m) {
  return equals(dot(l.b - l.a, m.b - m.a), 0);
}

bool is_intersect_ll(const Line& l, const Line& m) {
  return !is_parallel(l, m) || equals(cross(l.b - l.a, m.a - l.a), 0);
}

// Parallel distinct lines must not be given.
Point cross_point_ll(const Line& l, const Line& m) {
  Point u = l.b - l.a, v = m.b - m.a;
  Real d = cross(u, v);
  if (equals(d, 0)) {
    assert(equals(cross(u, m.a - l.a), 0));
    return m.a;
  }
  return l.a + u * (cross(m.a - l.a, v) / d);
}

Point projection(const Line& l, const Point& p) {
  Point d = l.b - l.a;
  return l.a + d * (dot(p - l.a, d) / norm(d));
}

Point reflection(const Line& l, const Point& p) {
  return projection(l, p) * 2 - p;
}

Real distance_lp(const Line& l, const Point& p) {
  return abs(p - projection(l, p));
}

// Returns the left side of the directed line l.a -> l.b.
Polygon convex_polygon_cut(const Polygon& P, const Line& l) {
  return convex_polygon_cut(P, l.a, l.b);
}

ConvexPolygonCutResult convex_polygon_cut_info(const Polygon& P,
                                               const Line& l) {
  return convex_polygon_cut_info(P, l.a, l.b);
}

/**
 * @brief 直線
 * @docs docs/geometry/line.md
 */
