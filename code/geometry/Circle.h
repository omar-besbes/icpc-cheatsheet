#include "Point.h"
#include "Line.h"

template <class T>
struct Circle {
  using P = Point<T>;
  using L = Line<T>;
  using C = Circle;
  T r;
  P o;
  Circle(P o, T r) : o(o), r(r) {}
  vector<P> intersection(L l) {
    P ab = b - a, p = a + ab * (c - a).dot(ab) / ab.dist2();
    double s = a.cross(b, c), h2 = r * r - s * s / ab.dist2();
    if (h2 < 0) return {};
    if (h2 == 0) return {p};
    P h = ab.unit() * sqrt(h2);
    return {p - h, p + h};
  }
};
