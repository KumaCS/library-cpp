#pragma once

#include "geometry-integer/geometry-base.hpp"

// Counter-clockwise order.
using Polygon = std::vector<Point>;

// OUT: 0, ON: 1, IN: 2.
int contains_polygon(const Polygon& P, const Point& p) {
  bool in = false;
  for (int i = 0; i < (int)P.size(); ++i) {
    Point a = P[i] - p, b = P[(i + 1) % P.size()] - p;
    if (a.y > b.y) std::swap(a, b);
    if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
    if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
  }
  return in ? 2 : 0;
}

WideInteger area2(const Polygon& P) {
  WideInteger ret = 0;
  for (int i = 0; i < (int)P.size(); ++i)
    ret += cross(P[i], P[(i + 1) % P.size()]);
  return ret;
}

bool is_convex(const Polygon& P) {
  int n = P.size();
  if (n < 3) return true;
  for (int i = 0; i < n; ++i) {
    if (cross(P[(i + 1) % n] - P[i], P[(i + 2) % n] - P[i]) < 0)
      return false;
  }
  return true;
}

template <bool boundary = false>
Polygon convex_hull(Points ps) {
  std::sort(ps.begin(), ps.end());
  ps.erase(std::unique(ps.begin(), ps.end()), ps.end());
  int n = ps.size(), k = 0;
  if (n <= 2) return ps;
  if constexpr (boundary) {
    bool collinear = true;
    for (int i = 2; i < n; ++i) {
      if (cross(ps[1] - ps[0], ps[i] - ps[0]) != 0) {
        collinear = false;
        break;
      }
    }
    if (collinear) return ps;
  }
  Polygon ch(2 * n);
  auto pop = [](WideInteger cr) {
    if constexpr (boundary)
      return cr < 0;
    else
      return cr <= 0;
  };
  for (int i = 0; i < n; ch[k++] = ps[i++]) {
    while (k >= 2 && pop(cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1])))
      --k;
  }
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {
    while (k >= t && pop(cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1])))
      --k;
  }
  ch.resize(k - 1);
  return ch;
}

// OUT: 0, ON: 1, IN: 2.
int contains_convex(const Polygon& C, const Point& p) {
  int n = C.size();
  if (n == 0) return 0;
  if (n == 1) return C[0] == p ? 1 : 0;
  if (n == 2) {
    return cross(C[1] - C[0], p - C[0]) == 0 &&
                   dot(p - C[0], p - C[1]) <= 0
               ? 1
               : 0;
  }
  WideInteger b1 = cross(C[1] - C[0], p - C[0]);
  WideInteger b2 = cross(C[n - 1] - C[0], p - C[0]);
  if (b1 < 0 || b2 > 0) return 0;
  int l = 1, r = n - 1;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    (cross(p - C[0], C[m] - C[0]) >= 0 ? r : l) = m;
  }
  WideInteger v = cross(C[l] - p, C[r] - p);
  if (v == 0) return 1;
  if (v < 0) return 0;
  return b1 == 0 || b2 == 0 ? 1 : 2;
}

std::pair<int, int> convex_polygon_diameter(const Polygon& C) {
  int n = C.size();
  assert(n > 0);
  if (n == 1) return {0, 0};
  if (n == 2) return {0, 1};
  if (area2(C) == 0) {
    int mn = std::min_element(C.begin(), C.end()) - C.begin();
    int mx = std::max_element(C.begin(), C.end()) - C.begin();
    return std::minmax(mn, mx);
  }
  WideInteger maxdis = -1;
  int maxi = 0, maxj = 0, j = 1;
  auto update = [&](int a, int b) {
    WideInteger d = norm(C[a] - C[b]);
    if (d > maxdis) {
      maxdis = d;
      maxi = a;
      maxj = b;
    }
  };
  for (int i = 0; i < n; ++i) {
    int ni = (i + 1) % n;
    if (j == i) j = (j + 1) % n;
    auto height = [&](int k) { return cross(C[ni] - C[i], C[k] - C[i]); };
    while (height((j + 1) % n) > height(j)) j = (j + 1) % n;
    update(i, j);
    update(ni, j);
    int nj = (j + 1) % n;
    if (height(nj) == height(j)) {
      update(i, nj);
      update(ni, nj);
    }
  }
  return std::minmax(maxi, maxj);
}

int argmax_dot(const Polygon& C, const Point& p) {
  int n = C.size();
  assert(n > 0);
  assert(p.x != 0 || p.y != 0);
  if (n <= 2) {
    if (n == 1 || dot(C[0], p) >= dot(C[1], p)) return 0;
    return 1;
  }
  auto arg_half = [](const Point& a) {
    return a.y < 0 || (a.y == 0 && a.x < 0);
  };
  auto arg_less = [&](const Point& a, const Point& b) {
    int ha = arg_half(a), hb = arg_half(b);
    return ha != hb ? ha < hb : cross(a, b) > 0;
  };
  auto edge = [&](int i) { return C[(i + 1) % n] - C[i]; };
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (arg_less(edge(r), edge(m)))
      l = m + 1;
    else
      r = m;
  }
  int s = l;
  Point q = p.rotate90();
  l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (arg_less(edge((s + m) % n), q))
      l = m + 1;
    else
      r = m;
  }
  int i = (s + (l == n ? 0 : l)) % n;
  Point e = edge(i);
  if (!arg_less(e, q) && !arg_less(q, e)) {
    int low = l;
    r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (!arg_less(q, edge((s + m) % n)))
        l = m + 1;
      else
        r = m;
    }
    int count = l - low;
    return i + count >= n ? 0 : i;
  }
  return i;
}

/**
 * @brief 整数座標上の多角形
 * @docs docs/geometry-integer/polygon.md
 */
