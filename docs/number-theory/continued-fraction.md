有限連分数の評価と，平方根の周期連分数展開を扱う．

- `ContinuedFraction::Finite<I>`：有限連分数の係数列を `terms` に保持する．
- `ContinuedFraction::Periodic<I>`：非周期部分を `prefix`，周期部分を `cycle` に保持する．
- `ContinuedFraction::calc(terms)`：$[a_0;a_1,\dots,a_{k-1}]$ の分子・分母を組で返す．空の係数列では `(1, 0)` を返す．
- `ContinuedFraction::calc(terms, a, b)`：初期値を `(a, b)` とし，係数 $q$ を後ろから見て `(a, b) = (q*a+b, a)` を繰り返す．組を渡す overload もある．
- `ContinuedFraction::sqrt(n)`：$\sqrt n$ の係数列を `Periodic<I>` で返す．$n\geq 1$ かつ $n$ は平方数でないものとする．

型 `I` の既定値は `long long`．演算途中の値も `I` に収まる必要がある．
