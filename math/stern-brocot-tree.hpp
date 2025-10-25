#pragma once

template <class T>
struct SternBrocotTreeNode {
  using Node = SternBrocotTreeNode;
  T la, lb, a, b, ra, rb;
  vector<T> seq;
  SternBrocotTreeNode() : la(0), lb(1), a(1), b(1), ra(1), rb(0) {}
  SternBrocotTreeNode(T x, T y) : SternBrocotTreeNode() {
    assert(x > 0 && y > 0);
    T g = gcd(x, y);
    x /= g, y /= g;
    bool is_right = true;
    while (x > 0 && y > 0) {
      T d = x / y;
      x -= d * y;
      if (is_right)
        go_right(d - (x == 0 ? 1 : 0));
      else
        go_left(d - (x == 0 ? 1 : 0));
      swap(x, y);
      is_right = !is_right;
    }
  }
  SternBrocotTreeNode(pair<T, T> p) : SternBrocotTreeNode(p.first, p.second) {}
  SternBrocotTreeNode(const vector<T> seq_) {
    for (auto& v : seq_) {
      assert(v != 0);
      if (v > 0)
        go_right(v);
      else
        go_left(v);
    }
    assert(seq == seq_);
  }
  pair<T, T> get() const { return {a, b}; }
  pair<T, T> lower_bound() const { return {la, lb}; }
  pair<T, T> upper_bound() const { return {ra, rb}; }

  void go_left(const T d = 1) {
    if (d <= 0) return;
    if (seq.empty() || seq.back() > 0) seq.push_back(0);
    seq.back() -= d;
    ra += la * d, rb += lb * d;
    a = la + ra, b = lb + rb;
  }
  void go_right(const T d = 1) {
    if (d <= 0) return;
    if (seq.empty() || seq.back() < 0) seq.push_back(0);
    seq.back() += d;
    la += ra * d, lb += rb * d;
    a = la + ra, b = lb + rb;
  }
  T depth() const {
    T d = 0;
    for (auto& v : seq) d += abs(v);
    return d;
  }
  static Node lca(const Node& x, const Node& y) {
    Node res;
    for (int i = 0; i < min(x.seq.size(), y.seq.size()); i++) {
      T d1 = x.seq[i], d2 = y.seq[i];
      if ((d1 > 0) != (d2 > 0)) break;
      if (d1 > 0)
        res.go_right(min(d1, d2));
      else
        res.go_left(min(-d1, -d2));
      if (d1 != d2) break;
    }
    return res;
  }
  bool go_parent(T d = 1) {
    if (d <= 0) return true;
    while (d > 0) {
      if (seq.empty()) return false;
      T d1 = min(d, abs(seq.back()));
      if (seq.back() > 0) {
        la -= ra * d1, lb -= rb * d1;
        seq.back() -= d1;
      } else {
        ra -= la * d1, rb -= lb * d1;
        seq.back() += d1;
      }
      a = la + ra, b = lb + rb;
      if (seq.back() <= 0) seq.pop_back();
      d -= d1;
    }
    return true;
  }
  template <class F>
  static Node binary_search(T n, F f) {
    Node res;
    while (true) {
      if (!f(res.a, res.b)) {
        T ok = 0, ng = min(res.la > 0 ? (n - res.ra) / res.la : n, res.lb > 0 ? (n - res.rb) / res.lb : n) + 1;
        while (ng - ok > 1) {
          T mid = (ok + ng) / 2;
          (!f(mid * res.la + res.ra, mid * res.lb + res.rb) ? ok : ng) = mid;
        }
        if (ok == 0) return res;
        res.go_left(ok);
      } else {
        T ok = 0, ng = min(res.ra > 0 ? (n - res.la) / res.ra : n, res.rb > 0 ? (n - res.lb) / res.rb : n) + 1;
        while (ng - ok > 1) {
          T mid = (ok + ng) / 2;
          (f(res.la + mid * res.ra, res.lb + mid * res.rb) ? ok : ng) = mid;
        }
        if (ok == 0) return res;
        res.go_left(ok);
      }
    }
  }
};

/**
 * @brief Stern-Brocot Tree
 * @docs docs/math/stern-brocot-tree.md
 */