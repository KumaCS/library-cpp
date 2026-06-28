必ずしも NTT friendly でない一般の (32 bit の) mod において $O(N\log N)$ 時間で畳み込みが計算できる．

3 つの NTT friendly な素数について畳み込み，それらの結果から本来の mod での値を復元する．

- `ConvolutionIntMod::multiply(a, b)`：多項式 $a,b$ の積を返す．
- `ConvolutionIntMod::middle_product(a, b)`：middle product を返す．`a.size() <= b.size()` を要求する．

戻り値の係数は，引数に渡した `mint` の mod 上の値になる．
