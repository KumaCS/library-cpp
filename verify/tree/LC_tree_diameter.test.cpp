#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "template/template.hpp"
#include "tree/tree-diameter.hpp"

int main() {
  int n;
  in(n);
  auto g = IO::Tree::weighted<ll>(n, false, 0);
  auto [len, vs] = TreeDiameter(g);
  out(len, vs.size());
  out(vs);
}