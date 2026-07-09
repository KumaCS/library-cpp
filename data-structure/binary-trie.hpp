#pragma once

template <class I = int, int B = 30, class C = int>
struct BinaryTrie {
  struct Node {
    Node* next[2];
    C count;
    Node() : count(0) { next[0] = next[1] = nullptr; }
  };
  BinaryTrie() : root(new Node()) {}
  void add(I val, C cnt = 1) { add(root, val, cnt); }
  C count(I val) { return count(root, val); }
  bool contains(I val) { return count(val) > 0; }
  bool insert(I val) {
    if (contains(val)) return false;
    add(val);
    return true;
  }
  bool erase(I val) {
    if (!contains(val)) return false;
    add(val, -1);
    return true;
  }
  C count_leq(I val, I xor_val = 0) { return count_leq(root, val, xor_val); }
  // 0-indexed
  I min_element(C index = 0, I xor_val = 0) { return min_element(root, index, xor_val); }
  I max_element(C index = 0, I xor_val = 0) { return max_element(root, index, xor_val); }

 private:
  Node* root;
  Node* get_child(Node* node, int x) {
    if (!node->next[x]) node->next[x] = new Node();
    return node->next[x];
  }
  C count(Node* node) { return node ? node->count : 0; }
  void add(Node* node, I val, C cnt, int k = B - 1) {
    node->count += cnt;
    if (k >= 0) add(get_child(node, (val >> k) & 1), val, cnt, k - 1);
  }
  C count(Node* node, I val, int k = B - 1) {
    if (!node) return 0;
    if (k == -1) return node->count;
    return count(node->next[(val >> k) & 1], val, k - 1);
  }
  C count_leq(Node* node, I val, I xor_val, int k = B - 1) {
    if (!node) return 0;
    if (k == -1) return node->count;
    int t = (xor_val >> k) & 1;
    if ((val >> k) & 1)
      return count(node->next[t]) + count_leq(node->next[t ^ 1], val, xor_val, k - 1);
    else
      return count_leq(node->next[t], val, xor_val, k - 1);
  }
  I min_element(Node* node, C index, I xor_val, int k = B - 1) {
    assert(node);
    if (k == -1) return I{};
    int t = (xor_val >> k) & 1;
    C cnt0 = count(node->next[t]);
    if (index < cnt0) return min_element(node->next[t], index, xor_val, k - 1) | (I(t) << k);
    return min_element(node->next[t ^ 1], index - cnt0, xor_val, k - 1) | (I(t ^ 1) << k);
  }
  I max_element(Node* node, C index, I xor_val, int k = B - 1) {
    assert(node);
    if (k == -1) return I{};
    int t = (xor_val >> k) & 1;
    C cnt1 = count(node->next[t ^ 1]);
    if (index < cnt1) return max_element(node->next[t ^ 1], index, xor_val, k - 1) | (I(t ^ 1) << k);
    return max_element(node->next[t], index - cnt1, xor_val, k - 1) | (I(t) << k);
  }
};

/**
 * @brief Binary Trie
 * @docs docs/data-structure/binary-trie.md
 */
