#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"

int main() {
  {
    ostringstream oss;
    oss << array<int, 3>{1, 2, 3};
    assert(oss.str() == "1 2 3");
  }
  {
    ostringstream oss;
    oss << array<int, 0>{};
    assert(oss.str().empty());
  }
  {
    ostringstream oss;
    oss << vector<array<int, 2>>{{1, 2}, {3, 4}};
    assert(oss.str() == "1 2 3 4");
  }
  {
    ostringstream oss;
    oss << array<vector<int>, 2>{{{1, 2}, {3, 4}}};
    assert(oss.str() == "1 2 3 4");
  }
  {
    ostringstream oss;
    auto* cerr_buf = cerr.rdbuf(oss.rdbuf());
    array<int, 3> a{1, 2, 3};
    _show(0, "a", a);
    cerr.rdbuf(cerr_buf);
    assert(oss.str() == "a:1 2 3 \n");
  }
  {
    istringstream iss("10 20 30 1 2 3 4 5 6 7");
    auto* cin_buf = cin.rdbuf(iss.rdbuf());
    auto x = IO::read<int>();
    auto p = IO::read<pair<int, int>>();
    auto v = IO::read<vector<int>>(3);
    vector<int> a(2), b(2);
    in_zip(2, a, b);
    vector<int> empty;
    in_zip(0, empty);
    cin.rdbuf(cin_buf);
    cin.clear();
    assert(x == 10);
    assert(p == make_pair(20, 30));
    assert(v == vector<int>({1, 2, 3}));
    assert(a == vector<int>({4, 6}));
    assert(b == vector<int>({5, 7}));
  }

  int a, b;
  in(a, b);
  out(a + b);
}
