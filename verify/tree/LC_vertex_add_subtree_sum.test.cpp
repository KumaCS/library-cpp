#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "template/template.hpp"
#include "algebraic-structure/monoid.hpp"
#include "graph/graph.hpp"
#include "tree/tree-vertex-set-subtree-prod.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<long long> a(n);
  in(a);
  GraphUnweighted g(n);
  rep(x, 1, n) {
    int p;
    in(p);
    g.add_edge(p, x);
  }
  TreeVertexSetSubtreeProd<AddMonoid<long long>> ds(g, a);
  while (q--) {
    int type, x;
    in(type, x);
    if (type == 0) {
      long long v;
      in(v);
      ds.apply(x, v);
    } else {
      out(ds.prod(x));
    }
  }
}
