const int MX = 2e5+5;
vector<ll> BIT(MX+1,0);
int n, q;
ll merge(ll a, ll b){
	return a+b;
}

ll qry(int i){ // [1,i] 1 indexado
	ll ret = 0;
	for(; i > 0; i -= i & -i){
		ret = merge(ret,BIT[i]);
	}
	return ret;
}

ll qryRange(int l, int r){ // 1 indexado inclusivo
	ll qr = qry(r);
	ll ql = qry(l-1);
	return qr-ql;
}
void update(ll i, ll v){ // 1 indexado
	for(; i <= n; i += i & -i){
		BIT[i] = merge(BIT[i],v);
	}
}
void build(const vector<ll>& nums){
	for(int i = 0; i < nums.size(); i++){
		update(i+1,nums[i]);
	}
}