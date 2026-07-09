#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "template/template.hpp"
#include "data-structure/binary-trie.hpp"

int main() {
  int q;
  in(q);
  BinaryTrie<int, 30> trie;
  while (q--) {
    int type, x;
    in(type, x);
    if (type == 0) {
      trie.insert(x);
    } else if (type == 1) {
      trie.erase(x);
    } else {
      out(trie.min_element(0, x) ^ x);
    }
  }
}
