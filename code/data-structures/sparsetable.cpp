// use const, principalmente no log
// log = maior msb a[i]
const int LOG = 20;
// query [L,R] 
template<typename T>
struct SparseTable{
  int n;
  vector<vector<T>> table;
  SparseTable(){}
  SparseTable(vector<T>& v){
    n = v.size();
    table = vector(LOG + 1, vector<T>(n));
    table[0] = v;
    for(int lg = 0; lg < LOG; lg++){
      for(int i = 0; i < n; i++){
        if (j + (1 << i) >= n) break;
        table[i + 1][j] = min(table[i][j], table[i][j + (1 << i)]);
      }
    }
  }
  T qry(int l, int r){
    int k = 31 - __builtin_clz(r-l+1);
    return min(table[k][l], table[k][r - (1 << k) + 1]);
  }
};