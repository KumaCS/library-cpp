Project Selection Problem を最大流に帰着して解く．

- `add_project()`: 新しい project を追加し、その番号を返す．
- `solve()`: 最大利益を返す．毎回新規に最大流を解く．

扱える制約

- `gain0(x, w)`: `x = 0` のとき `w` を得る．
- `gain1(x, w)`: `x = 1` のとき `w` を得る．
- `lose0(x, w)`: `x = 0` のとき `w` を失う．
- `lose1(x, w)`: `x = 1` のとき `w` を失う．
- `ban0(x)`: `x = 0` を禁止する．
- `ban1(x)`: `x = 1` を禁止する．
- `gain_same(x, y, w)`: `x = y` のとき `w` を得る．
- `lose_diff(x, y, w)`: `x != y` のとき `w` を失う．
