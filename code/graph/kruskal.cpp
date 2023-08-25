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