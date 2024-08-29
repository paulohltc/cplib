typedef PT<double> P;
double ccRadius(P& A, P& B, P& C) {
  return (B-A).len()*(C-B).len()*(A-C).len()/
      abs((B-A).cross(C-A))/2.0;
}

P ccCenter(P& A, P& B, P& C) {
  P b = C-A, c = B-A;
  return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pair<P, double> mec(vector<P>& pts){
	shuffle(begin(pts),end(pts),rng);
	P o = pts[0];
	const double EPSS = 1+1e-8;
	double r = 0;
	for(int i = 0; i < pts.size(); i++) if((o-pts[i]).len() > r * EPSS){
		o = pts[i], r = 0;
		for(int j = 0; j < i; j++) if((o-pts[j]).len() > r * EPSS){
			o = (pts[i]+pts[j])/2.0;
			r = (o - pts[i]).len();
			for(int k = 0; k < j; k++) if((o-pts[k]).len() > r * EPSS){
				o = ccCenter(pts[i],pts[j],pts[k]);
				r = (o - pts[i]).len();
			}
		}
	}
	return {o, r};
}