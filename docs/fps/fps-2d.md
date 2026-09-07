二変数の形式的冪級数

$$f(x,y)=\sum_{i=0}^{N-1}\sum_{j=0}^{M-1}a_{i,j}x^iy^j$$

を `vector<vector<mint>>` として扱う．`f[i][j]` が $a_{i,j}$ を表す．

- `FormalPowerSeries2D(n, m)`：$N=n,M=m$ の零 FPS を構築する．
- `height()`, `width()`：$N,M$ を取得する．
- `pre(n, m)`：$f\bmod (x^n,y^m)$ を取得する．
- `+`, `-`, `*`, `/`：FPS またはスカラーとの四則演算を行う．FPS による除算は左辺の大きさで打ち切る．
- `shift(i, j)`：$x^iy^jf$ を取得する．
- `inv(n, m)`：$f^{-1}\bmod (x^n,y^m)$ を求める．引数を省略したときは $N\times M$ 項を求める．$a_{0,0}\neq 0$ が必要．
- `log(n, m)`：$\log(f)\bmod (x^n,y^m)$ を求める．引数を省略したときは $N\times M$ 項を求める．$a_{0,0}=1$ が必要．
- `exp(n, m)`：$\exp(f)\bmod (x^n,y^m)$ を求める．引数を省略したときは $N\times M$ 項を求める．$a_{0,0}=0$ が必要．

積は Kronecker 置換と畳み込み，逆元と指数関数は Newton 法により求める．対数関数は $D=x\frac{\partial}{\partial x}+y\frac{\partial}{\partial y}$ として $D\log(f)=Df/f$ から求める．NTT friendly mod では `fps/fps-2d-ntt-friendly.hpp`，任意 mod では `fps/fps-2d-arbitrary.hpp` を include する．

$NM$ 項までの積，逆元，対数関数，指数関数をそれぞれ $O(NM\log(NM))$ 時間で求める．
