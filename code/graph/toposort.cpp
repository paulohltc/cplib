// Toposort
const int MX = 1e5+5;
vector<int> adj[MX];
vector<int> dep(MX,0); // dep[x] = quantos nós se ligam a x
vector<int> order;
int v;

bool toposort(){
	order.clear();
	for(int i = 0; i < v; i++)
		if(dep[i] == 0) q.push(i);
	if(q.empty()) return 0;
	while(!q.empty()){
		int f = q.front(); q.pop();
		order.PB(f);
		for(int nb : adj[f])
			if(--dep[nb] == 0)
				q.push(nb);
	}
	return order.size() == v;
}