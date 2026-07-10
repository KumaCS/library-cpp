#pragma once

#include "algebraic-structure/monoid.hpp"

template <class M>
REQUIRES(Monoid<M>)
struct FoldableQueue {
  using T = typename M::value_type;

  queue<T> front_prod;
  vector<T> back_val;
  T back_prod;
  void push(const T& v) {
    back_prod = back_val.empty() ? v : M::op(back_prod, v);
    back_val.push_back(v);
  }
  void pop() {
    if (front_prod.empty()) {
      for (int i = (int)back_val.size() - 1; i > 0; i--)
        back_val[i - 1] = M::op(back_val[i - 1], back_val[i]);
      for (int i = 0; i < (int)back_val.size(); i++)
        front_prod.push(back_val[i]);
      back_val.clear();
    }
    front_prod.pop();
  }
  size_t size() const { return front_prod.size() + back_val.size(); }
  bool empty() const { return front_prod.empty() && back_val.empty(); }
  T all_prod() const {
    if (front_prod.empty() && back_val.empty()) return M::e();
    if (front_prod.empty()) return back_prod;
    if (back_val.empty()) return front_prod.front();
    return M::op(front_prod.front(), back_prod);
  }
};

/**
 * @brief Foldable Queue
 * @docs docs/data-structure/foldable-queue.md
 */
