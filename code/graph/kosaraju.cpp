// Kosaraju
const int ms = 1e5 + 5;
vector<int> G[ms], Gt[ms];
vector<int> id, order, root;
vector<bool> vis;
int n;
void dfs1(int u){ // ordem de saida 
  vis[u] = true;
  for(int v : G[u])
    if(!vis[v]) 
      dfs1(v);
  order.push_back(u);
}
void dfs2(int u, int idx){
  id[u] = idx;
  for(int v : Gt[u])
    if(id[v] == -1) 
      dfs2(v,idx);
}
// retorna quantidade de componentes
int kosaraju(){  
  vis.assign(n,false);
  id.assign(n,-1);
  for(int i = 0; i < n; i++)
    if(!vis[i]) 
      dfs1(i);
  reverse(begin(order),end(order));
  int idx = 0;
  for(int u : order)
    if(id[u] == -1)
      dfs2(u, idx++), root.push_back(u); 
  return idx; 
}
