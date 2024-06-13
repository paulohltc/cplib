const double inf = 1e100, eps = 1e-9;
const double PI = acos(-1.0L);
int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct Point{
	double x,y;
	Point(double x = 0, double y = 0) : x(x),y(y){}
	Point(const Point& p): x(p.x), y(p.y){}
  bool operator < (const Point &p) const {
    if(cmp(x, p.x) != 0) return x < p.x;
    return cmp(y, p.y) < 0;
  }
  bool operator == (const Point &p) const {return !cmp(x, p.x) && !cmp(y, p.y);}
  bool operator != (const Point &p) const {return !(p == *this);}

	// basic ops
	Point operator + (const Point& p) const {return Point(x+p.x,y+p.y);}
	Point operator - (const Point& p) const {return Point(x-p.x,y-p.y);}
	Point operator * (const double k) const {return Point(x*k,y*k);}
	Point operator / (const double k) const {return Point(x/k,y/k);}
};
	// points ops
double dot (const Point& p,const Point& q) { return p.x*q.x + p.y*q.y; }
double cross (const Point& p,const Point& q) { return p.x*q.y - p.y*q.x; }
double norm(const Point& p) { return hypot(p.x,p.y); }
double dist(const Point& p, const Point& q) { return hypot(p.x-q.x,p.y-q.y); }
double dist2(const Point& p, const Point& q) { return dot(p-q,p-q); }
Point perp(const Point& p) { return Point(-p.x,p.y); }
Point normalize(const Point &p) { return p/hypot(p.x, p.y); }
double angle (const Point& p, Point& q) { return atan2(cross(p, q), dot(p, q)); }
double angle (const Point& p) { return atan2(p.y, p.x); }

ostream &operator<<(ostream &os, const Point &p) {
	return os << "(" << p.x << "," << p.y << ")"; 
}

struct Line{
	Point p, vd;
	Line(){}
	Line(const Point& p, const Point& vd) : p(p), vd(vd) {};
};


double distPointLine(const Point& p, const Line& l){
	Point vp = p-l.p;
	return abs(cross(vp,l.vd))/norm(l.vd);
}

ostream &operator<<(ostream &os, const Line &l) {
	return os << "(" << l.p.x << "," << l.p.y << ")" << "+ t(" << l.vd.x << "," << l.vd.y << ")"; 
}


