#pragma once

#include "algebraic-structure/monoid.hpp"

template <class M>
REQUIRES(Monoid<M>)
struct FoldableDeque {
  using T = typename M::value_type;

 private:
  struct Node {
    T val, prod;
  };
  vector<Node> front_stack, back_stack;
  void push_front_stack(const T& v) {
    T prod = front_stack.empty() ? v : M::op(v, front_stack.back().prod);
    front_stack.push_back({v, prod});
  }
  void push_back_stack(const T& v) {
    T prod = back_stack.empty() ? v : M::op(back_stack.back().prod, v);
    back_stack.push_back({v, prod});
  }
  void rebuild_front() {
    int n = back_stack.size();
    int k = (n + 1) / 2;
    vector<T> a(n);
    for (int i = 0; i < n; i++) a[i] = back_stack[i].val;
    front_stack.clear();
    back_stack.clear();
    for (int i = k - 1; i >= 0; i--) push_front_stack(a[i]);
    for (int i = k; i < n; i++) push_back_stack(a[i]);
  }
  void rebuild_back() {
    int n = front_stack.size();
    int k = (n + 1) / 2;
    vector<T> a(n);
    for (int i = 0; i < n; i++) a[i] = front_stack[n - 1 - i].val;
    front_stack.clear();
    back_stack.clear();
    for (int i = 0; i < n - k; i++) push_front_stack(a[n - k - 1 - i]);
    for (int i = n - k; i < n; i++) push_back_stack(a[i]);
  }

 public:
  FoldableDeque() {}

  size_t size() const { return front_stack.size() + back_stack.size(); }
  bool empty() const { return front_stack.empty() && back_stack.empty(); }
  void push_front(const T& v) { push_front_stack(v); }
  void push_back(const T& v) { push_back_stack(v); }
  void pop_front() {
    if (front_stack.empty()) rebuild_front();
    front_stack.pop_back();
  }
  void pop_back() {
    if (back_stack.empty()) rebuild_back();
    back_stack.pop_back();
  }
  const T& front() {
    if (front_stack.empty()) rebuild_front();
    return front_stack.back().val;
  }
  const T& back() {
    if (back_stack.empty()) rebuild_back();
    return back_stack.back().val;
  }
  T all_prod() const {
    if (front_stack.empty() && back_stack.empty()) return M::e();
    if (front_stack.empty()) return back_stack.back().prod;
    if (back_stack.empty()) return front_stack.back().prod;
    return M::op(front_stack.back().prod, back_stack.back().prod);
  }
};

/**
 * @brief Foldable Deque
 * @docs docs/data-structure/foldable-deque.md
 */
