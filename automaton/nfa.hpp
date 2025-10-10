#pragma once

#include "./dfa.hpp"

template <int c_min = 'a', int c_max = 'z'>
class NFA {
  using t_dfa = DFA<c_min, c_max>;
  using t_nfa = NFA<c_min, c_max>;
  static const int c_size = c_max - c_min + 1;

 public:
  NFA() {}
  NFA(int size_, int start_)
      : _size(size_),
        _start(start_),
        _final(size_, false),
        map(size_, vector(c_size, vector<bool>(size_, false))) {}
  void add(int p, char c, int q) { map[p][c - c_min][q] = true; }
  void remove(int p, char c, int q) { map[p][c - c_min][q] = false; }
  void set_final(int p, bool f) { _final[p] = f; }
  bool get_final(int p) { return _final[p]; }

  t_dfa subset_construction() {
    using T = long long;
    map<T, int> index;
    vector<vector<int>> map1;
    int size1 = 0;
    T start1 = T(1) << _start;
    stack<T> st;
    index[start1] = size1++;
    st.push(start1);
    while (!st.empty()) {
      T x = st.top();
      st.pop();
      vector<int> map_cur(c_size, -1);
      for (int c = 0; c < c_size; c++) {
        T y = 0;
        for (int i = 0; i < _size; i++)
          if ((x >> i) & 1)
            for (int j = 0; j < _size; j++) y |= T(map[i][c][j]) << j;
        if (!index.contains(y)) {
          index[y] = size1++;
          st.push(y);
        }
        map_cur[c] = index[y];
      }
      map1.push_back(map_cur);
    }
    vector<bool> final1(size1, false);
    for (auto [x, i] : index) {
      for (int j = 0; j < _size; j++)
        if (((x >> j) & 1) && _final[j]) final1[i] = 1;
    }
    return t_dfa(index.size(), start1, final1, map1);
  }

 private:
  int _size, _start;
  vector<bool> _final;
  vector<vector<vector<bool>>> map;
};

/**
 * @brief 非決定性有限オートマトン(NFA)
 * @docs docs/automaton/nfa.md
 */