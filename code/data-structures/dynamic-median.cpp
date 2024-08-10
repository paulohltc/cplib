struct DynamicMedian{
  priority_queue<ll> left;
  priority_queue<ll,vector<ll>,greater<ll>> right;
  ll get(){
    assert(left.size());
    return left.top();
  }
  void insert(ll x){
    if(left.empty()){
      left.push(x);
      return;
    }
    ll m = get();
    if(x <= m) left.push(x);
    else right.push(x);
    if(left.size() > right.size() + 1){
      ll y = left.top();
      left.pop();
      right.push(y);
    }
    if(right.size() > left.size()){ 
      ll y = right.top();
      right.pop();
      left.push(y);
    }
  }
  void removeMedian(){
    left.pop();
    if(right.size() > left.size()) {
      left.push(right.top());
      right.pop();
    }
  }
};
