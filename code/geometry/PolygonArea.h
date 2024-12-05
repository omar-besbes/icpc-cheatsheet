/**
 * Description: Returns twice the signed area of a polygon.
 *    Clockwise enumeration gives negative area.
 *    Watch out for overflow if using int as P!
 */

template <class P>
P polygonArea2(vector<Point<P>>& v) {
  P ans = v.back().cross(v[0]);
  for (int i = 0; i < v.size() - 1; i++) ans += v[i].cross(v[i + 1]);
  return ans;
};
