$d-1$ 次の FPS $f(x)$ について，$\dfrac{1}{f(x)}$ の $x^n$ から $x^{n+d-1}$ の係数を $O(d\log d\log n)$ 時間で求める．

これは $x^{-n}\bmod f(x)$ を求めることとも等価．

## アルゴリズム

$f(x)$ の $x^a$ から $x^{b-1}$ の係数を並べた列を $[x^{[a,b)}]f(x)$ で表すことにする．

以下が成り立つ．

$$[x^{[n,n+d)}]\frac{1}{Q(x)}=[x^{[n,n+d)}]\frac{Q(-x)}{Q(x)Q(-x)}$$

後から $Q(-x)$ を掛けることを考えると $[x^{[n-d,n+d)}]\dfrac{1}{Q(x)Q(-x)}$ を求めればよい．

$Q(x)Q(-x)=Q'(x^2)$ とおくと $[x^{[\lceil(n-d)/2\rceil,\lceil (n+d)/2\rceil)}]\dfrac{1}{Q'(x)}$ に帰着される．

$n$ が十分小さい場合は naive に計算してしまって構わない．
- 実装の場合分けを減らすため $n\leq d$ のとき naive に計算している．

## FFT 削減

疑似コードで書くと以下のようになる．

```
shift(n, f): // 1/f(x) の x^n から x^(n+d-1) を返す
  if n is small:
    return naive(n, f)
  f1(x) = f(-x)
  g(x^2) = f(x) * f1(x)
  g(x) = shift(ceil((n-d)/2), g) // d-1 次多項式とみなす
  g(x) = g(x^2) * x^((n-d)%2)
  return g(x) * f1(x) の x^d から x^(2d-1)
```

[FFT の回数を削減するテクニック集 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/12/10/163348) のテクニックを使える部分が多い．