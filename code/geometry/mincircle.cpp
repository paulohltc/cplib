double ccRadius(const Point& A, const Point& B, const Point& C) {
	Point ab = B-A, ac = C-A;
	return dist(A,B)*dist(B,C)*dist(A,C)/
			abs(cross(ab,ac))/2; 
}
Point ccCenter(const Point& A, const Point& B, const Point& C) {
	Point b = C-A, c = B-A;
	Point x = b*dot(c,c)-c*dot(b,b);
	return A + perp(x)/cross(b,c)/2;
}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<Point, double> mec(vector<Point>& pts){
	shuffle(begin(pts),end(pts),rng);
	Point o = pts[0];
	const double EPSS = 1+1e-8;
	double r = 0;
	for(int i = 0; i < pts.size(); i++) if(dist(o, pts[i]) > r * EPSS){
		o = pts[i], r = 0;
		for(int j = 0; j < i; j++) if(dist(o, pts[j]) > r * EPSS){
			o = (pts[i]+pts[j])/2.0;
			r = dist(o,pts[i]);
			for(int k = 0; k < j; k++) if(dist(o, pts[k]) > r * EPSS){
				o = ccCenter(pts[i],pts[j],pts[k]);
				r = dist(o,pts[i]);
			}
		}
	}
	return {o, r};
}