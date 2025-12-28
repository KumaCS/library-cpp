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
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n\nstruct RollingHash {\n  using\
    \ u128 = __uint128_t;\n  using u64 = uint64_t;\n  static const u64 MOD = (1ll\
    \ << 61) - 1;\n  static u64 base;\n  static u64 add(u64 x, u64 y) {\n    if ((x\
    \ += y) >= MOD) x -= MOD;\n    return x;\n  }\n  static u64 sub(u64 x, u64 y)\
    \ {\n    if ((x -= y) >= MOD) x += MOD;\n    return x;\n  }\n  static u64 mul(u64\
    \ x, u64 y) {\n    return (u64)((u128)x * y % MOD);\n  }\n  vector<u64> hash,\
    \ pw;\n  RollingHash() : hash({0}), pw({1}) {}\n  template <class T>\n  RollingHash(vector<T>&\
    \ a) : hash({0}), pw({1}) {\n    for (auto v : a) push(v);\n  }\n  template <class\
    \ T>\n  void push(T v) {\n    hash.push_back(add(mul(base, hash.back()), v));\n\
    \    pw.push_back(mul(base, pw.back()));\n  }\n  u64 get(int l, int r) {\n   \
    \ assert(l <= r);\n    return sub(hash[r], mul(hash[l], pw[r - l]));\n  }\n};\n\
    RollingHash::u64 RollingHash::base = []() {\n  random_device seed_gen;\n  mt19937\
    \ rnd(seed_gen());\n  return rnd() % (1ull << 40);\n}();\n"
  code: "#pragma once\n\nstruct RollingHash {\n  using u128 = __uint128_t;\n  using\
    \ u64 = uint64_t;\n  static const u64 MOD = (1ll << 61) - 1;\n  static u64 base;\n\
    \  static u64 add(u64 x, u64 y) {\n    if ((x += y) >= MOD) x -= MOD;\n    return\
    \ x;\n  }\n  static u64 sub(u64 x, u64 y) {\n    if ((x -= y) >= MOD) x += MOD;\n\
    \    return x;\n  }\n  static u64 mul(u64 x, u64 y) {\n    return (u64)((u128)x\
    \ * y % MOD);\n  }\n  vector<u64> hash, pw;\n  RollingHash() : hash({0}), pw({1})\
    \ {}\n  template <class T>\n  RollingHash(vector<T>& a) : hash({0}), pw({1}) {\n\
    \    for (auto v : a) push(v);\n  }\n  template <class T>\n  void push(T v) {\n\
    \    hash.push_back(add(mul(base, hash.back()), v));\n    pw.push_back(mul(base,\
    \ pw.back()));\n  }\n  u64 get(int l, int r) {\n    assert(l <= r);\n    return\
    \ sub(hash[r], mul(hash[l], pw[r - l]));\n  }\n};\nRollingHash::u64 RollingHash::base\
    \ = []() {\n  random_device seed_gen;\n  mt19937 rnd(seed_gen());\n  return rnd()\
    \ % (1ull << 40);\n}();"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2025-12-29 01:13:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
