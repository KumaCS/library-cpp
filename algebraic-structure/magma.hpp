#pragma once
#include "algebraic-structure/util.hpp"

#ifdef __cpp_concepts
template <class M>
concept Magma = requires(typename M::value_type x, typename M::value_type y) {
  typename M::value_type;
  { M::op(x, y) } -> same_as<typename M::value_type>;
};
#endif

template <class T>
struct AddMagma {
  using value_type = T;
  static T op(T x, T y) { return x + y; }
};
template <class T>
struct MulMagma {
  using value_type = T;
  static T op(T x, T y) { return x * y; }
};
template <class T, T id>
struct MaxMagma {
  using value_type = T;
  static T op(T x, T y) { return x > y ? x : y; }
};
template <class T, T id>
struct MinMagma {
  using value_type = T;
  static T op(T x, T y) { return x < y ? x : y; }
};