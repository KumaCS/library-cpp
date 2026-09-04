#pragma once

#include "algebraic-structure/monoid.hpp"
#include "tree/euler-tour.hpp"
#include "segment-tree/segment-tree.hpp"

template <class M>
REQUIRES(Monoid<M>)
struct TreeVertexSetSubtreeProd {
  using T = M::value_type;
  TreeVertexSetSubtreeProd() {}
  template <class G>
  TreeVertexSetSubtreeProd(const G& g, const vector<T>& vertex_value, int root = 0) : n(g.size()) {
    assert((int)vertex_value.size() == n);
    tie(in_time, out_time) = EulerTour(g, root);
    vector<T> data(n);
    for (int x = 0; x < n; x++) data[in_time[x]] = vertex_value[x];
    seg = SegmentTree<M>(data);
  }
  void set(int x, T v) { seg.set(in_time[x], v); }
  void apply(int x, T v) { seg.apply(in_time[x], v); }
  T prod(int x) { return seg.prod(in_time[x], out_time[x]); }

 private:
  int n;
  vector<int> in_time, out_time;
  SegmentTree<M> seg;
};

/**
 * @brief Tree Vertex Set Subtree Product
 * @docs docs/tree/tree-vertex-set-subtree-prod.md
 */
