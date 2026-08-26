#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "graph/cycle-detection.hpp"

int main() {
  int n, m;
  in(n, m);
  GraphUnweightedIndexed g(n);
  rep(i, 0, m) {
    int u, v;
    in(u, v);
    assert(g.add_edge_directed(u, v) == i);
  }
  auto cycle = CycleDetection(g);
  if (!cycle) {
    out(-1);
    return 0;
  }
  out(cycle->size());
  for (int id : *cycle) out(id);
}
