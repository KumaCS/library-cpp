永続ポテンシャル付き Union Find．

通常の Union Find の連結性に加えて，各頂点 $v$ に値 $p_v$ があるとして差分の情報を管理する．
各状態を snapshot として保存し，あとから過去の状態に戻せる．

`PersistentPotentializedUnionFind<G>` として使う．
`G` は `value_type`, `op(x,y)`, `e()`, `inv(x)` を持つ群を表す型．
加法の場合は `AddGroup<T>` を使えばよい．

- `find(v)`：頂点 $v$ を含む連結成分の代表頂点を返す．
- `size(v)`：頂点 $v$ を含む連結成分の頂点数を返す．
- `same(u, v)`：頂点 $u,v$ が同じ連結成分に含まれるかを返す．
- `diff(u, v)`：$p_u-p_v$ に対応する値を返す．
- `unite(u, v, w)`：$p_u-p_v=w$ という制約を追加する．既存の情報と矛盾しないかを返す．
- `take_snapshot()`：現在の状態を保存し，その番号を返す．
- `apply_snapshot(k)`：保存した状態 `k` に戻す．

永続化には `PersistentArray` を用いているため，path compression は行わない．
各操作の時間計算量は木の高さと永続配列の更新に依存する．
