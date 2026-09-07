よく使う Lazy Segment Tree の型エイリアス集．

`LazySegmentTree` に渡す演算を毎回定義せずに使えるようにするための utility．

- `LazySegmentTreeAddSum<T>`：列 $A$ に対し区間加算と区間和取得を行う．
  - `set(p, x)`：$A_p\gets x$ とする．
  - `get(p)`：$A_p$ を取得する．
  - `prod(l, r)`：$A_l+\cdots+A_{r-1}$ を取得する．
  - `apply(l, r, x)`：$i=l,\dots,r-1$ に対し $A_i\gets A_i+x$ とする．
- `LazySegmentTreeMulSum<T>`：列 $A$ に対し区間乗算と区間和取得を行う．

より細かい操作は基底クラス `LazySegmentTree` のメソッドを用いる．
