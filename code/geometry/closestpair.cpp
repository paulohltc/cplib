pii ClosestPair(vector<PT<ll>>& pts) {
  ll dist = (pts[0]-pts[1]).dist2();
  pii ans(0, 1);
  int n = pts.size();
  vector<int> p(n);
  iota(begin(p),end(p),0);
  sort(p.begin(), p.end(), [&](int a, int b) { return pts[a].x < pts[b].x; });
  set<pii> points;
  auto sqr = [](long long x) -> long long { return x * x; };
  for(int l = 0, r = 0; r < n; r++) {
    while(sqr(pts[p[r]].x - pts[p[l]].x) > dist) {
      points.erase(pii(pts[p[l]].y, p[l]));
      l++;
    }
    ll delta = sqrt(dist) + 1;
    auto itl = points.lower_bound(pii(pts[p[r]].y - delta, -1));
    auto itr = points.upper_bound(pii(pts[p[r]].y + delta, n + 1));
    for(auto it = itl; it != itr; it++) {
      ll curDist = (pts[p[r]] - pts[it->second]).dist2();
      if(curDist < dist) {
        dist = curDist;
        ans = pii(p[r], it->second); 
      }
    }
    points.insert(pii(pts[p[r]].y, p[r]));
  }
  if(ans.first > ans.second) 
    swap(ans.first, ans.second);
  return ans;
}