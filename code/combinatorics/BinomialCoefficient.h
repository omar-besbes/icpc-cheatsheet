#include "BinaryExponentiation.h"
vector<ll> fact;

ll nCk(ll n, ll k, ll p = mod) {
  if (k > n) return 0;
  if (k == 0) return 1;
  return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}

ll nCk1(ll n, ll k, ll p = mod) {
  if (k > n) return 0;
  if (k == 0) return 1;
  return ((nCk(n % p, k % p, p) % mod) * (nCk1(n / p, k / p, p)) %
          mod) %
         mod;
}

ll starsandbars(ll stars, ll bars) {
  return nCk(bars + stars, stars);
}

ll C(ll n, ll r) {
  ll p = 1, k = 1;
  if (r > n) return 0;
  if (n - r < r) r = n - r;
  if (r != 0)
    while (r) {
      p *= n, k *= r;
      ll m = gcd(p, k);
      p /= m, k /= m;
      n--, r--;
    }
  return p;
}
