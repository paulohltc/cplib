// Kosaraju
vector<vector<int>> G, Gt;
vector<int> id;
vector<int> order;
vector<bool> vis;
int n;

void dfs1(int v){ // ordem de saida 
  vis[v] = true;
  for(int u : G[v]){
    if(!vis[u]) dfs1(u);
  }
  order.PB(v);
}
void dfs2(int v, int idx, vector<int>& component){ // pegar um componente todo
    vis[v] = true;
    id[v] = idx;
    component.PB(v);
    for(int u : Gt[v]){
        if(!vis[u]) dfs2(u);
    }
}
vector<vector<int>> kosaraju(){ 
  vector<vector<int>> components;
  vis.assign(n,false);
  for(int i = 0; i < n; i++){
    if(!vis[i]) dfs1(i);
  }
  vis.assign(n,false);
  reverse(begin(order),end(order));
  int idx = 0;
  for(int v : order){
    if(!vis[v]){
      vector<int> component;
      dfs2(v, idx++, component); 
      // sort(begin(component),end(component));
      components.PB(component);
    }
  }
  return components; 
}