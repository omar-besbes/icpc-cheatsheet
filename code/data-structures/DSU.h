/**
 * Description: Disjoint-set data structure. Replace T with int.
 */

template <class T>
struct DSU {
   vector<T> e;
   DSU(T n) : e(n, -1) {}
   bool sameSet(T a, T b) { return find(a) == find(b); }
   T size(T x) { return -e[find(x)]; }
   T find(T x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
   bool join(T a, T b) {
      a = find(a), b = find(b);
      if (a == b) return false;
      if (e[a] > e[b]) swap(a, b);
      e[a] += e[b];
      e[b] = a;
      return true;
   }
};
