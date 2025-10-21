#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "template/template.hpp"
#include "math/floor-monoid-product.hpp"

struct T {
  ull x, y, z;
};
T op(T a, T b) { return T{a.x + b.x, a.y + b.y, a.y * b.x + a.z + b.z}; }
T e() { return T{0, 0, 0}; }

int main() {
  int t;
  in(t);
  T x{1, 0, 0}, y{0, 1, 0};
  while (t--) {
    ull n, m, a, b;
    in(n, m, a, b);
    ull sum = FloorMonoidProduct<T, op, e>(n, m, a, b, x, y).z;
    cout << sum << "\n";
  }
}