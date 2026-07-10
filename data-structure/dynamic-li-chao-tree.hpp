#pragma once

template <class T>
struct DynamicLiChaoTree {
  struct Line {
    T a, b;
    Line() : a(0), b(0) {}
    Line(T a_, T b_) : a(a_), b(b_) {}
    T get(T x) const { return a * x + b; }
  };

 private:
  struct Node {
    Line line;
    int l, r;
    Node(Line line_) : line(line_), l(-1), r(-1) {}
  };

  T xl, xr, inf;
  vector<Node> nodes;
  int root;

 public:
  DynamicLiChaoTree() : DynamicLiChaoTree(0, 1) {}
  DynamicLiChaoTree(T xl_, T xr_, T inf_ = numeric_limits<T>::max() / 4)
      : xl(xl_), xr(xr_), inf(inf_), root(-1) {
    assert(xl < xr);
  }

  void add_line(T a, T b) { add_line(Line(a, b)); }
  void add_line(Line line) { root = add_line(root, xl, xr, line); }
  void add_segment(T l, T r, T a, T b) { add_segment(l, r, Line(a, b)); }
  void add_segment(T l, T r, Line line) {
    l = max(l, xl);
    r = min(r, xr);
    if (l >= r) return;
    root = add_segment(root, xl, xr, l, r, line);
  }
  T get(T x) const {
    assert(xl <= x && x < xr);
    return get(root, xl, xr, x);
  }
  T query(T x) const { return get(x); }
  int node_count() const { return nodes.size(); }

 private:
  int new_node(Line line) {
    nodes.emplace_back(line);
    return (int)nodes.size() - 1;
  }
  int add_line(int k, T l, T r, Line line) {
    if (k == -1) {
      return new_node(line);
    }
    T m = l + (r - l) / 2;
    T rr = r - 1;
    Line low = nodes[k].line, high = line;
    if (low.get(m) > high.get(m)) swap(low, high);
    nodes[k].line = low;
    if (r - l == 1) return k;
    if (low.get(l) > high.get(l)) {
      nodes[k].l = add_line(nodes[k].l, l, m, high);
    } else if (low.get(rr) > high.get(rr)) {
      nodes[k].r = add_line(nodes[k].r, m, r, high);
    }
    return k;
  }
  int add_segment(int k, T l, T r, T ql, T qr, Line line) {
    if (qr <= l || r <= ql) return k;
    if (ql <= l && r <= qr) {
      return add_line(k, l, r, line);
    }
    if (k == -1) k = new_node(Line(0, inf));
    T m = l + (r - l) / 2;
    nodes[k].l = add_segment(nodes[k].l, l, m, ql, qr, line);
    nodes[k].r = add_segment(nodes[k].r, m, r, ql, qr, line);
    return k;
  }
  T get(int k, T l, T r, T x) const {
    if (k == -1) return inf;
    T ret = nodes[k].line.get(x);
    if (r - l == 1) return ret;
    T m = l + (r - l) / 2;
    if (x < m) return min(ret, get(nodes[k].l, l, m, x));
    return min(ret, get(nodes[k].r, m, r, x));
  }
};

/**
 * @brief Dynamic Li Chao Tree
 * @docs docs/data-structure/dynamic-li-chao-tree.md
 */
