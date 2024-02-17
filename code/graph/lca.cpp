const int mxn = 2e5+5;
const int LOG = 22;
int tin[mxn], tout[mxn];
vector<vector<int>> up; // up[v][k] = 2^k-esimo ancestor de v
vector<int> g[mxn];
int timer = 0;
void dfs(int u, int p){
    tin[u] = ++timer;
    up[u][0] = p;
    for(int i = 1; i <= LOG; i++){
        up[u][i] = up[ up[u][i-1] ][i-1];
    }
    for(int v : g[u]){
        if(v != u && !tin[v])
            dfs(v,u);
    }
    tout[u] = ++timer;
}
 
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int a, int b){
    if(is_ancestor(a,b)) return a;
    if(is_ancestor(b,a)) return b;
    for(int i = LOG; i >= 0; i--){
        if(!is_ancestor(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}