// SegTree
const int mx = 2e5 + 5;
ll seg[4*mx];
ll nums[mx];
int n,q;
ll merge(ll a, ll b){
	return a+b;
}

void build(int l = 0, int r = n-1, int idx = 0){
	if(l == r){
		seg[idx] = nums[l];
		return;
	}
	int mid = l + (r-l)/2;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	build(l,mid,left);
	build(mid+1,r,right);
	seg[idx] = merge(seg[left], seg[right]);
}

ll query(int L, int R, int l = 0, int r = n-1, int idx = 0){
	if(R < l || L > r) return 0; // elemento neutro
	if(L <= l && r <= R) return seg[idx];

	int mid = l + (r-l)/2;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	ll ql = query(L,R,l,mid,left);
	ll qr = query(L,R,mid+1,r,right);
	return merge(ql,qr); 
}

void update(int pos, int num, int l = 0, int r = n-1, int idx = 0){
	if(l == r){
		seg[idx] = num;
		return;
	}
	int mid = l + (r-l)/2;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	if(pos <= mid){
		update(pos,num,l,mid,left);
	}
	else update(pos,num,mid+1,r,right);
	seg[idx] = merge(seg[left],seg[right]);
}