#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "graph/shortest-path.hpp"

void test_bfs() {
  GraphUnweighted g(6);
  g.add_edge_directed(0, 1);
  g.add_edge_directed(0, 2);
  g.add_edge_directed(1, 3);
  g.add_edge_directed(2, 3);
  g.add_edge_directed(3, 4);
  auto dist = ShortestPath::BFS(g, 0);
  assert(dist == vector<optional<int>>({0, 1, 1, 2, 3, nullopt}));
  auto [dist_with_prev, prev] = ShortestPath::BFSWithPrev(g, 0);
  assert(dist_with_prev == dist);
  auto path = ShortestPath::EnumeratePath(prev, 4);
  assert(path.front() == 0 && path.back() == 4 && path.size() == 4);
  assert(ShortestPath::EnumeratePath(prev, 0) == vector<int>({0}));
}

void test_zero_one_bfs() {
  GraphWeighted<int> g(6);
  g.add_edge_directed(0, 1, 1);
  g.add_edge_directed(0, 2, 0);
  g.add_edge_directed(2, 1, 0);
  g.add_edge_directed(1, 3, 1);
  g.add_edge_directed(2, 3, 1);
  g.add_edge_directed(3, 4, 0);
  auto dist = ShortestPath::ZeroOneBFS(g, 0);
  assert(dist == vector<optional<int>>({0, 0, 0, 1, 1, nullopt}));
  auto [dist_with_prev, prev] = ShortestPath::ZeroOneBFSWithPrev(g, 0);
  assert(dist_with_prev == dist);
  assert(ShortestPath::EnumeratePath(prev, 4) == vector<int>({0, 2, 3, 4}));
}

int main() {
  test_bfs();
  test_zero_one_bfs();

  int a, b;
  in(a, b);
  out(a + b);
}
