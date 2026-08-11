#pragma once

#include "geometry/line.hpp"

// Returns the bounded, positive-area intersection of left half-planes.
// Returns an empty polygon if the intersection is empty, degenerate, or unbounded.
Polygon halfplane_intersection(Lines ls) {
  auto direction = [](const Line& l) { return l.b - l.a; };
  auto arg_half = [](const Point& a) {
    return a.y < 0 || (a.y == 0 && a.x < 0);
  };
  auto arg_less = [&](const Line& l, const Line& r) {
    Point a = direction(l), b = direction(r);
    int ha = arg_half(a), hb = arg_half(b);
    return ha != hb ? ha < hb : cross(a, b) > 0;
  };
  for (const auto& l : ls) assert(l.a != l.b);
  sort(ls.begin(), ls.end(), arg_less);
  Lines lines;
  for (const auto& l : ls) {
    if (!lines.empty() && is_parallel(lines.back(), l) &&
        dot(direction(lines.back()), direction(l)) > 0) {
      if (sign(cross(direction(lines.back()), l.a - lines.back().a)) > 0)
        lines.back() = l;
    } else {
      lines.push_back(l);
    }
  }
  auto outside = [&](const Line& l, const Point& p) {
    return sign(cross(direction(l), p - l.a)) < 0;
  };
  deque<Line> dq;
  for (const auto& l : lines) {
    while (dq.size() >= 2 &&
           outside(l, cross_point_ll(dq[dq.size() - 2], dq.back())))
      dq.pop_back();
    while (dq.size() >= 2 && outside(l, cross_point_ll(dq[0], dq[1])))
      dq.pop_front();
    if (!dq.empty() && is_parallel(dq.back(), l)) return {};
    dq.push_back(l);
  }
  while (dq.size() >= 3 &&
         outside(dq.front(), cross_point_ll(dq[dq.size() - 2], dq.back())))
    dq.pop_back();
  while (dq.size() >= 3 &&
         outside(dq.back(), cross_point_ll(dq[0], dq[1])))
    dq.pop_front();
  if (dq.size() < 3) return {};
  int n = dq.size();
  for (int i = 0; i < n; ++i) {
    if (sign(cross(direction(dq[i]), direction(dq[(i + 1) % n]))) <= 0)
      return {};
  }
  Polygon ret;
  for (int i = 0; i < n; ++i)
    ret.push_back(cross_point_ll(dq[i], dq[(i + 1) % n]));
  return ret;
}

/**
 * @brief 半平面交差
 * @docs docs/geometry/halfplane-intersection.md
 */
