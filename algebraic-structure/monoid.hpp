#pragma once
#include "algebraic-structure/magma.hpp"

#ifdef __cpp_concepts
template <class M>
concept Monoid = Magma<M> && requires {
  { M::e() } -> same_as<typename M::value_type>;
};
#endif

template <class T>
struct AddMonoid {
  using value_type = T;
  static T op(T x, T y) { return x + y; }
  static T e() { return T(0); }
};
template <class T>
struct MulMonoid {
  using value_type = T;
  static T op(T x, T y) { return x * y; }
  static T e() { return T(1); }
};
template <class T, T id>
struct MaxMonoid {
  using value_type = T;
  static T op(T x, T y) { return x > y ? x : y; }
  static T e() { return id; }
};
template <class T, T id>
struct MinMonoid {
  using value_type = T;
  static T op(T x, T y) { return x < y ? x : y; }
  static T e() { return id; }
};
