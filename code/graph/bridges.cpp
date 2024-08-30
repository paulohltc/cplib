int n, m;
const int mxn = 1e5 + 5;
vector<int> g[mxn];
int tin[mxn], low[mxn];
vector<pii> bridges;
int timer = 1;

void dfs(int u, int p){
  tin[u] = timer++;
  low[u] = tin[u];
  int ch = 0;
  for(int v : g[u]) if(v != p){
    if(tin[v]) // lowlink direta
      low[u] = min(tin[v],low[u]);
    else{
      dfs(v,u);
      low[u] = min(low[v],low[u]);
      if(tin[u] < low[v]) bridges.push_back({u,v});
    }
  }
}