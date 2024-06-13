struct Line {
  ll m, c;
  Line(ll m, ll c) : m(m), c(c) {}
  ll eval(ll x) {
    return m * x + c;
  }
};
struct CHT {
  vector<Line> lines;
  bool bad(Line a, Line b, Line c) {
  	// trocar pra < se for max
    return 1.d * (c.c - a.c)*(a.m - b.m) > 1.d * (b.c - a.c)*(a.m - c.m);
  }
  void insert(Line line) { // sortar antes de inserir
    int sz = (int)lines.size();
    for(; sz > 1; --sz) {
      if(bad(lines[sz - 2], lines[sz - 1], line)) {
        lines.pop_back();
        continue;
      }
      break;
    }
    lines.emplace_back(line);
  }
  ll query(ll x) {
    int l = 0, r = (int)lines.size() - 1;
    while(l < r) {
      int m = (l+r)/2;
      // trocar pra < se for max
      if(lines[m].eval(x) > lines[m+1].eval(x)) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return lines[l].eval(x);
  }
};