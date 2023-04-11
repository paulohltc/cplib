int v,e;
vector<int> adj[4005];
vector<int> clr (4005,-1);

void paint(int n){
	for(int a :  adj[n]){
		if(clr[a] == -1){
			clr[a] = 1 - clr[n];
			paint(a);
		}
	}
}

void paintAll(){
	for(int i = 0; i < v; i++){
		if(clr[i] == -1){
			clr[i] = 0;
			paint(i);
		}
	}
}

bool check(int n){
	for(int a : adj[n]){
		if(clr[a] != 1 - clr[n]) return true;
	}
	return false;
}