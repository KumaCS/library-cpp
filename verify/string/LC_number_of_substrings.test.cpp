#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "template/template.hpp"
#include "string/suffix-array.hpp"
#include "string/lcp-array.hpp"

int main() {
  string s;
  in(s);
  auto sa = SuffixArray(s);
  auto lcp = LCPArray(s, sa);
  assert(lcp == LCPArray(vector<char>(s.begin(), s.end()), sa));
  long long ans = (long long)s.size() * (s.size() + 1) / 2;
  for (int x : lcp) ans -= x;
  out(ans);
}
