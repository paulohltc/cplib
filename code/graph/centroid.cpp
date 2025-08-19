bool vis[mxn];
int par[mxn]; // parent na centroid tree, par do primeiro centroid eh -1
int sz[mxn];
int find_centroid(int u, int p, int s){
    for(int v : g[u]) if(v != p && !vis[v] && sz[v] > s / 2){
        return find_centroid(v,u,s);
    }
    return u;
}

void calc_size(int u, int p){
    if(vis[u]){
        sz[u] = 0;
        return;
    }
    sz[u] = 1;
    for(int v : g[u]) if(v != p){
        calc_size(v,u);
        sz[u] += sz[v];
    }
}

void init_centroid_tree(int u, int p = -1){
    calc_size(u,u);
    int c = find_centroid(u,u,sz[u]);
    vis[c] = 1;
    par[c] = p;
    for(int v : g[c]) if(!vis[v]){
        init_centroid_tree(v,c);
    }
}