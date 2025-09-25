template <class T>
struct Matrix {
  typedef Matrix M;
  int N;
  vector<vector<T>> d;
  Matrix(int n) : N(n), d(n, vector<T>(n)) {}
  M operator*(const M& m) const {
    M ans(N);
    rep(i, 0, N) rep(k, 0, N) if (d[i][k]) rep(j, 0, N) {
      ans.d[i][j] += (d[i][k] * m.d[k][j]) % MOD;
      ans.d[i][j] %= MOD;
    }
    return ans;
  }
  vector<T> operator*(const vector<T>& vec) const {
    vector<T> ans(N);
    rep(i, 0, N) rep(j, 0, N) {
      ans[i] += (d[i][j] * vec[j]) % MOD, ans[i] %= MOD;
    }
    return ans;
  }
  M operator^(ll p) const {
    assert(p >= 0);
    M a(N), b(*this);
    rep(i, 0, N) a.d[i][i] = 1;
    while (p) {
      if (p & 1) a = a * b;
      b = b * b;
      p >>= 1;
    }
    return a;
  }
};
