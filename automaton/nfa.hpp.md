---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: automaton/dfa.hpp
    title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/automaton/nfa.md
    document_title: "\u975E\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\
      \u30F3(NFA)"
    links: []
  bundledCode: "#line 2 \"automaton/nfa.hpp\"\n\n#line 2 \"automaton/dfa.hpp\"\n\n\
    template <int c_min = 'a', int c_max = 'z'>\nclass DFA {\n  using t_dfa = DFA<c_min,\
    \ c_max>;\n  static const int c_size = c_max - c_min + 1;\n\n public:\n  DFA()\
    \ {}\n  DFA(int size, int start)\n      : _size(size),\n        _start(start),\n\
    \        _final(size, false),\n        map(size, vector<int>(c_size, -1)) {}\n\
    \  DFA(int size, int start, const vector<vector<int>> &map_)\n      : _size(size),\
    \ _start(start), _final(size, false), map(map_) {}\n  DFA(int size, int start,\
    \ const vector<bool> final_,\n      const vector<vector<int>> &map_)\n      :\
    \ _size(size), _start(start), _final(final_), map(map_) {}\n  void set(int p,\
    \ char c, int q) { map[p][c - c_min] = q; }\n  int get(int p, char c) { return\
    \ map[p][c - c_min]; }\n  void set_final(int p, bool f) { _final[p] = f; }\n \
    \ bool get_final(int p) { return _final[p]; }\n\n  t_dfa normalize() {\n    vector<bool>\
    \ seen(_size, false);\n    vector<int> index(_size, -1);\n    vector<int> states;\n\
    \    queue<int> qu;\n    qu.push(_start);\n    while (!qu.empty()) {\n      int\
    \ x = qu.front();\n      qu.pop();\n      seen[x] = true;\n      index[x] = states.size();\n\
    \      states.push_back(x);\n      for (int j = 0; j < c_size; j++) {\n      \
    \  int y = map[x][j];\n        if (seen[y]) continue;\n        seen[y] = true;\n\
    \        qu.push(y);\n      }\n    }\n\n    int size1 = states.size();\n    vector<bool>\
    \ final1(size1, false);\n    for (int i = 0; i < size1; i++) final1[i] = _final[states[i]];\n\
    \    vector<vector<int>> map1(size1, vector<int>(c_size, -1));\n    for (int i\
    \ = 0; i < size1; i++)\n      for (int j = 0; j < c_size; j++) map1[i][j] = index[map[states[i]][j]];\n\
    \    return t_dfa(size1, index[_start], final1, map1);\n  }\n\n  t_dfa minimize()\
    \ {\n    vector<int> partition(_size, -1);\n    {\n      int accept = -1, reject\
    \ = -1;\n      for (int i = 0; i < _size; i++)\n        if (_final[i])\n     \
    \     partition[i] = accept == -1 ? (accept = i) : accept;\n        else\n   \
    \       partition[i] = reject == -1 ? (reject = i) : reject;\n    }\n\n    vector<int>\
    \ partition_new(_size, -1);\n    while (true) {\n      fill(partition_new.begin(),\
    \ partition_new.end(), -1);\n      for (int i = 0; i < _size; i++) {\n       \
    \ if (partition_new[i] != -1) continue;\n        partition_new[i] = i;\n     \
    \   for (int j = i + 1; j < _size; j++)\n          if (partition[i] == partition[j]\
    \ && equivalent(i, j, partition))\n            partition_new[j] = i;\n      }\n\
    \      if (partition == partition_new) break;\n      swap(partition, partition_new);\n\
    \    }\n\n    int size1 = 0;\n    vector<int> index(_size, -1), leader;\n    vector<bool>\
    \ final1;\n    for (int i = 0; i < _size; i++)\n      if (partition[i] == i) {\n\
    \        index[i] = size1++;\n        leader.push_back(i);\n        final1.push_back(_final[i]);\n\
    \      } else {\n        index[i] = index[partition[i]];\n      }\n    vector<vector<int>>\
    \ map1(size1, vector<int>(c_size, -1));\n    for (int i = 0; i < size1; i++)\n\
    \      for (int j = 0; j < c_size; j++) map1[i][j] = index[map[leader[i]][j]];\n\
    \    return t_dfa(size1, index[_start], final1, map1).normalize();\n  }\n\n  bool\
    \ operator==(const t_dfa &d) const {\n    if (_size != d._size) return false;\n\
    \    if (_start != d._start) return false;\n    if (_final != d._final) return\
    \ false;\n    return map == d.map;\n  }\n  int size() { return _size; }\n  int\
    \ start() { return _start; }\n\n private:\n  int _size, _start;\n  vector<bool>\
    \ _final;\n  vector<vector<int>> map;\n\n  bool equivalent(int i, int j, const\
    \ vector<int> &partition) {\n    if (i == j) return true;\n    for (int k = 0;\
    \ k < c_size; k++)\n      if (partition[map[i][k]] != partition[map[j][k]]) return\
    \ false;\n    return true;\n  }\n};\n\n/**\n * @brief \u6C7A\u5B9A\u6027\u6709\
    \u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA)\n * @docs docs/automaton/dfa.md\n\
    \ */\n#line 4 \"automaton/nfa.hpp\"\n\ntemplate <int c_min = 'a', int c_max =\
    \ 'z'>\nclass NFA {\n  using t_dfa = DFA<c_min, c_max>;\n  using t_nfa = NFA<c_min,\
    \ c_max>;\n  static const int c_size = c_max - c_min + 1;\n\n public:\n  NFA()\
    \ {}\n  NFA(int size_, int start_)\n      : _size(size_),\n        _start(start_),\n\
    \        _final(size_, false),\n        map(size_, vector(c_size, vector<bool>(size_,\
    \ false))) {}\n  void add(int p, char c, int q) { map[p][c - c_min][q] = true;\
    \ }\n  void remove(int p, char c, int q) { map[p][c - c_min][q] = false; }\n \
    \ void set_final(int p, bool f) { _final[p] = f; }\n  bool get_final(int p) {\
    \ return _final[p]; }\n\n  t_dfa subset_construction() {\n    using T = long long;\n\
    \    map<T, int> index;\n    vector<vector<int>> map1;\n    int size1 = 0;\n \
    \   T start1 = T(1) << _start;\n    stack<T> st;\n    index[start1] = size1++;\n\
    \    st.push(start1);\n    while (!st.empty()) {\n      T x = st.top();\n    \
    \  st.pop();\n      vector<int> map_cur(c_size, -1);\n      for (int c = 0; c\
    \ < c_size; c++) {\n        T y = 0;\n        for (int i = 0; i < _size; i++)\n\
    \          if ((x >> i) & 1)\n            for (int j = 0; j < _size; j++) y |=\
    \ T(map[i][c][j]) << j;\n        if (!index.contains(y)) {\n          index[y]\
    \ = size1++;\n          st.push(y);\n        }\n        map_cur[c] = index[y];\n\
    \      }\n      map1.push_back(map_cur);\n    }\n    vector<bool> final1(size1,\
    \ false);\n    for (auto [x, i] : index) {\n      for (int j = 0; j < _size; j++)\n\
    \        if (((x >> j) & 1) && _final[j]) final1[i] = 1;\n    }\n    return t_dfa(index.size(),\
    \ start1, final1, map1);\n  }\n\n private:\n  int _size, _start;\n  vector<bool>\
    \ _final;\n  vector<vector<vector<bool>>> map;\n};\n\n/**\n * @brief \u975E\u6C7A\
    \u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(NFA)\n * @docs docs/automaton/nfa.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"./dfa.hpp\"\n\ntemplate <int c_min = 'a', int\
    \ c_max = 'z'>\nclass NFA {\n  using t_dfa = DFA<c_min, c_max>;\n  using t_nfa\
    \ = NFA<c_min, c_max>;\n  static const int c_size = c_max - c_min + 1;\n\n public:\n\
    \  NFA() {}\n  NFA(int size_, int start_)\n      : _size(size_),\n        _start(start_),\n\
    \        _final(size_, false),\n        map(size_, vector(c_size, vector<bool>(size_,\
    \ false))) {}\n  void add(int p, char c, int q) { map[p][c - c_min][q] = true;\
    \ }\n  void remove(int p, char c, int q) { map[p][c - c_min][q] = false; }\n \
    \ void set_final(int p, bool f) { _final[p] = f; }\n  bool get_final(int p) {\
    \ return _final[p]; }\n\n  t_dfa subset_construction() {\n    using T = long long;\n\
    \    map<T, int> index;\n    vector<vector<int>> map1;\n    int size1 = 0;\n \
    \   T start1 = T(1) << _start;\n    stack<T> st;\n    index[start1] = size1++;\n\
    \    st.push(start1);\n    while (!st.empty()) {\n      T x = st.top();\n    \
    \  st.pop();\n      vector<int> map_cur(c_size, -1);\n      for (int c = 0; c\
    \ < c_size; c++) {\n        T y = 0;\n        for (int i = 0; i < _size; i++)\n\
    \          if ((x >> i) & 1)\n            for (int j = 0; j < _size; j++) y |=\
    \ T(map[i][c][j]) << j;\n        if (!index.contains(y)) {\n          index[y]\
    \ = size1++;\n          st.push(y);\n        }\n        map_cur[c] = index[y];\n\
    \      }\n      map1.push_back(map_cur);\n    }\n    vector<bool> final1(size1,\
    \ false);\n    for (auto [x, i] : index) {\n      for (int j = 0; j < _size; j++)\n\
    \        if (((x >> j) & 1) && _final[j]) final1[i] = 1;\n    }\n    return t_dfa(index.size(),\
    \ start1, final1, map1);\n  }\n\n private:\n  int _size, _start;\n  vector<bool>\
    \ _final;\n  vector<vector<vector<bool>>> map;\n};\n\n/**\n * @brief \u975E\u6C7A\
    \u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(NFA)\n * @docs docs/automaton/nfa.md\n\
    \ */"
  dependsOn:
  - automaton/dfa.hpp
  isVerificationFile: false
  path: automaton/nfa.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: automaton/nfa.hpp
