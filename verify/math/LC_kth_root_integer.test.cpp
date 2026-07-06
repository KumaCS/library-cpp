#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "template/template.hpp"
#include "math/util.hpp"

int main() {
  int t;
  in(t);
  while (t--) {
    unsigned long long a;
    int k;
    in(a, k);
    out(Math::floor_root_unsigned(a, k));
  }
}
