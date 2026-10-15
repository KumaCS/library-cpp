点集合 $\{(x,(ax+b)\bmod m):0\leq x<n\}$ を，同じ公差を持つ点列に分解する．

`ModLinearDecomposition<I>(n, m, a, b)` は `ModLinearDecompositionResult<I>` を返す．
$n\geq 0$，$m>0$，$0\leq a,b<m$ とする．`I` は符号付き整数型とし，$n$ は `long long` に収まるものとする．
計算途中の積と和も `I` に収まる必要がある．

返り値の `dx, dy` が共通の公差である．
`sequences` の各要素 `{size, x0, y0}` は，$0\leq j<\mathrm{size}$ に対する点 $(x_0+j\,dx,y_0+j\,dy)$ を表す．
各点はちょうど一つの点列に含まれる．$n=0$ では点列は空になる．

$s=\lceil\sqrt n\rceil$ とする．剰余を bucket に分けて公差を見つけ，各 $x\bmod dx$ について値が $[0,m)$ に収まる区間を列挙する．
計算量は $O(\min(s,m))$ 時間．
