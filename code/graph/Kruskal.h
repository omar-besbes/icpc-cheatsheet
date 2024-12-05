#include "../data-structures/DSU.h"

struct Edge {
  int u, v, weight;
  bool operator<(Edge const& other) { return weight < other.weight; }
};

struct Kruskal {
  int n;
  vector<Edge> edges;
  DSU uf;
  Kruskal(int n, vector<Edge>& edges) : n(n), edges(edges), uf(n) {}
  vector<Edge> mst() {
    vector<Edge> res;
    sort(edges.begin(), edges.end());
    int cost = 0;
    for (auto [u, v, w] : edges)
      if (uf.find(u) != uf.find(v)) {
        cost += w;
        res.push_back({u, v, w});
        uf.join(u, v);
      }
    return res;
  }
};
