#pragma once

template <int c_min = 'a', int c_max = 'z'>
class DFA {
  using t_dfa = DFA<c_min, c_max>;
  static const int c_size = c_max - c_min + 1;

 public:
  DFA() {}
  DFA(int size, int start)
      : _size(size),
        _start(start),
        _final(size, false),
        map(size, vector<int>(c_size, -1)) {}
  DFA(int size, int start, const vector<vector<int>> &map_)
      : _size(size), _start(start), _final(size, false), map(map_) {}
  DFA(int size, int start, const vector<bool> final_,
      const vector<vector<int>> &map_)
      : _size(size), _start(start), _final(final_), map(map_) {}
  void set(int p, char c, int q) { map[p][c - c_min] = q; }
  int get(int p, char c) { return map[p][c - c_min]; }
  void set_final(int p, bool f) { _final[p] = f; }
  bool get_final(int p) { return _final[p]; }

  t_dfa normalize() {
    vector<bool> seen(_size, false);
    vector<int> index(_size, -1);
    vector<int> states;
    queue<int> qu;
    qu.push(_start);
    while (!qu.empty()) {
      int x = qu.front();
      qu.pop();
      seen[x] = true;
      index[x] = states.size();
      states.push_back(x);
      for (int j = 0; j < c_size; j++) {
        int y = map[x][j];
        if (seen[y]) continue;
        seen[y] = true;
        qu.push(y);
      }
    }

    int size1 = states.size();
    vector<bool> final1(size1, false);
    for (int i = 0; i < size1; i++) final1[i] = _final[states[i]];
    vector<vector<int>> map1(size1, vector<int>(c_size, -1));
    for (int i = 0; i < size1; i++)
      for (int j = 0; j < c_size; j++) map1[i][j] = index[map[states[i]][j]];
    return t_dfa(size1, index[_start], final1, map1);
  }

  t_dfa minimize() {
    vector<int> partition(_size, -1);
    {
      int accept = -1, reject = -1;
      for (int i = 0; i < _size; i++)
        if (_final[i])
          partition[i] = accept == -1 ? (accept = i) : accept;
        else
          partition[i] = reject == -1 ? (reject = i) : reject;
    }

    vector<int> partition_new(_size, -1);
    while (true) {
      fill(partition_new.begin(), partition_new.end(), -1);
      for (int i = 0; i < _size; i++) {
        if (partition_new[i] != -1) continue;
        partition_new[i] = i;
        for (int j = i + 1; j < _size; j++)
          if (partition[i] == partition[j] && equivalent(i, j, partition))
            partition_new[j] = i;
      }
      if (partition == partition_new) break;
      swap(partition, partition_new);
    }

    int size1 = 0;
    vector<int> index(_size, -1), leader;
    vector<bool> final1;
    for (int i = 0; i < _size; i++)
      if (partition[i] == i) {
        index[i] = size1++;
        leader.push_back(i);
        final1.push_back(_final[i]);
      } else {
        index[i] = index[partition[i]];
      }
    vector<vector<int>> map1(size1, vector<int>(c_size, -1));
    for (int i = 0; i < size1; i++)
      for (int j = 0; j < c_size; j++) map1[i][j] = index[map[leader[i]][j]];
    return t_dfa(size1, index[_start], final1, map1).normalize();
  }

  bool operator==(const t_dfa &d) const {
    if (_size != d._size) return false;
    if (_start != d._start) return false;
    if (_final != d._final) return false;
    return map == d.map;
  }
  int size() { return _size; }
  int start() { return _start; }

 private:
  int _size, _start;
  vector<bool> _final;
  vector<vector<int>> map;

  bool equivalent(int i, int j, const vector<int> &partition) {
    if (i == j) return true;
    for (int k = 0; k < c_size; k++)
      if (partition[map[i][k]] != partition[map[j][k]]) return false;
    return true;
  }
};

/**
 * @brief 決定性有限オートマトン(DFA)
 * @docs docs/automaton/dfa.md
 */