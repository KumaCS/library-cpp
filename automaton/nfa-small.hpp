#pragma once

#include "./dfa-small.hpp"

template <class T = long long, int c_min = 'a', int c_max = 'z'>
class NFASmall {
  using t_dfa = DFASmall<T, c_min, c_max>;
  using t_nfa = NFASmall<T, c_min, c_max>;
  static const int c_size = c_max - c_min + 1;

 public:
  NFASmall() {}
  NFASmall(int size_, int start_, T final_)
      : size(size_),
        start(start_),
        final(final_),
        map(size_, vector<T>(c_size, 0)) {}
  void add(int p, char c, int q) { map[p][c - c_min] |= T(1) << q; }
  void remove(int p, char c, int q) { map[p][c - c_min] &= ~(T(1) << q); }

  t_dfa subset_construction() {
    map<T, int> index;
    vector<vector<int>> map1;
    int size1 = 0;
    T start1 = T(1) << start;
    stack<T> st;
    index[start1] = size1++;
    st.push(start1);
    T final1 = 0;
    while (!st.empty()) {
      T x = st.top();
      st.pop();
      vector<int> map_cur(c_size, -1);
      for (int c = 0; c < c_size; c++) {
        T y = 0;
        for (int i = 0; i < size; i++)
          if ((x >> i) & 1) y |= map[i][c];
        if (!index.contains(y)) {
          index[y] = size1++;
          st.push(y);
        }
        map_cur[c] = index[y];
      }
      map1.push_back(map_cur);
      for (int i = 0; i < size; i++)
        if (((final >> i) & 1) && ((x >> i) & 1)) final1 |= T(1) << index[x];
    }
    return t_dfa(index.size(), start1, final1, map1);
  }

 private:
  int size, start;
  T final;
  vector<vector<T>> map;
};

/**
 * @brief 非決定性有限オートマトン(NFA)(small)
 * @docs docs/automaton/nfa.md
 */