const int mx = 1e5+5;
using pii = pair<ll,int>;
vector<pii> g[mx];
const ll inf = 8e18;
ll dist[mx]; // setar tudo inf

void dijkstra(ll src){
  dist[src] = 0;
  priority_queue<pii,vector<pii>, greater<pii>> pq;
  pq.push({0,src});
  while(!pq.empty()){
    auto [d, u] = pq.top();
    pq.pop();
    if(d > dist[u]) continue;
    for(auto [w, v] : g[u]){
      ll cur = dist[u] + w;
      if(cur < dist[v]){
        dist[v] = cur;
        pq.push({cur,v});
      }
    }
  }
}