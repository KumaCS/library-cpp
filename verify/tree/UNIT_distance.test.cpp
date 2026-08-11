#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "graph/graph.hpp"
#include "tree/distance.hpp"
#include "util/xorshift.hpp"

void test_single_vertex() {
  GraphWeighted<long long> g(1);
  TreeDistance<long long> distance(g);
  assert(distance.size() == 1);
  assert(distance.dist(0, 0) == 0);
}

void test_random() {
  rep(loop, 0, 200) {
    int n = XORShift::xor32() % 30 + 1;
    GraphWeighted<long long> g(n);
    rep(x, 1, n) {
      int p = XORShift::xor32() % x;
      int w = (int)(XORShift::xor32() % 21) - 10;
      g.add_edge(x, p, w);
    }
    TreeDistance<long long> distance(g);
    rep(s, 0, n) {
      vector<long long> expected(n);
      stack<pair<int, int>> st;
      st.push({s, -1});
      while (!st.empty()) {
        auto [x, p] = st.top();
        st.pop();
        for (auto e : g[x]) {
          if (e.to == p) continue;
          expected[e.to] = expected[x] + e.weight;
          st.push({e.to, x});
        }
      }
      rep(t, 0, n) assert(distance.dist(s, t) == expected[t]);
    }
  }
}

int main() {
  test_single_vertex();
  test_random();

  int a, b;
  in(a, b);
  out(a + b);
}
