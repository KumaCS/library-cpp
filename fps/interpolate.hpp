#pragma once
#include "modint/factorial.hpp"

// f(0),f(1),...,f(n-1) -> f(x)
template <class mint>
mint Interpolate(const vector<mint>& f, mint x) {
  int n = f.size();
  vector<mint> l(n, 1), r(n, 1);
  for (int i = 0; i + 1 < n; i++) l[i + 1] = l[i] * (x - i);
  for (int i = n - 1; i > 0; i--) r[i - 1] = r[i] * (x - i);
  using fact = Factorial<mint>;
  mint s = 0;
  for (int i = 0; i < n; i++) {
    mint v = f[i] * l[i] * r[i] * fact::fact_inv(i) * fact::fact_inv(n - 1 - i);
    if ((n - i) & 1)
      s += v;
    else
      s -= v;
  }
  return s;
}
/**
 * @brief Interpolate
 * @docs docs/fps/interpolate.md
 */