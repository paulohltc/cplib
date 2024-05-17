



using Line = Segment;
bool inLine(const Point& p, const Line& l){
	return cmp(cross(p-l.p, l.q-l.p));
}