template <class T>
struct Matrix {
  typedef Matrix M;
  int N;
  vector<vector<T>> d;
  Matrix(int n) : N(n), d(n, vector<T>(n)) {}
  M operator*(const M& m) const {
    M ans(N);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        for (int k = 0; k < N; k++) {
          ans.d[i][j] += (d[i][k] * m.d[k][j]) % mod;
          ans.d[i][j] %= mod;
        }
    return ans;
  }
  vector<T> operator*(const vector<T>& vec) const {
    vector<T> ans(N);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        ans[i] += (d[i][j] * vec[j]) % mod, ans[i] %= mod;
    return ans;
  }
  M operator^(ll p) const {
    M a(N), b(*this);
    for (int i = 0; i < N; i++) a.d[i][i] = 1;
    while (p) {
      if (p & 1) a = a * b;
      b = b * b;
      p >>= 1;
    }
    return a;
  }
};
