更新のない列の区間最小値を求める．

- `RangeMinQuery(a)`：列 `a` から構築する．空列も構築できる．
- `query(l, r)`：半開区間 $[l,r)$ の最小値を返す．$0\leq l<r\leq n$．

block 内の最小値は monotone stack を bit mask に保持して求め，block 間は prefix・suffix の最小値と Sparse Table を使う．
計算量は実質的に前計算 $O(n)$ 時間，クエリ $O(1)$ 時間．
