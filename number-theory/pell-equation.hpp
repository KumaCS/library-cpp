#pragma once

#include "number-theory/continued-fraction.hpp"

namespace PellEquation {
template <class I = long long>
pair<I, I> minimum_solution(I n) {
  auto res = ContinuedFraction::sqrt(n);
  vector<I> xs(res.prefix);
  for (auto v : res.cycle) xs.push_back(v);
  xs.pop_back();
  auto [a, b] = ContinuedFraction::calc(xs);
  if (xs.size() & 1) {
    I a1 = a * a + n * b * b, b1 = 2 * a * b;
    swap(a, a1);
    swap(b, b1);
  }
  return {a, b};
}
};  // namespace PellEquation

/**
 * @brief Pell 方程式
 * @docs docs/number-theory/pell-equation.md
 */
