#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "template/template.hpp"
#include "data-structure/double-ended-priority-queue.hpp"

int main() {
  int n, q;
  in(n, q);
  vector<int> s0(n);
  in(s0);
  DoubleEndedPriorityQueue<int> pq(s0);
  while (q--) {
    int type;
    in(type);
    if (type == 0) {
      int x;
      in(x);
      pq.push(x);
    } else if (type == 1) {
      out(pq.get_min());
      pq.pop_min();
    } else if (type == 2) {
      out(pq.get_max());
      pq.pop_max();
    }
  }
}