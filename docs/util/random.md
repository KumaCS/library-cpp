疑似乱数の生成と，乱数を用いる基本操作を提供する．

- `Random::get()`：`uint64_t` の乱数を返す．
- `Random::get(n)`：半開区間 $[0,n)$ の整数を返す．$0\lt n$ を要求する．
- `Random::get(l, r)`：半開区間 $[l,r)$ の整数を返す．$l\lt r$ を要求する．
- `Random::uniform()`：半開区間 $[0,1)$ の `double` を返す．
- `Random::get_vector(n, l, r)`：各要素が $[l,r)$ の長さ $n$ の列を返す．
- `Random::shuffle(first, last)`：範囲 $[first,last)$ を shuffle する．random access iterator を要求する．

整数生成には `std::mt19937_64` の出力の剰余を用いる．
