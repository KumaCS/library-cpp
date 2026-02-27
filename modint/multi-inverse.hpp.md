---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-interpolation.hpp
    title: "\u591A\u9805\u5F0F\u88DC\u9593"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_polynomial_interpolation.test.cpp
    title: verify/fps/LC_polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/LC_polynomial_interpolation_on_geometric_sequence.test.cpp
    title: verify/fps/LC_polynomial_interpolation_on_geometric_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
    title: verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/modint/UNIT_multi_inverse.test.cpp
    title: verify/modint/UNIT_multi_inverse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u8907\u6570\u306E\u8981\u7D20\u306E\u9006\u5143\u3092\u4E00\u62EC\
      \u3067\u8A08\u7B97"
    links: []
  bundledCode: "#line 2 \"modint/multi-inverse.hpp\"\n\ntemplate <class mint>\nvector<mint>\
    \ MultiInverse(const vector<mint>& a) {\n  if (a.empty()) return {};\n  vector<mint>\
    \ b(a.begin(), a.end());\n  for (int i = 0; i + 1 < b.size(); i++) b[i + 1] *=\
    \ b[i];\n  mint c = b.back().inv();\n  for (int i = a.size() - 1; i > 0; i--)\
    \ {\n    b[i] = c * b[i - 1];\n    c *= a[i];\n  }\n  b[0] = c;\n  return b;\n\
    }\n/**\n * @brief \u8907\u6570\u306E\u8981\u7D20\u306E\u9006\u5143\u3092\u4E00\
    \u62EC\u3067\u8A08\u7B97\n */\n"
  code: "#pragma once\n\ntemplate <class mint>\nvector<mint> MultiInverse(const vector<mint>&\
    \ a) {\n  if (a.empty()) return {};\n  vector<mint> b(a.begin(), a.end());\n \
    \ for (int i = 0; i + 1 < b.size(); i++) b[i + 1] *= b[i];\n  mint c = b.back().inv();\n\
    \  for (int i = a.size() - 1; i > 0; i--) {\n    b[i] = c * b[i - 1];\n    c *=\
    \ a[i];\n  }\n  b[0] = c;\n  return b;\n}\n/**\n * @brief \u8907\u6570\u306E\u8981\
    \u7D20\u306E\u9006\u5143\u3092\u4E00\u62EC\u3067\u8A08\u7B97\n */"
  dependsOn: []
  isVerificationFile: false
  path: modint/multi-inverse.hpp
  requiredBy:
  - fps/polynomial-interpolation.hpp
  timestamp: '2025-10-31 21:40:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fps/UNIT_prefix_sum_of_polynomial.test.cpp
  - verify/fps/LC_polynomial_interpolation.test.cpp
  - verify/fps/LC_polynomial_interpolation_on_geometric_sequence.test.cpp
  - verify/modint/UNIT_multi_inverse.test.cpp
documentation_of: modint/multi-inverse.hpp
layout: document
redirect_from:
- /library/modint/multi-inverse.hpp
- /library/modint/multi-inverse.hpp.html
title: "\u8907\u6570\u306E\u8981\u7D20\u306E\u9006\u5143\u3092\u4E00\u62EC\u3067\u8A08\
  \u7B97"
---
