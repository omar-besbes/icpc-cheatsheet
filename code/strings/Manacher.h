/**
 * For each position in a string, computes p[0][i] = half length of
 * longest even palindrome around pos i (abaccaba -> 00004000), p[1][i] = longest
 * odd (half rounded down) (abacaba -> 1214121).
 */

struct Manacher {
   array<vector<int>, 2> p;
   Manacher(const string& s) {
      int n = s.length();
      p = {vector<int>(n), vector<int>(n)};
      for (int z = 0; z < 2; z++)
         for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= !z && R + !z < n && s[L - !z] == s[R + !z])
               p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
         }
   }
   bool check(int l, int r) {
      int z = (r - l + 1) & 1;
		int m = (l + r + 1) / 2;
		return p[z][m] >= r - m + 1;
	}
};
