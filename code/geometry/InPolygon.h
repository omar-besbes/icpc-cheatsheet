/**
 * Returns 1 if p lies inside the polygon, 0 if on the boundary of
 * the ploygon and -1 if outside the polygon.
 * Time: O(n).
 */

template <class P>
int inPolygon(vector<P> &poly, P cur) {
   auto intersect = [](P cur, P p1, P p2) {
      return cur.cross(p1, p2) == 0 &&
             (min(p1.x, p2.x) <= cur.x && max(p1.x, p2.x) >= cur.x) &&
             (min(p1.y, p2.y) <= cur.y && max(p1.y, p2.y) >= cur.y);
   };

   int crossings = 0;
   bool isBoundary = false;
   int n = poly.size();

   for (int i = 0; !isBoundary && i < n; i++) {
      auto p1 = poly[i], p2 = poly[(i + 1) % n];
      if (p1.y > p2.y) swap(p1, p2);

      if (intersect(cur, p1, p2)) {
         isBoundary = true;
      } else {
         auto isTouch = cur.cross(p1, p2) >= 0;
         auto isBetween = (p1.y < cur.y) && (p2.y >= cur.y);
         if (isTouch && isBetween) crossings++;
      }
   }

   if (!isBoundary)
      return (crossings & 1 ? 1 : -1);
   else
      return 0;
}
