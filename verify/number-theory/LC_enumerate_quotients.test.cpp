#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"

#include "template/template.hpp"
#include "number-theory/enumerate-quotients.hpp"

int main() {
  ll n;
  cin >> n;
  auto qs = EnumerateQuotients::table(n);
  cout << qs.size() << "\n";
  cout << qs << "\n";
}