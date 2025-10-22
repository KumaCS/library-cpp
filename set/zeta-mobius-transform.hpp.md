---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: set/and-convolution.hpp
    title: set/and-convolution.hpp
  - icon: ':x:'
    path: set/or-convolution.hpp
    title: set/or-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/set/LC_bitwise_and_convolution.or.test.cpp
    title: verify/set/LC_bitwise_and_convolution.or.test.cpp
  - icon: ':x:'
    path: verify/set/LC_bitwise_and_convolution.test.cpp
    title: verify/set/LC_bitwise_and_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set/zeta-mobius-transform.hpp\"\n\ntemplate <class T>\n\
    void SupsetZetaTransform(vector<T>& f) {\n  int n = f.size();\n  assert((n & (n\
    \ - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n;\
    \ j++) {\n      if ((j & i) == 0) {\n        f[j] += f[j | i];\n      }\n    }\n\
    \  }\n}\n\ntemplate <class T>\nvoid SupsetMobiusTransform(vector<T>& f) {\n  int\
    \ n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<=\
    \ 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n       \
    \ f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid SubsetZetaTransform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] += f[j];\n      }\n    }\n  }\n}\n\ntemplate <class T>\n\
    void SubsetMobiusTransform(vector<T>& f) {\n  int n = f.size();\n  assert((n &\
    \ (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j\
    \ < n; j++) {\n      if ((j & i) == 0) {\n        f[j | i] -= f[j];\n      }\n\
    \    }\n  }\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nvoid SupsetZetaTransform(vector<T>& f)\
    \ {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i <\
    \ n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n\
    \        f[j] += f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid\
    \ SupsetMobiusTransform(vector<T>& f) {\n  int n = f.size();\n  assert((n & (n\
    \ - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n;\
    \ j++) {\n      if ((j & i) == 0) {\n        f[j] -= f[j | i];\n      }\n    }\n\
    \  }\n}\n\ntemplate <class T>\nvoid SubsetZetaTransform(vector<T>& f) {\n  int\
    \ n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<=\
    \ 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n       \
    \ f[j | i] += f[j];\n      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid SubsetMobiusTransform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j | i] -= f[j];\n      }\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: set/zeta-mobius-transform.hpp
  requiredBy:
  - set/and-convolution.hpp
  - set/or-convolution.hpp
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/set/LC_bitwise_and_convolution.test.cpp
  - verify/set/LC_bitwise_and_convolution.or.test.cpp
documentation_of: set/zeta-mobius-transform.hpp
layout: document
redirect_from:
- /library/set/zeta-mobius-transform.hpp
- /library/set/zeta-mobius-transform.hpp.html
title: set/zeta-mobius-transform.hpp
---
