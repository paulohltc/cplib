class RabinKarp{
public:
	ll base, mod, sz;
	string s;
	vector<ll> pot, has;
	RabinKarp(const string& str,ll b = 997, ll m = 1e9 + 7): base(b), mod(m), s(str){
		sz = str.length();
		pot.resize(sz+1);
		has.resize(sz+1);
		build();
	}
	void build(){
		pot[0] = 1;
		has[0] = s[0];
		for(int i = 1; i < sz; i++){
			pot[i] = (pot[i-1]*base) % mod;
			has[i] = ((has[i-1]*base)+s[i])%mod;
		}
	}
	ll getKey(ll l, ll r){ // inclusivo
		ll ans = has[r];
		if(l > 0) ans = (((ans - pot[r-l+1]*has[l-1])%mod + mod)%mod);
		return ans;
	}
};