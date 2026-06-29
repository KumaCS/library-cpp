---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data-structure/UNIT_interval_set.test.cpp
    title: verify/data-structure/UNIT_interval_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/interval-set.md
    document_title: "\u533A\u9593\u96C6\u5408"
    links: []
  bundledCode: "#line 2 \"data-structure/interval-set.hpp\"\n\ntemplate <class T>\n\
    struct IntervalSet {\n  using value_type = pair<T, T>;\n  IntervalSet() = default;\n\
    \  bool contains(T x) const {\n    auto it = LR.upper_bound({x, INF});\n    if\
    \ (it == LR.begin()) return false;\n    --it;\n    return it->first <= x && x\
    \ < it->second;\n  }\n  bool contains(T l, T r) const {\n    assert(l <= r);\n\
    \    if (l == r) return true;\n    auto it = LR.upper_bound({l, INF});\n    if\
    \ (it == LR.begin()) return false;\n    --it;\n    return it->first <= l && r\
    \ <= it->second;\n  }\n\n  optional<value_type> get(T x) const {\n    auto it\
    \ = LR.upper_bound({x, INF});\n    if (it == LR.begin()) return nullopt;\n   \
    \ --it;\n    if (it->first <= x && x < it->second) return *it;\n    return nullopt;\n\
    \  }\n\n  void add(T x) {\n    assert(x < INF);\n    add(x, x + 1);\n  }\n  void\
    \ add(T l, T r) {\n    assert(l <= r);\n    if (l == r) return;\n\n    auto it\
    \ = LR.upper_bound({l, INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n\
    \      if (l <= pre->second) {\n        l = pre->first;\n        r = max(r, pre->second);\n\
    \        it = LR.erase(pre);\n      }\n    }\n    while (it != LR.end() && it->first\
    \ <= r) {\n      r = max(r, it->second);\n      it = LR.erase(it);\n    }\n  \
    \  LR.insert({l, r});\n  }\n\n  void remove(T x) {\n    assert(x < INF);\n   \
    \ remove(x, x + 1);\n  }\n  void remove(T l, T r) {\n    assert(l <= r);\n   \
    \ if (l == r) return;\n\n    auto it = LR.upper_bound({l, INF});\n    if (it !=\
    \ LR.begin()) {\n      auto pre = prev(it);\n      if (l < pre->second) {\n  \
    \      T l1 = pre->first, r1 = pre->second;\n        LR.erase(pre);\n        if\
    \ (l1 < l) LR.insert({l1, l});\n        if (r < r1) {\n          LR.insert({r,\
    \ r1});\n          return;\n        }\n      }\n    }\n    while (it != LR.end()\
    \ && it->first < r) {\n      T r1 = it->second;\n      it = LR.erase(it);\n  \
    \    if (r < r1) {\n        LR.insert({r, r1});\n        break;\n      }\n   \
    \ }\n  }\n\n  vector<value_type> enumerate(T l, T r) const {\n    assert(l <=\
    \ r);\n    vector<value_type> ret;\n    if (l == r) return ret;\n\n    auto it\
    \ = LR.upper_bound({l, INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n\
    \      if (l < pre->second) it = pre;\n    }\n    while (it != LR.end() && it->first\
    \ < r) {\n      ret.push_back({max(l, it->first), min(r, it->second)});\n    \
    \  ++it;\n    }\n    return ret;\n  }\n\n  T mex(T x = 0) const {\n    auto it\
    \ = LR.upper_bound({x, INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n\
    \      if (pre->first <= x && x < pre->second) x = pre->second;\n    }\n    while\
    \ (it != LR.end() && it->first <= x) {\n      if (x < it->second) x = it->second;\n\
    \      ++it;\n    }\n    return x;\n  }\n\n  bool empty() const { return LR.empty();\
    \ }\n  void clear() { LR.clear(); }\n\n  auto begin() const { return LR.begin();\
    \ }\n  auto end() const { return LR.end(); }\n\n private:\n  static constexpr\
    \ T INF = numeric_limits<T>::max();\n  set<value_type> LR;\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u96C6\u5408\n * @docs docs/data-structure/interval-set.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct IntervalSet {\n  using value_type\
    \ = pair<T, T>;\n  IntervalSet() = default;\n  bool contains(T x) const {\n  \
    \  auto it = LR.upper_bound({x, INF});\n    if (it == LR.begin()) return false;\n\
    \    --it;\n    return it->first <= x && x < it->second;\n  }\n  bool contains(T\
    \ l, T r) const {\n    assert(l <= r);\n    if (l == r) return true;\n    auto\
    \ it = LR.upper_bound({l, INF});\n    if (it == LR.begin()) return false;\n  \
    \  --it;\n    return it->first <= l && r <= it->second;\n  }\n\n  optional<value_type>\
    \ get(T x) const {\n    auto it = LR.upper_bound({x, INF});\n    if (it == LR.begin())\
    \ return nullopt;\n    --it;\n    if (it->first <= x && x < it->second) return\
    \ *it;\n    return nullopt;\n  }\n\n  void add(T x) {\n    assert(x < INF);\n\
    \    add(x, x + 1);\n  }\n  void add(T l, T r) {\n    assert(l <= r);\n    if\
    \ (l == r) return;\n\n    auto it = LR.upper_bound({l, INF});\n    if (it != LR.begin())\
    \ {\n      auto pre = prev(it);\n      if (l <= pre->second) {\n        l = pre->first;\n\
    \        r = max(r, pre->second);\n        it = LR.erase(pre);\n      }\n    }\n\
    \    while (it != LR.end() && it->first <= r) {\n      r = max(r, it->second);\n\
    \      it = LR.erase(it);\n    }\n    LR.insert({l, r});\n  }\n\n  void remove(T\
    \ x) {\n    assert(x < INF);\n    remove(x, x + 1);\n  }\n  void remove(T l, T\
    \ r) {\n    assert(l <= r);\n    if (l == r) return;\n\n    auto it = LR.upper_bound({l,\
    \ INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n      if (l\
    \ < pre->second) {\n        T l1 = pre->first, r1 = pre->second;\n        LR.erase(pre);\n\
    \        if (l1 < l) LR.insert({l1, l});\n        if (r < r1) {\n          LR.insert({r,\
    \ r1});\n          return;\n        }\n      }\n    }\n    while (it != LR.end()\
    \ && it->first < r) {\n      T r1 = it->second;\n      it = LR.erase(it);\n  \
    \    if (r < r1) {\n        LR.insert({r, r1});\n        break;\n      }\n   \
    \ }\n  }\n\n  vector<value_type> enumerate(T l, T r) const {\n    assert(l <=\
    \ r);\n    vector<value_type> ret;\n    if (l == r) return ret;\n\n    auto it\
    \ = LR.upper_bound({l, INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n\
    \      if (l < pre->second) it = pre;\n    }\n    while (it != LR.end() && it->first\
    \ < r) {\n      ret.push_back({max(l, it->first), min(r, it->second)});\n    \
    \  ++it;\n    }\n    return ret;\n  }\n\n  T mex(T x = 0) const {\n    auto it\
    \ = LR.upper_bound({x, INF});\n    if (it != LR.begin()) {\n      auto pre = prev(it);\n\
    \      if (pre->first <= x && x < pre->second) x = pre->second;\n    }\n    while\
    \ (it != LR.end() && it->first <= x) {\n      if (x < it->second) x = it->second;\n\
    \      ++it;\n    }\n    return x;\n  }\n\n  bool empty() const { return LR.empty();\
    \ }\n  void clear() { LR.clear(); }\n\n  auto begin() const { return LR.begin();\
    \ }\n  auto end() const { return LR.end(); }\n\n private:\n  static constexpr\
    \ T INF = numeric_limits<T>::max();\n  set<value_type> LR;\n};\n\n/**\n * @brief\
    \ \u533A\u9593\u96C6\u5408\n * @docs docs/data-structure/interval-set.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/interval-set.hpp
  requiredBy: []
  timestamp: '2026-06-30 02:52:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data-structure/UNIT_interval_set.test.cpp
