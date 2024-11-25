/**
 * Return the prefix hashes of a string using a pool of prime numbers.
 */

struct Hashing {
  typedef long long ll;
  const ll mod = 1e9 + 7;
  vector<vector<ll>> p, pref;
  // assuming s is only composed of a-z characters
  Hashing(const string &s) {
    int n = s.length();
    // change if s contains other chars than a-z
    // primes should be greater than number of possible characters
    vector primes{37, 41, 43};
    p.assign(primes.size(), vector<ll>(n + 1));
    pref.assign(primes.size(), vector<ll>(n + 1));
    for (int i = 0; i < primes.size(); i++)
      p[i][0] = 1, p[i][1] = primes[i];
    for (int i = 0; i < p.size(); i++) {
      p[i].resize(n + 1);
      for (int j = 0; j < n; j++) {
        // change here if s contains other chars than a-z
        int c = s[j] - 'a' + 1;
        pref[i][j + 1] = (pref[i][j] + c * p[i][j]) % mod;
        p[i][j + 1] = p[i][j] * p[i][1] % mod;
      }
    }
  }
  // hash of s[l..r] inclusive for l & r
  vector<ll> get(int l, int r) {
    int n = p[0].size() - 1;
    vector<ll> ans(p.size());
    for (int i = 0; i < p.size(); i++) {
      ans[i] = (pref[i][r + 1] - pref[i][l] + mod) % mod;
      ans[i] = ans[i] * p[i][n - l] % mod;
    }
    return ans;
  }
  bool compare(pair<int, int> r1, pair<int, int> r2) {
    auto res1 = get(r1.first, r1.second);
    auto res2 = get(r2.first, r2.second);
    for (int i = 0; i < p.size(); i++)
      if (res1[i] != res2[i]) return false;
    return true;
  }
};
