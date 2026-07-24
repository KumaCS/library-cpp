#pragma once

#include "geometry-3d/line.hpp"

struct Segment3D : Line3D {
  Segment3D() = default;
  Segment3D(const Point3D& _a, const Point3D& _b) {
    a = _a;
    b = _b;
  }
};

using Segments3D = vector<Segment3D>;

Point3D closest_point_sp(const Segment3D& s, const Point3D& p) {
  Point3D d = s.b - s.a;
  if (norm(d) <= EPS * EPS) return s.a;
  Real t = clamp(dot(p - s.a, d) / norm(d), (Real)0, (Real)1);
  return s.a + d * t;
}

pair<Point3D, Point3D> closest_points_ss(const Segment3D& s, const Segment3D& t) {
  Point3D d1 = s.b - s.a, d2 = t.b - t.a, r = s.a - t.a;
  Real a = norm(d1), e = norm(d2), x = 0, y = 0;
  if (a <= EPS * EPS && e <= EPS * EPS) return {s.a, t.a};
  if (a <= EPS * EPS) {
    y = clamp(dot(d2, r) / e, (Real)0, (Real)1);
  } else {
    Real c = dot(d1, r);
    if (e <= EPS * EPS) {
      x = clamp(-c / a, (Real)0, (Real)1);
    } else {
      Real b = dot(d1, d2), f = dot(d2, r);
      Real det = a * e - b * b;
      if (abs(det) > EPS * EPS * a * e) {
        x = clamp((b * f - c * e) / det, (Real)0, (Real)1);
      }
      y = (b * x + f) / e;
      if (y < 0) {
        y = 0;
        x = clamp(-c / a, (Real)0, (Real)1);
      } else if (y > 1) {
        y = 1;
        x = clamp((b - c) / a, (Real)0, (Real)1);
      }
    }
  }
  return {s.a + d1 * x, t.a + d2 * y};
}

Real distance_sp(const Segment3D& s, const Point3D& p) {
  return abs(p - closest_point_sp(s, p));
}

Real distance_ss(const Segment3D& s, const Segment3D& t) {
  auto [p, q] = closest_points_ss(s, t);
  return abs(p - q);
}

bool is_intersect_sp(const Segment3D& s, const Point3D& p) {
  return distance_sp(s, p) < EPS;
}

bool is_intersect_ss(const Segment3D& s, const Segment3D& t) {
  return distance_ss(s, t) < EPS;
}

/**
 * @brief 三次元空間上の線分
 * @docs docs/geometry-3d/segment.md
 */
