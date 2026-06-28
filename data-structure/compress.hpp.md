---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/algorithm/LC_static_range_count_distinct.test.cpp
    title: verify/algorithm/LC_static_range_count_distinct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/compress.md
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 2 \"data-structure/compress.hpp\"\n\ntemplate <class T>\nstruct\
    \ Compress : vector<T> {\n  void build() {\n    sort(this->begin(), this->end());\n\
    \    this->erase(unique(this->begin(), this->end()), this->end());\n  }\n  int\
    \ find(T v) const { return int(lower_bound(this->begin(), this->end(), v) - this->begin());\
    \ }\n};\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs docs/data-structure/compress.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct Compress : vector<T> {\n  void\
    \ build() {\n    sort(this->begin(), this->end());\n    this->erase(unique(this->begin(),\
    \ this->end()), this->end());\n  }\n  int find(T v) const { return int(lower_bound(this->begin(),\
    \ this->end(), v) - this->begin()); }\n};\n\n/**\n * @brief \u5EA7\u6A19\u5727\
    \u7E2E\n * @docs docs/data-structure/compress.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/compress.hpp
  requiredBy: []
  timestamp: '2026-06-28 16:21:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/algorithm/LC_static_range_count_distinct.test.cpp
documentation_of: data-structure/compress.hpp
layout: document
redirect_from:
- /library/data-structure/compress.hpp
- /library/data-structure/compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
座標圧縮をする．

- 圧縮したい値を `push_back` などで追加する．
- `build()`：追加した値を sort し，重複を除く．
- `operator[]`：圧縮後の番号から元の値を取得する．
- `find(v)`：値 `v` の圧縮後の index を返す．存在しない場合も lower bound の位置を返す．

`Compress<T>` は `vector<T>` を継承しているため，圧縮後の値集合そのものとして扱える．
