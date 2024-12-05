#include "../data-structures/SegmentTree.h"

struct RMQLCA {
  int n;
  vector<int> first, epath, etime;
  struct RMQ : Seg<int> {
    RMQ() : Seg<int>() { neutral = INT_MAX; }
    RMQ(int n, vector<int> &a) : Seg<int>(n, a) {}
    int merge(int l, int r) override { return min(l, r); }
  };
  RMQ t;
  RMQLCA(vector<vector<int>> &adj, int root = 0) {
    n = adj.size();
    first.resize(n);
    epath.reserve(n * 2);
    etime.reserve(n * 2);
    dfs(adj, root, root);
    int m = etime.size();
    t = RMQ(m, etime);
  }
  void dfs(vector<vector<int>> &adj, int v, int p, int h = 0) {
    first[v] = epath.size();
    for (auto c : adj[v])
      if (c != p) {
        epath.push_back(v), etime.push_back(first[v]);
        dfs(adj, c, v, h + 1);
      }
  }
  int lca(int u, int v) {
    auto [l, r] = minmax(first[u], first[v]);
    return epath[t.query(l, r)];
  }
};

struct BLLCA {
  int n, l, timer;
  vector<vector<int>> adj, up;
  vector<int> tin, tout;
  BLLCA(int n, vector<vector<int>> &adj, int root = 0)
      : n(n), adj(adj) {
    timer = 0, l = ceil(log2(n));
    tin.resize(n), tout.resize(n);
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
  }
  void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for (int u : adj[v])
      if (u != p) dfs(u, v);
    tout[v] = ++timer;
  }
  bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  }
  int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i)
      if (!is_ancestor(up[u][i], v)) u = up[u][i];
    return up[u][0];
  }
};