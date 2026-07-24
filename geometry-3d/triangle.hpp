#pragma once

#include "geometry-3d/plane.hpp"
#include "geometry-3d/segment.hpp"

struct Triangle3D {
  Point3D a, b, c;

  Triangle3D() = default;
  Triangle3D(const Point3D& _a, const Point3D& _b, const Point3D& _c)
      : a(_a), b(_b), c(_c) {
    assert(abs(cross(b - a, c - a)) > EPS);
  }
};

Point3D triangle_normal(const Triangle3D& t) {
  return cross(t.b - t.a, t.c - t.a);
}

Real area(const Triangle3D& t) { return abs(triangle_normal(t)) / 2; }

Real signed_volume(const Point3D& a, const Point3D& b, const Point3D& c,
                   const Point3D& d) {
  return triple(b - a, c - a, d - a) / 6;
}

Real volume(const Point3D& a, const Point3D& b, const Point3D& c,
            const Point3D& d) {
  return abs(signed_volume(a, b, c, d));
}

optional<array<Real, 3>> barycentric_coordinates(const Triangle3D& t,
                                                  const Point3D& p) {
  Point3D u = t.b - t.a, v = t.c - t.a, w = p - t.a;
  Real uu = norm(u), uv = dot(u, v), vv = norm(v);
  Real wu = dot(w, u), wv = dot(w, v);
  Real d = uu * vv - uv * uv;
  if (abs(d) < EPS * EPS) return nullopt;
  Real y = (vv * wu - uv * wv) / d;
  Real z = (uu * wv - uv * wu) / d;
  return array<Real, 3>{1 - y - z, y, z};
}

bool is_intersect_tp(const Triangle3D& t, const Point3D& p) {
  Plane3D pl{t.a, t.b, t.c};
  if (distance_pp(pl, p) >= EPS) return false;
  auto b = barycentric_coordinates(t, p);
  if (!b) return false;
  return (*b)[0] >= -EPS && (*b)[1] >= -EPS && (*b)[2] >= -EPS;
}

Point3D closest_point_tp(const Triangle3D& t, const Point3D& p) {
  Plane3D pl{t.a, t.b, t.c};
  assert(norm(pl.n) > EPS * EPS);
  Point3D q = projection(pl, p);
  if (is_intersect_tp(t, q)) return q;
  array<Point3D, 3> ps = {closest_point_sp(Segment3D{t.a, t.b}, p),
                         closest_point_sp(Segment3D{t.b, t.c}, p),
                         closest_point_sp(Segment3D{t.c, t.a}, p)};
  return *min_element(begin(ps), end(ps), [&](const Point3D& x, const Point3D& y) {
    return norm(x - p) < norm(y - p);
  });
}

Real distance_tp(const Triangle3D& t, const Point3D& p) {
  return abs(p - closest_point_tp(t, p));
}

/**
 * @brief 三次元空間上の三角形
 * @docs docs/geometry-3d/triangle.md
 */
