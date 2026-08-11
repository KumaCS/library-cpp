#pragma once
#include "algebraic-structure/magma.hpp"

template <class M>
REQUIRES(Magma<M>)
struct SparseTable {
  using T = typename M::value_type;

 private:
  int n;
  vector<vector<T>> st;

 public:
  SparseTable() : n(0) {}
  SparseTable(const vector<T>& arr) {
    n = arr.size();
    int log = 1;
    while (n >> log) log++;
    st = vector<vector<T>>(log);
    st[0] = vector<T>(arr.begin(), arr.end());
    for (int k = 1; k < log; k++) {
      const auto& stp = st[k - 1];
      auto sti = vector<T>(n - (1 << k) + 1);
      for (int i = 0; i < (int)sti.size(); i++)
        sti[i] = M::op(stp[i], stp[i + (1 << (k - 1))]);
      st[k] = move(sti);
    }
  }
  T prod(int l, int r) const  // [l,r)
  {
    assert(0 <= l && l < r && r <= n);
    int j = bit_width(static_cast<unsigned int>(r - l)) - 1;
    return M::op(st[j][l], st[j][r - (1 << j)]);
  }
};
