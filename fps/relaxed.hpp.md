---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/relaxed.hpp\"\n\ntemplate <class fps>\nclass RelaxedConvolution\
    \ {\n  using mint = typename fps::value_type;\n  int n, sz;\n  fps f, g, h;\n\
    \  void calc(int l1, int r1, int l2, int r2) {\n    int len = r1 + r2 - 1;\n \
    \   if (h.size() < len) h.resize(len);\n    fps f1(f.begin() + l1, f.begin() +\
    \ r1);\n    fps g1(g.begin() + l2, g.begin() + r2);\n    fps h1 = f1 * g1;\n \
    \   for (int i = 0; i < h1.size(); i++) h[i + l1 + l2] += h1[i];\n  }\n\n public:\n\
    \  RelaxedConvolution() : n(0), sz(1) {\n    n = 0;\n    sz = 1;\n    f.resize(sz);\n\
    \    g.resize(sz);\n    h.resize(sz * 2 - 1);\n  }\n  mint append(mint a, mint\
    \ b) {\n    if (n == sz) {\n      sz <<= 1;\n      f.resize(sz);\n      g.resize(sz);\n\
    \      h.resize(sz * 2 - 1);\n    }\n    f[n] = a, g[n] = b;\n    n++;\n    int\
    \ m = (n + 1) & -(n + 1), s = 0;\n    if (m <= n) {\n      int k = 1;\n      while\
    \ (k <= m) {\n        calc(n - k, n, s, s + k);\n        calc(s, s + k, n - k,\
    \ n);\n        s += k;\n        k <<= 1;\n      }\n    } else {\n      int k =\
    \ 1;\n      while (k < (m >> 1)) {\n        calc(n - k, n, s, s + k);\n      \
    \  calc(s, s + k, n - k, n);\n        s += k;\n        k <<= 1;\n      }\n   \
    \   calc(n - k, n, s, s + k);\n    }\n    return h[n - 1];\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class fps>\nclass RelaxedConvolution {\n  using\
    \ mint = typename fps::value_type;\n  int n, sz;\n  fps f, g, h;\n  void calc(int\
    \ l1, int r1, int l2, int r2) {\n    int len = r1 + r2 - 1;\n    if (h.size()\
    \ < len) h.resize(len);\n    fps f1(f.begin() + l1, f.begin() + r1);\n    fps\
    \ g1(g.begin() + l2, g.begin() + r2);\n    fps h1 = f1 * g1;\n    for (int i =\
    \ 0; i < h1.size(); i++) h[i + l1 + l2] += h1[i];\n  }\n\n public:\n  RelaxedConvolution()\
    \ : n(0), sz(1) {\n    n = 0;\n    sz = 1;\n    f.resize(sz);\n    g.resize(sz);\n\
    \    h.resize(sz * 2 - 1);\n  }\n  mint append(mint a, mint b) {\n    if (n ==\
    \ sz) {\n      sz <<= 1;\n      f.resize(sz);\n      g.resize(sz);\n      h.resize(sz\
    \ * 2 - 1);\n    }\n    f[n] = a, g[n] = b;\n    n++;\n    int m = (n + 1) & -(n\
    \ + 1), s = 0;\n    if (m <= n) {\n      int k = 1;\n      while (k <= m) {\n\
    \        calc(n - k, n, s, s + k);\n        calc(s, s + k, n - k, n);\n      \
    \  s += k;\n        k <<= 1;\n      }\n    } else {\n      int k = 1;\n      while\
    \ (k < (m >> 1)) {\n        calc(n - k, n, s, s + k);\n        calc(s, s + k,\
    \ n - k, n);\n        s += k;\n        k <<= 1;\n      }\n      calc(n - k, n,\
    \ s, s + k);\n    }\n    return h[n - 1];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/relaxed.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/relaxed.hpp
layout: document
redirect_from:
- /library/fps/relaxed.hpp
- /library/fps/relaxed.hpp.html
title: fps/relaxed.hpp
---
