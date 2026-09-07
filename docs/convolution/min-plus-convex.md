二つの数列 $(a_0,\dots,a_{n-1}),(b_0,\dots,b_{m-1})$ から以下を満たす数列 $(c_0,\dots,c_{n+m-2})$ を計算する．

$$c_k=\min_{i+j=k}(a_i+b_j)$$

ただし $a$ は下に凸，すなわち $a_i-a_{i-1}\leq a_{i+1}-a_i$ を満たす必要がある．

- monotone minima を用いる場合 $O((n+m)\log(n+m))$ 時間．
- SMAWK を用いるか $b$ も凸な場合 $O(n+m)$ 時間．

monotone minima と SMAWK は実用上だと定数倍の問題で大差ないという話もある．

## convex-arbitrary

$A_{i,j}=a_{i-j}+b_j$ として $(n+m-1)\times m$ 行列 $A$ を考える．
ただし値が存在しない場所は $\infty$ で埋める．

ある $i$ および $k\lt l$ に対し $A_{i,k}\gt A_{i,l}$ であると仮定する．
このとき任意の $j\gt i$ について

$$A_{j,k}-A_{j,l}=a_{j-k}-a_{j-l}+b_k-b_l\geq a_{i-k}-a_{i-l}+b_k-b_l=A_{i,k}-A_{i,l}\gt 0$$

より $A_{j,k}\gt A_{j,l}$ である．

従って $A$ は monotone であり，monotone minima や SMAWK によって列毎の argmin が列挙できる．
argmin が求まれば $c$ も容易に計算できる．

## convex-convex

上の議論をまとめれば $f(k)=\min\operatorname{arg\,min}_{i}(a_{k-i}+b_i)$ は $k$ について単調増加である．

$a,b$ を入れ替えても同じことがいえることから，$f(k+1)-f(k)\in\{0,1\}$ が得られる．

従って以下の流れで $c$ が求められる．

- $(i,j)=(0,0)$ から始めて，$i+j\leq n+m-2$ の間以下を繰り返す．
  - $c_{i+j}=a_i+b_j$ とする．
  - $a_{i+1}+b_{j} \lt a_{i}+b_{j+1}$ ならば $(i,j)\to(i+1,j)$，そうでないならば $(i,j)\to(i,j+1)$ へ遷移する．
