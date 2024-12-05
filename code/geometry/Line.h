#include "Point.h"

template <class T>
struct Line {
  using P = Point<T>;
  using L = Line;
  T a, b, c;
  Line() : a(0), b(0), c(0) {}
  Line(P u, P v) {
    a = u.y - v.y;
    b = v.x - u.x;
    c = -a * u.x - b * u.y;
    auto g = gcd(gcd(abs(a), abs(b)), abs(c));
    // for double: sqrt(a*a + b*b)
    assert(g != 0);
    // for double: abs(g) > EPS
    a /= g, b /= g, c /= g;
    if (a < 0 || (a == 0 && b < 0)) a *= -1, b *= -1, c *= -1;
    // for double: a < -EPS || (abs(a) <= EPS && b < -EPS)
  }
  Line(T a, T b, T c) : a(a), b(b), c(c) {}
  bool operator==(L &l) { return tie(a, b, c) == tie(l.a, l.b, l.c); }
  bool colinear(L &l) { return a * l.b == b * l.a; }
  double dist(P &p) {
    return (a * p.x + b * p.y + c) / sqrt(a * a + b * b);
  }
  P intersection(L &l) {
    auto v1 = P{a, l.a};
    auto v2 = P{b, l.b};
    auto v3 = P{c, l.c};
    // make sure T is double
    P p = {-v3.cross(v2) / v1.cross(v2),
           -v1.cross(v3) / v1.cross(v2)};
    return p;
  }
};