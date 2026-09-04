#pragma once

template <class G>
pair<vector<int>, vector<int>> EulerTour(const G& g, int root = 0) {
  int n = g.size();
  assert(n > 0);
  assert(0 <= root && root < n);
  vector<int> in_time(n), out_time(n);
  vector<int> parent(n, -2), iter(n);
  parent[root] = -1;
  int t = 0;
  vector<int> st = {root};
  while (!st.empty()) {
    int x = st.back();
    if (iter[x] == 0) in_time[x] = t++;
    if (iter[x] == (int)g[x].size()) {
      out_time[x] = t;
      st.pop_back();
      continue;
    }
    int y = g[x][iter[x]++].to;
    if (y == parent[x]) continue;
    assert(parent[y] == -2);
    parent[y] = x;
    st.push_back(y);
  }
  assert(t == n);
  return {in_time, out_time};
}

/**
 * @brief Euler Tour of Tree
 * @docs docs/tree/euler-tour.md
 */
