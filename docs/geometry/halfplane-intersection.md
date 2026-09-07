二次元平面上の複数の半平面の共通部分を求める．

各 `Line` について，有向直線 `a` $\to$ `b` の左側を閉半平面とする．

- `halfplane_intersection(ls)`：`ls` が表す半平面の共通部分を反時計回りの `Polygon` として返す．共通部分が空，退化，または非有界なら空の `Polygon` を返す．$O(|ls|\log |ls|)$ 時間．
