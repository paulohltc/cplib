// Mo apelao
// Ordering based on the Hilbert curve
inline int64_t hilbertOrder(int x, int y, int pow, int rotate){
    if(pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3) : ( (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
struct Query{
    int l, r, idx;
    int64_t ord;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {
        ord = hilbertOrder(l, r, 21, 0);
    }
    bool operator < (Query &other){
        return ord < other.ord;
    }
};
// hash de cima: cc976f44618d4ffc1bce4043eeed0ab2d48e270c90075135727d8e8b83bc8e76
// Mo normal
const int MXN = 2e5;
const int B = sqrt(MXN) + 1;
struct Query {
    int l, r, idx;
    bool operator<(Query o) const{
      return make_pair(l / B, ((l/B) & 1) ? -r : r) < make_pair(o.l / B, ((o.l/B) & 1) ? -o.r : o.r);
    }
};

ll a[MXN];
ll resp = 0;
void add(int x);
void remove(int x);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<Query> queries;
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        queries.push_back(Query(l-1,r-1,i));
    }
    sort(begin(queries),end(queries));
    vector<ll> answers(q);
    int L = 0, R = -1;
    for(Query qr : queries){
      while (L > qr.l) add(--L);
      while (R < qr.r) add(++R);
      while (L < qr.l) remove(L++);
      while (R > qr.r) remove(R--);
      answers[qr.idx] = resp;
    }
    for(int i = 0; i < q; i++)
        cout << answers[i] << "\n";
}