素数を法とする原始根を求める．

- `PrimitiveRoot(p)`：素数 $p$ の原始根をひとつ返す．$2\leq p\leq 10^{18}$ とする．

$p-1$ を Pollard's rho algorithm で素因数分解する．$p-1$ の相異なる素因数を $q_1,q_2,\dots,q_k$ とすると，$g$ が原始根であることは

$$g^{(p-1)/q_i}\not\equiv 1\pmod p\quad(1\leq i\leq k)$$

と同値である．小さい $g$ から順にこの条件を判定する．

計算量は $p-1$ の素因数分解に依存する．
