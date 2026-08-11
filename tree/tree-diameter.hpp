#pragma once

namespace TreeDiameterInternal {
template <class T, class G, class F>
int farthest(const G& g, int root, const F& weight, vector<T>& dist, vector<int>* prev = nullptr) {
  int n = g.size();
  dist[root] = T{};
  if (prev) prev->assign(n, -1);
  stack<pair<int, int>> st;
  st.push({root, -1});
  while (!st.empty()) {
    auto [x, p] = st.top();
    st.pop();
    for (const auto& e : g[x]) {
      int y = e.to;
      if (y == p) continue;
      dist[y] = dist[x] + weight(e);
      if (prev) (*prev)[y] = x;
      st.push({y, x});
    }
  }
  int farthest = root;
  for (int i = 0; i < n; i++)
    if (dist[i] > dist[farthest]) farthest = i;
  return farthest;
}
template <class T, class G, class F>
pair<T, vector<int>> solve(const G& g, F weight) {
  int n = g.size();
  assert(n > 0);
  vector<T> dist(n);
  int u = farthest(g, 0, weight, dist);
  vector<int> prv;
  int v = farthest(g, u, weight, dist, &prv);
  vector<int> path;
  for (int x = v; x != -1; x = prv[x]) path.push_back(x);
  return {dist[v], path};
}
}  // namespace TreeDiameterInternal

template <class G>
auto TreeDiameter(const G& g) {
  using E = remove_cvref_t<decltype(g[0][0])>;
  if constexpr (requires(E e) { e.weight; }) {
    using T = remove_cvref_t<decltype(declval<E>().weight)>;
    return TreeDiameterInternal::solve<T>(g, [](const E& e) { return e.weight; });
  } else {
    return TreeDiameterInternal::solve<int>(g, [](const E&) { return 1; });
  }
}
/**
 * @brief 木の直径
 * @docs docs/tree/tree-diameter.md
 */
