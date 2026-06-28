#pragma once
#include "algebraic-structure/monoid.hpp"

#ifdef __cpp_concepts
template <class A>
concept MonoidAction = Monoid<typename A::value_monoid> && Monoid<typename A::operator_monoid> && requires(typename A::value_monoid::value_type x, typename A::operator_monoid::value_type f) {
  typename A::value_monoid;
  typename A::operator_monoid;
  { A::mapping(f, x) } -> same_as<typename A::value_monoid::value_type>;
};
#endif
