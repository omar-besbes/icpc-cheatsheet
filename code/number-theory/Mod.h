#include "Euclid.h"

const ll mod = 1e9 + 7;  // change to something else
struct Mod {
   ll x;
   Mod(ll x) : x(x) {}
   Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
   Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
   Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
   Mod operator/(Mod b) { return *this * invert(b); }
   Mod invert(Mod a) {
      ll x, y, g = euclid(a.x, mod, x, y);
      assert(g == 1);
      return Mod((x + mod) % mod);
   }
   Mod operator^(ll e) {
      if (!e) return Mod(1);
      Mod r = *this ^ (e / 2);
      r = r * r;
      return e & 1 ? *this * r : r;
   }
};