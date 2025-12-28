#pragma once

template <class T>
vector<int> ZAlgorithm(const T& a) {
  int n = a.size();
  vector<int> p(n);
  p[0] = n;
  for (int i = 1, j = 0; i < n;) {
    while (i + j < n && a[j] == a[i + j]) j++;
    p[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (i + k < n && k + p[k] < j) {
      p[i + k] = p[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return p;
}
/**
 * @brief Z-algorithm
 * @docs docs/string/z-algorithm.md
 */