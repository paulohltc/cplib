// Kruskal
struct DSU{
	vector<int> p;
	vector<int> sz;
	int n;
	DSU(int nodes){
		p.resize(nodes);
		sz.resize(nodes,1);
		iota(begin(p), end(p), 0);
	}
	int size(int a){ return sz[root(a)]; }
	int root(int a){ return p[a] = (p[a] == a ? a : root(p[a])); }
	bool unite(int a, int b){
		int ra = root(a), rb = root(b);
		if(ra != rb){
			if(sz[ra] < sz[rb]) swap(ra,rb);
			p[rb] = ra;
			sz[ra] += sz[rb];
			return 1;
		}
		return 0;
	}
};

int v = 1e5;
DSU dsu = DSU(v+5);
priority_queue<pair<int,pii>,vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
for(int i = 0; i < e; i++){
	int x,y,w; cin >> x >> y >> w;
	pq.push({w,{x,y}});
}
int edges = v-1; // mst count
ll mstSum = 0;
while(edges > 0){
	pair<int,pii> curr = pq.top();pq.pop();
	int w = curr.X, x = curr.Y.X, y = curr.Y.Y;
	if(dsu.unite(x,y)){
		mstSum += w;
		edges--;
	}
}
cout << mstSum;