int INF = INT_MAX;

vector<vector<pii>> nxt(1,vector<pii>(2,{0,INF})); // (ID,#nos)
vector<bool> isTerm(1);
int id = 0;

void remove(ll x){
	int node = 0;
	for(int i = 31; i >= 0; i--){
		bool bit = x & (1<<i);
		if(nxt[node][bit].X == 0 || nxt[node][bit].Y == 0) return;
		nxt[node][bit].Y--;
		node = nxt[node][bit].X;
	}
}

void insert(ll x){
	int node = 0;
	for(int i = 31; i >= 0; i--){
		bool bit = x & (1<<i);
		if(nxt[node][bit].X == 0){
			nxt.PB(vector<pii>(2,{0LL,0LL}));
			isTerm.PB(false);
			nxt[node][bit].X = ++id;
			nxt[node][bit].Y++;			
		}
		else{
			nxt[node][bit].Y++;
		}
		node = nxt[node][bit].X;
	}
	isTerm[node] = true;	
}

int maxXor(ll k){
	int node = 0;
	ll ans = 0;
	for(int i = 31; i >= 0; i--){
		bool bit = k & (1<<i);
		if(nxt[node][!bit].X != 0 && nxt[node][!bit].Y != 0){
			ans += (1LL << i);
			node = nxt[node][!bit].X;
		}
		else{
			node = nxt[node][bit].X;
		}
	}
	return ans;
}
