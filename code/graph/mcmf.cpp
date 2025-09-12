template<typename Cap, typename Cost>
struct MCMF{
  const Cost INF = numeric_limits<Cost>::max();
  struct Edge {
    int to;
    Cap cap, flow;
    Cost cost;
    Edge(int to, Cap cap, Cost cost) : to(to), cap(cap), flow(0), cost(cost) {}
    Cap res() const { return cap - flow; }
  };
  int m = 0, n;
  vector<Edge> edges;
  vector<vector<int>> g;
  vector<Cap> neck;
  vector<Cost> dist, pot;
  vector<int> from;
  MCMF(int n) : n(n), g(n), neck(n), pot(n) {}
  void add_edge(int u, int v, Cap cap, Cost cost) {
    if(u != v) {
      edges.emplace_back(v, cap, cost);
      edges.emplace_back(u, 0, -cost);
      g[u].emplace_back(m++);
      g[v].emplace_back(m++);
    }	
  }
  void spfa(int s) {
    vector<bool> inq(n, false);
    queue<int> q({s});
    while(!q.empty()) {
      auto u = q.front();
      q.pop();
      inq[u] = false;
      for(auto e : g[u]) {
        auto ed = edges[e];
        if(ed.res() == 0) continue;
        Cost w = ed.cost + pot[u] - pot[ed.to];
        if(pot[ed.to] > pot[u] + w) {
          pot[ed.to] = pot[u] + w;
          if(!inq[ed.to]) {
            inq[ed.to] = true;
            q.push(ed.to);
          }
        }
      }
    }
  }
  bool dijkstra(int s, int t) {
    dist.assign(n, INF);
    from.assign(n, -1);
    neck[s] = numeric_limits<Cap>::max();
    using ii = pair<Cost, int>;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({dist[s] = 0, s});
    while(!pq.empty()) {
      auto [d_u, u] = pq.top();
      pq.pop();
      if(dist[u] != d_u) continue;
      for(auto i : g[u]) {
        auto ed = edges[i];
        Cost w = ed.cost + pot[u] - pot[ed.to];
        if(ed.res() > 0 && dist[ed.to] > dist[u] + w) {
          from[ed.to] = i;
          pq.push({dist[ed.to] = dist[u] + w, ed.to});
          neck[ed.to] = min(neck[u], ed.res());
        }
      }
    }
    return dist[t] < INF;
  }
  pair<Cap, Cost> mcmf(int s, int t, Cap k = numeric_limits<Cap>::max()) {
    Cap flow = 0;
    Cost cost = 0;
    spfa(s);
    while(flow < k && dijkstra(s, t)) {
      Cap amt = min(neck[t], k - flow);
      for(int v = t; v != s; v = edges[from[v] ^ 1].to) {
        cost += edges[from[v]].cost * amt;
        edges[from[v]].flow += amt;
        edges[from[v] ^ 1].flow -= amt;
      }
      flow += amt;
      fix_pot();
    }
    return {flow, cost};
  }
  void fix_pot() {
    for(int u = 0; u < n; ++u) {
      if(dist[u] < INF) {
        pot[u] += dist[u];
      }
    }
  }
};