非負整数の multiset を bit ごとの trie で管理するデータ構造．

`BinaryTrie<I, B, C>` として使う．`I` は値の型，`B` は見る bit 数，`C` は個数の型．管理できる値は $0 \leq x < 2^B$．

- `add(x, cnt = 1)`：値 `x` の個数を `cnt` 増やす．削除は `cnt = -1` で行う．
- `count(x)`：値 `x` の個数を返す．
- `contains(x)`：値 `x` が存在するか判定する．
- `insert(x)`：値 `x` が存在しなければ追加して `true` を返す．既に存在する場合は何もせず `false` を返す．
- `erase(x)`：値 `x` が存在すれば 1 個削除して `true` を返す．存在しない場合は何もせず `false` を返す．
- `count_leq(x, xor_val = 0)`：`(y xor xor_val) <= x` を満たす要素 `y` の個数を返す．
- `min_element(k = 0, xor_val = 0)`：`y xor xor_val` が小さい順で `k` 番目の要素 `y` を返す．
- `max_element(k = 0, xor_val = 0)`：`y xor xor_val` が大きい順で `k` 番目の要素 `y` を返す．

`min_element`, `max_element` の `k` は 0-indexed．存在する要素数未満であることを要求する．

`add(x, cnt)` は `x` の個数が負にならないことを要求する．

各操作の計算量は $O(B)$．
