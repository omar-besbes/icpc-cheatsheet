#include "Point.h"
#include "Line.h"

template <class T>
struct Ray {
  using P = Point<T>;
  using L = Line<T>;
  using R = Ray;
  P p1, p2;  // ray from p1 to p2
  L l;

  Ray(P p1, P p2) : p1(p1), p2(p2), l(p1, p2) {}

  double dist(P x) {
    if (p1.dot(p2, x) <= 0) {
      return (p1 - x).dist();
    } else {
      auto [a, b, c] = l;
      return abs(a * x.x + b * x.y + c) / sqrt(a * a + b * b);
    }
  }

  bool intersect(R &r) {
    if ((p1 - p2).cross(r.p1, r.p2) == 0) {
      if (l.c != r.l.c) return false;
      return p1.dot(p2, r.p1) >= 0 || r.p1.dot(r.p1, p1) >= 0;
    } else {
      auto i = l.intersection(r.l);
      return p1.dot(i, p2) >= 0 && r.p1.dot(i, r.p2) >= 0;
    }
  }

  double dist(R r) {
    if (intersect(r)) return 0;
    return min(dist(r.p1), r.dist(p1));
  }
};
