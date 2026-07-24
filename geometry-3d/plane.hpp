#pragma once

#include "geometry-3d/line.hpp"

struct Plane3D {
  Point3D p, n;

  Plane3D() = default;
  Plane3D(const Point3D& _p, const Point3D& _n) : p(_p), n(_n) {
    assert(abs(n) > EPS);
  }
  Plane3D(const Point3D& a, const Point3D& b, const Point3D& c)
      : p(a), n(cross(b - a, c - a)) {
    assert(abs(n) > EPS);
  }
};

using Planes3D = vector<Plane3D>;

Real plane_value(const Plane3D& pl, const Point3D& p) {
  return dot(pl.n, p - pl.p);
}

bool is_intersect_pp(const Plane3D& pl, const Point3D& p) {
  return abs(plane_value(pl, p)) < EPS * abs(pl.n);
}

bool is_parallel(const Plane3D& a, const Plane3D& b) {
  return abs(cross(a.n, b.n)) < EPS * abs(a.n) * abs(b.n);
}

bool is_orthogonal(const Plane3D& a, const Plane3D& b) {
  return abs(dot(a.n, b.n)) < EPS * abs(a.n) * abs(b.n);
}

Point3D projection(const Plane3D& pl, const Point3D& p) {
  assert(norm(pl.n) > EPS * EPS);
  return p - pl.n * (plane_value(pl, p) / norm(pl.n));
}

Point3D reflection(const Plane3D& pl, const Point3D& p) {
  return projection(pl, p) * 2 - p;
}

Real signed_distance_pp(const Plane3D& pl, const Point3D& p) {
  return plane_value(pl, p) / abs(pl.n);
}

Real distance_pp(const Plane3D& pl, const Point3D& p) {
  return abs(signed_distance_pp(pl, p));
}

bool is_intersect_lp(const Line3D& l, const Plane3D& pl) {
  Point3D d = l.b - l.a;
  bool parallel = abs(dot(pl.n, d)) < EPS * abs(pl.n) * abs(d);
  return !parallel || is_intersect_pp(pl, l.a);
}

optional<Point3D> cross_point_lp(const Line3D& l, const Plane3D& pl) {
  Point3D v = l.b - l.a;
  Real d = dot(pl.n, v);
  if (abs(d) < EPS * abs(pl.n) * abs(v)) return nullopt;
  Real t = dot(pl.n, pl.p - l.a) / d;
  return l.a + v * t;
}

Real distance_lp(const Line3D& l, const Plane3D& pl) {
  return is_intersect_lp(l, pl) ? 0 : distance_pp(pl, l.a);
}

optional<Line3D> cross_line_pp(const Plane3D& a, const Plane3D& b) {
  Point3D d = cross(a.n, b.n);
  Real d2 = norm(d);
  if (d2 < EPS * EPS * norm(a.n) * norm(b.n)) return nullopt;
  Real da = dot(a.n, a.p), db = dot(b.n, b.p);
  Point3D p = cross(da * b.n - db * a.n, d) / d2;
  return Line3D{p, p + d};
}

Real distance_pp(const Plane3D& a, const Plane3D& b) {
  return is_parallel(a, b) ? distance_pp(a, b.p) : 0;
}

/**
 * @brief 三次元空間上の平面
 * @docs docs/geometry-3d/plane.md
 */
