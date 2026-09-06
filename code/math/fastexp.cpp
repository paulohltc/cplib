// Fast Exp
const ll mod = 1e9+7;


ll fexpll(ll a, ll n){
	ll ans = 1;
	while(n){
		if(n & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}

template<int MOD>
class Matrix {
public:
    vector<vector<int>> mat;
    int m;

    Matrix(int m) : m(m), mat(m, vector<int>(m, 0)) {}

    Matrix operator*(const Matrix& rhs) const {
        Matrix ans(m);
        for(int i = 0; i < m; i++) {
            for(int k = 0; k < m; k++) {
                for(int j = 0; j < m; j++) {
                    ans.mat[i][j] += 1LL * mat[i][k] * rhs.mat[k][j] % MOD;
                    if(ans.mat[i][j] >= MOD) ans.mat[i][j] -= MOD;
                }
            }
        }

        return ans;
    }
};

template<int MOD>
Matrix<MOD> fexp(Matrix<MOD> a, long long n) {
    Matrix<MOD> ans(a.m);
    for(int i = 0; i < a.m; i++) ans.mat[i][i] = 1;
    while(n) {
        if(n & 1) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}
