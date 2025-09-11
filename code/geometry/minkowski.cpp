using P = PT<double>;
vector<P> minkowskiSum(vector<P> p, vector<P> q){
  if(p.empty() || q.empty()) return {};
  auto fix = [](vector<P>& x) {
      rotate(x.begin(), min_element(x.begin(), x.end()), x.end());
      x.push_back(x[0]), x.push_back(x[1]);
  };
  fix(p); fix(q);
	vector<P> ret;
	int i = 0, j = 0;
	while (i < p.size()-2 or j < q.size()-2) {
		ret.push_back(p[i] + q[j]);
		auto c = ((p[i+1] - p[i]).cross(q[j+1] - q[j]));
		if (c >= 0) i = min<int>(i+1, p.size()-2);
		if (c <= 0) j = min<int>(j+1, q.size()-2);
	}
	return ret;
}

double segDist(P s, P e, P p) {
	if (s==e) return (p-s).len();
	auto d = (e-s).dist2(), t = min(d,max(.0l,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).len()/d;
}

double dist_convex(vector<P> p, vector<P> q) {
	for (P& i : p) i = i * -1;
	auto s = minkowskiSum(p, q);
	if (isInside(s, P(0,0))) return 0;
	double ans = 1e18; // INF
  int ssz = s.size();
  for(int i = 0; i < ssz; i++){
        int j = (i+1)%ssz;
        ans = min(ans, segDist(s[i], s[j], P(0,0)));
    }
	return ans;
}
 
