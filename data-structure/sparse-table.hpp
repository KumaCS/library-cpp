#pragma once

template <class T, T (*op)(T, T)>
struct SparseTable {
 private:
  int n;
  vector<vector<T>> st;

 public:
  SparseTable() {}
  SparseTable(const vector<T> &arr) {
    n = arr.size();
    int log = 1;
    while (n >> log) log++;
    st = vector<vector<T>>(log);
    st[0] = vector<T>(arr.begin(), arr.end());
    for (int k = 1; k < log; k++) {
      auto stp = st[k - 1];
      auto sti = vector<T>(n - (1 << k) + 1);
      for (int i = 0; i < sti.size(); i++)
        sti[i] = op(stp[i], stp[i + (1 << (k - 1))]);
      st[k] = sti;
    }
  }
  T prod(int l, int r)  // [l,r)
  {
    assert(0 <= l && l < r && r <= n);
    int j = 0;
    while ((2 << j) <= r - l) j++;
    return op(st[j][l], st[j][r - (1 << j)]);
  }
};