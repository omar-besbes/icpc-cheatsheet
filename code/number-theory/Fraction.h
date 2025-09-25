/**
 * If fraction is negative, the nominator holds the sign.
 * Nominator and denominator values can go up to 1e9.
 * For values up to 1e18, replace ll with ld and int with ll
 * and add the proper implementation of gcd for ld
 */

struct Frac {
  ll a, b;
  Frac(int a) : a(a), b(1) {}
  Frac(int x, int y) {
    assert(y != 0);
    auto sgn = x && (x < 0) ^ (y < 0) ? -1 : 1;
    x = abs(x), y = abs(y);  // ensure positive denominator
    auto g = gcd(x, y);
    a = sgn * x / g, b = y / g;
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
