通常の Union Find のほかに列 $(p_0,p_1,\dots,p_{n-1})$ に関する情報を管理する．

`PotentializedUnionFind<G>` として使う．
`G` は `value_type`, `op(x,y)`, `e()`, `inv(x)` を持つ群を表す型．
加法の場合は `AddGroup<T>` を使えばよい．

- `find(v)`：頂点 $v$ を含む連結成分の代表頂点を返す．
- `size(v)`：頂点 $v$ を含む連結成分の頂点数を返す．
- `same(u, v)`：頂点 $u,v$ が同じ連結成分に含まれるかを返す．
- `unite(u, v, w)`：$p_u-p_v=w$ という情報を追加する．それまでの情報と矛盾しないかを返す．
- `diff(u, v)`：$p_u-p_v$ に対応する値を返す．

## アルゴリズム

Union Find の内部において $p_v$ から $v$ を含む連結成分の根の $p$ の値を減じたものを管理する．
