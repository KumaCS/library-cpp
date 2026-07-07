長さを実行時に決められる bitset．

内部では `uint64_t` ごとに bit を詰めて保持する．`std::bitset` と同様に `set`, `reset`, `flip`, `test`, `count`, `any`, `all`, `none`, bit 演算，shift 演算を提供する．

bit の番号は下位 bit から数える．`to_string()` は `std::bitset` と同じく，添字の大きい bit から順に文字列化する．

`find_first()` は立っている最小の bit を返す．存在しない場合は `size()` を返す．
`find_next(i)` は `i` より大きい位置で立っている最小の bit を返す．存在しない場合は `size()` を返す．
