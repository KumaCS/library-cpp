#pragma once

#include "geometry-3d/geometry-base.hpp"

struct Line3D {
  Point3D a, b;

  Line3D() = default;
  Line3D(const Point3D& _a, const Point3D& _b) : a(_a), b(_b) {
    assert(abs(b - a) > EPS);
  }

  friend istream& operator>>(istream& is, Line3D& l) { return is >> l.a >> l.b; }
  friend ostream& operator<<(ostream& os, const Line3D& l) {
    return os << l.a << " to " << l.b;
  }
};

using Lines3D = vector<Line3D>;

bool is_intersect_lp(const Line3D& l, const Point3D& p) {
  Point3D d = l.b - l.a;
  assert(abs(d) > EPS);
  return abs(cross(d, p - l.a)) < EPS * abs(d);
}

bool is_parallel(const Line3D& l, const Line3D& m) {
  Point3D u = l.b - l.a, v = m.b - m.a;
  assert(abs(u) > EPS && abs(v) > EPS);
  return abs(cross(u, v)) < EPS * abs(u) * abs(v);
}

bool is_orthogonal(const Line3D& l, const Line3D& m) {
  Point3D u = l.b - l.a, v = m.b - m.a;
  assert(abs(u) > EPS && abs(v) > EPS);
  return abs(dot(u, v)) < EPS * abs(u) * abs(v);
}

Point3D projection(const Line3D& l, const Point3D& p) {
  Point3D d = l.b - l.a;
  assert(norm(d) > EPS * EPS);
  return l.a + d * (dot(p - l.a, d) / norm(d));
}

Point3D reflection(const Line3D& l, const Point3D& p) {
  return projection(l, p) * 2 - p;
}

Real distance_lp(const Line3D& l, const Point3D& p) {
  return abs(p - projection(l, p));
}

pair<Point3D, Point3D> closest_points_ll(const Line3D& l, const Line3D& m) {
  Point3D u = l.b - l.a, v = m.b - m.a, w = l.a - m.a;
  Real a = norm(u), b = dot(u, v), c = norm(v);
  assert(a > EPS * EPS && c > EPS * EPS);
  Real d = dot(u, w), e = dot(v, w);
  Real det = a * c - b * b;
  if (abs(det) < EPS * EPS * a * c) {
    Point3D q = projection(m, l.a);
    return {l.a, q};
  }
  Real s = (b * e - c * d) / det;
  Real t = (a * e - b * d) / det;
  return {l.a + u * s, m.a + v * t};
}

Real distance_ll(const Line3D& l, const Line3D& m) {
  auto [p, q] = closest_points_ll(l, m);
  return abs(p - q);
}

bool is_intersect_ll(const Line3D& l, const Line3D& m) {
  return distance_ll(l, m) < EPS;
}

optional<Point3D> cross_point_ll(const Line3D& l, const Line3D& m) {
  if (is_parallel(l, m)) return nullopt;
  auto [p, q] = closest_points_ll(l, m);
  if (abs(p - q) >= EPS) return nullopt;
  return (p + q) / 2;
}

/**
 * @brief 三次元空間上の直線
 * @docs docs/geometry-3d/line.md
 */
