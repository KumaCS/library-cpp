#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "template/template.hpp"
#include "tree/tree-jump.hpp"

int main() {
  int n, q;
  in(n, q);
  auto g = IO::Tree::unweighted(n, false, 0);
  auto jump = TreeJump(g);
  while (q--) {
    int s, t, i;
    in(s, t, i);
    out(jump.jump(s, t, i));
  }
}