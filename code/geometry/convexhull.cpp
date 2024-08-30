// retorna poligono no sentido anti horario, trocar pra < se quiser horario
template<typename T>
vector<PT<T>> convexHull(vector<PT<T>>& pts, bool sorted = false){
  if(!sorted) sort(begin(pts),end(pts));
  vector<PT<T>> h;
  h.reserve(pts.size() + 1);
  for(int it = 0; it < 2; it++){
    int start = h.size();
    for(PT<T>& c : pts){
      while((int)h.size() >= start + 2){
        PT<T> a = h[h.size()-2], b = h.back();
        // '>=' pra nao descartar pontos colineares
        if((b-a).cross(c-a) >= 0) break; 
        h.pop_back();
      }
      h.push_back(c);
    }
    reverse(begin(pts),end(pts));
    h.pop_back();
  }
  if(h.size() == 2 && h[0] == h[1]) h.pop_back();
  return h;
}

// nao funciona se tem pontos colineares!!!!
// considera ponto na aresta como dentro
template<typename T>
bool isInside(vector<PT<T>>& hull, PT<T> p) {
  int n = hull.size();
  PT<T> v0 = p - hull[0], v1 = hull[1] - hull[0], v2 = hull[n-1] - hull[0];
  if(v0.cross(v1) > 0 || v0.cross(v2) < 0){
    return false;
  }
  int l = 1, r = n - 1;
  while(l != r){
    int mid = (l + r + 1) / 2;
    PT<T> v0 = p - hull[0], v1 = hull[mid] - hull[0];
    if(v0.cross(v1) < 0)
      l = mid;
    else 
      r = mid - 1;
  }
  v0 = hull[(l+1)%n] - hull[l], v1 = p - hull[l];
  return v0.cross(v1) >= 0;
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