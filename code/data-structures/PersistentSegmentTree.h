struct PersistentSegmentTree {
  struct Vertex {
    Vertex *l, *r;
    int sum;
    int xxor;
    Vertex(int val, int x)
        : l(nullptr), r(nullptr), sum(val), xxor(x) {}
    Vertex(Vertex* l, Vertex* r) : l(l), r(r), sum(0), xxor(0) {
      if (l) sum += l->sum;
      if (r) sum += r->sum;
      if (l) xxor ^= l->xxor;
      if (r) xxor ^= r->xxor;
    }
  };
  int conquer(int a, int b) { return a ^ b; }
  Vertex* build(int tl, int tr) {
    if (tl == tr) return new Vertex(0LL, 0LL);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm + 1, tr));
  }

  Vertex* update(Vertex* v, int tl, int tr, int pos, int val) {
    if (tl == tr) return new Vertex(1, val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      return new Vertex(update(v->l, tl, tm, pos, val), v->r);
    else
      return new Vertex(v->l, update(v->r, tm + 1, tr, pos, val));
  }

  int find_xor(Vertex* vl, Vertex* vr, int tl, int tr, int k) {
    if (tl == tr) return vr->xxor ^ vl->xxor;
    int tm = (tl + tr) / 2;
    int left_count = vr->l->sum - vl->l->sum;
    int left_res = vr->l->xxor ^ vl->l->xxor;
    if (left_count >= k) return find_xor(vl->l, vr->l, tl, tm, k);
    return left_res ^
           find_xor(vl->r, vr->r, tm + 1, tr, k - left_count);
  }
};
