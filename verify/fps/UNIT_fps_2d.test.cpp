#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "modint/modint.hpp"
using mint = ModInt<998244353>;
#include "fps/fps-2d-ntt-friendly.hpp"
using fps2d = FormalPowerSeries2D<mint>;

fps2d exp_naive(const fps2d& f) {
  int n = f.height(), m = f.width();
  fps2d g(n, m);
  g[0][0] = 1;
  for (int s = 1; s <= n + m - 2; s++) {
    for (int i = 0; i < n; i++) {
      int j = s - i;
      if (j < 0 || j >= m) continue;
      for (int x = 0; x <= i; x++) {
        for (int y = 0; y <= j; y++) {
          if (x + y > 0) g[i][j] += mint(x + y) * f[x][y] * g[i - x][j - y];
        }
      }
      g[i][j] /= mint(i + j);
    }
  }
  return g;
}

int main() {
  {
    fps2d f{{1, 2, 3}, {4, 5, 6}};
    auto g = f.shift(2, 1);
    assert(g.height() == 4 && g.width() == 4);
    for (int i = 0; i < g.height(); i++) {
      for (int j = 0; j < g.width(); j++) {
        mint expected = i >= 2 && j >= 1 ? f[i - 2][j - 1] : mint(0);
        assert(g[i][j] == expected);
      }
    }
    assert(f.shift(0, 0) == f);
    assert(fps2d{}.shift(2, 1).empty());
  }

  mt19937 rng(0);
  for (int n = 1; n <= 10; n++) {
    for (int m = 1; m <= 10; m++) {
      fps2d f(n, m);
      for (auto& row : f)
        for (auto& x : row) x = rng();
      f[0][0] = 0;
      fps2d g = f.exp();
      assert(g == exp_naive(f));
      assert(g.log() == f);
      g[0][0] = 1;
      assert(g.log().exp() == g);
    }
  }

  int a, b;
  in(a, b);
  out(a + b);
}
