#pragma once

template <class T>
struct SimpleQueue {
 private:
  vector<T> a;
  int p;

 public:
  SimpleQueue() {}
  SimpleQueue(int n) { a.reserve(n); }
  void reserve(int n) { a.reserve(n); }
  int size() { return a.size() - p; }
  bool empty() { return a.size() == p; }
  void push(const T& v) { a.push_back(v); }
  T& front() { return a[p]; }
  void pop() { p++; }
  void clear() {
    a.clear();
    p = 0;
  }
};
