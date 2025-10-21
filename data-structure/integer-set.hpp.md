---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6574\u6570\u306E\u96C6\u5408(64\u5206\u6728)"
    links: []
  bundledCode: "#line 2 \"data-structure/integer-set.hpp\"\n\ntemplate <class T =\
    \ unsigned int, class U = unsigned long long>\nclass IntegerSet {\n private:\n\
    \  const static T B = 6, W = 64, MASK = W - 1;\n  T size;\n  vector<T> start;\n\
    \  vector<U> data;\n  static T high_bit(U x) {\n    if (x == 0) return 0;\n  \
    \  return W - 1 - countl_zero(x);\n  }\n  static T low_bit(U x) {\n    if (x ==\
    \ 0) return W;\n    return countr_zero(x);\n  }\n\n public:\n  IntegerSet(T n)\
    \ {\n    size = n;\n    vector<T> len;\n    do len.push_back((n >>= B) + 1);\n\
    \    while (n > 0);\n    start = vector<T>(1, 0);\n    start.reserve(len.size()\
    \ + 1);\n    for (const auto v : len) start.push_back(start.back() + v);\n   \
    \ data = vector<U>(start.back());\n  }\n  IntegerSet(string s = \"\") {\n    T\
    \ n = size = s.size();\n    vector<T> len;\n    do len.push_back((n >>= B) + 1);\n\
    \    while (n > 0);\n    start = vector<T>(1, 0);\n    start.reserve(len.size()\
    \ + 1);\n    for (const auto v : len) start.push_back(start.back() + v);\n   \
    \ data = vector<U>(start.back());\n\n    for (T i = 0; i < s.size(); i++)\n  \
    \    if (s[i] == '1') data[i >> B] |= U(1) << (i & MASK);\n    for (T i = 0; i\
    \ + 1 < len.size(); i++)\n      for (T j = 0; j < len[i]; j++)\n        if (data[start[i]\
    \ + j])\n          data[start[i + 1] + (j >> B)] |= U(1) << (j & MASK);\n  }\n\
    \  void add(T x) {\n    for (T i = 0; i + 1 < start.size(); i++) {\n      data[start[i]\
    \ + (x >> B)] |= U(1) << (x & MASK);\n      x >>= B;\n    }\n  }\n  void remove(T\
    \ x) {\n    for (T i = 0; i + 1 < start.size(); i++) {\n      data[start[i] +\
    \ (x >> B)] &= ~(U(1) << (x & MASK));\n      if (data[start[i] + (x >> B)] !=\
    \ 0) return;\n      x >>= B;\n    }\n  }\n  bool contains(T x) const { return\
    \ (data[x >> B] >> (x & MASK)) & 1; }\n  optional<T> min(T x) const {\n    T d\
    \ = 0, i = x;\n    while (true) {\n      if (d + 1 >= start.size()) return nullopt;\n\
    \      if ((i >> B) >= start[d + 1] - start[d]) return nullopt;\n      U m = data[start[d]\
    \ + (i >> B)] & ((~U(0)) << (i & MASK));\n      if (m == 0) {\n        d++;\n\
    \        i >>= B;\n        i++;\n      } else {\n        i = (i & ~MASK) + low_bit(m);\n\
    \        if (d == 0) break;\n        i <<= B;\n        d--;\n      }\n    }\n\
    \    return i;\n  }\n  optional<T> max(T x) const {\n    T d = 0, i = x;\n   \
    \ while (true) {\n      if (i >= size) return nullopt;\n      if (d >= data.size())\
    \ return nullopt;\n      U m = data[start[d] + (i >> B)] & ~((~U(1)) << (i & MASK));\n\
    \      if (m == 0) {\n        d++;\n        i >>= B;\n        i--;\n      } else\
    \ {\n        i = (i & ~MASK) + high_bit(m);\n        if (d == 0) break;\n    \
    \    i <<= B;\n        i |= MASK;\n        d--;\n      }\n    }\n    return i;\n\
    \  }\n};\n\n/**\n * @brief \u6574\u6570\u306E\u96C6\u5408(64\u5206\u6728)\n */\n"
  code: "#pragma once\n\ntemplate <class T = unsigned int, class U = unsigned long\
    \ long>\nclass IntegerSet {\n private:\n  const static T B = 6, W = 64, MASK =\
    \ W - 1;\n  T size;\n  vector<T> start;\n  vector<U> data;\n  static T high_bit(U\
    \ x) {\n    if (x == 0) return 0;\n    return W - 1 - countl_zero(x);\n  }\n \
    \ static T low_bit(U x) {\n    if (x == 0) return W;\n    return countr_zero(x);\n\
    \  }\n\n public:\n  IntegerSet(T n) {\n    size = n;\n    vector<T> len;\n   \
    \ do len.push_back((n >>= B) + 1);\n    while (n > 0);\n    start = vector<T>(1,\
    \ 0);\n    start.reserve(len.size() + 1);\n    for (const auto v : len) start.push_back(start.back()\
    \ + v);\n    data = vector<U>(start.back());\n  }\n  IntegerSet(string s = \"\"\
    ) {\n    T n = size = s.size();\n    vector<T> len;\n    do len.push_back((n >>=\
    \ B) + 1);\n    while (n > 0);\n    start = vector<T>(1, 0);\n    start.reserve(len.size()\
    \ + 1);\n    for (const auto v : len) start.push_back(start.back() + v);\n   \
    \ data = vector<U>(start.back());\n\n    for (T i = 0; i < s.size(); i++)\n  \
    \    if (s[i] == '1') data[i >> B] |= U(1) << (i & MASK);\n    for (T i = 0; i\
    \ + 1 < len.size(); i++)\n      for (T j = 0; j < len[i]; j++)\n        if (data[start[i]\
    \ + j])\n          data[start[i + 1] + (j >> B)] |= U(1) << (j & MASK);\n  }\n\
    \  void add(T x) {\n    for (T i = 0; i + 1 < start.size(); i++) {\n      data[start[i]\
    \ + (x >> B)] |= U(1) << (x & MASK);\n      x >>= B;\n    }\n  }\n  void remove(T\
    \ x) {\n    for (T i = 0; i + 1 < start.size(); i++) {\n      data[start[i] +\
    \ (x >> B)] &= ~(U(1) << (x & MASK));\n      if (data[start[i] + (x >> B)] !=\
    \ 0) return;\n      x >>= B;\n    }\n  }\n  bool contains(T x) const { return\
    \ (data[x >> B] >> (x & MASK)) & 1; }\n  optional<T> min(T x) const {\n    T d\
    \ = 0, i = x;\n    while (true) {\n      if (d + 1 >= start.size()) return nullopt;\n\
    \      if ((i >> B) >= start[d + 1] - start[d]) return nullopt;\n      U m = data[start[d]\
    \ + (i >> B)] & ((~U(0)) << (i & MASK));\n      if (m == 0) {\n        d++;\n\
    \        i >>= B;\n        i++;\n      } else {\n        i = (i & ~MASK) + low_bit(m);\n\
    \        if (d == 0) break;\n        i <<= B;\n        d--;\n      }\n    }\n\
    \    return i;\n  }\n  optional<T> max(T x) const {\n    T d = 0, i = x;\n   \
    \ while (true) {\n      if (i >= size) return nullopt;\n      if (d >= data.size())\
    \ return nullopt;\n      U m = data[start[d] + (i >> B)] & ~((~U(1)) << (i & MASK));\n\
    \      if (m == 0) {\n        d++;\n        i >>= B;\n        i--;\n      } else\
    \ {\n        i = (i & ~MASK) + high_bit(m);\n        if (d == 0) break;\n    \
    \    i <<= B;\n        i |= MASK;\n        d--;\n      }\n    }\n    return i;\n\
    \  }\n};\n\n/**\n * @brief \u6574\u6570\u306E\u96C6\u5408(64\u5206\u6728)\n */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/integer-set.hpp
  requiredBy: []
  timestamp: '2025-10-21 23:07:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/integer-set.hpp
layout: document
redirect_from:
- /library/data-structure/integer-set.hpp
- /library/data-structure/integer-set.hpp.html
title: "\u6574\u6570\u306E\u96C6\u5408(64\u5206\u6728)"
---
