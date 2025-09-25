const int n = 1e6 + 1;
bool prime[n];
int mob[n];

void mobius() {
  for (int i = 2; i < n; i++) mob[i] = -1, prime[i] = true;
  for (int i = 2; i < n; i++)
    if (prime[i]) {
      mob[i] = 1;
      for (int j = 2 * i; j < n; j += i) {
        prime[j] = false;
        mob[j] = j % (i * i) == 0 ? 0 : -mob[j];
      }
    }
}
