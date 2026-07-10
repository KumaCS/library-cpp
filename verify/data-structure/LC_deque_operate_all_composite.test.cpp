#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "template/template.hpp"
#include "data-structure/foldable-deque.hpp"
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
  FoldableDeque<CompositeMonoid> deq;
  while (q--) {
    int t;
    in(t);
    if (t == 0) {
      mint a, b;
      in(a, b);
      deq.push_front({a, b});
    } else if (t == 1) {
      mint a, b;
      in(a, b);
      deq.push_back({a, b});
    } else if (t == 2) {
      deq.pop_front();
    } else if (t == 3) {
      deq.pop_back();
    } else {
      mint x;
      in(x);
      out(deq.all_prod().eval(x));
    }
  }
}
