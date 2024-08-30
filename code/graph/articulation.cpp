int n, m;
const int mxn = 1e5 + 5;
vector<int> g[mxn];
int tin[mxn], low[mxn];
vector<int> art;
int timer = 1;

void dfs(int u, int p){
  tin[u] = timer++;
  low[u] = tin[u];
  int ch = 0;
  int fw = 0;
  for(int v : g[u]) if(v != p){
    if(tin[v]) // lowlink direta
      low[u] = min(tin[v],low[u]);
    else{
      dfs(v,u);
      fw++;
      low[u] = min(low[v],low[u]);
      ch = max(low[v],ch);
    }
  }
  if(u == p && fw > 1) art.push_back(u);
  else if(u != p && ch && tin[u] <= ch) art.push_back(u);
}