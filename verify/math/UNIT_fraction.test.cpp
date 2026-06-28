#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "math/fraction.hpp"
#include "math/simple-fraction.hpp"

void check_fraction(Fraction<ll> x) {
  assert(x.b > 0);
  assert(gcd(abs(x.a), abs(x.b)) == 1);
}

void test_fraction() {
  rep(a, -20, 21) rep(b, 1, 21) {
    Fraction<ll> x(a, b);
    check_fraction(x);
    assert(x == Fraction<ll>(a * 3, b * 3));
    if (a != 0) assert(x * x.inv() == Fraction<ll>(1));

    Fraction<ll> y(b - 10, b + 1);
    check_fraction(x + y);
    check_fraction(x - y);
    check_fraction(x * y);
    if (y.a != 0) check_fraction(x / y);

    long double v = x.get<long double>();
    assert(x.floor() <= v && v < x.floor() + 1);
    assert(x.ceil() - 1 < v && v <= x.ceil());
  }
}

void test_simple_fraction() {
  SimpleFraction<ll> x(1, 2), y(1, 3);
  assert(x + y == SimpleFraction<ll>(5, 6));
  assert(x - y == SimpleFraction<ll>(1, 6));
  assert(x * y == SimpleFraction<ll>(1, 6));
  assert(x / y == SimpleFraction<ll>(3, 2));
  assert(SimpleFraction<ll>(-1, -2) == SimpleFraction<ll>(1, 2));
  assert(SimpleFraction<ll>(0, 100).b == 1);
}

int main() {
  test_fraction();
  test_simple_fraction();

  int a, b;
  in(a, b);
  out(a + b);
}
