struct VirtualTree {
    int n, LOG;
    vector<vector<int>> adj; // Original tree adjacency list
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    int timer;
  
    // --- Virtual Tree Members ---
    vector<vector<int>> vadj; // Adjacency list for the virtual tree
    vector<int> used_nodes;   // For efficient cleanup
  
    VirtualTree(int _n) : n(_n) {
      LOG = __lg(n) + 2; // Use +2 for safety
      adj.resize(n);
      tin.resize(n);
      tout.resize(n);
      depth.resize(n);
      up.assign(n, vector<int>(LOG));
      vadj.resize(n); // IMPORTANT: Allocate memory for vadj only ONCE.
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
      for (int i = 1; i < LOG; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
      }
  
      for (int u : adj[v]) {
        if (u != p) {
          dfs_lca(u, v, d + 1);
        }
      }
      tout[v] = timer++;
    }
  
    void build(int root = 0) { dfs_lca(root, root, 0); }
  
    bool isAncestor(int u, int v) {
      return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
  
    int lca(int u, int v) {
      if (isAncestor(u, v))
        return u;
      if (isAncestor(v, u))
        return v;
      for (int i = LOG - 1; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
          u = up[u][i];
        }
      }
      return up[u][0];
    }
  
    // OPTIMIZATION 1: Efficient Cleanup
    // This function is now called internally by buildVirtualTree.
    void clearVirtualTree() {
      for (int v : used_nodes) {
        vadj[v].clear();
      }
      used_nodes.clear();
    }
  
    // OPTIMIZATION 2: Efficient Single-Pass Construction
    vector<int> buildVirtualTree(vector<int> &nodes) {
      if (nodes.size() <= 1) {
        return nodes; // No paths to form with 0 or 1 node
      }
  
      // Start by cleaning up the state from the previous run.
      clearVirtualTree();
  
      auto cmpTin = [&](int a, int b) { return tin[a] < tin[b]; };
      sort(nodes.begin(), nodes.end(), cmpTin);
  
      // Add LCAs of adjacent nodes to capture all necessary path junctions.
      int k = nodes.size();
      for (int i = 0; i < k - 1; ++i) {
        nodes.push_back(lca(nodes[i], nodes[i + 1]));
      }
  
      // Sort again and remove duplicates to get the final set of virtual tree
      // nodes.
      sort(nodes.begin(), nodes.end(), cmpTin);
      nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
  
      vector<int> st;
      for (int v : nodes) {
        while (!st.empty() && !isAncestor(st.back(), v)) {
          st.pop_back();
        }
        if (!st.empty()) {
          vadj[st.back()].push_back(v);
        }
        st.push_back(v);
        used_nodes.push_back(v); // Track node for cleanup
      }
  
      // The root of the virtual tree is the first node in the sorted list.
      return nodes;
    }
  };