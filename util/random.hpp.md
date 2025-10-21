---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Random
    links: []
  bundledCode: "#line 2 \"util/random.hpp\"\n\nnamespace Random {\nmt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    uint64_t get() { return gen(); }\ntemplate <class T>\nT get(T n) { return get()\
    \ % n; }\ntemplate <class T>\nT get(T l, T r) { return get(r - l) % (r - l + 1)\
    \ + l; }\ndouble uniform() { return double(get(1 << 30)) / (1 << 30); }\n\ntemplate\
    \ <class T>\nvector<T> get_vector(size_t n, T l, T r) {\n  vector<T> a(n);\n \
    \ for (auto& v : a) v = get(l, r);\n  return a;\n}\n\ntemplate <class Iter>\n\
    void shuffle(Iter begin, Iter end) {\n  if (begin == end) return;\n  int n = end\
    \ - begin;\n  for (int i = n - 1; i > 0; i--) {\n    int j = get(i + 1);\n   \
    \ if (j < i) swap(*(begin + i), *(begin + j));\n  }\n}\n};  // namespace Random\n\
    \n/**\n * @brief Random\n */\n"
  code: "#pragma once\n\nnamespace Random {\nmt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());\n\
    uint64_t get() { return gen(); }\ntemplate <class T>\nT get(T n) { return get()\
    \ % n; }\ntemplate <class T>\nT get(T l, T r) { return get(r - l) % (r - l + 1)\
    \ + l; }\ndouble uniform() { return double(get(1 << 30)) / (1 << 30); }\n\ntemplate\
    \ <class T>\nvector<T> get_vector(size_t n, T l, T r) {\n  vector<T> a(n);\n \
    \ for (auto& v : a) v = get(l, r);\n  return a;\n}\n\ntemplate <class Iter>\n\
    void shuffle(Iter begin, Iter end) {\n  if (begin == end) return;\n  int n = end\
    \ - begin;\n  for (int i = n - 1; i > 0; i--) {\n    int j = get(i + 1);\n   \
    \ if (j < i) swap(*(begin + i), *(begin + j));\n  }\n}\n};  // namespace Random\n\
    \n/**\n * @brief Random\n */"
  dependsOn: []
  isVerificationFile: false
  path: util/random.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/random.hpp
layout: document
redirect_from:
- /library/util/random.hpp
- /library/util/random.hpp.html
title: Random
---
