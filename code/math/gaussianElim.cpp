template<typename T>
struct GaussianElimination {
  // may change if using doubles
  static bool cmp(const T& a, const T& b) { return a == b; }
  vector<vector<T>> a, inv;
  vector<int> pivot;
  GaussianElimination(const vector<vector<T>> a = {}) : a(a) {}
  void add_equation(const vector<T>& equation) {
    a.emplace_back(equation);
  }
  /*
    pair(0, ans) impossible
    pair(1, ans) one solution
    pair(2, ans) infinite solutions
  */
  pair<int, vector<T>> solve_system(bool findInverse = false) {
    int n = (int)a.size();
    int m = (int)a[0].size() - 1;
    pivot.assign(m, -1);
    if(findInverse) {
      inv.assign(n, vector<T>(n));
      for(int i = 0; i < n; ++i) inv[i][i] = T(1);
    }
    for(int col = 0, row = 0; col < m && row < n; ++col) {
      int sel = -1;
      for(int i = row; i < n; ++i) {
        if(!cmp(a[i][col], 0)) {
          sel = i;
          break;
        }
      }
      if(sel == -1) continue;
      for(int j = col; j <= m; ++j) {
        swap(a[row][j], a[sel][j]);
      }
      if(findInverse) swap(inv[row], inv[sel]);
      for(int i = 0; i < n; ++i) {
        if(i == row) continue;
        T c = a[i][col] / a[row][col];
        for(int j = col; j <= m; ++j) {
          a[i][j] -= c * a[row][j];
        }
        if(!findInverse) continue;
        for(int j = 0; j < n; ++j) {
          inv[i][j] -= c * inv[row][j];
        }
      }
      pivot[col] = row++; 
    }
    vector<T> ans(m);
    for(int j = 0; j < m; ++j) {
      if(pivot[j] == -1) continue;
      //normalize pivots
      int i = pivot[j];
      for(int k = j + 1; k <= m; ++k) {
        a[i][k] /= a[i][j];
      }
      if(findInverse) {
        for(int k = 0; k < n; ++k) {
          inv[i][k] /= a[i][j];
        }
      }
      a[i][j] = T(1);
      ans[j] = a[i][m];
    }
    for(int i = 0; i < n; ++i) {
        T value(0);
        for(int j = 0; j < m; ++j) {
          value += ans[j] * a[i][j];
        }
        if(!cmp(value, a[i][m])) return make_pair(0, ans);
    }
    for(int j = 0; j < m; ++j) {
      if(pivot[j] == -1) return make_pair(2, ans);
    }
    return make_pair(1, ans);
  }
};