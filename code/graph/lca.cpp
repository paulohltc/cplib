// lembrar de chamar dfs + buildBL antes de usar
const int mxn = 1e5+5;
const int LOG = 18;
int n, q;
int tin[mxn], tout[mxn], lvl[mxn];
int up[LOG][mxn], maior[LOG][mxn]; 
vector<pair<int,int>> g[mxn];
int timer = 0;

void dfs(int u, int p, int c){
  tin[u] = ++timer;
  lvl[u] = lvl[p] + 1;
  up[0][u] = p;
  maior[0][u] = c;
  for(auto [v,c] : g[u]) if(v != p)
    dfs(v,u,c);
  tout[u] = ++timer;
}
 
bool is_ancestor(int u, int v){
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void buildBL(){
  for(int lg = 1; lg < LOG; lg++){
    for(int u = 0; u < n; u++){
      up[lg][u] = up[lg-1][ up[lg-1][u] ];
      maior[lg][u] = max(
        maior[lg-1][u],
        maior[lg-1][ up[lg-1][u] ]
      );
    }
  }   
}
 
int lca(int a, int b){
  if(is_ancestor(a,b)) return a;
  if(is_ancestor(b,a)) return b;
  for(int i = LOG - 1; i >= 0; i--){
    if(!is_ancestor(up[i][a], b)){
      a = up[i][a];
    }
  }
  return up[0][a];
}

int lift(int &u, int k) {
  int ans = 0;

  for (int i = LOG - 1; i >= 0; i--) {
    if (k & (1 << i)) {
      ans = max(ans, maior[i][u]);
      u = up[i][u];
    }
  }

  return ans;
}

int getMaior(int u, int v) {
  int l = lca(u, v);

  int ans = 0;
  int du = lvl[u] - lvl[l];
  int dv = lvl[v] - lvl[l];
  ans = max(ans, lift(u, du));
  ans = max(ans, lift(v, dv));

  return ans;
}