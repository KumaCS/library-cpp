#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "graph/csr.hpp"
#include "graph/graph.hpp"

void test_unweighted() {
  GraphUnweighted g(4);
  g.add_edge(0, 1);
  g.add_edge_directed(1, 2);
  assert(g.size() == 4);
  assert(g[0].size() == 1 && g[0][0].to == 1);
  assert(g[1].size() == 2 && g[1][0].to == 0 && g[1][1].to == 2);
  assert(g[2].empty() && g[3].empty());

  GraphUnweighted copied(vector<vector<int>>{{1}, {0, 2}, {}, {}});
  assert(copied[1].size() == 2 && copied[1][1].to == 2);
}

void test_weighted() {
  GraphWeighted<long long> g(3);
  g.add_edge(0, 1, 7);
  g.add_edge_directed(1, 2, -4);
  assert(g[0][0].to == 1 && g[0][0].weight == 7);
  assert(g[1][0].to == 0 && g[1][0].weight == 7);
  assert(g[1][1].to == 2 && g[1][1].weight == -4);

  GraphWeighted<long long> copied(vector<vector<pair<int, long long>>>{{{1, 3}}, {{2, 5}}, {}});
  assert(copied[0][0].to == 1 && copied[0][0].weight == 3);
  assert(copied[1][0].to == 2 && copied[1][0].weight == 5);
}

void test_conversion_and_csr() {
  GraphUnweighted g(3);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  auto weighted = GraphUnweightedToWeighted(g);
  rep(x, 0, 3) for (auto e : weighted[x]) assert(e.weight == 1);

  CSR<EdgeUnweighted> csr(g);
  assert(csr.size() == 3 && csr.edge_count() == 4);
  assert(csr[0].size() == 1 && csr[0][0].to == 1);
  assert(csr[1].size() == 2 && csr[1][0].to == 0 && csr[1][1].to == 2);
  GraphUnweighted empty(1);
  csr.build(empty);
  assert(csr.size() == 1 && csr.edge_count() == 0 && csr[0].empty());
}

int main() {
  test_unweighted();
  test_weighted();
  test_conversion_and_csr();

  int a, b;
  in(a, b);
  out(a + b);
}
