#pragma once

#include <bits/stdc++.h>

using Integer = long long;
using WideInteger = __int128_t;

int sign(WideInteger a) { return a == 0 ? 0 : (a > 0 ? 1 : -1); }

template <class I>
struct PointBase {
  using P = PointBase;
  I x, y;
  PointBase() : x(0), y(0) {}
  PointBase(I _x, I _y) : x(_x), y(_y) {}
  template <class T, class U>
  PointBase(const std::pair<T, U>& p) : x(p.first), y(p.second) {}

  P operator+(const P& r) const { return P{x + r.x, y + r.y}; }
  P operator-(const P& r) const { return P{x - r.x, y - r.y}; }
  P operator-() const { return P{-x, -y}; }
  P operator*(I r) const { return P{x * r, y * r}; }

  P& operator+=(const P& r) { return (*this) = (*this) + r; }
  P& operator-=(const P& r) { return (*this) = (*this) - r; }
  P& operator*=(I r) { return (*this) = (*this) * r; }

  bool operator<(const P& r) const { return x != r.x ? x < r.x : y < r.y; }
  bool operator==(const P& r) const { return x == r.x && y == r.y; }
  bool operator!=(const P& r) const { return !(*this == r); }

  P rotate90() const { return {-y, x}; }
  I real() const { return x; }
  I imag() const { return y; }

  friend P operator*(I r, const P& p) { return p * r; }
  friend I real(const P& p) { return p.x; }
  friend I imag(const P& p) { return p.y; }
  friend WideInteger dot(const P& l, const P& r) {
    return (WideInteger)l.x * r.x + (WideInteger)l.y * r.y;
  }
  friend WideInteger cross(const P& l, const P& r) {
    return (WideInteger)l.x * r.y - (WideInteger)l.y * r.x;
  }
  friend WideInteger norm(const P& p) { return dot(p, p); }

  friend std::istream& operator>>(std::istream& is, P& p) {
    return is >> p.x >> p.y;
  }
  friend std::ostream& operator<<(std::ostream& os, const P& p) {
    return os << p.x << " " << p.y;
  }
};

using Point = PointBase<Integer>;
using Points = std::vector<Point>;

// Relative position of c from a -> b.
int ccw(const Point& a, const Point& b, const Point& c) {
  Point x = b - a, y = c - a;
  WideInteger cr = cross(x, y);
  if (cr > 0) return +1;       // counter-clockwise
  if (cr < 0) return -1;       // clockwise
  if (dot(x, y) < 0) return +2;  // collinear in the order c-a-b
  if (norm(x) < norm(y)) return -2;  // collinear in the order a-b-c
  return 0;                    // collinear in the order a-c-b
}

/**
 * @brief 整数二次元幾何の基本要素
 * @docs docs/geometry-integer/geometry-base.md
 */
