#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "tree/centroid-decomposition.hpp"
#include "util/xorshift.hpp"

void verify(const GraphUnweighted& g) {
  int n = g.size();
  auto [root, parent] = CentroidDecomposition(g);
  assert(0 <= root && root < n);
  assert((int)parent.size() == n && parent[root] == -1);
  vector<vector<int>> child(n);
  rep(x, 0, n) {
    if (x == root) continue;
    assert(0 <= parent[x] && parent[x] < n);
    child[parent[x]].push_back(x);
  }
  vector<int> seen(n), vertices;
  auto dfs = [&](auto&& self, int x) -> void {
    assert(!seen[x]);
    seen[x] = 1;
    for (int y : child[x]) self(self, y);
  };
  dfs(dfs, root);
  assert(accumulate(seen.begin(), seen.end(), 0) == n);

  auto check = [&](auto&& self, int centroid) -> vector<int> {
    vector<int> component = {centroid};
    for (int y : child[centroid]) {
      auto part = self(self, y);
      component.insert(component.end(), part.begin(), part.end());
    }
    vector<unsigned char> in_component(n);
    for (int x : component) in_component[x] = true;
    int max_size = 0;
    for (auto e : g[centroid]) {
      if (!in_component[e.to]) continue;
      int size = 0;
      vector<pair<int, int>> st = {{e.to, centroid}};
      while (!st.empty()) {
        auto [x, p] = st.back();
        st.pop_back();
        size++;
        for (auto f : g[x])
          if (f.to != p && f.to != centroid && in_component[f.to]) st.push_back({f.to, x});
      }
      max_size = max(max_size, size);
    }
    assert(max_size * 2 <= (int)component.size());
    return component;
  };
  check(check, root);
}

void test() {
  verify(GraphUnweighted(1));
  rep(loop, 0, 500) {
    int n = XORShift::xor32() % 80 + 1;
    GraphUnweighted g(n);
    rep(x, 1, n) g.add_edge(x, XORShift::xor32() % x);
    verify(g);
  }
}

int main() {
  test();
  int a, b;
  in(a, b);
  out(a + b);
}
