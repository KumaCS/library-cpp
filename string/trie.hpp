#pragma once

template <int char_size = 26, char char_start = 'a'>
struct Trie {
  struct Node {
    int prev, count, c;
    int next[char_size];
    vector<int> ids;
    Node(int prev, int c) : prev(prev), count(0), c(c) {
      memset(next, -1, sizeof(next));
    }
  };

  Trie() : root(make_node()) {}

  int add(const string& str, int id = -1) {
    if (id == -1) id = size();
    int x = root;
    nodes[x].count++;
    for (auto c : str) {
      x = get_child(x, char_index(c));
      nodes[x].count++;
    }
    nodes[x].ids.emplace_back(id);
    return x;
  }
  bool insert(const string& str, int id = -1) {
    if (contains(str)) return false;
    add(str, id);
    return true;
  }
  bool erase(const string& str) {
    int x = find_node(str);
    if (x == -1 || nodes[x].ids.empty()) return false;
    nodes[x].ids.pop_back();
    subtract_path(x);
    return true;
  }
  bool erase(const string& str, int id) {
    int x = find_node(str);
    if (x == -1) return false;
    auto it = find(nodes[x].ids.begin(), nodes[x].ids.end(), id);
    if (it == nodes[x].ids.end()) return false;
    nodes[x].ids.erase(it);
    subtract_path(x);
    return true;
  }
  int size() const { return nodes[root].count; }
  int count() const { return size(); }
  int node_size() const { return nodes.size(); }
  bool empty() const { return size() == 0; }
  int count(const string& str) const {
    int x = find_node(str);
    return x == -1 ? 0 : nodes[x].ids.size();
  }
  int count_prefix(const string& str) const {
    int x = find_node(str);
    return x == -1 ? 0 : nodes[x].count;
  }
  bool contains(const string& str) const { return count(str) > 0; }
  vector<int> find_ids(const string& str) const {
    int x = find_node(str);
    return x == -1 ? vector<int>() : nodes[x].ids;
  }
  vector<int> prefix_match(const string& str) const {
    vector<int> ret;
    int x = root;
    append(ret, nodes[x].ids);
    for (auto c : str) {
      x = next_node(x, c);
      if (x == -1) break;
      append(ret, nodes[x].ids);
    }
    return ret;
  }
  vector<int> enumerate_prefix(const string& str) const {
    vector<int> ret;
    int x = find_node(str);
    if (x != -1) dfs_ids(x, ret);
    return ret;
  }
  int longest_prefix(const string& str) const {
    int x = root, ret = nodes[x].ids.empty() ? -1 : 0;
    for (int i = 0; i < (int)str.size(); i++) {
      x = next_node(x, str[i]);
      if (x == -1) break;
      if (!nodes[x].ids.empty()) ret = i + 1;
    }
    return ret;
  }
  int root_node() const { return root; }
  int find_node(const string& str) const {
    int x = root;
    for (auto c : str) {
      x = next_node(x, c);
      if (x == -1) return -1;
    }
    return x;
  }
  int next_node(int index, char c) const {
    return index == -1 ? -1 : nodes[index].next[char_index(c)];
  }
  const Node& node(int index) const { return nodes[index]; }
  string restore(int index) const {
    string ret;
    while (index != root) {
      ret.push_back(char_start + nodes[index].c);
      index = nodes[index].prev;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
  void clear() {
    nodes.clear();
    root = make_node();
  }

 private:
  vector<Node> nodes;
  int root;
  int make_node(int prev = -1, int c = -1) {
    nodes.push_back(Node(prev, c));
    return nodes.size() - 1;
  }
  int get_child(int index, int char_index) {
    if (nodes[index].next[char_index] == -1) {
      int child = make_node(index, char_index);
      nodes[index].next[char_index] = child;
    }
    return nodes[index].next[char_index];
  }
  int char_index(char c) const {
    int x = c - char_start;
    assert(0 <= x && x < char_size);
    return x;
  }
  void subtract_path(int index) {
    while (index != -1) {
      nodes[index].count--;
      index = nodes[index].prev;
    }
  }
  void append(vector<int>& a, const vector<int>& b) const {
    a.insert(a.end(), b.begin(), b.end());
  }
  void dfs_ids(int index, vector<int>& ret) const {
    append(ret, nodes[index].ids);
    for (int c = 0; c < char_size; c++)
      if (nodes[index].next[c] != -1) dfs_ids(nodes[index].next[c], ret);
  }
};

/**
 * @brief Trie
 * @docs docs/string/trie.md
 */
