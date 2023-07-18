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