#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "template/template.hpp"
#include "number-theory/primitive-root.hpp"

int main() {
  int Q;
  in(Q);
  while (Q--) {
    long long p;
    in(p);
    out(PrimitiveRoot(p));
  }
}
