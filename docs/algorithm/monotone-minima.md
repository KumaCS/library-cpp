注意：以下では適当にタイブレークすることで $\operatorname{arg\,min}$ を集合ではなく添字を返す関数とみなす．

タイブレークは行によらないものならなんでもよい．

## (totally) monotone

$N\times M$ 行列 $A=(A_{i,j})$ について，

$$i \leq i' \implies \operatorname{arg\,min}_{j}A_{i,j} \leq \operatorname{arg\,min}_{j}A_{i',j}$$

が成り立つとき $A$ は **monotone** であるという．

また $A$ の任意の部分行列が monotone であるとき，$A$ は **totally monotone** であるという．

## monotone minima

$A$ は monotone とする．
$i=1,2,\dots,N$ に対して $\operatorname{arg\,min}_{j}A_{i,j}$ を $O(M\log N)$ 時間で列挙できる．

まず $i_m\coloneqq\lfloor N/2\rfloor$ 行目の argmin $j_m$ を線形探索により $O(M)$ 時間で発見できる．
その後，$[1,i,m-1]\times[1,j_m]$ と $[i_m+1,N]\times[j_m,M]$ の範囲それぞれについて再帰的に計算する．

$N\times M$ 行列を陽に持つとそれだけで $O(NM)$ 時間かかるので，実際には以下のようなものから計算することが多い．

- $(i,j)$ 成分と $(i,k)$ 成分を比較した結果を返す関数．
- $(i,j)$ 成分を返す関数．

## 応用: min-plus convolution

monotone minima を用いることで min-plus convolution が計算できる．

詳細は該当ライブラリのページを参照．

## 関連

(totally) monotone 性と関係している性質として Monge 性がある．

参照：[[Monge まとめ①] Monge 性とは？](https://hackmd.io/@tatyam-prime/monge1)