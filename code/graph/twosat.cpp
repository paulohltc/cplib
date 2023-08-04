#define PB push_back
// Kosaraju
struct TwoSat{
	int n;
	vector<vector<int>> G, Gt;
	vector<int> id, order, ans;
	vector<bool> vis;

	TwoSat(){}
	TwoSat(int n) : n(n){init();}
	void init(){
		G.resize(2*n);
		Gt.resize(2*n);
		id.resize(2*n);
		ans.resize(n);
	}
	void add_edge(int u, int v){
		G[u].PB(v);
		Gt[v].PB(u);
	}
	// Algum ser 1
	void add_or(int a, bool neg1, int b, bool neg2){ 
		// (neg1 A | neg2 B) = (!neg1 A -> neg2 B) & (!neg2 B -> neg1 A)
		add_edge(a + (neg1 ? 0 : n), b + (neg2 ? n : 0));
		add_edge(b + (neg2 ? 0 : n), a + (neg1 ? n : 0));
	}
	// Apenas algum ser 1
	void add_xor(int a, bool neg1, int b, bool neg2){
		 add_or(a,neg1,b,neg2);
		 add_or(a,!neg1,b,!neg2);
	}
	// Setar variavel a pra b
	void set(int a, bool b){ // (a|a)
		add_or(a,!b,a,!b);
	}
	// Mesmo valor
    void add_and(int a, bool neg1, int b, bool neg2) {
        add_xor(a, !neg1, b, neg2);
    }
    // 

	void dfs1(int v){ // ordem de saida 
	  vis[v] = true;
	  for(int u : G[v]){
	    if(!vis[u]){
	      dfs1(u);
	    }
	  }
	  order.PB(v);
	}
	void dfs2(int v, int idx){ // pegar um componente todo
	    vis[v] = true;
	    id[v] = idx;
	    for(int u : Gt[v]){
	        if(!vis[u]) dfs2(u,idx);
	    }
	}
	void kosaraju(){ 
	  vis.assign(2*n,false);
	  for(int i = 0; i < 2*n; i++){
	  	if(!vis[i]) dfs1(i);
	  }
	  vis.assign(2*n,false);
	  reverse(begin(order),end(order));
	  int idx = 0;
	  for(int v : order){
	    if(!vis[v]) dfs2(v, idx++); 
	  }
	}
	bool satisfiable(){
		kosaraju();
		for(int i = 0; i < n; i++){
			if(id[i] == id[i+n]) return false;
			ans[i] = (id[i] > id[i+n]);
		}
		return true;
	}
};