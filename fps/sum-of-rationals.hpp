#pragma once
#include "fps/formal-power-series.hpp"
#include "fps/fps-rational.hpp"

template <class mint>
FPSRational<mint> SumOfRationals(vector<FPSRational<mint>> rs) {
  if (ps.empty()) return {};
  for (auto& r : rs) {
    r.num.shrink(), r.den.shrink();
    if (r.den.size() < r.num.size()) r.num.resize(r.den.size());
  }
  const int B = 1 << 5;
  for (int i = 0, j = -1; i < rs.size(); i++) {
    if (rs[i].den.size() > B) continue;
    if (j == -1 || rs[i].den.size() + rs[j].den.size() - 1 > B) {
      j = i;
      continue;
    }
    rs[j] += rs[i];
    swap(rs[i--], rs.back());
    rs.pop_back();
  }
  if (rs.size() == 1) return rs[0];
  for (auto& r : rs) {
    int sz = B;
    while (sz < r.size()) sz <<= 1;
    r.num.resize(sz);
    r.num.ntt();
    r.den.resize(sz);
    r.den.ntt();
  }
  for (int sz = B * 2; rs.size() > 1; sz <<= 1) {
    for (int i = 0, j = -1; i < rs.size(); i++) {
      if (rs[i].den.size() >= sz) continue;
      rs[i].num.ntt_doubling();
      rs[i].den.ntt_doubling();
      if (j == -1) {
        j = i;
      } else {
        for (int k = 0; k < sz; k++) rs[j].num[k] = rs[j].num[k] * rs[i].den[k] + rs[j].den[k] * rs[i].num[k];
        for (int k = 0; k < sz; k++) rs[j].den[k] *= rs[i].den[k];
        swap(rs[i--], rs.back());
        rs.pop_back();
        j = -1;
      }
    }
  }
  rs[0].num.intt();
  rs[0].num.shrink();
  rs[0].den.intt();
  rs[0].den.shrink();
  return rs[0];
}
/**
 * @brief 有理式の和
 */