#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "data-structure/simple-queue.hpp"

void test() {
  SimpleQueue<int> q;
  queue<int> expected;
  rep(i, 0, 10000) {
    if (expected.empty() || i % 3 != 0) {
      q.push(i * 17);
      expected.push(i * 17);
    } else {
      assert(!q.empty());
      assert(q.front() == expected.front());
      q.pop();
      expected.pop();
    }
    assert(q.size() == (int)expected.size());
    assert(q.empty() == expected.empty());
  }
  q.clear();
  assert(q.empty());
  q.reserve(100);
  q.push(42);
  assert(q.front() == 42);
}

int main() {
  test();

  int a, b;
  in(a, b);
  out(a + b);
}
