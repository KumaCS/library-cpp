#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "template/template.hpp"
#include "number-theory/enumerate-quotients.hpp"

int main() {
  ll n;
  in(n);
  auto qs = EnumerateQuotients::table(n);
  out(qs.size());
  out(qs);
}