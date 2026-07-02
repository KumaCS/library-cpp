#pragma once

template <class T>
struct RangeAddRangePositiveSum {
  RangeAddRangePositiveSum() {}
  RangeAddRangePositiveSum(int n) : RangeAddRangePositiveSum(vector<T>(n)) {}
  RangeAddRangePositiveSum(const vector<T>& a) : N(a.size()), B(max(1, (int)sqrt(N))), M((N + B - 1) / B), data(a), sorted(a), sorted_sum(N + M), lazy(M) {
    for (int k = 0; k < M; k++) update_block(k);
  }
  void add(int l, int r, T v) {
    if (l >= r) return;
    int bl = l / B, br = (r - 1) / B;
    if (bl == br) {
      for (int i = l; i < r; i++) data[i] += v;
      update_block(bl);
    } else {
      if (bl * B != l) {
        bl++;
        int l1 = bl * B;
        while (l < l1) data[l++] += v;
        update_block(bl - 1);
      }
      if (r < min(N, (br + 1) * B)) {
        int r1 = br * B;
        while (r1 < r) data[--r] += v;
        update_block(br--);
      }
      for (int k = bl; k <= br; k++) lazy[k] += v;
    }
  }
  T sum(int l, int r) const {
    if (l >= r) return 0;
    T ret = 0;
    int bl = l / B, br = (r - 1) / B;
    if (bl == br) {
      for (int i = l; i < r; i++) ret += sum_point(i);
    } else {
      if (bl * B != l) {
        bl++;
        int l1 = bl * B;
        while (l < l1) ret += sum_point(l++);
      }
      if (r < min(N, (br + 1) * B)) {
        int r1 = br * B;
        while (r1 < r) ret += sum_point(--r);
        br--;
      }
      for (int k = bl; k <= br; k++) ret += sum_block(k);
    }
    return ret;
  }

 private:
  int N, B, M;
  vector<T> data, sorted, sorted_sum, lazy;
  void update_block(int k) {
    int l = B * k, r = min(N, l + B);
    int sz = r - l;
    copy(data.begin() + l, data.begin() + r, sorted.begin() + l);
    sort(sorted.begin() + l, sorted.begin() + r);
    auto it = sorted_sum.begin() + l + k;
    *it = 0;
    for (int i = 0; i < sz; i++)
      *(it + i + 1) = *(it + i) + sorted[l + i];
  }
  T sum_point(int x) const { return max<T>(0, data[x] + lazy[x / B]); }
  T sum_block(int k) const {
    int l = B * k, r = min(N, l + B);
    int sz = r - l;
    auto itl = sorted.begin() + l;
    int i = lower_bound(itl, itl + sz, -lazy[k]) - itl;
    int l1 = l + k, r1 = l1 + sz;
    return sorted_sum[r1] - sorted_sum[l1 + i] + lazy[k] * (sz - i);
  }
};
