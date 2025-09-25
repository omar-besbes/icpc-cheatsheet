template <class P>
pair<P, P> closest(vector<P> v) {
  assert(sz(v) > 1);
  set<P> s;
  sort(all(v), [](P a, P b) { return a.y < b.y; });
  pair<ll, pair<P, P>> ret{LLONG_MAX, {P(), P()}};
  int j = 0;
  for (auto p : v) {
    P d{1 + (ll)sqrt(ret.first), 0};
    while (v[j].y <= p.y - d.x) s.erase(v[j++]);
    auto lo = s.lower_bound(p - d), hi = s.upper_bound(p + d);
    while (hi != lo)
      ret = min(ret, {(*lo - p).dist2(), {*lo, p}}), lo++;
    s.insert(p);
  }
  return ret.second;
}