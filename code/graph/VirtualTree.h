struct VirtualTree {
    int n, LOG, timer;
    vector<vector<int>> adj, up, vadj; 
    vector<int> tin, tout, depth, used_nodes;
    
    VirtualTree(int _n) : n(_n) {
      LOG = __lg(n) + 2; // Use +2 for safety
      tin.resize(n), tout.resize(n), depth.resize(n);
      up.assign(n, vector<int>(LOG));
      adj.resize(n), vadj.resize(n);
      timer = 0;
    }
  
    void addEdge(int u, int v) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  
    void dfs_lca(int v, int p, int d) {
      tin[v] = timer++;
      up[v][0] = p;
      depth[v] = d;
      for (int i = 1; i < LOG; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
  
      for (int u : adj[v]) 
        if (u != p)  dfs_lca(u, v, d + 1);  
      tout[v] = timer++;
    }
  
    void build(int root = 0) { dfs_lca(root, root, 0); }
  
    bool isAncestor(int u, int v) {
      return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
  
    int lca(int u, int v) {
      if (isAncestor(u, v)) return u;
      if (isAncestor(v, u)) return v;
        
      for (int i = LOG - 1; i >= 0; --i) 
        if (!isAncestor(up[u][i], v)) u = up[u][i];
      return up[u][0];
    }
  
    void clearVirtualTree() {
      for (int v : used_nodes) vadj[v].clear();
      used_nodes.clear();
    }
  
    vector<int> buildVirtualTree(vector<int> &nodes) {
      if (nodes.size() <= 1)   return nodes;
      clearVirtualTree();
  
      auto cmpTin = [&](int a, int b) { return tin[a] < tin[b]; };
      sort(nodes.begin(), nodes.end(), cmpTin);
  
      int k = nodes.size();
      for (int i = 0; i < k - 1; ++i) 
        nodes.push_back(lca(nodes[i], nodes[i + 1]));
  
      sort(nodes.begin(), nodes.end(), cmpTin);
      nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
  
      vector<int> st;
      for (int v : nodes) {
        while (!st.empty() && !isAncestor(st.back(), v)) st.pop_back();
        if (!st.empty())  vadj[st.back()].push_back(v);
        st.push_back(v);
        used_nodes.push_back(v); 
      }
  
      return nodes;
    }
  };