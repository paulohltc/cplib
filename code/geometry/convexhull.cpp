// O(nlogn) sorted = false
// O(n) sorted = true
// retorna todos os pontos q tao no c.h
vector<Point> convexHull(vector<Point>& pts, bool sorted = false){ // pts.size() >= 3
  int n = pts.size();
  if(!sorted){  
    sort(begin(pts),end(pts));
  }
  vector<Point> lower(n + 1), upper(n + 1);
  int s = 0;
  for(int i = 0; i < n; i++){
    lower[s++] = pts[i];
    while(s >= 3){
      Point a = lower[s-3], b = lower[s-2], c = lower[s-1];
      Point v1 = b-a, v2 = c-b;
      if(cross(v1,v2) >= 0){
        break;
      }
      if(cross(v1,v2) < 0){ // tirar b
        lower[s-2] = lower[s-1];
        s--;
      }
    }
  }
  lower.resize(s);
  s = 0;
  for(int i = 0; i < n; i++){
    upper[s++] = pts[i];
    while(s >= 3){
      Point a = upper[s-3], b = upper[s-2], c = upper[s-1];
      Point v1 = b-a, v2 = c-b;
      if(cross(v1,v2) <= 0){
        break;
      }
      if(cross(v1,v2) > 0){ // tirar b
        upper[s-2] = upper[s-1];
        s--;
      }
    }
    
  }
  upper.resize(s-1);
  reverse(begin(upper),end(upper));
  upper.pop_back();
  lower.insert(end(lower),begin(upper),end(upper));
  return lower;
}

bool isInside(const vector<Point> &hull, Point pt) {
  int n = hull.size();
    Point v0 = pt - hull[0], v1 = hull[1] - hull[0], v2 = hull[n-1] - hull[0];
  if(cross(v0,v1) > 0 || cross(v0,v2) < 0) {
    return false;
  }
  int l = 1, r = n - 1;
  while(l != r) {
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
ll cntInsidePts(ll area_db, ll boundPts){
  return (area_db + 2LL - boundPts)/2;
}