int n = 1e5;
DSU dsu = DSU(n+5);
using tp = tuple<ll,int,int>
vector<tp> edges(e);
for(auto& [w, u, v] : edges){
	cin >> u >> v >> w;
}
sort(begin(edges),end(edges));
ll cost = 0;
int cnt = 0;
for(auto [w, u, v] : edges){
	if(dsu.unite(u,v)){
		cost += w;
		cnt++;
	}
}
// if(cnt != n-1) cout << "IMPOSSIBLE" << br;
