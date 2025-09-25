ll binpow(ll a, ll b, ll m = mod) {
  if (a == 0) return 0;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

ll inv(ll a, ll m = mod) { return binpow(a, m - 2, m); }