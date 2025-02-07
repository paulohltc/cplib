template<typename T>
T bin_exp(T a, long long e) {
  T r(1);
  for(; e > 0; e >>= 1) {
    if(e & 1) {
      r *= a;
    }
    a *= a;
  }
  return r;
}
template<const uint32_t MOD>
struct Mod {
  uint32_t x;
  Mod() : x(0) {};
  template<typename T>
  Mod(T x) : x(uint32_t(((int64_t(x) % MOD) + MOD) % MOD)) {}
  Mod& operator+=(Mod rhs) {
    x += rhs.x;
    if(x >= MOD) x -= MOD;
    return *this;
  }
  Mod& operator-=(Mod rhs) {
    x += MOD - rhs.x;
    if(x >= MOD) x -= MOD;
    return *this;
  }
  Mod& operator*=(Mod rhs) {
    auto y = 1ull * x * rhs.x;
    if(y >= MOD) y %= MOD;
    x = uint32_t(y);
    return *this;
  }
  Mod& operator/=(Mod rhs) { return *this *= bin_exp(rhs, MOD - 2); }
  friend Mod operator+(Mod lhs, Mod rhs) { return lhs += rhs; }
  friend Mod operator-(Mod lhs, Mod rhs) { return lhs -= rhs; }
  friend Mod operator*(Mod lhs, Mod rhs) { return lhs *= rhs; }
  friend Mod operator/(Mod lhs, Mod rhs) { return lhs /= rhs; }
  bool operator==(Mod rhs) const { return x == rhs.x; }
  bool operator!=(Mod rhs) const { return x != rhs.x; }
  friend ostream& operator<<(ostream& os, const Mod& o) { return os << o.x; }
  friend istream& operator>>(istream& is, Mod& o) { 
    int64_t x;
    is >> x;
    o = Mod(x);
    return is;
  }
};
