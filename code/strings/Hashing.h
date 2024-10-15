/**
 * Return the prefix hashes of a string using a pool of prime numbers.
 */

struct Hashing {
   typedef long long ll;
   const ll mod = 1e9 + 7;
   vector<vector<ll>> p, pref;
   // assuming s is only composed of a-z characters
   Hashing(string &s) {
      // change if s contains other chars than a-z
      // primes should be greater than number of possible characters
      vector primes{31, 37, 43};
      p.resize(primes.size());
      for (int i = 0; i < primes.size(); i++) p[i][0] = 1, p[i][1] = primes[i];
      int n = s.length();
      vector<vector<ll>> pref(n + 1);
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
      int n = p[0].size();
      vector<ll> ans(p.size());
      for (int i = 0; i < p.size(); i++) {
         ans[i] = (pref[i][r + 1] - pref[i][l] + mod) % mod;
         ans[i] = ans[i] * p[i][n - l] % mod;
      }
      return ans;
   }
};
