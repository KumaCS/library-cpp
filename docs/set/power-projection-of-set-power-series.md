$a$ を集合冪級数とする．
$\sum_{s}w_s[x^s]a^i$ を $i=0,\dots,M-1$ について列挙する．

$O(N^22^N+NM)$ 時間．

- [https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-3-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90%e3%81%ae%e8%bb%a2%e7%bd%ae]

## 導入

$a$ を fix したとき，合成 $f(a)$ の計算は $\sum_{i}f_i[x^s]a^i$ の $s$ についての列挙．

この転置問題は $\sum_{s}w_s[x^s]a^i$ の $i$ についての列挙．

多項式 $f$ との合成は以下の要領で計算していた．

- $g(x)=f(x+c)$ とする
- $g$ を EGF にする
- $g$ と $a-c$ を合成する

$g(x)=f(x+c)$ のとき $g_i=\sum_{j\geq i}\binom{j}{i}c^{j-i}f_j$ である．この転置は難しくない．

また $g$ を EGF にするには $x^k$ の係数を $k!$ 倍すればよいので，特に転置は同じものである．

$[x^0]a=0$ のときの EGF との合成の転置を考える．
subset convolution $a\star b$ は $b$ を固定すれば $a$ について線形写像．
その転置アルゴリズムは $a\star b=\operatorname{rev}(\operatorname{rev}(a)\star b)$ である．
