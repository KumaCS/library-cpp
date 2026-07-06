#pragma once

vector<int> LPFTable(int n) {
  vector<int> lpf(n + 1, 0);
  iota(lpf.begin(), lpf.end(), 0);
  for (int p = 2; p * p <= n; p += (p & 1) + 1) {
    if (lpf[p] != p) continue;
    for (int i = p * p; i <= n; i += p)
      if (lpf[i] == i) lpf[i] = p;
  }
  return lpf;
}
/**
 * @brief LPF Table
 */