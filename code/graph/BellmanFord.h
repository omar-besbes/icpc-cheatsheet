const int INF = 1e9 + 7;

template <class edge>
void bellmanford(int n, int v, vector<edge> &edges) {
  vector<int> d(n, INF);
  d[v] = 0;
  vector<int> p(n, -1);
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (auto e : edges)
      if (d[e.a] < INF)
        if (d[e.b] > d[e.a] + e.cost) {
          d[e.b] = max(-INF, d[e.a] + e.cost);
          p[e.b] = e.a;
          x = e.b;
        }
  }

  if (x == -1)
    cout << "No negative cycle from " << v;
  else {
    int y = x;
    for (int i = 0; i < n; ++i) y = p[y];

    vector<int> path;
    for (int cur = y;; cur = p[cur]) {
      path.push_back(cur);
      if (cur == y && path.size() > 1) break;
    }
    reverse(path.begin(), path.end());

    cout << "Negative cycle: ";
    for (int u : path) cout << u << ' ';
  }
}