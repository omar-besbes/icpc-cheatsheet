const ll mod = 1e9 + 7;

tuple<ll, ll, ll> numprodsum(vector<pll> &a) {
  int n = a.size();

  // num  is the number of divisors mod 1e9+7
  ll num = 1, sum = 1, prod = 1;
  for (auto [p, k] : a) {
    num *= (k + 1) % mod, num %= mod;
    sum *= (binpow(p, k + 1) - 1) * inv(p - 1) % mod, sum %= mod;
  }

  // there is no way to compute inverse modulo of 2 mod (1e9 + 7) - 1
  // or any prime modulus, since 2 and mod - 1 are always not coprime
  vector<ll> precompute(n);
  for (ll i = 0, num2 = 1; i < n; i++) {
    auto [p, k] = *(a.begin() + i);
    precompute[i] =
        binpow(p, num2 * (k * (k + 1) / 2 % (mod - 1)) % (mod - 1));
    num2 *= (k + 1) % (mod - 1), num2 %= mod - 1;
  }

  for (ll i = n - 1, num2 = 1; i >= 0; i--) {
    auto [p, k] = *(a.begin() + i);
    prod *= binpow(precompute[i], num2), prod %= mod;
    num2 *= (k + 1) % (mod - 1), num2 %= mod - 1;
  }

  return make_tuple(num, sum, prod);
}