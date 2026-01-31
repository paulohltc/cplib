const int mxn = 2e5+5;
const int LOG = 22;
int n, q;
int tin[mxn], tout[mxn];
int up[LOG][mxn]; 
vector<int> g[mxn];
int lvl[mxn];
int timer = 0;
void dfs(int u, int p){
    tin[u] = ++timer;
    lvl[u] = lvl[p] + 1;
    up[0][u] = p;
    for(int v : g[u]) if(v != p)
        dfs(v,u);
    tout[u] = ++timer;
}
 
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void buildBL(){
    for(int lg = 1; lg < LOG; lg++)
        for(int u = 0; u < n; u++)
            up[lg][u] = up[lg-1][ up[lg-1][u] ];
}
 
// lembrar de chamar dfs + buildbl antes de usar
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