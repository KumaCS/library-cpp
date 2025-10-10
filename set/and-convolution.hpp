#pragma once

#include "./zeta-mobius-transform.hpp"

template <class T>
vector<T> AndConvolution(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  SupsetZetaTransform(a);
  SupsetZetaTransform(b);
  for (int i = 0; i < a.size(); i++) a[i] *= b[i];
  SupsetMobiusTransform(a);
  return a;
}