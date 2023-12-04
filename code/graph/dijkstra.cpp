// Dijkstra
#define pii pair<ll,ll>
const ll MXN = 2e5+5;
const ll INF = LLONG_MAX;
int v,e;
vector<pii> adj[MXN];
vector<ll> parent(MXN,-1);
vector<ll> dist(MXN,INF);

void dijkstra(ll node){
	dist[node] = 0;
	priority_queue<pii,vector<pii>, greater<pii>> pq;
	pq.push({0,node});
	while(!pq.empty()){
		auto [d,u] = pq.top();
		pq.pop();
		if(d > dist[u]) continue;
		for(auto [cost, v] : adj[u]){
			ll currD = dist[u] + cost;
			if(currD < dist[v]){
				dist[v] = currD;
				parent[v] = out;
				pq.push({currD,v});
			}
		}
	}
}