// nlogn small to large (offline)

int tin[mxn],tout[mxn];
vector<int> g[mxn];
int clr[mxn];
int inv[mxn];
int sz[mxn];
int cnt[mxn]
void calcsz(int u, int p){
    sz[u] = 1;
    tin[u] = ++timer;
    inv[timer] = u;
    for(int v : g[u]) if(v != p){
        calcsz(v,u);
        sz[u] += sz[v];
    }
    tout[u] = timer;
}

void dfs(int u, int p, bool mata = 0){
    int big = -1;
    int howBig = 0;
    for(int v : g[u]) if(v != p){
        if(sz[v] > howBig){
            big = v;
            howBig = sz[big];
        }
    }
    for(int v : g[u]) if(v != p && v != big){
        dfs(v,u,1);
    }
    if(big != -1)
        dfs(big,u,0);
    for(int v : g[u]) if(v != p && v != big){
        for(int l = tin[v]; l <= tout[v]; l++){
            int who = inv[l];
            cnt[clr[who]]++;
        }
    }
    cnt[clr[u]]++;
    // solve queries aqui
    //
    if(mata){
        for(int l = tin[u]; l <= tout[u]; l++){
            int who = inv[l];
            cnt[clr[who]]--;
        }
    }
}