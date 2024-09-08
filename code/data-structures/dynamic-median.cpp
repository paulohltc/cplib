const ll inf = 1e18 + 5;
struct DynamicMedian{
  multiset<ll> left, right;
  ll leftsum = 0, rightsum = 0;
  ll get(){
    // if(left.empty()) return -1; // cuidar aqui
    return *left.rbegin();
  }
  ll qry(){ // somatorio de distancia absoluta pra mediana
    ll m = (left.empty() ? inf : get());
    // if(m == -1) return -1;
    return left.size()*m - leftsum + rightsum - right.size()*m;
  }
  void fix(){
    // (L,R) ou (L+1,R)
    while(right.size() + 1 < left.size()){ 
      // tirar do l e colocar no r
      auto lst = --left.end();
      rightsum += *lst;
      leftsum -= *lst;
      right.insert(*lst);
      left.erase(lst);
    }
    while(right.size() > left.size()){
      // tirar do r e colocar no l
      leftsum += *right.begin();
      rightsum -= *right.begin();
      left.insert(*right.begin());
      right.erase(right.begin());
    }
  }

  void insert(ll x){
    ll m = get();
    if(x <= m){
      left.insert(x);
      leftsum += x;
    }else{
      right.insert(x);
      rightsum += x;
    }
    fix();
  }
  void erase(ll x){
    auto l = left.find(x);
    if(l != left.end()){
      leftsum -= *l;
      left.erase(l);
    }
    else{
      auto r = right.find(x);
      rightsum -= *r;
      right.erase(r);
    }
    fix();
  }
};
