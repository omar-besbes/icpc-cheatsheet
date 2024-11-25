#include "Sieve.h"

vector<ll> fact(ll n) {
  vector<ll> ans;
  for (auto p : primes) {
    if (p * p > n) break;
    while (n % p == 0) ans.push_back(p), n /= p;
  }
  if (n > 1) ans.push_back(n);
  return ans;
}

vector<ll> fact2(ll x) {
  vector<ll> ans;
  while (x > 1) ans.push_back(lpd[x]), x /= lpd[x];
  return ans;
}