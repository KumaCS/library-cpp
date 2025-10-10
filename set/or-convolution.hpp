#pragma once

#include "./zeta-mobius-transform.hpp"

template <class T>
vector<T> OrConvolution(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  SubsetZetaTransform(a);
  SubsetZetaTransform(b);
  for (int i = 0; i < a.size(); i++) a[i] *= b[i];
  SubsetMobiusTransform(a);
  return a;
}