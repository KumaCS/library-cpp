---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: set/zeta-mobius-transform.hpp
    title: set/zeta-mobius-transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/set/LC_bitwise_and_convolution.or.test.cpp
    title: verify/set/LC_bitwise_and_convolution.or.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set/or-convolution.hpp\"\n\n#line 2 \"set/zeta-mobius-transform.hpp\"\
    \n\ntemplate <class T>\nvoid SupsetZetaTransform(vector<T>& f) {\n  int n = f.size();\n\
    \  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int\
    \ j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n        f[j] += f[j | i];\n\
    \      }\n    }\n  }\n}\n\ntemplate <class T>\nvoid SupsetMobiusTransform(vector<T>&\
    \ f) {\n  int n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1;\
    \ i < n; i <<= 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0)\
    \ {\n        f[j] -= f[j | i];\n      }\n    }\n  }\n}\n\ntemplate <class T>\n\
    void SubsetZetaTransform(vector<T>& f) {\n  int n = f.size();\n  assert((n & (n\
    \ - 1)) == 0);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int j = 0; j < n;\
    \ j++) {\n      if ((j & i) == 0) {\n        f[j | i] += f[j];\n      }\n    }\n\
    \  }\n}\n\ntemplate <class T>\nvoid SubsetMobiusTransform(vector<T>& f) {\n  int\
    \ n = f.size();\n  assert((n & (n - 1)) == 0);\n  for (int i = 1; i < n; i <<=\
    \ 1) {\n    for (int j = 0; j < n; j++) {\n      if ((j & i) == 0) {\n       \
    \ f[j | i] -= f[j];\n      }\n    }\n  }\n}\n#line 4 \"set/or-convolution.hpp\"\
    \n\ntemplate <class T>\nvector<T> OrConvolution(vector<T> a, vector<T> b) {\n\
    \  assert(a.size() == b.size());\n  SubsetZetaTransform(a);\n  SubsetZetaTransform(b);\n\
    \  for (int i = 0; i < a.size(); i++) a[i] *= b[i];\n  SubsetMobiusTransform(a);\n\
    \  return a;\n}\n"
  code: "#pragma once\n\n#include \"./zeta-mobius-transform.hpp\"\n\ntemplate <class\
    \ T>\nvector<T> OrConvolution(vector<T> a, vector<T> b) {\n  assert(a.size() ==\
    \ b.size());\n  SubsetZetaTransform(a);\n  SubsetZetaTransform(b);\n  for (int\
    \ i = 0; i < a.size(); i++) a[i] *= b[i];\n  SubsetMobiusTransform(a);\n  return\
    \ a;\n}"
  dependsOn:
  - set/zeta-mobius-transform.hpp
  isVerificationFile: false
  path: set/or-convolution.hpp
  requiredBy: []
  timestamp: '2025-10-10 17:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/set/LC_bitwise_and_convolution.or.test.cpp
documentation_of: set/or-convolution.hpp
layout: document
redirect_from:
- /library/set/or-convolution.hpp
- /library/set/or-convolution.hpp.html
title: set/or-convolution.hpp
---
