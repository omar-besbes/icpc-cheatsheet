struct Edge {
  int w = INT_MAX, to = -1;
  bool operator>(Edge const& other) const {
    return make_pair(w, to) > make_pair(other.w, other.to);
  }
};

struct Prim {
  int n;
  vector<vector<Edge>> adj;
  Prim(int n, vector<vector<Edge>>& adj) : n(n), adj(adj) {}
  vector<Edge> mst() {
    int cost = 0;
    vector<Edge> res;
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    q.push({0, 0});
    vector<bool> vis(n, false);
    while (!q.empty()) {
      auto e = q.top();
      auto [w, v] = e;
      q.pop();
      cost += w;
      vis[v] = true;
      res.push_back(e);
      for (auto e : adj[v])
        if (!vis[e.to]) q.push(e);
    }
    return res;
  }
};