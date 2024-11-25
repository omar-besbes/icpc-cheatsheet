/**
 * Returns a vector of the points of the convex hull in
 * counter-clockwise order.
 * Points on the edge of the hull between two other points are
 * considered part of the hull.
 */

template <class P>
vector<P> convexHull(vector<P> &v) {
  int n = v.size();
  vector<P> ch;
  auto chk = [&](P z) {
    auto x = ch[ch.size() - 2], y = ch[ch.size() - 1];
    return x.cross(y, z) <= 0;
  };
  sort(v.begin(), v.end(),
       [](P a, P b) { return a.x == b.x ? a.y > b.y : a.x < b.x; });
  for (auto cur : v) {  // construct upper hull
    while (ch.size() >= 2 && !chk(cur)) ch.pop_back();
    ch.push_back(cur);
  }
  ch.pop_back();
  reverse(v.begin(), v.end());
  int s = ch.size();
  for (auto cur : v) {  // construct lower hull
    while (ch.size() - s >= 2 && !chk(cur)) ch.pop_back();
    ch.push_back(cur);
  }
  ch.pop_back();
  return ch;
}