template <class T>
vector<pair<P, P>> rotatingcallipers(vector<P> &p) {
  int n = p.size();
  vector<pair<P, P>> res;
  // parallel edges shouldn't be visited twice
  vector<bool> vis(n, false);
  auto sgn = [](ll x) { return x < 0 ? -1 : x > 0; };
  auto nxt = [&](int idx) { return (idx + 1) % n; };
  auto prv = [&](int idx) { return (idx - 1 + n) % n; };
  for (int p1 = 0, p2 = 0; p1 < n; p1++) {
    auto u = p[nxt(p1)] - p[p1];
    auto v1 = p[nxt(p2)] - p[p2], v2 = p[p2] - p[prv(p2)];
    while (p1 == p2 || nxt(p1) == p2 ||
           sgn(u.cross(v1)) == sgn(u.cross(v2))) {
      p2 = nxt(p2);
      v1 = p[nxt(p2)] - p[p2], v2 = p[p2] - p[prv(p2)];
    }
    if (vis[p1]) continue;
    vis[p1] = true;
    res.push_back({p[p1], p[p2]});
    res.push_back({p[nxt(p1)], p[p2]});
    // if both edges from p1 and p2 are parallel to each other
    if (u.cross(v1) == 0) {
      res.push_back({p[p1], p[nxt(p2)]});
      res.push_back({p[nxt(p1)], p[nxt(p2)]});
      vis[p2] = true;
    }
  }
  return res;
}