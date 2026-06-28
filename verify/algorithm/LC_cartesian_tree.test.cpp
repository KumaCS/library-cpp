#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "template/template.hpp"
#include "algorithm/cartesian-tree.hpp"

int main() {
  int n;
  in(n);
  vector<int> a(n);
  in(a);
  auto [root, nodes] = CartesianTree(a);
  vector<int> p(n);
  rep(i, 0, n) p[i] = nodes[i][0] == -1 ? i : nodes[i][0];
  out(p);
}
