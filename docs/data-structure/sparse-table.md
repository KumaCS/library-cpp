更新のない列に対する半開区間の積を Sparse Table で求める．

演算は結合則と冪等性 $x\cdot x=x$ を満たす必要がある．可換性と単位元は不要．

- `SparseTable(a)`：列 `a` から構築する．空列も構築できる．
- `prod(l, r)`：$a_l\cdot a_{l+1}\cdots a_{r-1}$ を返す．$0\leq l<r\leq n$．

計算量は前処理 $O(n\log n)$ 時間，クエリ $O(1)$ 時間．
