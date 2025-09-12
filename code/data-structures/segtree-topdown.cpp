// SegTree
const int mx = 2e5 + 5;
ll seg[4*mx];
ll a[mx];
int n,q;
ll join(ll a, ll b){
	return a+b;
}

void build(int l = 0, int r = n - 1, int idx = 0){
	if(l == r){
		seg[idx] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, 2*idx + 1);
	build(mid + 1, r, 2*idx + 2);
	seg[idx] = join(seg[2*idx + 1], seg[2*idx + 2]);
}

ll query(int L, int R, int l = 0, int r = n - 1, int idx = 0){
	if(R < l || L > r) return 0; // elemento neutro
	if(L <= l && r <= R) return seg[idx];
	int mid = (l + r)/2;
	return join(query(L, R, l, mid, 2*idx + 1), query(L, R, mid + 1, r, 2*idx + 2));
}

void update(int i, ll val, int l = 0, int r = n - 1, int idx = 0){
	if(l == r){
		seg[idx] = val;
		return;
	}
	int mid = (l + r)/2;
	if(i <= mid) update(i, val, l, mid, 2*idx + 1);
	else 		 update(i, val, mid + 1, r, 2*idx + 2);
	seg[idx] = join(seg[2*idx + 1], seg[2*idx + 2]);
}