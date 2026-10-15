#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "template/template.hpp"
#include "string/suffix-array.hpp"

int main() {
  string s;
  in(s);
  out(SuffixArray(s));
}
