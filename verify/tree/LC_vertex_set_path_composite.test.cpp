#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "modint/modint.hpp"
#include "segment-tree/segment-tree.hpp"
#include "tree/heavy-light-decomposition.hpp"

using mint = ModInt998244353;
struct F {
  mint a, b;
  mint eval(mint x) const { return a * x + b; }
};
struct CompositeMonoid {
  using value_type = F;
  static F op(F f, F g) { return {f.a * g.a, f.b * g.a + g.b}; }
  static F e() { return {1, 0}; }
};
struct ReverseCompositeMonoid {
  using value_type = F;
  static F op(F f, F g) { return CompositeMonoid::op(g, f); }
  static F e() { return CompositeMonoid::e(); }
};

int main() {
  int n, q;
  in(n, q);
  vector<F> f(n);
  rep(x, 0, n) in(f[x].a, f[x].b);
  GraphUnweighted g(n);
  rep(i, 0, n - 1) {
    int u, v;
    in(u, v);
    g.add_edge(u, v);
  }
  HeavyLightDecomposition hld(g);
  vector<F> arranged(n);
  rep(x, 0, n) arranged[hld.pos[x]] = f[x];
  SegmentTree<CompositeMonoid> seg(arranged);
  SegmentTree<ReverseCompositeMonoid> rseg(arranged);
  while (q--) {
    int type;
    in(type);
    if (type == 0) {
      int p;
      F value;
      in(p, value.a, value.b);
      seg.set(hld.pos[p], value);
      rseg.set(hld.pos[p], value);
    } else {
      int u, v;
      mint x;
      in(u, v, x);
      F prod = CompositeMonoid::e();
      hld.path(u, v, [&](int l, int r, bool rev) {
        F part = rev ? rseg.prod(l, r) : seg.prod(l, r);
        prod = CompositeMonoid::op(prod, part);
      });
      out(prod.eval(x));
    }
  }
}
