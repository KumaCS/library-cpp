#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "tree/lca-auxiliary-tree.hpp"

void test_auxiliary_tree() {
  GraphUnweighted g(8);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  g.add_edge(2, 5);
  g.add_edge(2, 6);
  g.add_edge(5, 7);

  const LCAAuxiliaryTree auxiliary_tree(g);
  GraphUnweighted auxiliary(g.size());
  auto [root, vertices] = auxiliary_tree.calc({7, 3, 4, 3}, auxiliary);
  assert(root == 0);
  assert(vertices == vector<int>({0, 1, 3, 4, 7}));
  assert(auxiliary[0].size() == 2);
  assert(auxiliary[0][0].to == 1 && auxiliary[0][1].to == 7);
  assert(auxiliary[1].size() == 2);
  assert(auxiliary[1][0].to == 3 && auxiliary[1][1].to == 4);
  for (int x : vector<int>{3, 4, 7}) assert(auxiliary[x].empty());
}

int main() {
  test_auxiliary_tree();

  int a, b;
  in(a, b);
  out(a + b);
}
