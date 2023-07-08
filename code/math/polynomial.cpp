template<typename T> 
struct Poly {
  int n;
  vector<T> v;
  Poly(int sz) : n(sz+1) { v.resize(sz+1,0);}
  friend Poly operator*(const Poly& lhs, const Poly& rhs) {
    int grauL = (int)lhs.n - 1;
    int grauR = (int)rhs.n - 1;
    Poly ans(grauR+grauL);
    for(int i = 0; i <= grauL; ++i) {
      for(int j = 0; j <= grauR; ++j) {
        ans.v[i + j] += lhs.v[i] * rhs.v[j];
      }
    }
    return ans;
  }
  void set_identity() { // 1
    v[0] = T(1);
    for(int i = 1; i < n; ++i) {
      v[i] = T(0);
    }
  }
};
template<typename T>
Poly<T> poly_exp(Poly<T> a, long long e) {
  Poly<T> r(0);
  r.set_identity();
  for(; e > 0; e >>= 1) {
    if(e & 1) {
      r = r * a;
    }
    a = a * a;
  }
  return r;
}