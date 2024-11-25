struct Frac {
  ll a, b;
  Frac(ll a) : a(a), b(1) {}
  Frac(ll x, ll y) {
    assert(y != 0);
    auto g = gcd(x, y);
    a = x / g, b = y / g;
    if (b < 0) a *= -1, b *= -1; // ensure positive denominator
  }
  Frac operator+(Frac f) { return Frac(a * f.b + b * f.a, b * f.b); }
  Frac operator-(Frac f) { return Frac(a * f.b - b * f.a, b * f.b); }
  Frac operator*(Frac f) { return Frac(a * f.a, b * f.b); }
  Frac operator/(Frac f) { return Frac(a * f.b, b * f.a); }
  Frac inverse() { return Frac(b, a); }
  bool operator<(Frac f) { return a * f.b < b * f.a; }
  bool operator<=(Frac f) { return a * f.b <= b * f.a; }
  bool operator>(Frac f) { return a * f.b > b * f.a; }
  bool operator>=(Frac f) { return a * f.b >= b * f.a; }
};