layout: document
redirect_from:
- /library/automaton/nfa.hpp
- /library/automaton/nfa.hpp.html
title: "\u975E\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(NFA)"
---
## 概要

NFA $N=(Q,\Sigma,\Delta,s,F)$ は以下を満たすもの．

- 状態集合 $Q$：有限集合
- 文字集合 $\Sigma$：有限集合
- 遷移関数 $\Delta:Q\times\Sigma\to 2^Q$
- 開始状態 $s\in Q$
- 受理状態集合 $F\subseteq Q$

以下のようにして $\Delta:2^Q\times\Sigma\to 2^Q$ とみなす．

- $\forall X\subseteq Q,\forall c\in\Sigma,\Delta(X,c)=\bigcup_{q\in X}\Delta(q,c)$

$\hat{\Delta}:2^Q\times\Sigma^*\to 2^Q$ を以下のように定義する．

- $\forall X\subseteq Q,\hat{\Delta}(X,\epsilon)=X$
- $\forall X\subseteq Q,\forall x\in\Sigma^*,\forall c\in\Sigma,\hat{\Delta}(X,xc)=\Delta(\hat{\Delta}(X,x),c)$

$x\in\Sigma^*$ について，$\hat{\Delta}(s,x)\cap F\neq\emptyset$ ならば $x$ は $N$ によって **受理される**，そうでないならば **拒否される** という．

言語 $L$ について，任意の文字列 $x$ に対し $x\in L$ と $N$ が $x$ を受理することが同値であるとき，$L$ は $N$ によって受理されるという．

## DFA との関係

DFA は自然に NFA とみなせる．

逆に NFA は DFA で再現できる．状態集合を $2^Q$ と思えばよい．

従って DFA と NFA の表現力は等価である．

扱いやすさの面では DFA が，少ない状態数で表すには NFA が便利であるから使い分けが重要．