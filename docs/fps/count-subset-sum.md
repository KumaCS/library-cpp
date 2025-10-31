整数列 $A=(A_0,A_1,\dots,A_{M-1})$ が与えられる．
$k=0,1,\dots,N$ に対して $\sum_{i\in I}A_i=k$ を満たす $I\subseteq\{0,1,\dots,M-1\}$ の個数を $O(N\log N)$ 時間で列挙する．

## アルゴリズム

$\prod_{i}(1+x^{A_i})$ を $N$ 次まで計算できればよい．
以下のように変形する．

$$\prod_{i}(1+x^{A_i})=\exp\left(\log\prod_{i}(1+x^{A_i})\right)=\exp\left(\sum_{i}\log(1+x^{A_i})\right)$$

$\log(1+x^{A_i})$ は $A_i$ の倍数次の項だけをもつので，$\exp$ の中身は調和級数の議論で $O(N\log N)$ 時間で計算できる．
