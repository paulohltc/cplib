#define PB push_back

/*LATEX_DESC_BEGIN***************************
usar ~ para negacao
regras logica
A->B = ~B->~A (contrapositiva)
A->B = ~A | B (lei da implicacao)
~(A|B) = ~A & ~B (de morgan)
A & (B|C) = (A&B) | (A&C) (distributiva)
*****************************LATEX_DESC_END*/
 
struct TwoSat{
  int n;
  vector<vector<int>> G, Gt;
  vector<int> id, order, ans;
  vector<bool> vis;
  TwoSat(){}
  TwoSat(int n) : n(n){
    G.resize(2*n);
    Gt.resize(2*n);
    id.assign(2*n,-1);
    ans.resize(n);
  }
  // negativos na esquerda
  void add_edge(int u, int v){
    u = (u < 0 ? -1-u : u + n);
    v = (v < 0 ? -1-v : v + n);
    G[u].PB(v);
    Gt[v].PB(u);
  }
  void add_or(int a, int b){
    add_edge(~a,b);
    add_edge(~b,a);
  }
  // Apenas algum ser 1
  void add_xor(int a, int b){
    add_or(a,b);
    add_or(~a,~b);
  }
  // set(a) = 1, set(~a) = 0
  void set(int a){ // (a|a)
    add_or(a,a);
  }
  // Mesmo valor
  void add_xnor(int a, int b) {
    add_xor(~a,b);
  }
  void dfs1(int u){ 
    vis[u] = true;
    for(int v : G[u])
      if(!vis[v])
        dfs1(v);
    
    order.PB(u);
  }
  void dfs2(int u, int idx){ 
    id[u] = idx;
    for(int v : Gt[u])
      if(id[v] == -1) 
        dfs2(v,idx);
  }
  void kosaraju(){ 
    vis.assign(2*n,false);
    for(int i = 0; i < 2*n; i++)
      if(!vis[i]) 
        dfs1(i);
    reverse(begin(order),end(order));
    int idx = 0;
    for(int u : order){
      if(id[u] == -1) 
        dfs2(u, idx++); 
    }
  }
  bool satisfiable(){
    kosaraju();
    for(int i = 0; i < n; i++){
      if(id[i] == id[i + n]) return false;
      ans[i] = (id[i] < id[i + n]);
    }
    return true;
  }
};