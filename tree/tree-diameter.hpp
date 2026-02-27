#pragma once

template <class T>
pair<T, vector<int>> TreeDiameter(const vector<vector<pair<int, T>>>& g) {
  int n = g.size();
  assert(n > 0);
  stack<pair<int, int>> st;
  vector<T> d(n);
  st.push({0, -1});
  while (!st.empty()) {
    auto [x, p] = st.top();
    st.pop();
    for (auto [y, w] : g[x]) {
      if (y == p) continue;
      d[y] = d[x] + w;
      st.push({y, x});
    }
  }
  int u = 0;
  for (int i = 1; i < n; i++)
    if (d[i] > d[u]) u = i;
  d[u] = T{};
  st.push({u, -1});
  vector<int> prv(n, -1);
  while (!st.empty()) {
    auto [x, p] = st.top();
    st.pop();
    for (auto [y, w] : g[x]) {
      if (y == p) continue;
      prv[y] = x;
      d[y] = d[x] + w;
      st.push({y, x});
    }
  }
  int v = 0;
  for (int i = 1; i < n; i++)
    if (d[i] > d[v]) v = i;
  vector<int> path;
  for (int x = v; x != -1; x = prv[x]) path.push_back(x);
  return {d[v], path};
}
pair<int, vector<int>> TreeDiameter(const vector<vector<int>>& g) {
  int n = g.size();
  assert(n > 0);
  stack<pair<int, int>> st;
  vector<int> d(n);
  st.push({0, -1});
  while (!st.empty()) {
    auto [x, p] = st.top();
    st.pop();
    for (auto y : g[x]) {
      if (y == p) continue;
      d[y] = d[x] + 1;
      st.push({y, x});
    }
  }
  int u = 0;
  for (int i = 1; i < n; i++)
    if (d[i] > d[u]) u = i;
  d[u] = 0;
  st.push({u, -1});
  vector<int> prv(n, -1);
  while (!st.empty()) {
    auto [x, p] = st.top();
    st.pop();
    for (auto y : g[x]) {
      if (y == p) continue;
      prv[y] = x;
      d[y] = d[x] + 1;
      st.push({y, x});
    }
  }
  int v = 0;
  for (int i = 1; i < n; i++)
    if (d[i] > d[v]) v = i;
  vector<int> path;
  for (int x = v; x != -1; x = prv[x]) path.push_back(x);
  return {d[v], path};
}
/**
 * @brief 木の直径
 * @docs docs/tree/tree-diameter.md
 */