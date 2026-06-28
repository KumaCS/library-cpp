#pragma once

template <class T>
struct SlopeTrick {
  const T INF = numeric_limits<T>::max() / 3;
  T min_f;
  priority_queue<T, vector<T>, less<> > pq_l;
  priority_queue<T, vector<T>, greater<> > pq_r;
  T add_l, add_r;
  SlopeTrick() : min_f(0), add_l(0), add_r(0) {}
  T get_min() const { return min_f; }
  pair<T, T> get_min_range() const { return {top_l(), top_r()}; }
  // f(x) += a
  void add_const(const T& a) { min_f += a; }
  // f(x) += max(0, x - a)
  void add_x_minus_a(const T& a) {
    min_f += max(T(0), top_l() - a);
    push_l(a);
    push_r(pop_l());
  }
  // f(x) += max(a - x, 0)
  void add_a_minus_x(const T& a) {
    min_f += max(T(0), a - top_r());
    push_r(a);
    push_l(pop_r());
  }
  // f(x) += abs(x - a)
  void add_abs(const T& a) {
    add_a_minus_x(a);
    add_x_minus_a(a);
  }
  // f(x) <- min_{y <= x} f(y)
  // \/ -> \_
  void clear_right() {
    while (!pq_r.empty()) pq_r.pop();
  }
  // f(x) <- min_{x <= y} f(y)
  // \/ -> _/
  void clear_left() {
    while (!pq_l.empty()) pq_l.pop();
  }
  // f(x) <- min_{x-b <= y <= x-a} f(y)
  // \/ -> \_/
  void shift(const T& a, const T& b) {
    assert(a <= b);
    add_l += a;
    add_r += b;
  }

  T get_destructive(const T& x) {
    T ret = min_f;
    while (!pq_l.empty()) ret += max(T(0), pop_l() - x);
    while (!pq_r.empty()) ret += max(T(0), x - pop_r());
    return ret;
  }
  void merge(SlopeTrick& st) {
    if (st.size() > size()) {
      swap(st.pq_l, pq_l);
      swap(st.pq_r, pq_r);
      swap(st.add_l, add_l);
      swap(st.add_r, add_r);
      swap(st.min_f, min_f);
    }
    while (!st.pq_r.empty()) add_x_minus_a(st.pop_r());
    while (!st.pq_l.empty()) add_a_minus_x(st.pop_l());
    min_f += st.min_f;
  }

 private:
  void push_r(const T& a) { pq_r.push(a - add_r); }
  T top_r() const { return pq_r.empty() ? INF : pq_r.top() + add_r; }
  T pop_r() {
    T val = top_r();
    if (!pq_r.empty()) pq_r.pop();
    return val;
  }
  void push_l(const T& a) { pq_l.push(a - add_l); }
  T top_l() const { return pq_l.empty() ? -INF : pq_l.top() + add_l; }
  T pop_l() {
    T val = top_l();
    if (!pq_l.empty()) pq_l.pop();
    return val;
  }
  size_t size() { return pq_l.size() + pq_r.size(); }
};

/**
 * @brief Slope Trick
 * @docs docs/data-structure/slope-trick.md
 */
