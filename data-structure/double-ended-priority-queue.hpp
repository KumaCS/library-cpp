#pragma once

template <class T>
struct DoubleEndedPriorityQueue {
  vector<T> d;
  DoubleEndedPriorityQueue() {}
  DoubleEndedPriorityQueue(const vector<T>& _d) : d(_d) { make_heap(); }
  template <class Iter>
  DoubleEndedPriorityQueue(Iter first, Iter last) : d(first, last) { make_heap(); }

  int size() const { return d.size(); }
  bool empty() const { return d.empty(); }
  void push(const T& x) { d.push_back(x), up(d.size() - 1); }
  void pop_min() {
    if (d.size() <= 2u)
      d.pop_back();
    else {
      swap(d[1], d.back());
      d.pop_back();
      up(down(1));
    }
  }
  void pop_max() {
    if (d.size() <= 1u)
      d.pop_back();
    else {
      swap(d[0], d.back());
      d.pop_back();
      up(down(0));
    }
  }
  const T& get_min() const { return d.size() <= 1u ? d[0] : d[1]; }
  const T& get_max() const { return d[0]; }

 private:
  void make_heap() {
    for (int i = d.size() - 1; i >= 0; i--) {
      if ((i & 1) && d[i - 1] < d[i]) swap(d[i - 1], d[i]);
      up(down(i), i);
    }
  }
  inline int parent(int k) const { return ((k >> 1) - 1) & ~1; }
  int down(int k) {
    int n = d.size();
    if (k & 1) {  // min heap
      while (2 * k + 1 < n) {
        int c = 2 * k + 1;
        if (c + 2 < n && d[c] > d[c + 2]) c += 2;
        if (d[k] > d[c])
          swap(d[k], d[c]), k = c;
        else
          break;
      }
    } else {  // max heap
      while (2 * k + 2 < n) {
        int c = 2 * k + 2;
        if (c + 2 < n && d[c] < d[c + 2]) c += 2;
        if (d[k] < d[c])
          swap(d[k], d[c]), k = c;
        else
          break;
      }
    }
    return k;
  }
  int up(int k, int root = 1) {
    if ((k | 1) < (int)d.size() && d[k & ~1] < d[k | 1]) swap(d[k & ~1], d[k | 1]), k ^= 1;
    int p;
    while (root < k && d[p = parent(k)] < d[k]) swap(d[p], d[k]), k = p;        // max heap
    while (root < k && d[k] < d[p = (parent(k) | 1)]) swap(d[p], d[k]), k = p;  // min heap
    return k;
  }
};

/**
 * @brief Double Ended Priority Queue
 * @docs docs/data-structure/double-ended-priority-queue.md
 */