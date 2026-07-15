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

  int a, b;
  in(a, b);
  out(a + b);
}
