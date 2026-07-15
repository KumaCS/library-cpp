#pragma once

#include <bits/stdc++.h>

using Real = long double;
constexpr Real EPS = 1e-10;
constexpr Real PI = 3.141592653589793238462643383279L;
bool equals(Real x, Real y) { return fabs(x - y) < EPS; }
int sign(Real a) { return equals(a, 0) ? 0 : (a > 0 ? 1 : -1); }

template <class R>
struct PointBase {
  using P = PointBase;
  R x, y;
  PointBase() : x(0), y(0) {}
  PointBase(R _x, R _y) : x(_x), y(_y) {}
  template <typename T, typename U>
  PointBase(const pair<T, U>& p) : x(p.first), y(p.second) {}

  P operator+(const P& r) const { return P{x + r.x, y + r.y}; }
  P operator-(const P& r) const { return P{x - r.x, y - r.y}; }
  P operator-() const { return P{-x, -y}; }
  P operator*(R r) const { return P{x * r, y * r}; }
  P operator/(R r) const { return P{x / r, y / r}; }

  P& operator+=(const P& r) { return (*this) = (*this) + r; }
  P& operator-=(const P& r) { return (*this) = (*this) - r; }
  P& operator*=(R r) { return (*this) = (*this) * r; }
  P& operator/=(R r) { return (*this) = (*this) / r; }

  bool operator<(const P& r) const { return x != r.x ? x < r.x : y < r.y; }
  bool operator==(const P& r) const { return x == r.x and y == r.y; }
  bool operator!=(const P& r) const { return !((*this) == r); }

  P rotate(R rad) const {
    return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)};
  }
  P rotate90() const { return {-y, x}; }

  R real() const { return x; }
  R imag() const { return y; }

  friend P operator*(R r, const P& p) { return p * r; }
  friend R real(const P& p) { return p.x; }
  friend R imag(const P& p) { return p.y; }
  friend R dot(const P& l, const P& r) { return l.x * r.x + l.y * r.y; }
  friend R cross(const P& l, const P& r) { return l.x * r.y - l.y * r.x; }
  friend R abs(const P& p) { return sqrt(p.x * p.x + p.y * p.y); }
  friend R norm(const P& p) { return p.x * p.x + p.y * p.y; }
  friend R arg(const P& p) { return atan2(p.y, p.x); }

  friend istream& operator>>(istream& is, P& p) {
    R a, b;
    is >> a >> b;
    p = P{a, b};
    return is;
  }
  friend ostream& operator<<(ostream& os, const P& p) {
    return os << p.x << " " << p.y;
  }
};
using Point = PointBase<Real>;
using Points = vector<Point>;

// relative position of c from a->b
int ccw(const Point& a, const Point& b, const Point& c) {
  Point x = b - a, y = c - a;
  if (cross(x, y) > EPS) return +1;        // counter-clockwise
  if (cross(x, y) < -EPS) return -1;       // clockwise
  if (dot(x, y) < -EPS) return +2;         // collinear in the order c-a-b
  if (norm(x) + EPS < norm(y)) return -2;  // collinear in the order a-b-c
  return 0;                                // collinear in the order a-c-b
}

/**
 * @brief 二次元幾何の基本要素
 * @docs docs/geometry/geometry-base.md
 */
