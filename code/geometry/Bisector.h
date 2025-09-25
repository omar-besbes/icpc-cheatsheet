template <class P, class L>
L bisector(P x, P y, P z) {
  // make sure T is double
  y = (y - x), z = (z - x);
  P mid = (y * z.dist() + z * y.dist());
  return L(x, x + mid);
}