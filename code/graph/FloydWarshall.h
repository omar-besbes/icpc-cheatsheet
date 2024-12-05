const int INF = 1e9 + 7;

void floydwarshall(int n, vector<vector<int>> &d) {
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (d[i][k] < INF && d[k][j] < INF) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          d[j][i] = min(d[j][i], d[j][k] + d[k][i]);
        }
}