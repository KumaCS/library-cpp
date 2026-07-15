#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "string/trie.hpp"

int main() {
  {
    Trie<> trie;
    assert(trie.empty());
    assert(trie.add("", 0) == trie.root_node());
    int a = trie.add("a", 1);
    assert(a == trie.find_node("a"));
    int ab = trie.add("ab", 2);
    assert(ab == trie.find_node("ab"));
    int abc = trie.add("abc", 3);
    assert(abc == trie.find_node("abc"));
    int abd = trie.add("abd", 4);
    assert(abd == trie.find_node("abd"));
    int ab2 = trie.add("ab", 5);
    assert(ab2 == trie.find_node("ab"));
    int b = trie.add("b", 6);
    assert(b == trie.find_node("b"));

    assert(trie.size() == 7);
    assert(trie.count() == 7);
    assert(!trie.empty());
    assert(trie.count("") == 1);
    assert(trie.count("a") == 1);
    assert(trie.count("ab") == 2);
    assert(trie.count("ac") == 0);
    assert(trie.contains("abc"));
    assert(!trie.contains("ac"));

    assert(trie.count_prefix("") == 7);
    assert(trie.count_prefix("a") == 5);
    assert(trie.count_prefix("ab") == 4);
    assert(trie.count_prefix("abc") == 1);
    assert(trie.count_prefix("ac") == 0);

    assert(trie.find_ids("ab") == vector<int>({2, 5}));
    assert(trie.find_ids("ac").empty());
    assert(trie.prefix_match("abcd") == vector<int>({0, 1, 2, 5, 3}));
    assert(trie.enumerate_prefix("a") == vector<int>({1, 2, 5, 3, 4}));
    assert(trie.enumerate_prefix("ab") == vector<int>({2, 5, 3, 4}));
    assert(trie.longest_prefix("abcd") == 3);
    assert(trie.longest_prefix("ac") == 1);
    assert(trie.longest_prefix("c") == 0);

    int v = trie.find_node("abd");
    assert(v != -1);
    assert(trie.restore(v) == "abd");
    assert(trie.next_node(trie.find_node("ab"), 'd') == v);
    assert(trie.next_node(trie.find_node("ab"), 'e') == -1);

    assert(!trie.insert("ab", 100));
    assert(trie.erase("ab", 5));
    assert(trie.find_ids("ab") == vector<int>({2}));
    assert(trie.count_prefix("a") == 4);
    assert(trie.size() == 6);
    assert(!trie.erase("ab", 5));
    assert(trie.erase("ab"));
    assert(!trie.contains("ab"));
    assert(trie.count_prefix("a") == 3);
    assert(trie.size() == 5);
    assert(trie.insert("ab", 7));
    assert(trie.find_ids("ab") == vector<int>({7}));

    trie.clear();
    assert(trie.empty());
    assert(trie.node_size() == 1);
    assert(trie.find_node("") == trie.root_node());
  }
  {
    Trie<10, '0'> trie;
    trie.add("012", 10);
    trie.add("01", 11);
    assert(trie.count_prefix("0") == 2);
    assert(trie.longest_prefix("0123") == 3);
    assert(trie.prefix_match("0123") == vector<int>({11, 10}));
  }

  int a, b;
  in(a, b);
  out(a + b);
}
