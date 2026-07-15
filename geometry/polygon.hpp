#pragma once

#include "geometry/geometry-base.hpp"

// 反時計周り
using Polygon = vector<Point>;

// 多角形の内部に点があるか
// OUT : 0, ON : 1, IN : 2
// 凸でなくてもよい, 自己交差はもたない
// crossing number algorithm : x 軸正方向に伸ばした半直線が奇数回交われば内部
int contains_polygon(const Polygon& P, const Point& p) {
  bool in = false;
  for (int i = 0; i < (int)P.size(); i++) {
    Point a = P[i] - p, b = P[(i + 1) % P.size()] - p;
    if (a.y > b.y) swap(a, b);
    if (equals(cross(a, b), 0) && sign(dot(a, b)) <= 0) return 1;
    if (sign(a.y) <= 0 && 0 < sign(b.y) && sign(cross(a, b)) < 0)
      in = !in;
  }
  return in ? 2 : 0;
}

// 多角形の面積
Real area(const Polygon& P) {
  Real A = 0;
  for (int i = 0; i < (int)P.size(); i++) {
    A += cross(P[i], P[(i + 1) % P.size()]);
  }
  return A * 0.5;
}

bool is_convex(const Polygon& P) {
  int n = P.size();
  if (n < 3) return true;
  for (int i = 0; i < n; ++i) {
    if (ccw(P[i], P[(i + 1) % n], P[(i + 2) % n]) == -1) return false;
  }
  return true;
}

// 頂点集合から凸包を生成
// boundary : 周上の点も列挙する場合 true
template <bool boundary = false>
Polygon convex_hull(vector<Point> ps) {
  sort(begin(ps), end(ps));
  ps.erase(unique(begin(ps), end(ps)), end(ps));
  int n = ps.size(), k = 0;
  if (n <= 2) return ps;
  if constexpr (boundary) {
    bool collinear = true;
    for (int i = 2; i < n; ++i) {
      if (!equals(cross(ps[1] - ps[0], ps[i] - ps[0]), 0)) {
        collinear = false;
        break;
      }
    }
    if (collinear) return ps;
  }
  vector<Point> ch(2 * n);
  // 反時計周り
  const Real th = boundary ? -EPS : +EPS;
  for (int i = 0; i < n; ch[k++] = ps[i++]) {
    while (k >= 2 && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < th) --k;
  }
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {
    while (k >= t && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < th) --k;
  }
  ch.resize(k - 1);
  return ch;
}

// 凸包の内部に点があるか
// OUT : 0, ON : 1, IN : 2
int contains_convex(const Polygon& C, const Point& p) {
  int N = C.size();
  if (N == 0) return 0;
  if (N == 1) return abs(C[0] - p) < EPS ? 1 : 0;
  if (N == 2) return ccw(C[0], C[1], p) == 0 ? 1 : 0;
  auto b1 = cross(C[1] - C[0], p - C[0]);
  auto b2 = cross(C[N - 1] - C[0], p - C[0]);
  if (b1 < -EPS or b2 > EPS) return 0;
  int L = 1, R = N - 1;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    (cross(p - C[0], C[M] - C[0]) >= 0 ? R : L) = M;
  }
  auto v = cross(C[L] - p, C[R] - p);
  if (equals(v, 0)) {
    return 1;
  } else if (v > 0) {
    return equals(b1, 0) or equals(b2, 0) ? 1 : 2;
  } else {
    return 0;
  }
}

// 凸多角形の最遠点対を返す
// 返り値：頂点番号のペア
pair<int, int> convex_polygon_diameter(const Polygon& C) {
  int N = (int)C.size();
  assert(N > 0);
  if (N == 1) return {0, 0};
  if (N == 2) return {0, 1};
  int is = 0, js = 0;
  for (int i = 1; i < N; i++) {
    if (C[i].y > C[is].y) is = i;
    if (C[i].y < C[js].y) js = i;
  }
  Real maxdis = norm(C[is] - C[js]);

  int maxi, maxj, i, j;
  i = maxi = is;
  j = maxj = js;
  do {
    if (cross(C[(i + 1) % N] - C[i], C[(j + 1) % N] - C[j]) >= 0) {
      j = (j + 1) % N;
    } else {
      i = (i + 1) % N;
    }
    if (norm(C[i] - C[j]) > maxdis) {
      maxdis = norm(C[i] - C[j]);
      maxi = i;
      maxj = j;
    }
  } while (i != is || j != js);
  return minmax(maxi, maxj);
}

/**
 * @brief 多角形
 * @docs docs/geometry/polygon.md
 */
