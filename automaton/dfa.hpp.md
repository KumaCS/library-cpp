---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: automaton/nfa.hpp
    title: "\u975E\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\
      (NFA)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/automaton/dfa.md
    document_title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\
      (DFA)"
    links: []
  bundledCode: "#line 2 \"automaton/dfa.hpp\"\n\ntemplate <int c_min = 'a', int c_max\
    \ = 'z'>\nclass DFA {\n  using t_dfa = DFA<c_min, c_max>;\n  static const int\
    \ c_size = c_max - c_min + 1;\n\n public:\n  DFA() {}\n  DFA(int size, int start)\n\
    \      : _size(size),\n        _start(start),\n        _final(size, false),\n\
    \        map(size, vector<int>(c_size, -1)) {}\n  DFA(int size, int start, const\
    \ vector<vector<int>> &map_)\n      : _size(size), _start(start), _final(size,\
    \ false), map(map_) {}\n  DFA(int size, int start, const vector<bool> final_,\n\
    \      const vector<vector<int>> &map_)\n      : _size(size), _start(start), _final(final_),\
    \ map(map_) {}\n  void set(int p, char c, int q) { map[p][c - c_min] = q; }\n\
    \  int get(int p, char c) { return map[p][c - c_min]; }\n  void set_final(int\
    \ p, bool f) { _final[p] = f; }\n  bool get_final(int p) { return _final[p]; }\n\
    \n  t_dfa normalize() {\n    vector<bool> seen(_size, false);\n    vector<int>\
    \ index(_size, -1);\n    vector<int> states;\n    queue<int> qu;\n    qu.push(_start);\n\
    \    while (!qu.empty()) {\n      int x = qu.front();\n      qu.pop();\n     \
    \ seen[x] = true;\n      index[x] = states.size();\n      states.push_back(x);\n\
    \      for (int j = 0; j < c_size; j++) {\n        int y = map[x][j];\n      \
    \  if (seen[y]) continue;\n        seen[y] = true;\n        qu.push(y);\n    \
    \  }\n    }\n\n    int size1 = states.size();\n    vector<bool> final1(size1,\
    \ false);\n    for (int i = 0; i < size1; i++) final1[i] = _final[states[i]];\n\
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
    \ */\n"
  code: "#pragma once\n\ntemplate <int c_min = 'a', int c_max = 'z'>\nclass DFA {\n\
    \  using t_dfa = DFA<c_min, c_max>;\n  static const int c_size = c_max - c_min\
    \ + 1;\n\n public:\n  DFA() {}\n  DFA(int size, int start)\n      : _size(size),\n\
    \        _start(start),\n        _final(size, false),\n        map(size, vector<int>(c_size,\
    \ -1)) {}\n  DFA(int size, int start, const vector<vector<int>> &map_)\n     \
    \ : _size(size), _start(start), _final(size, false), map(map_) {}\n  DFA(int size,\
    \ int start, const vector<bool> final_,\n      const vector<vector<int>> &map_)\n\
    \      : _size(size), _start(start), _final(final_), map(map_) {}\n  void set(int\
    \ p, char c, int q) { map[p][c - c_min] = q; }\n  int get(int p, char c) { return\
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
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: automaton/dfa.hpp
  requiredBy:
  - automaton/nfa.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: automaton/dfa.hpp
layout: document
redirect_from:
- /library/automaton/dfa.hpp
- /library/automaton/dfa.hpp.html
title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA)"
---
## 概要

DFA $M=(Q,\Sigma,\delta,s,F)$ は以下を満たすもの．

- 状態集合 $Q$：有限集合
- 文字集合 $\Sigma$：有限集合
- 遷移関数 $\delta:Q\times\Sigma\to Q$
- 開始状態 $s\in Q$
- 受理状態集合 $F\subseteq Q$

$\hat{\delta}:Q\times\Sigma^*\to Q$ を以下のように定義する．

- $\forall q\in Q,\hat{\delta}(q,\epsilon)=q$
- $\forall q\in Q,\forall x\in\Sigma^*,\forall c\in \Sigma,\hat{\delta}(q,xc)=\delta(\hat{\delta}(q,x),c)$

$x\in\Sigma^*$ について，$\hat{\delta}(s,x)\in F$ ならば $x$ は $M$ によって **受理される**，そうでないならば **拒否される** という．

言語 $L$ について，任意の文字列 $x$ に対し $x\in L$ と $M$ が $x$ を受理することが同値であるとき，$L$ は $M$ によって受理されるという．

自身を受理する DFA が存在する言語を正規言語と呼ぶ．

## 利用

状態集合 $Q$，文字集合 $\Sigma$ の DFA $M$ が与えられたとする．

このとき例えば $M$ によって受理される長さ $N$ 以下の文字列の総数を $O(2^{\lvert Q \rvert}\lvert \Sigma \rvert N)$ 時間で計算できる．

単純に bit dp すればよい．

遷移に重みがついているような場合でも問題ない．

## Myhill-Nerode の定理

言語 $L$ に対し，$\Sigma^*$ 上の同値関係 $\sim_L$ を以下で定める．

$$x \sim_L y \iff \forall z\in\Sigma^*(xz\in L\iff yz\in L)$$

Myhill-Nerode の定理の主張は以下の通り．

- $L$ が正規言語であることと $\sim_L$ の同値類が有限個であることは同値．
- $L$ が正規言語のとき，$L$ を受理する DFA の状態数の最小値は $\sim_L$ の同値類の個数に一致する．
- $L$ が正規言語のとき，$L$ を受理する状態数最小の DFA は一意．

## DFA の推定

規則的に定義された言語の場合，深い考察をせずに DFA が構築できる場合がある．

例題：ABC418-G

- 短い文字数では正しく判定できるような DFA を作る．
- DFA $M$ が$L$ を受理するならば $f(M)$ と $M$ が同型になるような変換 $f$ を用意し，実際に同型になったら終了．