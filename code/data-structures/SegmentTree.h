/**
 * Description: Zero-indexed tree. 
 * Bounds are inclusive to the left and to the right. 
 * Can be changed by modifying T, merge and neutral.
 */

template <class T>
struct Seg {
   int n;
   vector<T> t;
   static constexpr T neutral;
   Seg(vector<int> &a) {
      n = a.size();
      t.resize(4 * n);
      build(a, 1, 0, n - 1);
   }
   T merge(T a, T b);  // (any associative fn)
   void build(vector<T> &a, int v, int l, int r) {
      if (l == r)
         t[v] = a[l];
      else {
         int m = (l + r) / 2;
         build(a, 2 * v, l, m);
         build(a, 2 * v + 1, m + 1, r);
         t[v] = merge(t[2 * v], t[2 * v + 1]);
      }
   }
   // query for range [a,b]
   T query(int a, int b, int v, int l, int r) {
      if (a > r || b < l) return neutral;
      if (a == l && b == r) return t[v];
      int m = (l + r) / 2;
      auto ql = query(a, min(b, m), 2 * v, l, m);
      auto qr = query(max(a, m + 1), b, 2 * v + 1, m + 1, r);
      return merge(ql, qr);
   }
};
