ll euclid(ll a, ll b, ll&x ,ll&y){
  if(!b) return x = 1, y = 0, a;
  ll d = euclid(b, a % b, y , x);
  return y -= a/b * x, d;
}
ll crt(vector<ll>& rem, vector<ll>& mod){
  int n = rem.size();
  if(n == 0) return 0;
  ll ans = rem[0], m = mod[0];
  for(int i = 1; i < n; i++){
    ll x,y;
    ll g = euclid(mod[i],m,x,y);
    // if((ans - rem[i]) % g != 0) return -5;
    assert((ans - rem[i]) % g == 0);
    ans = ans + 1LL*(rem[i]-ans)*(m/g)*y;
    m = (mod[i]/g)*(m/g)*g;
  }
  return ans;
}