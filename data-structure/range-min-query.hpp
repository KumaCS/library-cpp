#pragma once

#include "algebraic-structure/magma.hpp"
#include "data-structure/sparse-table.hpp"

template <class T, int LOG = 4>
struct RangeMinQuery {
 private:
  static constexpr int MASK = (1 << LOG) - 1;
  int n;
  vector<T> data, pre, suf;
  vector<unsigned int> upd;
  SparseTable<MinMagma<T>> st;
  void chmin(T& a, const T& b) {
    if (a > b) a = b;
  }

 public:
  RangeMinQuery() : n(0) {}
  RangeMinQuery(const vector<T>& ar) : n(ar.size()), data(ar), pre(ar), suf(ar), upd(n) {
    for (int i = 1; i < n; i++)
      if (i & MASK) chmin(pre[i], pre[i - 1]);
    for (int i = n - 1; i > 0; i--)
      if (i & MASK) chmin(suf[i - 1], suf[i]);
    const int m = n >> LOG;
    vector<T> b(m);
    for (int i = 0; i < m; i++) b[i] = suf[i << LOG];
    st = SparseTable<MinMagma<T>>(b);
    vector<int> stk(1 << LOG);
    int k = 0, f = 0;
    for (int i = 0; i < n; i++) {
      if ((i & MASK) == 0) k = 0, f = 0;
      while (k > 0 && ar[stk[k - 1]] >= ar[i]) f &= ~(1u << (stk[--k] & MASK));
      stk[k++] = i;
      f |= 1u << (i & MASK);
      upd[i] = f;
    }
  }
  T query(int l, int r)  // [l,r)
  {
    assert(0 <= l && l < r && r <= n);
    r--;
    int a = l >> LOG, b = r >> LOG;
    if (a + 1 < b) {
      T x = st.prod(a + 1, b);
      chmin(x, suf[l]);
      chmin(x, pre[r]);
      return x;
    } else if (a + 1 == b) {
      T x = suf[l];
      chmin(x, pre[r]);
      return x;
    } else {
      return data[l + __builtin_ctz(upd[r] >> (l & MASK))];
    }
  }
};

/**
 * @brief Range Minimum Query
 * @docs docs/data-structure/range-min-query.md
 */
