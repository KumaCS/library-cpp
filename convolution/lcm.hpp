#pragma once

#include "../number-theory/divisor-multiple-transform.hpp"

template <class T>
vector<T> LcmConvolution(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  if (a.empty()) return {};
  DivisorZetaTransform(a);
  DivisorZetaTransform(b);
  for (int i = 0; i < a.size(); i++) a[i] *= b[i];
  DivisorMobiusTransform(a);
  return a;
}

/**
 * @brief lcm 畳み込み
 * @docs docs/convolution/gcd-lcm.md
 */