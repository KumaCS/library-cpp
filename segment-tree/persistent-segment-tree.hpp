#pragma once

template <class T, T (*op)(T, T), T (*e)(), int MAX_NODES = 20000000>
struct PersistentSegmentTree {
  struct Node {
    Node *l, *r;
    T v;
  };

 private:
  int n;
  vector<Node> nodes;
  vector<Node*> roots;
  Node* make_node(const T& v) {
    nodes.push_back(Node{nullptr, nullptr, v});
    return &nodes.back();
  }
  Node* merge(Node* l, Node* r) {
    nodes.push_back(Node{l, r, op(l->v, r->v)});
    return &nodes.back();
  }
  Node* build(int l, int r, const vector<T>& v) {
    if (l + 1 == r) return make_node(v[l]);
    return merge(build(l, (l + r) / 2, v), build((l + r) / 2, r, v));
  }
  Node* set(Node* x, int l, int r, int p, const T& v) {
    if (l + 1 == r) return make_node(v);
    int m = (l + r) / 2;
    return p < m ? merge(set(x->l, l, m, p, v), x->r) : merge(x->l, set(x->r, m, r, p, v));
  }
  Node* apply(Node* x, int l, int r, int p, const T& v) {
    if (l + 1 == r) return make_node(op(x->v, v));
    int m = (l + r) / 2;
    return p < m ? merge(apply(x->l, l, m, p, v), x->r) : merge(x->l, apply(x->r, m, r, p, v));
  }
  T prod(Node* x, int xl, int xr, int l, int r) {
    if (x == nullptr) return e();
    if (r <= xl || xr <= l) return e();
    if (l <= xl && xr <= r) return x->v;
    int xm = (xl + xr) / 2;
    return op(prod(x->l, xl, xm, l, r), prod(x->r, xm, xr, l, r));
  }

 public:
  PersistentSegmentTree() : PersistentSegmentTree(1) {}
  PersistentSegmentTree(int sz) : PersistentSegmentTree(vector<T>(sz, e())) {}
  PersistentSegmentTree(const vector<T>& v) : n(v.size()) {
    assert(n > 0);
    roots.reserve(300000);
    nodes.reserve(MAX_NODES);
    roots.push_back(build(0, n, v));
  }

  int get_recent_time() { return (int)roots.size() - 1; }
  Node* get_root(int time = -1) {
    if (time == -1) return roots.back();
    return roots[time];
  }

  T get(Node* x, int p) {
    assert(0 <= p && p < n);
    int l = 0, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (p < m) {
        x = x->l;
        r = m;
      } else {
        x = x->r;
        l = m;
      }
    }
    return x->v;
  }
  T get(int time, int p) { return get(roots[time], p); }
  T get(int p) { return get(roots.back(), p); }

  Node* set(Node* x, int p, T v) {
    assert(0 <= p && p < n);
    roots.push_back(set(x, 0, n, p, v));
    return roots.back();
  }
  Node* set(int time, int p, T v) { return set(roots[time], p, v); }
  Node* set(int p, T v) { return set(roots.back(), p, v); }

  Node* apply(Node* x, int p, T v) {
    assert(0 <= p && p < n);
    roots.push_back(apply(x, 0, n, p, v));
    return roots.back();
  }
  Node* apply(int time, int p, T v) { return apply(roots[time], p, v); }
  Node* apply(int p, T v) { return apply(roots.back(), p, v); }

  T all_prod(Node* x) { return x->v; }
  T all_prod(int time) { return roots[time]->v; }
  T all_prod() { return roots.back()->v; }

  T prod(Node* x, int l, int r) {
    if (l >= r) return e();
    assert(0 <= l && l <= r && r <= n);
    return prod(x, 0, n, l, r);
  }
  T prod(int time, int l, int r) { return prod(roots[time], l, r); }
  T prod(int l, int r) { return prod(roots.back(), l, r); }
};

/**
 * @brief Persistent Segment Tree
 * @docs docs/segment-tree/persistent-segment-tree.md
 */
