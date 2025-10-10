#pragma once

vector<int> MonotoneMinima(int n, int m, const function<bool(int, int, int)> &f) {
  vector<int> res(n);
  auto dfs = [&](auto rc, int il, int ir, int l, int r) -> void {
    if (il == ir) return;
    int i = (il + ir) / 2;
    int m = l;
    for (int k = l + 1; k < r; k++)
      if (!f(i, m, k)) m = k;
    res[i] = m;
    rc(rc, il, i, l, m + 1);
    rc(rc, i + 1, ir, m, r);
  };
  dfs(dfs, 0, n, 0, m);
  return res;
}

// m_i := argmin_j (A_{i,j}) が単調増加であるときに m_i を列挙する
template <class T>
vector<int> MonotoneMinima(int N, int M, const function<T(int, int)> &A) {
  const auto f = [&](int i, int j, int k) -> bool {
    return A(i, j) <= A(i, k);
  };
  return MonotoneMinima(N, M, f);
}

/**
 * @brief monotone minima
 * @docs docs/algorithm/monotone-minima.md
 */