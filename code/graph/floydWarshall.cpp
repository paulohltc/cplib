const int mxn = 505;
const ll inf = 1e18;
ll g[mxn][mxn]; // setar tudo infinito menos (i,i) como 0
int n;
void addEdge(int u, int v, ll w){
  g[u][v] = min(g[u][v],w);
  g[v][u] = min(g[v][u],w); // tirar se for 1 dir
}

void floyd(){
  for(int k = 0; k < n; k++) // << k
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) 
        if(g[i][k] + g[k][j] < g[i][j]) // cuida overflow aqui (inf)
          g[i][j] = g[i][k] + g[k][j];
}