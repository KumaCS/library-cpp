#pragma once

template <class T>
struct IntervalSet {
  using value_type = pair<T, T>;
  IntervalSet() = default;
  bool contains(T x) const {
    auto it = LR.upper_bound({x, INF});
    if (it == LR.begin()) return false;
    --it;
    return it->first <= x && x < it->second;
  }
  bool contains(T l, T r) const {
    assert(l <= r);
    if (l == r) return true;
    auto it = LR.upper_bound({l, INF});
    if (it == LR.begin()) return false;
    --it;
    return it->first <= l && r <= it->second;
  }

  optional<value_type> get(T x) const {
    auto it = LR.upper_bound({x, INF});
    if (it == LR.begin()) return nullopt;
    --it;
    if (it->first <= x && x < it->second) return *it;
    return nullopt;
  }

  void add(T x) {
    assert(x < INF);
    add(x, x + 1);
  }
  void add(T l, T r) {
    assert(l <= r);
    if (l == r) return;

    auto it = LR.upper_bound({l, INF});
    if (it != LR.begin()) {
      auto pre = prev(it);
      if (l <= pre->second) {
        l = pre->first;
        r = max(r, pre->second);
        it = LR.erase(pre);
      }
    }
    while (it != LR.end() && it->first <= r) {
      r = max(r, it->second);
      it = LR.erase(it);
    }
    LR.insert({l, r});
  }

  void remove(T x) {
    assert(x < INF);
    remove(x, x + 1);
  }
  void remove(T l, T r) {
    assert(l <= r);
    if (l == r) return;

    auto it = LR.upper_bound({l, INF});
    if (it != LR.begin()) {
      auto pre = prev(it);
      if (l < pre->second) {
        T l1 = pre->first, r1 = pre->second;
        LR.erase(pre);
        if (l1 < l) LR.insert({l1, l});
        if (r < r1) {
          LR.insert({r, r1});
          return;
        }
      }
    }
    while (it != LR.end() && it->first < r) {
      T r1 = it->second;
      it = LR.erase(it);
      if (r < r1) {
        LR.insert({r, r1});
        break;
      }
    }
  }

  vector<value_type> enumerate(T l, T r) const {
    assert(l <= r);
    vector<value_type> ret;
    if (l == r) return ret;

    auto it = LR.upper_bound({l, INF});
    if (it != LR.begin()) {
      auto pre = prev(it);
      if (l < pre->second) it = pre;
    }
    while (it != LR.end() && it->first < r) {
      ret.push_back({max(l, it->first), min(r, it->second)});
      ++it;
    }
    return ret;
  }

  T mex(T x = 0) const {
    auto it = LR.upper_bound({x, INF});
    if (it != LR.begin()) {
      auto pre = prev(it);
      if (pre->first <= x && x < pre->second) x = pre->second;
    }
    while (it != LR.end() && it->first <= x) {
      if (x < it->second) x = it->second;
      ++it;
    }
    return x;
  }

  bool empty() const { return LR.empty(); }
  void clear() { LR.clear(); }

  auto begin() const { return LR.begin(); }
  auto end() const { return LR.end(); }

 private:
  static constexpr T INF = numeric_limits<T>::max();
  set<value_type> LR;
};

/**
 * @brief 区間集合
 * @docs docs/data-structure/interval-set.md
 */
