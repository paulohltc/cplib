struct DSU{
	vector<int> p;
	vector<int> sz;
	int n;
	DSU(int n) : n(n){
		p.resize(n);
		sz.resize(n,1);
		iota(begin(p), end(p), 0);
	}
	int size(int a){ return sz[root(a)]; }
	int root(int a){ return p[a] = (p[a] == a ? a : root(p[a])); }
	bool unite(int a, int b){
		int ra = root(a), rb = root(b);
		if(ra == rb) return 0;
		if(sz[ra] < sz[rb]) swap(ra,rb);
		p[rb] = ra;
		sz[ra] += sz[rb];
		return 1;
	}
};
