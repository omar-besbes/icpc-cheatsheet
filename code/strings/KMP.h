/**
 * pi[x] computes the length of the longest prefix of s that ends
 * at x, other than s[0...x] itself (abacaba -> 0010123).
 * Can be used to find all occurrences of a string.
 */

vector<int> pi(const string& s) {
  vector<int> p(s.length());
  for (int i = 1; i < s.length(); i++) {
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

vector<int> match(const string& s, const string& pat) {
  vector<int> p = pi(pat + '\0' + s), res;
  int n = s.length(), m = pat.length();
  for (int i = m; i < n + m + 1; i++)
    if (p[i] == m) res.push_back(i - 2 * m);
  return res;
}
