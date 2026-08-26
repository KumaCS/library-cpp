#pragma once

template <class T, class I = int>
struct StaticRectangleAddRectangleSum {
  void query_add(I lx, I rx, I ly, I ry, T v) {
    assert(lx <= rx && ly <= ry);
    rs.push_back({lx, rx, ly, ry, v});
  }
  void query_sum(I lx, I rx, I ly, I ry) {
    assert(lx <= rx && ly <= ry);
    qs.push_back({lx, rx, ly, ry});
  }
  vector<T> calc() const {
    struct A {
      I x, y;
      T v;
      bool operator<(const A& a) const { return x < a.x; }
    };
    struct E {
      I x, y;
      int q, s;
      bool operator<(const E& e) const { return x < e.x; }
    };
    struct BIT {
      int n;
      vector<array<T, 4>> d;
      BIT(int n_) : n(n_), d(n_) {}
      void add(int p, array<T, 4> v) {
        for (p++; p <= n; p += p & -p)
          for (int k = 0; k < 4; k++) d[p - 1][k] += v[k];
      }
      array<T, 4> sum(int p) const {
        array<T, 4> s{};
        for (; p; p -= p & -p)
          for (int k = 0; k < 4; k++) s[k] += d[p - 1][k];
        return s;
      }
    };
    vector<I> ys;
    vector<A> as;
    as.reserve(rs.size() * 4);
    ys.reserve(rs.size() * 2);
    for (auto [lx, rx, ly, ry, v] : rs) {
      as.push_back({lx, ly, v});
      as.push_back({lx, ry, -v});
      as.push_back({rx, ly, -v});
      as.push_back({rx, ry, v});
      ys.push_back(ly);
      ys.push_back(ry);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    vector<E> ev;
    ev.reserve(qs.size() * 4);
    for (int i = 0; i < (int)qs.size(); i++) {
      auto [lx, rx, ly, ry] = qs[i];
      ev.push_back({lx, ly, i, 1});
      ev.push_back({lx, ry, i, -1});
      ev.push_back({rx, ly, i, -1});
      ev.push_back({rx, ry, i, 1});
    }
    sort(as.begin(), as.end());
    sort(ev.begin(), ev.end());
    BIT bit(ys.size());
    vector<T> ans(qs.size());
    int p = 0;
    for (auto [x, y, q, s] : ev) {
      while (p < (int)as.size() && as[p].x < x) {
        auto [ax, ay, v] = as[p++];
        bit.add(LB(ys, ay), {v * ax * ay, v * ax, v * ay, v});
      }
      auto v = bit.sum(LB(ys, y));
      T z = v[0] - v[1] * y - v[2] * x + v[3] * x * y;
      ans[q] += s == 1 ? z : -z;
    }
    return ans;
  }

 private:
  struct R {
    I lx, rx, ly, ry;
    T v;
  };
  struct Q { I lx, rx, ly, ry; };
  vector<R> rs;
  vector<Q> qs;
};

/**
 * @brief Static Rectangle Add Rectangle Sum
 * @docs docs/data-structure/static-rectangle-add-rectangle-sum.md
 */
