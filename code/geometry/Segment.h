#include "Point.h"

template <class T>
struct Segment {
  using P = Point<T>;
  using S = Segment;
  P p1, p2;
  Segment() : p1(), p2() {}
  Segment(P u, P v) : p1(u), p2(v) {}
  bool intersect(S &l) {
    auto [p3, p4] = l;
    // adjust with epsilon when using double
    auto sgn = [](T x) { return x > 0 ? 1 : x < 0 ? -1 : 0; };
    auto c1 = p3.cross(p4, p1);
    auto c2 = p3.cross(p4, p2);
    auto c3 = p1.cross(p2, p3);
    auto c4 = p1.cross(p2, p4);
    // adjust with epsilon when using double
    if (c1 == 0 && c2 == 0)
      return p1.between(p3, p4) || p2.between(p3, p4) ||
             p3.between(p1, p2) || p4.between(p1, p2);
    return sgn(c1) != sgn(c2) && sgn(c3) != sgn(c4);
  }
  bool has(P &p) {
    return p1.dot(p, p2) == 0 && p.between(p1, p2);
  }
};
