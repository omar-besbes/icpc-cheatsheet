#include "../data-structures/SegmentTree.h"

template <class node>
struct HLD {
  int n, root, segsz = 0;
  vector<vector<int>> adj;
  vector<int> parent, depth, heavy, head, pos;
  Seg<node> t;
  HLD(int n, vector<vector<int>> &adj, vector<node> &vals, int root = 0)
      : n(n), adj(adj), root(root) {
    parent.resize(n);
    depth.resize(n);
    heavy.resize(n);
    head.resize(n);
    pos.resize(n);
    dfs(root, -1);
    decompose(root, root);
    t = Seg<node>(segsz, vals);
  }
  int dfs(int v, int p, int d = 0) {
    parent[v] = p, depth[v] = d, heavy[v] = -1;
    int sz = 1, mxsz = 0;
    for (auto c : adj[v])
      if (c != p) {
        auto csz = dfs(c, v, d + 1);
        sz += csz;
        if (csz > mxsz) mxsz = csz, heavy[v] = c;
      }
    return sz;
  }
  void decompose(int v, int curhead) {
    head[v] = curhead, pos[v] = segsz++;
    if (heavy[v] != -1) decompose(heavy[v], curhead);
    for (auto c : adj[v])
      if (c != parent[v] && c != heavy[v]) decompose(c, c);
  }
  node query(int u, int v) {
    node res = t.neutral;
    while (head[u] != head[v]) {
      if (depth[head[u]] < depth[head[v]]) swap(u, v);
      auto curans = t.query(pos[head[u]], pos[u]);
      res = t.merge(res, curans);
      u = parent[head[u]];
    }
    if (pos[u] > pos[v]) swap(u, v);
    auto curans = t.query(pos[u], pos[v]);
    res = t.merge(res, curans);
    return res;
  }
};
