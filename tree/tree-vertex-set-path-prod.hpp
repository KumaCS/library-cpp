#pragma once

#include "algebraic-structure/monoid.hpp"
#include "tree/heavy-light-decomposition.hpp"
#include "segment-tree/segment-tree.hpp"

template <class M>
REQUIRES(Monoid<M>)
struct TreeVertexSetPathProd {
  using T = M::value_type;
  TreeVertexSetPathProd() {}
  template <class G>
  TreeVertexSetPathProd(const G& g, const vector<T>& vertex_value, int root = 0) : n(g.size()), hld(g, root) {
    assert((int)vertex_value.size() == n);
    vector<T> data(g.size());
    for (int i = 0; i < n; i++) data[i] = vertex_value[hld.vertices[i]];
    seg = SegmentTree<M>(data);
    reverse(data.begin(), data.end());
    segr = SegmentTree<M>(data);
  }
  void set(int x, T v) {
    seg.set(hld.pos[x], v);
    segr.set(n - 1 - hld.pos[x], v);
  }
  void apply(int x, T v) {
    seg.apply(hld.pos[x], v);
    segr.apply(n - 1 - hld.pos[x], v);
  }
  T prod(int x, int y) {
    T p = M::e();
    hld.path(x, y, [&](int l, int r, bool rev) {
      p = M::op(p, rev ? segr.prod(n - r, n - l) : seg.prod(l, r));
    });
    return p;
  }

 private:
  int n;
  HeavyLightDecomposition hld;
  SegmentTree<M> seg, segr;
};

template <class M>
REQUIRES(Monoid<M>)
struct TreeVertexSetPathProdCommutative {
  using T = M::value_type;
  TreeVertexSetPathProdCommutative() {}
  template <class G>
  TreeVertexSetPathProdCommutative(const G& g, const vector<T>& vertex_value, int root = 0)
      : n(g.size()), hld(g, root) {
    assert((int)vertex_value.size() == n);
    vector<T> data(g.size());
    for (int i = 0; i < n; i++) data[i] = vertex_value[hld.vertices[i]];
    seg = SegmentTree<M>(data);
  }
  void set(int x, T v) { seg.set(hld.pos[x], v); }
  void apply(int x, T v) { seg.apply(hld.pos[x], v); }
  T prod(int x, int y) {
    T p = M::e();
    hld.path(x, y, [&](int l, int r, bool) { p = M::op(p, seg.prod(l, r)); });
    return p;
  }

 private:
  int n;
  HeavyLightDecomposition hld;
  SegmentTree<M> seg;
};

/**
 * @brief Tree Vertex Set Path Product
 * @docs docs/tree/tree-vertex-set-path-prod.md
 */
