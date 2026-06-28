# 永続セグメント木

https://info.atcoder.jp/entry/algorithm_lectures/persistent_segment_tree

完全永続的（fully persistent）なセグメント木

https://nyaannyaan.github.io/library/segment-tree/persistent-segment-tree.hpp.html

`PersistentSegmentTree<M>` として使う．
`M` は `value_type`, `op(x,y)`, `e()` を持つモノイドを表す型．

`set`, `apply`, `get`, `prod` それぞれ以下のように 3 パターンの方法で呼び出せる

- `set(p, v)` : 最新の木で位置 `p` の値を `v` に更新した新たな木の根へのポインタを返す
- `set(time, p, v)` : 時刻 `time` の木で位置 `p` の値を `v` に更新した新たな木の根へのポインタを返す
- `set(ptr, p, v)` : 根が `ptr` の木で位置 `p` の値を `v` に更新した新たな木の根へのポインタを返す
