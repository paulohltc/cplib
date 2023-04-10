int n,m;
// g : labirinto de . e #
string g[505];
pii start,finish;
vector<pii> dir = {{-1,0},{1,0},{0,-1},{0,1}};

bool inRange(pii p){
	return p.X >= 0 && p.X < n && p.Y >= 0 && p.Y < m;
}

pii operator + (pii lhs, pii rhs){
	return {lhs.X+rhs.X,lhs.Y+rhs.Y};
}

int bfs(){
	queue<pii> q;
	q.push(start);
	vector<vector<bool>> vis(505,vector<bool>(505,0));
	vis[start.X][start.Y] = 1;
	int cnt = 0;
	while(!q.empty()){
		int lvlSz = q.size();
		while(lvlSz--){
			pii c = q.front();q.pop();
			vector<pii> newPts;
			for(pii currDir : dir) newPts.PB(c + currDir);
			for(pii pt : newPts){
				if(inRange(pt) && !vis[pt.X][pt.Y] && g[pt.X][pt.Y] != '#'){
					if(pt == finish) return cnt;
					vis[pt.X][pt.Y] = 1;
					q.push(pt);					
				}
			}
		}
		cnt++;
	}
	return cnt;
}
