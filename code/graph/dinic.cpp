//O(V^2 E), O(E sqrtV) in unit networks
template<typename T>
struct Edge {
  int to;
  T cap, flow;
  Edge(int to, T cap) : to(to), cap(cap), flow(0) {}
  T res() const { return cap - flow; }
};
template<typename T>
struct Dinic {
  using E = Edge<T>;
  int m = 0, n;
  vector<E> ed;
  vector<vector<int>> g;
  vector<int> dist, ptr;
  Dinic(int n) : n(n), g(n), dist(n), ptr(n) {}
  void add_edge(int u, int v, T cap) {
    if(u != v) {
      ed.emplace_back(v, cap);
      ed.emplace_back(u, 0);
      g[u].emplace_back(m++);
      g[v].emplace_back(m++);
    }	
  }
  bool bfs(int s, int t) {
    fill(begin(dist), end(dist), n + 1);
    dist[s] = 0;
    queue<int> q({s});
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      if(u == t) break;
      for(int id : g[u]) {
        E& e = ed[id];
        if(e.res() > 0 && dist[e.to] > dist[u] + 1) {
          dist[e.to] = dist[u] + 1;
          q.emplace(e.to);
        }
      }
    }
    return dist[t] != n + 1;
  }
  T dfs(int u, int t, T flow) {
    if(u == t || flow == 0) {
      return flow;
    }
    for(int& i = ptr[u]; i < (int)g[u].size(); ++i) {
      E& e = ed[g[u][i]];
      E& eRev = ed[g[u][i] ^ 1];
      if(dist[e.to] == dist[eRev.to] + 1) {
        T amt = min(flow, e.res());
        if(T ret = dfs(e.to, t, amt)) {
          e.flow += ret;
          eRev.flow -= ret;
          return ret;
        }
      }
    }
    return 0;
  }
  T max_flow(int s, int t) {
    T total = 0;
    while(bfs(s, t)) {
      fill(begin(ptr), end(ptr), 0);
      while(T flow = dfs(s, t, numeric_limits<T>::max())) {
        total += flow;
      }
    }
    return total;
  }
  bool cut(int u) const { return dist[u] == n + 1; }
};
