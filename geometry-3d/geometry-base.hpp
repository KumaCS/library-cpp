#pragma once

#include "geometry/geometry-base.hpp"

template <class R>
struct Point3DBase {
  using P = Point3DBase;
  R x, y, z;

  Point3DBase() : x(0), y(0), z(0) {}
  Point3DBase(R _x, R _y, R _z) : x(_x), y(_y), z(_z) {}

  P operator+(const P& r) const { return {x + r.x, y + r.y, z + r.z}; }
  P operator-(const P& r) const { return {x - r.x, y - r.y, z - r.z}; }
  P operator-() const { return {-x, -y, -z}; }
  P operator*(R r) const { return {x * r, y * r, z * r}; }
  P operator/(R r) const { return {x / r, y / r, z / r}; }

  P& operator+=(const P& r) { return (*this) = (*this) + r; }
  P& operator-=(const P& r) { return (*this) = (*this) - r; }
  P& operator*=(R r) { return (*this) = (*this) * r; }
  P& operator/=(R r) { return (*this) = (*this) / r; }

  bool operator<(const P& r) const {
    if (x != r.x) return x < r.x;
    return y != r.y ? y < r.y : z < r.z;
  }
  bool operator==(const P& r) const {
    return x == r.x && y == r.y && z == r.z;
  }
  bool operator!=(const P& r) const { return !((*this) == r); }

  friend P operator*(R r, const P& p) { return p * r; }
  friend R dot(const P& l, const P& r) {
    return l.x * r.x + l.y * r.y + l.z * r.z;
  }
  friend P cross(const P& l, const P& r) {
    return {l.y * r.z - l.z * r.y, l.z * r.x - l.x * r.z,
            l.x * r.y - l.y * r.x};
  }
  friend R norm(const P& p) { return dot(p, p); }
  friend R abs(const P& p) { return sqrt(norm(p)); }

  friend istream& operator>>(istream& is, P& p) {
    return is >> p.x >> p.y >> p.z;
  }
  friend ostream& operator<<(ostream& os, const P& p) {
    return os << p.x << " " << p.y << " " << p.z;
  }
};

using Point3D = Point3DBase<Real>;
using Points3D = vector<Point3D>;

Real triple(const Point3D& a, const Point3D& b, const Point3D& c) {
  return dot(a, cross(b, c));
}

Point3D normalize(const Point3D& p) {
  Real len = abs(p);
  assert(len > EPS);
  return p / len;
}

Real angle(const Point3D& a, const Point3D& b) {
  Real d = abs(a) * abs(b);
  assert(d > EPS);
  return acos(clamp(dot(a, b) / d, (Real)-1, (Real)1));
}

bool equals(const Point3D& a, const Point3D& b) { return abs(a - b) < EPS; }

/**
 * @brief 三次元幾何の基本要素
 * @docs docs/geometry-3d/geometry-base.md
 */
