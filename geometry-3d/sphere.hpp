#pragma once

#include "geometry-3d/plane.hpp"

struct Circle3D {
  Point3D p, n;
  Real r;

  Circle3D() = default;
  Circle3D(const Point3D& _p, const Point3D& _n, Real _r)
      : p(_p), n(_n), r(_r) {
    assert(abs(n) > EPS && r >= 0);
  }
};

struct Sphere3D {
  Point3D p;
  Real r;

  Sphere3D() = default;
  Sphere3D(const Point3D& _p, Real _r) : p(_p), r(_r) { assert(r >= 0); }
};

using Circles3D = vector<Circle3D>;
using Spheres3D = vector<Sphere3D>;

Real area(const Circle3D& c) { return PI * c.r * c.r; }
Real circumference(const Circle3D& c) { return 2 * PI * c.r; }
Real surface_area(const Sphere3D& s) { return 4 * PI * s.r * s.r; }
Real volume(const Sphere3D& s) { return 4 * PI * s.r * s.r * s.r / 3; }

int contains_sphere(const Sphere3D& s, const Point3D& p) {
  int z = sign(abs(p - s.p) - s.r);
  return z > 0 ? 0 : z == 0 ? 1 : 2;
}

// 0: contained, 1: internally tangent, 2: intersecting,
// 3: externally tangent, 4: separate.
int intersect(Sphere3D s, Sphere3D t) {
  if (s.r < t.r) swap(s, t);
  Real d = abs(s.p - t.p);
  if (s.r + t.r < d - EPS) return 4;
  if (equals(s.r + t.r, d)) return 3;
  if (s.r - t.r < d - EPS) return 2;
  if (equals(s.r - t.r, d)) return 1;
  return 0;
}

optional<pair<Point3D, Point3D>> cross_point_ls(const Line3D& l,
                                               const Sphere3D& s) {
  Point3D q = projection(l, s.p);
  Real h2 = s.r * s.r - norm(q - s.p);
  if (h2 < -EPS) return nullopt;
  h2 = max<Real>(0, h2);
  Point3D d = normalize(l.b - l.a) * sqrt(h2);
  return pair<Point3D, Point3D>{q - d, q + d};
}

optional<Circle3D> cross_circle_ps(const Plane3D& pl, const Sphere3D& s) {
  Point3D q = projection(pl, s.p);
  Real r2 = s.r * s.r - norm(q - s.p);
  if (r2 < -EPS) return nullopt;
  return Circle3D{q, normalize(pl.n), sqrt(max<Real>(0, r2))};
}

optional<Circle3D> cross_circle_ss(const Sphere3D& s, const Sphere3D& t) {
  int relation = intersect(s, t);
  if (relation == 0 || relation == 4) return nullopt;
  Point3D d = t.p - s.p;
  Real len = abs(d);
  if (len < EPS) return nullopt;
  Real x = (s.r * s.r - t.r * t.r + len * len) / (2 * len);
  Real r2 = s.r * s.r - x * x;
  Point3D n = d / len;
  return Circle3D{s.p + n * x, n, sqrt(max<Real>(0, r2))};
}

/**
 * @brief 三次元空間上の円と球
 * @docs docs/geometry-3d/sphere.md
 */
