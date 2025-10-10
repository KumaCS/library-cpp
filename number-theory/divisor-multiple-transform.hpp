#pragma once

template <class T>
void DivisorZetaTransform(vector<T>& a) {
  if (a.empty()) return;
  int n = a.size();
  vector<bool> sieve(n, true);
  for (int p = 2; p < n; p++) {
    if (sieve[p]) {
      for (int k = 1; k * p < n; k++) {
        sieve[k * p] = false;
        a[k * p] += a[k];
      }
    }
  }
}

template <class T>
void DivisorMobiusTransform(vector<T>& a) {
  if (a.empty()) return;
  int n = a.size();
  vector<bool> sieve(n, true);
  for (int p = 2; p < n; p++) {
    if (sieve[p]) {
      for (int k = (n - 1) / p; k > 0; k--) {
        sieve[k * p] = false;
        a[k * p] -= a[k];
      }
    }
  }
}

template <class T>
void MultipleZetaTransform(vector<T>& a) {
  if (a.empty()) return;
  int n = a.size();
  vector<bool> sieve(n, true);
  for (int p = 2; p < n; p++) {
    if (sieve[p]) {
      for (int k = (n - 1) / p; k > 0; k--) {
        sieve[k * p] = false;
        a[k] += a[k * p];
      }
    }
  }
}

template <class T>
void MultipleMobiusTransform(vector<T>& a) {
  if (a.empty()) return;
  int n = a.size();
  vector<bool> sieve(n, true);
  for (int p = 2; p < n; p++) {
    if (sieve[p]) {
      for (int k = 1; k * p < n; k++) {
        sieve[k * p] = false;
        a[k] -= a[k * p];
      }
    }
  }
}

/**
 * @brief 約数・倍数変換
 * @docs docs/number-theory/divisor-multiple-transform.md
 */