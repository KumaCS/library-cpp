---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/compress.md
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 2 \"data-structure/compress.hpp\"\n\ntemplate <class T>\nstruct\
    \ Compress : vector<T> {\n  void build() {\n    sort(begin(), end());\n    erase(unique(begin(),\
    \ end()), end());\n  }\n  int find(T v) const { return int(lower_bound(begin(),\
    \ end(), v) - begin()); }\n};\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs\
    \ docs/data-structure/compress.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct Compress : vector<T> {\n  void\
    \ build() {\n    sort(begin(), end());\n    erase(unique(begin(), end()), end());\n\
    \  }\n  int find(T v) const { return int(lower_bound(begin(), end(), v) - begin());\
    \ }\n};\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs docs/data-structure/compress.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/compress.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/compress.hpp
layout: document
redirect_from:
- /library/data-structure/compress.hpp
- /library/data-structure/compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
座標圧縮をする．

- `build` で構築
- `[]` で座標圧縮後の要素にアクセス
- `find` で座標圧縮後の index を検索, lower bound を返す