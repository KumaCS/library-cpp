よく使う Segment Tree の型エイリアス集．

`SegmentTree` に渡す演算を毎回定義せずに使えるようにするための utility．

- `SegmentTreeSum<T>`：区間和を管理する．単位元は `T{}`．
- `SegmentTreeProd<T>`：区間積を管理する．単位元は `T{1}`．
- `SegmentTreeMax<T, e>`：区間最大値を管理する．単位元は `e`．
- `SegmentTreeMin<T, e>`：区間最小値を管理する．単位元は `e`．

構築後の操作は基底クラス `SegmentTree` と同じ．
`set`, `apply`, `get`, `prod`, `max_right`, `min_left` などを使える．
