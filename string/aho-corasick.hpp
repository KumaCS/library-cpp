#pragma once

template <int char_size = 26, char char_start = 'a'>
struct AhoCorasick {
  struct Node {
    int prev, c, fail;
    int next[char_size];
    vector<int> accept;
    Node(int prev, int c) : prev(prev), c(c), fail(-1) {
      memset(next, -1, sizeof(next));
    }
  };

  AhoCorasick() : root(make_node()), str_count(0) {}

  int add(const string& str) {
    assert(!str.empty());
    int id = str_count++;
    int x = root;
    for (auto c : str) x = get_child(x, char_index(c));
    nodes[x].accept.emplace_back(id);
    return id;
  }
  int size() const { return str_count; }
  int node_size() const { return (int)nodes.size(); }
  int get_root() const { return root; }
  const vector<int>& accept(int x) const { return nodes[x].accept; }

  void build() {
    queue<int> qu;
    for (int i = 0; i < char_size; i++) {
      int& x = nodes[root].next[i];
      if (x == -1) {
        x = root;
      } else {
        qu.push(x);
        nodes[x].fail = root;
      }
    }
    while (!qu.empty()) {
      int x = qu.front();
      qu.pop();
      int f = nodes[x].fail;
      auto& accept_x = nodes[x].accept;
      auto& accept_f = nodes[f].accept;
      vector<int> accept;
      set_union(accept_x.begin(), accept_x.end(), accept_f.begin(), accept_f.end(), back_inserter(accept));
      swap(accept_x, accept);
      for (int i = 0; i < char_size; i++) {
        int& y = nodes[x].next[i];
        if (y == -1) {
          y = nodes[f].next[i];
        } else {
          qu.push(y);
          nodes[y].fail = nodes[f].next[i];
        }
      }
    }
  }

  int move(int x, const char c) const {
    int y = nodes[x].next[c - char_start];
    if (y == -1) y = nodes[x].fail;
    return y;
  }
  unordered_map<int, int> match(const string& s) const {
    int x = root;
    unordered_map<int, int> count;
    for (auto c : s) {
      x = move(x, c);
      for (auto id : nodes[x].accept) count[id]++;
    }
    return count;
  }
  int match_any(const string& s) const {
    int x = root;
    int count = 0;
    for (auto c : s) {
      x = move(x, c);
      count += nodes[x].accept.size();
    }
    return count;
  }

 private:
  vector<Node> nodes;
  int root, str_count;
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
};

/**
 * @brief Aho-Corasick
 * @docs docs/string/aho-corasick.md
 */
