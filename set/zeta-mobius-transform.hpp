#pragma once

template <class T>
void SupsetZetaTransform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i * 2)
      for (int k = 0; k < i; k++)
        f[j + k] += f[i + j + k];
}

template <class T>
void SupsetMobiusTransform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i * 2)
      for (int k = 0; k < i; k++)
        f[j + k] -= f[i + j + k];
}

template <class T>
void SubsetZetaTransform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i * 2)
      for (int k = 0; k < i; k++)
        f[i + j + k] += f[j + k];
}

template <class T>
void SubsetMobiusTransform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i * 2)
      for (int k = 0; k < i; k++)
        f[i + j + k] -= f[j + k];
}
