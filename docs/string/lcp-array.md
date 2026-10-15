辞書順に隣り合う suffix の最長共通接頭辞の長さを求める．

`LCPArray(s, sa)` は長さ $n-1$ の列 `lcp` を返す．
`lcp[i]` は `s[sa[i]:]` と `s[sa[i+1]:]` の LCP の長さである．
`s` は `string` または `vector<T>`，`sa` は `s` の suffix array とし，$n\geq 1$ を要求する．

計算量は $O(n)$ 時間．
