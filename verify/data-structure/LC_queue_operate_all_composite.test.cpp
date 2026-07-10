#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "template/template.hpp"
#include "data-structure/foldable-queue.hpp"
#include "modint/modint.hpp"

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

int main() {
  int q;
  in(q);
  FoldableQueue<CompositeMonoid> que;
  while (q--) {
    int t;
    in(t);
    if (t == 0) {
      mint a, b;
      in(a, b);
      que.push({a, b});
    } else if (t == 1) {
      que.pop();
    } else {
      mint x;
      in(x);
      out(que.all_prod().eval(x));
    }
  }
}
