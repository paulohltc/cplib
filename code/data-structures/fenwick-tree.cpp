const int mx = 2e5+5;
ll bit[mx];
int n, q;

ll qry(int i){ // [1,i] 1 indexado
	ll ret = 0;
	for(; i > 0; i -= i & -i)
		ret += bit[i];
	return ret;
}

void increment(ll i, ll v){ // 1 indexado (+= v)
	for(; i <= n; i += i & -i)
		bit[i] += v;
}