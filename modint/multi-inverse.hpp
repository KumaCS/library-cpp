#pragma once

template <class mint>
vector<mint> MultiInverse(const vector<mint>& a) {
  if (a.empty()) return {};
  vector<mint> b(a.begin(), a.end());
  for (int i = 0; i + 1 < b.size(); i++) b[i + 1] *= b[i];
  mint c = b.back().inv();
  for (int i = a.size() - 1; i > 0; i--) {
    b[i] = c * b[i - 1];
    c *= a[i];
  }
  b[0] = c;
  return b;
}
/**
 * @brief 複数の要素の逆元を一括で計算
 */