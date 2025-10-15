struct DSU{
    int n;
    int comps;
    vector<int> sz, p;
    vector<vector<int>> g;
    DSU(int n) : n(n){
        comps = n;
        sz.assign(n,1);
        p.resize(n);
        iota(begin(p),end(p),0);
        g.resize(n);
        for(int i = 0; i < n; i++) g[i] = {i};
    }
    int root(int x){ return p[x] = (x == p[x] ? x : root(p[x])); }
    int join(int a, int b){
        a = root(a), b = root(b);
        if(a == b) return 0;
        if(sz[a] > sz[b]) swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
        for(int x : g[a]) g[b].push_back(x);
        g[a].clear();
        comps--;
        return 1;
    }
};

while(dsu.comps > 1){ // O(log)
      for(int i = 0; i < n && dsu.comps > 1; i++) if(!dsu.g[i].empty()){
          // i eh raiz
          array<int,2> mn = {inf,inf}; // min_cost, vertex
          // walk through i neighbors: dsu.g[i] and get min cost edge
            // min xor version:
            // for(int x : dsu.g[i])
            //     rem(a[x]);
            // for(int x : dsu.g[i])
            //     mn = min(mn, {min_xor(a[x]), a[x]});
            // for(int x : dsu.g[i])
            //     insert(a[x]);
          cost += mn[0];
          dsu.join(i, mn[1]);
      }
  }
