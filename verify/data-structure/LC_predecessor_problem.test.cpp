#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "template/template.hpp"
#include "data-structure/integer-set.hpp"

int main() {
  int n, q;
  in(n, q);
  string t;
  in(t);
  IntegerSet set(t);
  while (q--) {
    int type, k;
    in(type, k);
    if (type == 0)
      set.add(k);
    else if (type == 1)
      set.remove(k);
    else if (type == 2)
      out(set.contains(k));
    else if (type == 3)
      out(set.min(k));
    else if (type == 4)
      out(set.max(k));
  }
}