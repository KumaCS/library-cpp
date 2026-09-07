## トーシェント関数

オイラーのトーシェント関数 $\phi(n)$ に関する関数群．

### `TotientFunction::table(n)`

列挙．`phi[i] = \phi(i)` を満たす長さ `n + 1` の列を返す．

最小素因数列挙に依存し，時間計算量は $O(N\log\log N)$．

### `TotientFunction::sum<T>(n)`

$\sum_{i=1}^{n}\phi(i)$ を返す．

時間計算量は $O(n^{2/3+\varepsilon})$．

値は 64 bit 整数に収まらないことがあるため，`T` には modint や `__int128_t` などを指定する．

参考：[トーティエント関数$\varphi(i)$の和$\sum_{i=1}^{N}{\varphi (i)}$を$O(N^{2/3}(\log\log{N})^{1/3})$で求める Wiki - yukicoder](https://yukicoder.me/wiki/sum_totient)
