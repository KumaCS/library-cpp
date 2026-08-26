#pragma once

#include "data-structure/binary-indexed-tree.hpp"

template <class T, class I = int>
struct StaticPointAddRectangleSum {
  void query_add(I x, I y, T v) { ps.push_back({x, y, v}); }
  void query_sum(I lx, I rx, I ly, I ry) {
    assert(lx <= rx && ly <= ry);
    qs.push_back({lx, rx, ly, ry});
  }
  vector<T> calc() const {
    struct E {
      I x, ly, ry;
      int q, s;
      bool operator<(const E& e) const { return x < e.x; }
    };
    vector<I> ys;
    ys.reserve(ps.size());
    for (auto [x, y, v] : ps) ys.push_back(y);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    vector<P> a = ps;
    sort(a.begin(), a.end(), [](const P& p, const P& q) { return p.x < q.x; });
    vector<E> ev;
    ev.reserve(qs.size() * 2);
    for (int i = 0; i < (int)qs.size(); i++) {
      auto [lx, rx, ly, ry] = qs[i];
      ev.push_back({lx, ly, ry, i, -1});
      ev.push_back({rx, ly, ry, i, 1});
    }
    sort(ev.begin(), ev.end());
    BinaryIndexedTree<T> bit(ys.size());
    vector<T> ans(qs.size());
    int p = 0;
    for (auto [x, ly, ry, q, s] : ev) {
      while (p < (int)a.size() && a[p].x < x) {
        bit.add(LB(ys, a[p].y), a[p].v);
        p++;
      }
      T v = bit.sum(LB(ys, ly), LB(ys, ry));
      ans[q] += s == 1 ? v : -v;
    }
    return ans;
  }

 private:
  struct P {
    I x, y;
    T v;
  };
  struct Q {
    I lx, rx, ly, ry;
  };
  vector<P> ps;
  vector<Q> qs;
};

/**
 * @brief Static Point Add Rectangle Sum
 * @docs docs/data-structure/static-point-add-rectangle-sum.md
 */
