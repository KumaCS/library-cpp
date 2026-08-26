#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_D"

#include "template/template.hpp"
#include "string/aho-corasick.hpp"

int main() {
  string t;
  int q;
  in(t, q);
  AhoCorasick<'z' - '0' + 1, '0'> ac;
  rep(i, 0, q) {
    string p;
    in(p);
    ac.add(p);
  }
  ac.build();
  auto count = ac.match(t);
  rep(i, 0, q) out(count.contains(i));
}
