// O(nlogn) sorted = false
// O(n) sorted = true
vector<Point> convexHull(vector<Point> points, bool sorted = false) { 
  if(!sorted)  sort(begin(points), end(points));
  vector<Point> hull;
  hull.reserve(points.size() + 1);
  for (int phase = 0; phase < 2; ++phase) {
    int start = hull.size();
    for (Point& c : points) {
      while (hull.size() >= start+2){
        Point a = hull[hull.size()-2], b = hull.back();
        if(cross(b-a,c-a) > 0) break; // '>' descarta pontos colineares, '>=' nao, '<' sentido horario
        hull.pop_back();
      } 
      reverse(begin(points), end(points));
      hull.push_back(c);
    }
    hull.pop_back();
  }
  if (hull.size() == 2 && hull[0] == hull[1]) hull.pop_back();
  return hull;
}
// pegar half-hull 0 -> n
vector<Point> halfHull(vector<Point>& pts, bool upper = 0){
  int n = pts.size();
  vector<Point> hull(n + 1);
  int s = 0;
  for(int i = 0; i < n; i++){
    hull[s++] = pts[i];
    while(s >= 3){
      Point a = hull[s-3], b = hull[s-2], c = hull[s-1];
      Point v1 = b-a, v2 = c-b;
      if((upper?-1:1)*cross(v1,v2) >= 0)  break;
      hull[s-2] = hull[s-1];
      s--;
    }
  }
  hull.resize(s);
  return hull;
}

bool isInside(const vector<Point> &hull, Point pt) {
  int n = hull.size();
  Point v0 = pt - hull[0], v1 = hull[1] - hull[0], v2 = hull[n-1] - hull[0];
  if(cross(v0,v1) > 0 || cross(v0,v2) < 0){
    return false;
  }
  int l = 1, r = n - 1;
  while(l != r){
    int mid = (l + r + 1) / 2;
    Point v0 = pt - hull[0], v1 = hull[mid] - hull[0];
    if(cross(v0,v1) < 0) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  v0 = hull[(l+1)%n] - hull[l], v1 = pt - hull[l];
  return cross(v0,v1) >= 0;
}
// poligonos
ll polygon_area_db(const vector<Point>& poly){
  ll area = 0;
  for(int i = 0, n = (int)poly.size(); i < n; ++i) {
    int j = i + 1 == n ? 0 : i + 1;
    area += cross(poly[i], poly[j]);
  }
  return abs(area);
}
// Teorema de Pick para lattice points
// Area = insidePts + boundPts/2 - 1
// 2A - b + 2 = 2i
// usar gcd dos lados pra contar bound pts
ll cntInsidePts(ll area_db, ll bound){
  return (area_db + 2LL - bound)/2;
}