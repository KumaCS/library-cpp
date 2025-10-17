#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "template/template.hpp"
#include "math/floor-sum.hpp"

int main() {
  int t;
  in(t);
  while (t--) {
    ull n, m, a, b;
    in(n, m, a, b);
    ull us = FloorSumUnsigned<ull>(n, m, a, b);
    ll s = FloorSum<ll>(ll(n), ll(m), ll(a), ll(b));
    assert(us == ull(s));
    cout << us << "\n";
  }
}