documentation_of: data-structure/interval-set.hpp
layout: document
redirect_from:
- /library/data-structure/interval-set.hpp
- /library/data-structure/interval-set.hpp.html
title: "\u533A\u9593\u96C6\u5408"
---
半開区間 $[l,r)$ の集合を，互いに交わらず隣接もしない区間列として管理するデータ構造．

`add` で追加した区間は既存の区間とマージされ，`remove` で削除した区間は必要に応じて分割される．

- `contains(x)`：$x$ が集合に含まれるか判定する．
- `contains(l, r)`：$[l,r)$ がすべて集合に含まれるか判定する．空区間は真．
- `get(x)`：$x$ を含む管理区間を `optional<pair<T, T>>` で返す．存在しない場合は `nullopt`．
- `add(x)`：$x$ を追加する．内部では $[x,x+1)$ を追加する．
- `add(l, r)`：$[l,r)$ を追加する．
- `remove(x)`：$x$ を削除する．内部では $[x,x+1)$ を削除する．
- `remove(l, r)`：$[l,r)$ を削除する．
- `enumerate(l, r)`：$[l,r)$ と交わる部分を，交差区間の列として返す．
- `mex(x = 0)`：$x$ 以上で集合に含まれない最小の値を返す．
- `empty()`：管理している区間がないか判定する．
- `clear()`：すべての区間を削除する．
- `begin()`, `end()`：管理している区間列を走査する iterator を返す．

単点操作 `add(x)`, `remove(x)` は $x+1$ を使うため，`x < numeric_limits<T>::max()` を要求する．

各操作の計算量は，削除またはマージされる区間数を $k$ として $O((k+1)\log N)$．
`contains`, `get`, `mex` は，`mex` が連続する区間をまたぐ場合を除いて $O(\log N)$．
