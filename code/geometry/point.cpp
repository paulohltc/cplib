// hypot, atan2, gcd
const double PI = acos(-1);
template<typename T>
struct PT{
  T x, y;
  PT(T x=0, T y=0) : x(x),y(y){}
  bool operator < (PT o)  { return tie(x,y) < tie(o.x,o.y); }
  bool operator == (PT o) { return tie(x,y) == tie(o.x,o.y); }
  PT operator + (PT o) { return PT(x+o.x,y+o.y); }
  PT operator - (PT o) { return PT(x-o.x,y-o.y); }
  PT operator * (T k) { return PT(x*k,y*k); }
  PT operator /(T k) { return PT(x/k,y/k); }
  T cross(PT o) { return x*o.y - y*o.x; }
  T dot(PT o) { return x*o.x + y*o.y; }
  T dist2() { return x*x + y*y; }
  double len() { return hypot(x,y); }
  PT perp() { return PT(-y,x); }
  PT rotate(double a) { return PT(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); }
};
ostream &operator<<(ostream &os, const PT<double> &p) {
  return os << "(" << p.x << "," << p.y << ")"; 
}
