int g(int n) { return n ^ (n >> 1); }

int revg(int g) {
  int n = 0;
  while (g) n ^= g, g >>= 1;
  return n;
}