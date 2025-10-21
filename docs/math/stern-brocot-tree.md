## 使い方

Stern-Brocot Tree 上のノードに対応する構造体．

- `SternBrocotTreeNode()` : $1/1$．
- `SternBrocotTreeNode(T x, T y)` : $x/y$．
- `SternBrocotTreeNode(const vector<T> seq)` : SBT 上でのパス `seq` から復元．
- `get()` : 現在のノードに対応する値．
- `lower_bound()` : 現在のノードに対応する区間の左端の値．
- `upper_bound()` : 現在のノードに対応する区間の右端の値．
- `go_left(T d = 1)` : 左の子へ $d$ 回降りる．
- `go_right(T d = 1)` : 右の子へ $d$ 回降りる．
- `depth()` : SBT 上での深さを計算．
- `go_parent(T d = 1)` : 親へ $d$ 回上がる．深さが $d$ 未満なら $1/1$ で停止して `false` を返す．
- `SternBrocotTreeNode::lca(x, y)` : `x`, `y` の LCA を計算．
- `SternBrocotTreeNode::binary_search<F>(T n, F f)` : `f(a,b)` が `true` かつ分母が $n$ 以下の最小のノードを返す．
  - $f(a,b)$ は $a/b$ について単調であることが必要．