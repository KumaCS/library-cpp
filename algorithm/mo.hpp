#pragma once

struct Mo {
  using F = function<void(int)>;
  int n;
  vector<int> left, right;
  Mo(int size) : n(size) {}
  void add_query(int l, int r) {  // [l,r)
    left.emplace_back(l);
    right.emplace_back(r);
  }
  void run(const F& add_left, const F& add_right, const F& del_left, const F& del_right, const F& query) {
    const int q = left.size();
    if (q == 0) return;
    const int width = max(1, (int)(n / sqrt(q)));
    vector<int> order(q);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      if (left[i] / width != left[j] / width) return left[i] < left[j];
      return right[i] < right[j];
    });
    int l = 0, r = 0;
    for (int i : order) {
      while (l > left[i]) add_left(--l);
      while (r < right[i]) add_right(r++);
      while (l < left[i]) del_left(l++);
      while (r > right[i]) del_right(--r);
      query(i);
    }
  }
  void run(const F& add, const F& del, const F& query) {
    run(add, add, del, del, query);
  }
};
