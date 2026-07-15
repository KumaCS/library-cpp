#pragma once

#include "geometry/line.hpp"

struct Circle {
  Point p;
  Real r;

  Circle() = default;
  Circle(const Point& _p, Real _r) : p(_p), r(_r) {}
};

using Circles = vector<Circle>;

// 0: contained, 1: internally tangent, 2: intersecting,
// 3: externally tangent, 4: separate.
int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if (c1.r + c2.r < d - EPS) return 4;
  if (equals(c1.r + c2.r, d)) return 3;
  if (c1.r - c2.r < d - EPS) return 2;
  if (equals(c1.r - c2.r, d)) return 1;
  return 0;
}

pair<Point, Point> cross_point_cl(const Circle& c, const Line& l) {
  Point q = projection(l, c.p);
  Real h2 = max<Real>(0, c.r * c.r - norm(q - c.p));
  Point e = (l.b - l.a) / abs(l.b - l.a);
  Point d = e * sqrt(h2);
  return {q - d, q + d};
}

pair<Point, Point> cross_point_cc(const Circle& c1, const Circle& c2) {
  Point d = c2.p - c1.p;
  Real d2 = norm(d), len = sqrt(d2);
  Real x = (c1.r * c1.r - c2.r * c2.r + d2) / (2 * len);
  Real h = sqrt(max<Real>(0, c1.r * c1.r - x * x));
  Point q = c1.p + d * (x / len);
  Point v = d.rotate90() * (h / len);
  return {q - v, q + v};
}

// Compatibility with the reference implementation.
pair<Point, Point> crosspoint(const Circle& c1, const Circle& c2) {
  return cross_point_cc(c1, c2);
}

pair<Point, Point> tangent_points(const Circle& c, const Point& p) {
  Point d = p - c.p;
  Real d2 = norm(d);
  Real x = c.r * c.r / d2;
  Real y = c.r * sqrt(max<Real>(0, d2 - c.r * c.r)) / d2;
  Point q = c.p + d * x;
  Point v = d.rotate90() * y;
  return {q - v, q + v};
}

Lines common_tangents(const Circle& c1, const Circle& c2) {
  Lines ret;
  Point d = c2.p - c1.p;
  Real d2 = norm(d);
  if (equals(d2, 0)) return ret;
  for (int s : {-1, 1}) {
    Real r = c1.r - s * c2.r;
    Real h2 = d2 - r * r;
    if (h2 < -EPS) continue;
    h2 = max<Real>(0, h2);
    for (int t : {-1, 1}) {
      Point v = (d * r + d.rotate90() * (sqrt(h2) * t)) / d2;
      ret.emplace_back(c1.p + v * c1.r, c2.p + v * (s * c2.r));
      if (equals(h2, 0)) break;
    }
  }
  return ret;
}

Real common_area(const Circle& c1, const Circle& c2) {
  Real d = abs(c1.p - c2.p);
  if (d >= c1.r + c2.r - EPS) return 0;
  if (d <= abs(c1.r - c2.r) + EPS) {
    Real r = min(c1.r, c2.r);
    return PI * r * r;
  }
  Real a1 = acos(clamp((d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d * c1.r), (Real)-1, (Real)1));
  Real a2 = acos(clamp((d * d + c2.r * c2.r - c1.r * c1.r) / (2 * d * c2.r), (Real)-1, (Real)1));
  auto x_minus_sin = [](Real x) {
    if (abs(x) > 0.1L) return x - sin(x);
    Real x2 = x * x;
    return x * x2 * (1.0L / 6 - x2 / 120 + x2 * x2 / 5040 - x2 * x2 * x2 / 362880 + x2 * x2 * x2 * x2 / 39916800);
  };
  return (c1.r * c1.r * x_minus_sin(2 * a1) + c2.r * c2.r * x_minus_sin(2 * a2)) / 2;
}

/**
 * @brief 円
 * @docs docs/geometry/circle.md
 */
