複数のパターン文字列を Aho-Corasick automaton で検索する．

パターン文字列から構築した Trie に failure link と遷移を追加した automaton である．検索文字列を先頭から 1 文字ずつ automaton に通すことで，すべてのパターンを同時に検索する．

`AhoCorasick<char_size, char_start>` として使う．扱える文字は `char_start` 以上 `char_start + char_size` 未満とし，空のパターン文字列は扱わない．すべてのパターンを追加してから `build()` を 1 回呼び，以降はパターンを追加しないことを要求する．

- `add(s)`：パターン `s` を追加し，追加順の ID を返す．
- `size()`：追加したパターン数を返す．
- `node_size()`：automaton のノード数を返す．
- `get_root()`：root の index を返す．
- `accept(v)`：ノード `v` で一致するパターン ID の列を返す．
- `build()`：failure link と遷移を構築する．
- `move(v, c)`：ノード `v` から文字 `c` で遷移した先を返す．
- `match(s)`：`s` における各パターンの出現回数を `unordered_map<ID, count>` で返す．出現しない ID は含まない．
- `match_any(s)`：`s` における全パターンの出現回数の総和を返す．

## アルゴリズム

Trie の各ノードを，root からそのノードまでの文字列と同一視する．ノード $v$ の failure link を，$v$ 自身を除く suffix のうち Trie に存在する最長のものに対応するノードへの辺とする．

failure link は root に近いノードから BFS 順に構築する．ノード $v$ から文字 $c$ に対応する Trie の辺が存在する場合，遷移先を $u$ とすると，$u$ の failure link は $v$ の failure link から $c$ で遷移した先となる．辺が存在しない場合は，$v$ の failure link から $c$ で遷移した先を $v$ からの遷移先とする．root に対応する遷移先が存在しない場合は root へ戻る．

各ノードには，そのノードで終端するパターンに加えて，failure link の遷移先で終端するパターンも保持する．これにより，検索時には現在のノードが保持する ID を列挙すれば，その位置で終わるすべてのパターンを取得できる．

パターンの長さの総和を $L$，failure link に沿って複製されるパターン ID 数を $K$ とすると，`build()` は $O(char\_size\cdot L+K)$ 時間，$O(char\_size\cdot L+K)$ 空間．検索文字列の長さを $N$，報告する出現数を $M$ とすると，`match()` は期待 $O(N+M)$ 時間，`match_any()` は $O(N)$ 時間．

## 資料

- Alfred V. Aho and Margaret J. Corasick. Efficient string matching: an aid to bibliographic search. 1975.
