#pragma once
#include "binary-search-tree/rbst-base.hpp"

template <typename T>
struct RBSTArrayNode {
  typename RBSTBase<RBSTArrayNode>::Ptr l, r;
  T key;
  int cnt;
  RBSTArrayNode(const T& t = T()) : l(), r(), key(t), cnt(1) {}
};

template <class T>
struct RBSTArray : RBSTBase<RBSTArrayNode<T>> {
  using Node = RBSTArrayNode<T>;
  using base = RBSTBase<Node>;
  using base::merge;
  using base::split;
  using typename base::Ptr;

  RBSTArray() = default;
  T get(Ptr& t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    T v = y.first->key;
    t = merge(x.first, merge(y.first, y.second));
    return v;
  }
  void set(Ptr& t, int k, T v) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    y.first->key = v;
    t = merge(x.first, merge(y.first, y.second));
  }

 protected:
  Ptr update(Ptr t) override {
    t->cnt = 1;
    if (t->l) t->cnt += t->l->cnt;
    if (t->r) t->cnt += t->r->cnt;
    return t;
  }
  void push(Ptr t) override {}
};

/**
 * @brief 挿入/削除の可能な配列 (乱択二分探索木)
 */