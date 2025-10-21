#pragma once

vector<int> PrimeSieve(int n) {
  vector<bool> f(n + 1, false);
  for (int p = 2; p * p <= n; p += (p & 1) + 1) {
    if (f[p]) continue;
    for (int i = p * p; i <= n; i += p) f[i] = true;
  }
  vector<int> ps;
  for (int p = 2; p <= n; p += (p & 1) + 1)
    if (!f[p]) ps.push_back(p);
  return ps;
}
/**
 * @brief 素数篩
 */