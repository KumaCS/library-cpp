#pragma once

#include "math/util.hpp"

template <class I = long long>
struct ModLinearDecompositionResult {
  struct SequenceInfo {
    I size, x0, y0;
  };
  I dx, dy;
  vector<SequenceInfo> sequences;
};
// 点の集合 (x,(ax+b)%m) (0<=x<n) を等間隔な点列 O(min(sqrt(n),m)) 個に分解
template <class I = long long>
ModLinearDecompositionResult<I> ModLinearDecomposition(I n, I m, I a, I b) {
  assert(n >= 0);
  assert(m > 0 && 0 <= a && a < m && 0 <= b && b < m);
  if (n == 0) return {0, 0, {}};
  I s = Math::isqrt((long long)n - 1) + 1;
  I width = (m - 1) / s + 1;
  I bucket_count = (m - 1) / width + 1;
  vector<pair<I, I>> first(bucket_count, {-1, 0});
  I d = 0, h = 0, x = 0;
  for (I i = 0; i <= s; i++) {
    I bucket = x / width;
    if (first[bucket].first != -1) {
      d = i - first[bucket].first;
      h = x - first[bucket].second;
      break;
    }
    first[bucket] = {i, x};
    x = x >= m - a ? x - (m - a) : x + a;
  }
  assert(d > 0);
  ModLinearDecompositionResult<I> res;
  res.dx = d;
  res.dy = h;
  I y0 = b;
  for (I r = 0; r < d && r < n; ++r) {
    I rem = (n - 1 - r) / d + 1;
    I x = r, y = y0;
    while (rem > 0) {
      I size;
      if (h > 0)
        size = min(rem, Math::ceil(m - y, h));
      else if (h < 0)
        size = min(rem, Math::ceil(y + 1, -h));
      else
        size = rem;
      res.sequences.push_back({size, x, y});
      rem -= size;
      if (rem == 0) break;
      x += size * d;
      y += size * h + (h > 0 ? -m : m);
    }
    y0 = y0 >= m - a ? y0 - (m - a) : y0 + a;
  }
  return res;
}

/**
 * @brief 一次式の剰余の点列分解
 * @docs docs/math/mod-linear-decomposition.md
 */
