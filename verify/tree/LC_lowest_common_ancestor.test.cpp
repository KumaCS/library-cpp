#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "template/template.hpp"
#include "tree/lowest-common-ancestor.hpp"

int main() {
  int n, q;
  in(n, q);
  auto g = IO::Tree::rooted(n, true, true, 0);
  LowestCommonAncestor lca(g);
  while (q--) {
    int u, v;
    in(u, v);
    out(lca.lca(u, v));
  }
}