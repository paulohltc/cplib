// Dijkstra
#define pii pair<ll,ll>
const ll MXN = 1e5+5;
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
		auto [d,out] = pq.top();
		pq.pop();
		ll d = curr.X, out = curr.Y; 
		if(d > dist[out]) continue;
		for(auto [cost, nb] : adj[out]){
			ll currD = dist[out] + cost;
			if(currD < dist[nb]){
				dist[nb] = currD;
				parent[nb] = out;
				pq.push({currD,nb});
			}
		}
	}
}