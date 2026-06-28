#pragma once

struct Graph {
  int n;
  vector<vector<int>> g;
  Graph() : Graph(0) {}
  Graph(int size) : n(size), g(size) {}
  void add_edge(int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
  }
  void add_edge_directed(int from, int to) {
    g[from].push_back(to);
  }
};