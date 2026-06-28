#pragma once

template <class T, int B = 8>
struct PersistentArray {
  struct Node {
    T val;
    Node* child[B] = {};
    Node() {}
    Node(const T& v) : val(v) {}
  };
  Node* root;
  vector<Node*> snapshots;
  PersistentArray() : root(nullptr) {}
  T get(Node* t, int k) { return k == 0 ? t->val : get(t->child[k % B], k / B); }
  T get(const int& k) { return get(root, k); }
  pair<Node*, T*> mutable_get(Node* t, int k) {
    t = t ? new Node(*t) : new Node();
    if (k == 0) return {t, &t->val};
    auto p = mutable_get(t->child[k % B], k / B);
    t->child[k % B] = p.first;
    return {t, p.second};
  }
  T* mutable_get(const int& k) {
    auto ret = mutable_get(root, k);
    root = ret.first;
    return ret.second;
  }
  Node* build(Node* t, const T& val, int k) {
    if (!t) t = new Node();
    if (k == 0) {
      t->val = val;
      return t;
    }
    t->child[k % B] = build(t->child[k % B], val, k / B);
    return t;
  }
  void build(const vector<T>& v) {
    root = nullptr;
    for (int i = 0; i < v.size(); i++) root = build(root, v[i], i);
  }
  int take_snapshot() {
    snapshots.push_back(root);
    return snapshots.size() - 1;
  }
  void apply_snapshot(int k) {
    root = snapshots[k];
  }
};

/**
 * @brief Persistent Array
 * @docs docs/val-structure/persistent-array.md
 */