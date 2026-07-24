#pragma once

namespace TernarySearch {
template <class I, class V, class F>
pair<I, V> integer_min(I low, I high, F f) {
  assert(low <= high);
  while (high - low > I(2)) {
    I d = (high - low) / 3;
    I midl = low + d;
    I midr = low + d * 2;
    if (f(midl) >= f(midr))
      low = midl;
    else
      high = midr;
  }
  I minx = low;
  V minv = f(minx);
  for (I x = low + 1; x <= high; x++) {
    V v = f(x);
    if (v < minv) {
      minx = x;
      minv = v;
    }
  }
  return pair<I, V>(minx, minv);
};
template <class I, class V, class F>
pair<I, V> integer_max(I low, I high, F f) {
  assert(low <= high);
  while (high - low > I(2)) {
    I d = (high - low) / 3;
    I midl = low + d;
    I midr = low + d * 2;
    if (f(midl) <= f(midr))
      low = midl;
    else
      high = midr;
  }
  I maxx = low;
  V maxv = f(maxx);
  for (I x = low + 1; x <= high; x++) {
    V v = f(x);
    if (v > maxv) {
      maxx = x;
      maxv = v;
    }
  }
  return pair<I, V>(maxx, maxv);
};
};  // namespace TernarySearch