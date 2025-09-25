vector<int> toposort(const vector<vector<int>>& adj) {
  vector<int> deg(adj.size()), q;
  for (int i = 0; i < adj.size(); i++) deg[i] = adj[i].size();
  for (int i = 0; i < adj.size(); i++)
    if (deg[i] == 0) q.push_back(i);
  for (int j = 0; j < q.size(); j++)
    for (auto x : adj[q[j]])
      if (--deg[x] == 0) q.push_back(x);
  return q;
}