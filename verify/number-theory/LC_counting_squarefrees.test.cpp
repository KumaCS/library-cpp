#define PROBLEM "https://judge.yosupo.jp/problem/counting_squarefrees"

#include "template/template.hpp"
#include "number-theory/count-square-free.hpp"

int main() {
  ll n;
  in(n);
  out(CountSquareFree(n));
}
