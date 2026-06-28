永続 Union Find．

$n$ 頂点 $0$ 辺のグラフに対して連結性を管理し，各状態を snapshot として保存できる．
過去の状態に戻してから更新することで，永続的な Union Find として使える．

- `find(v)`：頂点 $v$ を含む連結成分の代表頂点を返す．
- `size(v)`：頂点 $v$ を含む連結成分の頂点数を返す．
- `same(u, v)`：頂点 $u,v$ が同じ連結成分に含まれるかを返す．
- `unite(u, v)`：辺 $uv$ を追加する．すでに同じ連結成分なら `false`，そうでなければ `true` を返す．
- `take_snapshot()`：現在の状態を保存し，その番号を返す．
- `apply_snapshot(k)`：`take_snapshot` で保存した状態 `k` に戻す．

永続化には `PersistentArray` を用いているため，path compression は行わない．
union by size により根付き木の高さを抑える．
