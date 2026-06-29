#pragma once

#include "flow/max-flow.hpp"

template <class Cap = long long>
struct ProjectSelectionProblem {
  ProjectSelectionProblem() : ProjectSelectionProblem(numeric_limits<Cap>::max() / 4) {}
  explicit ProjectSelectionProblem(Cap inf) : n(2), sum(0), inf(inf) {}

  int add_project() { return n++; }
  void ban0(int x) { add_edge(x, 1, inf); }
  void lose0(int x, Cap w) { add_edge(x, 1, w); }
  void gain0(int x, Cap w) {
    sum += w;
    add_edge(0, x, w);
  }
  void ban1(int x) { add_edge(0, x, inf); }
  void lose1(int x, Cap w) { add_edge(0, x, w); }
  void gain1(int x, Cap w) {
    sum += w;
    add_edge(x, 1, w);
  }
  void ban01(int x, int y) { add_edge(x, y, inf); }
  void lose01(int x, int y, Cap w) { add_edge(x, y, w); }
  void gain_same(int x, int y, Cap w) {
    sum += w;
    add_edge(x, y, w);
    add_edge(y, x, w);
  }
  void lose_diff(int x, int y, Cap w) {
    add_edge(x, y, w);
    add_edge(y, x, w);
  }
  void ban_diff(int x, int y) {
    add_edge(x, y, inf);
    add_edge(y, x, inf);
  }
  void gain00(int x, int y, Cap w) {
    sum += w;
    int z = add_project();
    add_edge(0, z, w);
    add_edge(z, x, inf);
    add_edge(z, y, inf);
  }
  void gain11(int x, int y, Cap w) {
    sum += w;
    int z = add_project();
    add_edge(z, 1, w);
    add_edge(x, z, inf);
    add_edge(y, z, inf);
  }
  template <class Container>
  void gain_all0(const Container& xs, Cap w) {
    sum += w;
    int y = add_project();
    add_edge(0, y, w);
    for (int x : xs) add_edge(y, x, inf);
  }
  template <class Container>
  void gain_all1(const Container& xs, Cap w) {
    sum += w;
    int y = add_project();
    add_edge(y, 1, w);
    for (int x : xs) add_edge(x, y, inf);
  }
  Cap solve() const {
    MaxFlow<Cap> mf(n);
    for (auto [from, to, cap] : _edges) mf.add_edge(from, to, cap);
    return sum - mf.flow(0, 1);
  }

 private:
  void add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < n);
    assert(0 <= to && to < n);
    assert(0 <= cap);
    _edges.push_back({from, to, cap});
  }
  int n;
  Cap sum, inf;
  vector<tuple<int, int, Cap>> _edges;
};

/**
 * @brief Project Selection Problem
 * @docs docs/flow/project-selection-problem.md
 */
