#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "geometry-3d/sphere.hpp"
#include "geometry-3d/triangle.hpp"

bool near(Real a, Real b, Real eps = 1e-8) { return abs(a - b) < eps; }
bool near(const Point3D& a, const Point3D& b, Real eps = 1e-8) {
  return abs(a - b) < eps;
}

int main() {
  {
    Point3D x{1, 0, 0}, y{0, 1, 0}, z{0, 0, 1};
    assert(dot(x, y) == 0);
    assert(cross(x, y) == z);
    assert(triple(x, y, z) == 1);
    assert(near(angle(x, y), PI / 2));
    assert(near(normalize(Point3D{2, 0, 0}), x));
  }
  {
    Line3D l{{0, 0, 0}, {1, 0, 0}};
    Line3D m{{0, -1, 0}, {0, 1, 0}};
    assert(is_orthogonal(l, m));
    assert(is_intersect_ll(l, m));
    assert(near(*cross_point_ll(l, m), Point3D{0, 0, 0}));
    assert(near(projection(l, Point3D{2, 3, 4}), Point3D{2, 0, 0}));
    assert(near(reflection(l, Point3D{2, 3, 4}), Point3D{2, -3, -4}));

    Line3D skew{{0, 1, 1}, {0, 2, 1}};
    assert(!is_intersect_ll(l, skew));
    assert(!cross_point_ll(l, skew));
    assert(near(distance_ll(l, skew), 1));

    Line3D parallel{{0, 2, 0}, {1, 2, 0}};
    assert(is_parallel(l, parallel));
    assert(near(distance_ll(l, parallel), 2));
    assert(!cross_point_ll(l, parallel));
    Line3D same{{-2, 0, 0}, {3, 0, 0}};
    assert(is_intersect_ll(l, same));
    assert(!cross_point_ll(l, same));
  }
  {
    Segment3D s{{0, 0, 0}, {2, 0, 0}};
    Segment3D t{{1, -1, 0}, {1, 1, 0}};
    assert(is_intersect_ss(s, t));
    assert(near(distance_ss(s, t), 0));
    assert(near(closest_point_sp(s, Point3D{3, 4, 0}), Point3D{2, 0, 0}));
    assert(near(distance_sp(s, Point3D{1, 2, 2}), sqrt((Real)8)));

    Segment3D u{{0, 0, 0}, {0, 0, 0}};
    assert(is_intersect_sp(u, Point3D{0, 0, 0}));
    assert(near(distance_sp(u, Point3D{1, 2, 2}), 3));
  }
  {
    Plane3D xy{{0, 0, 0}, {0, 0, 1}};
    assert(is_intersect_pp(xy, Point3D{2, 3, 0}));
    assert(near(projection(xy, Point3D{2, 3, 4}), Point3D{2, 3, 0}));
    assert(near(reflection(xy, Point3D{2, 3, 4}), Point3D{2, 3, -4}));
    assert(near(signed_distance_pp(xy, Point3D{2, 3, 4}), 4));

    Line3D l{{1, 2, -1}, {1, 2, 1}};
    assert(near(*cross_point_lp(l, xy), Point3D{1, 2, 0}));
    Line3D parallel{{0, 0, 2}, {1, 0, 2}};
    assert(!is_intersect_lp(parallel, xy));
    assert(!cross_point_lp(parallel, xy));
    assert(near(distance_lp(parallel, xy), 2));
    Line3D included{{0, 0, 0}, {1, 0, 0}};
    assert(is_intersect_lp(included, xy));
    assert(!cross_point_lp(included, xy));

    Plane3D x2{{2, 0, 0}, {1, 0, 0}};
    Plane3D y3{{0, 3, 0}, {0, 1, 0}};
    auto line = cross_line_pp(x2, y3);
    assert(line);
    assert(is_intersect_pp(x2, line->a));
    assert(is_intersect_pp(y3, line->a));
    assert(is_intersect_pp(x2, line->b));
    assert(is_intersect_pp(y3, line->b));
    Plane3D z2{{0, 0, 2}, {0, 0, 2}};
    assert(is_parallel(xy, z2));
    assert(!cross_line_pp(xy, z2));
    assert(near(distance_pp(xy, z2), 2));
  }
  {
    Triangle3D t{{0, 0, 0}, {2, 0, 0}, {0, 2, 0}};
    assert(near(area(t), 2));
    assert(near(signed_volume(Point3D{0, 0, 0}, Point3D{1, 0, 0},
                              Point3D{0, 1, 0}, Point3D{0, 0, 1}),
                1.0L / 6));
    assert(near(volume(Point3D{0, 0, 0}, Point3D{1, 0, 0},
                       Point3D{0, 1, 0}, Point3D{0, 0, -1}),
                1.0L / 6));
    auto b = barycentric_coordinates(t, Point3D{0.5, 0.5, 0});
    assert(b && near((*b)[0], 0.5) && near((*b)[1], 0.25) &&
           near((*b)[2], 0.25));
    assert(is_intersect_tp(t, Point3D{0.5, 0.5, 0}));
    assert(!is_intersect_tp(t, Point3D{1.5, 1.5, 0}));
    assert(near(closest_point_tp(t, Point3D{0.5, 0.5, 3}),
                Point3D{0.5, 0.5, 0}));
    assert(near(distance_tp(t, Point3D{0.5, 0.5, 3}), 3));
    assert(near(closest_point_tp(t, Point3D{2, 2, 0}), Point3D{1, 1, 0}));
  }
  {
    Sphere3D s{{0, 0, 0}, 2};
    assert(contains_sphere(s, Point3D{0, 0, 0}) == 2);
    assert(contains_sphere(s, Point3D{2, 0, 0}) == 1);
    assert(contains_sphere(s, Point3D{3, 0, 0}) == 0);
    assert(near(surface_area(s), 16 * PI));
    assert(near(volume(s), 32 * PI / 3));

    auto ps = cross_point_ls(Line3D{{-3, 0, 0}, {3, 0, 0}}, s);
    assert(ps);
    assert(near(ps->first, Point3D{-2, 0, 0}));
    assert(near(ps->second, Point3D{2, 0, 0}));
    auto tangent = cross_point_ls(Line3D{{-3, 2, 0}, {3, 2, 0}}, s);
    assert(tangent && near(tangent->first, Point3D{0, 2, 0}) &&
           near(tangent->second, Point3D{0, 2, 0}));
    assert(!cross_point_ls(Line3D{{-3, 3, 0}, {3, 3, 0}}, s));

    auto c1 = cross_circle_ps(Plane3D{{0, 0, 1}, {0, 0, 1}}, s);
    assert(c1 && near(c1->p, Point3D{0, 0, 1}) && near(c1->r, sqrt((Real)3)));
    assert(!cross_circle_ps(Plane3D{{0, 0, 3}, {0, 0, 1}}, s));

    Sphere3D t{{2, 0, 0}, 2};
    auto c2 = cross_circle_ss(s, t);
    assert(c2 && near(c2->p, Point3D{1, 0, 0}) && near(c2->r, sqrt((Real)3)));
    assert(intersect(s, t) == 2);
    assert(intersect(s, Sphere3D{{4, 0, 0}, 2}) == 3);
    assert(intersect(s, Sphere3D{{5, 0, 0}, 2}) == 4);
    assert(intersect(s, Sphere3D{{1, 0, 0}, 1}) == 1);
    assert(intersect(s, Sphere3D{{0, 0, 0}, 1}) == 0);
  }

  mt19937_64 rng(1234567);
  uniform_real_distribution<Real> dist(-10, 10);
  auto random_point = [&]() { return Point3D{dist(rng), dist(rng), dist(rng)}; };
  for (int qi = 0; qi < 5000; ++qi) {
    Point3D a = random_point(), b = random_point(), p = random_point();
    if (abs(a - b) < 0.1) {
      --qi;
      continue;
    }
    Line3D l{a, b};
    Point3D q = projection(l, p);
    assert(abs(cross(l.b - l.a, q - l.a)) < 1e-7);
    assert(abs(dot(l.b - l.a, p - q)) < 1e-7);
    assert(near(distance_lp(l, p), abs(p - q), 1e-7));

    Point3D c = random_point(), d = random_point();
    if (abs(c - d) < 0.1) {
      --qi;
      continue;
    }
    Line3D m{c, d};
    auto [x, y] = closest_points_ll(l, m);
    assert(is_intersect_lp(l, x));
    assert(is_intersect_lp(m, y));
    assert(near(distance_ll(l, m), distance_ll(m, l), 1e-7));
    if (!is_parallel(l, m)) {
      assert(abs(dot(l.b - l.a, x - y)) < 1e-7);
      assert(abs(dot(m.b - m.a, x - y)) < 1e-7);
    }

    Segment3D s{a, b}, t{c, d};
    auto [u, v] = closest_points_ss(s, t);
    assert(is_intersect_sp(s, u));
    assert(is_intersect_sp(t, v));
    assert(near(distance_ss(s, t), distance_ss(t, s), 1e-7));

    Point3D n = random_point();
    if (abs(n) < 0.1) {
      --qi;
      continue;
    }
    Plane3D pl{a, n};
    Point3D z = projection(pl, p);
    assert(abs(plane_value(pl, z)) < 1e-7);
    assert(near(distance_pp(pl, p), abs(p - z), 1e-7));
  }

  long long a, b;
  in(a, b);
  out(a + b);
}
