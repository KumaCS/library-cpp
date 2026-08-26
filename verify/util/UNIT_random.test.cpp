#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "util/random.hpp"

void test() {
  Random::gen.seed(123456789);
  rep(i, 0, 10000) {
    int x = Random::get(7);
    assert(0 <= x && x < 7);
    int y = Random::get(-5, 12);
    assert(-5 <= y && y < 12);
    double z = Random::uniform();
    assert(0 <= z && z < 1);
  }
  auto a = Random::get_vector(1000, 20, 30);
  for (int x : a) assert(20 <= x && x < 30);
  vector<int> p(1000);
  iota(p.begin(), p.end(), 0);
  Random::shuffle(p.begin(), p.end());
  auto q = p;
  sort(q.begin(), q.end());
  rep(i, 0, 1000) assert(q[i] == i);
}

int main() {
  test();
  int a, b;
  in(a, b);
  out(a + b);
}
