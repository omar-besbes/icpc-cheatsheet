const int n = 1e6 + 1;
int phi[n];

int totient() {
   for (int i = 0; i < n; i++) phi[i] = i;
   for (int i = 1; i < n; i++)
      for (int j = 2 * i; j < n; j += i) phi[j] -= phi[i];
}
