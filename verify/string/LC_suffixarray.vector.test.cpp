#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "template/template.hpp"
#include "string/suffix-array.hpp"

int main() {
  string s;
  in(s);
  vector<int> a(s.begin(), s.end());
  auto sa = SuffixArray(a, 255);
  for (auto& x : a) x -= 128;
  assert(sa == SuffixArray(a));
  out(sa);
}
