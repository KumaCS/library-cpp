#pragma once

#include "../number-theory/divisor-multiple-transform.hpp"

template <class T>
vector<T> GcdConvolution(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  if (a.empty()) return {};
  MultipleZetaTransform(a);
  MultipleZetaTransform(b);
  for (int i = 0; i < a.size(); i++) a[i] *= b[i];
  MultipleMobiusTransform(a);
  return a;
}

/**
 * @brief gcd 畳み込み
 * @docs docs/convolution/gcd-lcm.md
 */