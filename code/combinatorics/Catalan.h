const int mod = 1e9 + 7;
const int n = 1e6 + 1;
int catalan[n];

void gencatalan() {
  catalan[0] = catalan[1] = 1;
  for (int i = 2; i <= n; i++) {
    catalan[i] = 0;
    for (int j = 0; j < i; j++) {
      catalan[i] += (catalan[j] * catalan[i - j - 1]) % mod;
      if (catalan[i] >= mod) catalan[i] -= mod;
    }
  }
}