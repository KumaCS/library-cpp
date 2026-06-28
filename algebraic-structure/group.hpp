#pragma once
#include "algebraic-structure/monoid.hpp"

#ifdef __cpp_concepts
template <class G>
concept Group = Monoid<G> && requires(typename G::value_type x) {
  { G::inv(x) } -> same_as<typename G::value_type>;
};
#endif

template <class T>
struct AddGroup {
  using value_type = T;
  static T op(T x, T y) { return x + y; }
  static T e() { return T(0); }
  static T inv(T x) { return -x; }
};
template <class T>
struct MulGroup {
  using value_type = T;
  static T op(T x, T y) { return x * y; }
  static T e() { return T(1); }
  static T inv(T x) { return T(1) / x; }
};
