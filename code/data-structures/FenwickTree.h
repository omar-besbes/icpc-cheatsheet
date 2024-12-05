/**
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1],
 * and updates single elements a[i],
 * taking the difference between the old and new value.
 */

template <class T>
struct FT {
  vector<T> s;
  FT(int n) : s(n) {}
  void update(int pos, T dif) {  // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  // sum of values in [0, pos)
  T query(int pos) {
    T res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
  // min pos st sum of [0, pos] >= sum
  // Returns n if no sum is >= sum, or -1 if empty sum is.
  int lower_bound(T sum) {
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};
