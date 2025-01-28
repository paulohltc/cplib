// hypot, atan2, gcd
const double PI = acos(-1);
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<typename T>
struct PT{
  T x, y;
  PT(T x=0, T y=0) : x(x),y(y){}
  bool operator < (PT o) const { return tie(x,y) < tie(o.x,o.y); }
  bool operator == (PT o) const { return tie(x,y) == tie(o.x,o.y); }
  PT operator + (PT o) const { return PT(x+o.x,y+o.y); }
  PT operator - (PT o) const { return PT(x-o.x,y-o.y); }
  PT operator * (T k) const { return PT(x*k,y*k); }
  PT operator / (T k) const { return PT(x/k,y/k); }
  T cross(PT o) const { return x*o.y - y*o.x; }
  T cross(PT a, PT b) const { return (a-*this).cross(b-*this); }
  T dot(PT o) const { return x*o.x + y*o.y; }
  T dist2() const { return x*x + y*y; }
  double len() const { return hypot(x,y); }
  PT perp() const { return PT(-y,x); }
  PT rotate(double a) const { return PT(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
  int quad() { return (x<0)^3*(y<0); }
  bool ccw(PT<T> q, PT<T> r){ return (q-*this).cross(r-q) > 0;}
};
template<typename T>
bool cmp_ang(PT<T> p, PT<T> q){
    if (p.quad() != q.quad()) return p.quad() < q.quad();
    return q.ccw(PT<T>(0,0),p);
}

ostream &operator<<(ostream &os, const PT<int> &p) {
  return os << "(" << p.x << "," << p.y << ")"; 
}
