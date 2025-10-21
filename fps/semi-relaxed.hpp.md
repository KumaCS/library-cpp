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
  bundledCode: "#line 2 \"fps/semi-relaxed.hpp\"\n\ntemplate <class fps>\nclass SemiRelaxedConvolution\
    \ {\n  using mint = typename fps::value_type;\n  int n;\n  fps f, g, h;\n  void\
    \ calc(int l1, int r1, int l2, int r2) {\n    fps f1(f.begin() + l1, f.begin()\
    \ + r1);\n    fps g1(g.begin() + l2, g.begin() + r2);\n    fps h1 = f1 * g1;\n\
    \    for (int i = 0; i < h1.size(); i++) h[i + l1 + l2] += h1[i];\n  }\n\n public:\n\
    \  SemiRelaxedConvolution(const fps &f_, int g_deg) : n(0), f(f_), g(g_deg, 0)\
    \ {\n    for (int k = 0;; k++)\n      if ((1 << k) - 1 >= (int)f.size()) {\n \
    \       h = fps((1 << k) - 1 + g_deg, 0);\n        break;\n      }\n  }\n  mint\
    \ append(mint a) {\n    g[n++] = a;\n    for (int p = 1;; p <<= 1) {\n      int\
    \ l1 = p - 1, r1 = l1 + p, l2 = n - p, r2 = n;\n      r1 = min(r1, (int)f.size());\n\
    \      if (l1 >= r1) break;\n      calc(l1, r1, l2, r2);\n      if (p == (-n &\
    \ n)) break;\n    }\n    return h[n - 1];\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class fps>\nclass SemiRelaxedConvolution {\n  using\
    \ mint = typename fps::value_type;\n  int n;\n  fps f, g, h;\n  void calc(int\
    \ l1, int r1, int l2, int r2) {\n    fps f1(f.begin() + l1, f.begin() + r1);\n\
    \    fps g1(g.begin() + l2, g.begin() + r2);\n    fps h1 = f1 * g1;\n    for (int\
    \ i = 0; i < h1.size(); i++) h[i + l1 + l2] += h1[i];\n  }\n\n public:\n  SemiRelaxedConvolution(const\
    \ fps &f_, int g_deg) : n(0), f(f_), g(g_deg, 0) {\n    for (int k = 0;; k++)\n\
    \      if ((1 << k) - 1 >= (int)f.size()) {\n        h = fps((1 << k) - 1 + g_deg,\
    \ 0);\n        break;\n      }\n  }\n  mint append(mint a) {\n    g[n++] = a;\n\
    \    for (int p = 1;; p <<= 1) {\n      int l1 = p - 1, r1 = l1 + p, l2 = n -\
    \ p, r2 = n;\n      r1 = min(r1, (int)f.size());\n      if (l1 >= r1) break;\n\
    \      calc(l1, r1, l2, r2);\n      if (p == (-n & n)) break;\n    }\n    return\
    \ h[n - 1];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/semi-relaxed.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/semi-relaxed.hpp
layout: document
redirect_from:
- /library/fps/semi-relaxed.hpp
- /library/fps/semi-relaxed.hpp.html
title: fps/semi-relaxed.hpp
---
