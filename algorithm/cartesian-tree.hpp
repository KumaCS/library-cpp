#pragma once

// min
// (root, nodes)
// node: (parent, left, right)
template <class T>
pair<int, vector<array<int, 3>>> CartesianTree(const vector<T>& v) {
  int root = 0;
  vector<array<int, 3>> nodes(v.size(), {-1, -1, -1});
  vector<int> st(v.size(), 0);
  int top = 0;
  for (int i = 1; i < v.size(); ++i) {
    if (v[st[top]] > v[i]) {
      while (top >= 1 && v[st[top - 1]] > v[i]) --top;
      nodes[nodes[i][1] = st[top]][0] = i;
      (top == 0 ? root : nodes[nodes[i][0] = st[top - 1]][2]) = i;
      st[top] = i;
    } else {
      nodes[nodes[i][0] = st[top]][2] = i;
      st[++top] = i;
    }
  }
  return {root, nodes};
}
