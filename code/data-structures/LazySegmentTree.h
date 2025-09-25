template <class T>
struct LazySeg {
  int n;
  vector<T> t;
  vector<T> lazy;
  // 0 for sum/gcd/or/xor and 1 for
  // and/product and infinity for max/min
  static const T neutral;
  // 0 for sum/gcd/or/xor and 1 for and/product
  // and infinity for max/min
  static const T neutralLazy;
  LazySeg() = default;
  LazySeg(vector<T>& a) {
    n = a.size();
    t.resize(4 * n, neutral);
    lazy.resize(4 * n, neutralLazy);
    build(a, 1, 0, n - 1);
  }
  T merge(T a, T b) { return a | b; }
  T conquer(T a, T b) { return a & b; }
  void propagate(int v, int l, int r) {
    if (l == r) return;
    t[2 * v] = merge(t[2 * v], lazy[v]);
    lazy[2 * v] = merge(lazy[2 * v], lazy[v]);
    t[2 * v + 1] = merge(t[2 * v + 1], lazy[v]);
    lazy[2 * v + 1] = merge(lazy[2 * v + 1], lazy[v]);
    lazy[v] = neutralLazy;
  }
  void build(vector<T>& a, int v = 1, int l = 0, int r = n - 1) {
    if (l == r)
      t[v] = a[l];
    else {
      int m = (l + r) / 2;
      build(a, 2 * v, l, m);
      build(a, 2 * v + 1, m + 1, r);
      t[v] = conquer(t[2 * v], t[2 * v + 1]);
    }
  }
  void update(int a, int b, T val, int v, int l, int r) {
    propagate(v, l, r);
    if (a > r || b < l) return;
    if (l >= a && r <= b) {
      t[v] = merge(t[v], val);
      lazy[v] = merge(lazy[v], val);
      return;
    }
    int m = (l + r) / 2;
    update(a, b, val, 2 * v, l, m);
    update(a, b, val, 2 * v + 1, m + 1, r);
    t[v] = conquer(t[2 * v], t[2 * v + 1]);
  }
  void update(int a, int b, T val) { update(a, b, val, 1, 0, n - 1); }
  // query for range [a,b]
  T query(int a, int b, int v, int l, int r) {
    propagate(v, l, r);
    if (a > r || b < l) return neutral;
    if (l >= a && r <= b) return t[v];
    int m = (l + r) / 2;
    auto ql = query(a, b, 2 * v, l, m);
    auto qr = query(a, b, 2 * v + 1, m + 1, r);
    return conquer(ql, qr);
  }
  T query(int a, int b) { return query(a, b, 1, 0, n - 1); }
};