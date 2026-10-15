#pragma once
#include "binary-search-tree/rbst-base.hpp"

template <class I>
struct RBSTReversibleArrayLargeNode {
  typename RBSTBase<RBSTReversibleArrayLargeNode>::Ptr l, r;
  int cnt;
  I lx, rx, size;
  bool rev;
  // [lx, rx]
  RBSTReversibleArrayLargeNode(I lx = I{}, I rx = I{}) : l(), r(), cnt(1), lx(lx), rx(rx), size(node_size()), rev(false) {}
  I node_size() const { return lx <= rx ? rx - lx + 1 : lx - rx + 1; }
  I get_val(I k) const { return lx <= rx ? lx + k : lx - k; }
};

template <class I>
struct RBSTReversibleArrayLarge : RBSTBase<RBSTReversibleArrayLargeNode<I>> {
  using Node = RBSTReversibleArrayLargeNode<I>;
  using base = RBSTBase<Node>;
  using base::merge;
  using base::my_new;
  using typename base::Ptr;

  RBSTReversibleArrayLarge() = default;
  // [0,n)
  Ptr build(I n) { return n <= 0 ? nullptr : my_new(I(0), I(n - 1)); }
  inline I size(const Ptr t) const { return t ? t->size : I{}; }
  I get(const Ptr& t, I k) {
    push(t);
    I size_l = size(t->l);
    if (k < size_l) return get(t->l, k);
    k -= size_l;
    I size_m = t->node_size();
    if (k < size_m) return t->get_val(k);
    return get(t->r, k - size_m);
  }
  // [l,r)
  void reverse(Ptr& t, I l, I r) {
    if (l >= r) return;
    auto [tlm, tr] = split(t, r);
    auto [tl, tm] = split(tlm, l);
    toggle(tm);
    t = merge(merge(tl, tm), tr);
  }
  // [,k), [k,)
  pair<Ptr, Ptr> split(Ptr t, I k) {
    if (!t) return {nullptr, nullptr};
    push(t);
    I size_l = size(t->l);
    I size_m = t->node_size();
    if (k <= size_l) {
      auto [tl, tm] = split(t->l, k);
      t->l = tm;
      return {tl, update(t)};
    } else if (k < size_l + size_m) {
      I d = k - size_l;
      I lx = t->lx, rx = t->rx;
      Ptr tl, tr;
      if (lx < rx) {
        tl = my_new(lx, lx + d - 1);
        tr = my_new(lx + d, rx);
      } else {
        tl = my_new(lx, lx - (d - 1));
        tr = my_new(lx - d, rx);
      }
      tl->l = t->l;
      tr->r = t->r;
      return {update(tl), update(tr)};
    } else {
      auto [tm, tr] = split(t->r, k - size_l - size_m);
      t->r = tm;
      return {update(t), tr};
    }
  }
  vector<pair<I, I>> enumerate(Ptr t) {
    if (!t) return {};
    vector<pair<I, I>> res;
    enumerate(t, res);
    return res;
  }

 protected:
  Ptr update(Ptr t) override {
    t->cnt = 1;
    t->size = t->node_size();
    if (t->l) {
      t->cnt += t->l->cnt;
      t->size += t->l->size;
    }
    if (t->r) {
      t->cnt += t->r->cnt;
      t->size += t->r->size;
    }
    return t;
  }
  void push(Ptr t) override {
    if (!t->rev) return;
    if (t->l) toggle(t->l);
    if (t->r) toggle(t->r);
    t->rev = false;
  }

 private:
  void enumerate(Ptr t, vector<pair<I, I>>& res) {
    if (!t) return;
    push(t);
    enumerate(t->l, res);
    res.push_back({t->lx, t->rx});
    enumerate(t->r, res);
  }
  void toggle(Ptr t) {
    swap(t->l, t->r);
    swap(t->lx, t->rx);
    t->rev ^= true;
  }
};

/**
 * @brief 分割/反転可能な配列 (index を管理)
 * @docs docs/binary-search-tree/rbst-reversible-array-large.md
 */