/**
 * Shortest path
 * T is the distance metric (e.g. int or long long).
 */

template <class node, typename D>
struct Dijkstra {
  vector<D> dist;
  vector<vector<pair<int, D>>> adj;
  Dijkstra(vector<vector<pair<int, D>>> &_adj) : adj(_adj) {}
  void compute(int s) {
    dist.assign(adj.size(), numeric_limits<D>::max());
    typedef tuple<D, node> state;
    priority_queue<state, vector<state>, greater<state>> q;
    q.push({0, node(s)});
    dist[s] = 0;
    while (!q.empty()) {
      auto [d, cur] = q.top();
      q.pop();

      for (auto [w, c] : adj[cur])
        if (dist[c] > d + w) {
          dist[c] = d + w;
          q.push({dist[c], c});
        }
    }
  }
  D get(int idx) { return dist[idx]; }
};