const int n = 1e6 + 1;
int lpd[n];
vector<int> primes;

void sieve() {
  for (int i = 2; i < n; ++i) {
    if (lpd[i] == 0) lpd[i] = i, primes.push_back(i);
    for (int j = 0; i * primes[j] < n; ++j) {
      lpd[i * primes[j]] = primes[j];
      if (primes[j] == lpd[i]) break;
    }
  }
}
