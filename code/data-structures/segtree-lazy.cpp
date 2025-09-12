// Lazy SegTree ta meio desatualizado mas sei modificar
const int mx = 2e5+5;
vector<ll> seg(4*mx);
vector<ll> lazy(4*mx,0);
vector<ll> nums(mx);
int n,q;

void build(int l = 0, int r = n-1, int idx = 0){
	if(l == r){
		seg[idx] = nums[l];
		lazy[idx] = 0;
		return;
	}
	int m = (l+r)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	build(l,m,left);
	build(m+1,r,right);
	seg[idx] = seg[left] + seg[right];
}

void prop(int l = 0, int r = n-1, int idx = 0){
	seg[idx] += (ll)(r-l+1)*lazy[idx];
	if(l != r){ // nao for folha
		int left = 2*idx+1;
		int right = 2*idx+2;
		lazy[left] += lazy[idx];
		lazy[right] += lazy[idx];
	}
	lazy[idx] = 0;
}

void update(int L, int R, ll val, int l = 0, int r = n-1, int idx = 0){
	if(R < l || L > r) return;
	prop(l,r,idx);
	if(L <= l && r <= R){
		lazy[idx] = val;
		prop(l,r,idx);
	}
	else{
		int m = (l+r)/2;
		int left = 2*idx+1;
		int right = 2*idx+2;
		update(L,R,val,l,m,left);
		update(L,R,val,m+1,r,right);
		seg[idx] = seg[left] + seg[right];
	}
}

ll query(int L, int R, int l = 0, int r = n-1, int idx = 0){
	prop(l,r,idx);
	if(R < l || L > r) return 0;
	if(L <= l && r <= R){
		return seg[idx];
	}
	int m = (l+r)/2;
	int left = 2*idx+1;
	int right = 2*idx+2;
	return query(L,R,l,m,left) + query(L,R,m+1,r,right);
}