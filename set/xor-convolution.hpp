#pragma once

#include "./hadamard-transform.hpp"

template <class T>
vector<T> XorConvolution(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  HadamardTransform(a);
  HadamardTransform(b);
  for (int i = 0; i < a.size(); i++) a[i] *= b[i];
  HadamardTransform(a, true);
  return a;
}