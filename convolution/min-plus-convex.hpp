#pragma once

#include "../algorithm/monotone-minima.hpp"

// a : 下に凸, b : 自由
template <class T>
vector<T> MinPlusConvolutionConvexArbitrary(const vector<T> &a, const vector<T> &b) {
  if (a.empty() || b.empty()) return {};
  int n = a.size(), m = b.size();
  auto argmin = MonotoneMinima(n + m - 1, m, [&](int i, int j, int k) {
    if (i < k) return true;
    if (i - j >= n) return false;
    return a[i - j] + b[j] <= a[i - k] + b[k];
  });
  vector<T> c(n + m - 1);
  for (int i = 0; i < n + m - 1; i++) {
    int j = argmin[i];
    c[i] = a[i - j] + b[j];
  }
  return c;
}

// a,b : 下に凸
template <class T>
vector<T> MinPlusConvolutionConvexConvex(const vector<T> &a, const vector<T> &b) {
  if (a.empty() || b.empty()) return {};
  int n = a.size(), m = b.size();
  vector<T> c(n + m - 1);
  c[0] = a[0] + b[0];
  for (int k = 0, i = 0; k < n + m - 2; k++) {
    int j = k - i;
    if (j == m - 1 || (i < n - 1 && a[i + 1] + b[j] < a[i] + b[j + 1])) {
      c[k + 1] = a[++i] + b[j];
    } else {
      c[k + 1] = a[i] + b[++j];
    }
  }
  return c;
}

/**
 * @brief min-plus 畳み込み (convex)
 * @docs docs/convolution/min-plus-convex.md
 */