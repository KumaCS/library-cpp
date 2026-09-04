#pragma once

#include "segment-tree/lazy-segment-tree.hpp"

template <class I = long long>
struct RectangleUnionArea {
  void add_rectangle(I lx, I rx, I ly, I ry) {
    assert(lx < rx && ly < ry);
    rects.push_back({lx, rx, ly, ry});
  }
  I calc() const {
    if (rects.empty()) return I(0);
    struct Event {
      I x;
      int l, r, add;
      bool operator<(const Event& e) const { return x < e.x; }
    };
    vector<I> ys;
    ys.reserve(rects.size() * 2);
    for (auto [lx, rx, ly, ry] : rects) ys.push_back(ly), ys.push_back(ry);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    vector<Event> events;
    events.reserve(rects.size() * 2);
    for (auto [lx, rx, ly, ry] : rects) {
      int l = LB(ys, ly), r = LB(ys, ry);
      events.push_back({lx, l, r, 1});
      events.push_back({rx, l, r, -1});
    }
    sort(events.begin(), events.end());
    vector<T> data(ys.size() - 1);
    for (int i = 0; i + 1 < (int)ys.size(); i++) data[i] = {0, ys[i + 1] - ys[i]};
    LazySegmentTree<Action> seg(data);
    I ret = 0, covered = 0, prev = events[0].x;
    for (int i = 0; i < (int)events.size();) {
      I x = events[i].x;
      ret += (x - prev) * covered;
      while (i < (int)events.size() && events[i].x == x) {
        seg.apply(events[i].l, events[i].r, events[i].add);
        i++;
      }
      auto [mn, width] = seg.all_prod();
      covered = ys.back() - ys.front() - (mn == 0 ? width : I(0));
      prev = x;
    }
    return ret;
  }

 private:
  using T = pair<int, I>;
  struct ValueMonoid {
    using value_type = T;
    static T op(T x, T y) {
      if (x.first == y.first) return {x.first, x.second + y.second};
      return x.first < y.first ? x : y;
    }
    static T e() { return {1 << 30, I(0)}; }
  };
  struct OperatorMonoid {
    using value_type = int;
    static int op(int x, int y) { return x + y; }
    static int e() { return 0; }
  };
  struct Action {
    using value_monoid = ValueMonoid;
    using operator_monoid = OperatorMonoid;
    static T mapping(int f, T x) { return {x.first + f, x.second}; }
  };
  vector<array<I, 4>> rects;
};

/**
 * @brief Area of Union of Rectangles
 * @docs docs/data-structure/rectangle-union-area.md
 */
