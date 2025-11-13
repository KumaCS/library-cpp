---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/binary-search-tree/UNIT_rbst_array.test.cpp
    title: verify/binary-search-tree/UNIT_rbst_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: XOR shift
    links: []
  bundledCode: "#line 2 \"util/xorshift.hpp\"\n\nnamespace XORShift {\nunsigned int\
    \ xor32() {\n  static unsigned int x = 123456789u;\n  x ^= x << 13, x ^= x >>\
    \ 17, x ^= x << 5;\n  return x;\n}\nunsigned long long xor64() {\n  static unsigned\
    \ long long x = 123456789ull;\n  x ^= x << 13, x ^= x >> 7, x ^= x << 17;\n  return\
    \ x;\n}\n};  // namespace XORShift\n\n/**\n * @brief XOR shift\n */\n"
  code: "#pragma once\n\nnamespace XORShift {\nunsigned int xor32() {\n  static unsigned\
    \ int x = 123456789u;\n  x ^= x << 13, x ^= x >> 17, x ^= x << 5;\n  return x;\n\
    }\nunsigned long long xor64() {\n  static unsigned long long x = 123456789ull;\n\
    \  x ^= x << 13, x ^= x >> 7, x ^= x << 17;\n  return x;\n}\n};  // namespace\
    \ XORShift\n\n/**\n * @brief XOR shift\n */"
  dependsOn: []
  isVerificationFile: false
  path: util/xorshift.hpp
  requiredBy: []
  timestamp: '2025-11-13 15:25:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/binary-search-tree/UNIT_rbst_array.test.cpp
documentation_of: util/xorshift.hpp
layout: document
redirect_from:
- /library/util/xorshift.hpp
- /library/util/xorshift.hpp.html
title: XOR shift
---
