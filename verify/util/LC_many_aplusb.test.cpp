#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "template/template.hpp"
#include "util/fastio.hpp"

FastIO::InStream is;
FastIO::OutStream os;

int main() {
  unsigned int t;
  is >> t;
  while (t--) {
    unsigned long long a, b;
    is >> a >> b;
    os << (a + b) << '\n';
  }
}
