#pragma once
#ifdef LOCAL
#define debug 1
#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug 0
#define show(...) true
#endif
template <class T>
void _show(int i, T name) {
  cerr << '\n';
}
template <class T1, class T2, class... T3>
void _show(int i, const T1& a, const T2& b, const T3&... c) {
  for (; a[i] != ',' && a[i] != '\0'; i++) cerr << a[i];
  cerr << ":" << b << " ";
  _show(i + 1, a, c...);
}