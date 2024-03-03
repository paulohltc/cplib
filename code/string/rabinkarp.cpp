// Rabin Karp
const ll base = 997;
const ll mod[] ={1000000007, 1000000009};
using Hash = pair<ll,ll>;
const int str_mxsz = 1e5+2;
ll pot[str_mxsz][2];
void buildPots(){ // lembrar de chamar essa funcao
	pot[0][0] = 1;
	pot[0][1] = 1;
	for(int i = 1; i < str_mxsz; i++)
		for(int j = 0; j < 2; j++)
			pot[i][j] = (pot[i-1][j]*base) % mod[j];
}

class RabinKarp{
public:
	string s;
	int sz;
	vector<vector<ll>> has;
	RabinKarp(){}
	RabinKarp(const string& str): s(str){
		sz = str.size();
		has.assign(sz+1,vector<ll>(2));
		build();
	}
	void build(){
		has[0] = {s[0],s[0]};
		for(int i = 1; i < sz; i++)
			for(int j = 0; j < 2; j++)
				has[i][j] = ((has[i-1][j]*base)+s[i])%mod[j];
	}
	Hash getKey(ll l, ll r){ // inclusivo
		Hash ans = {has[r][0],has[r][1]};
		if(l > 0){
			ans.first = (((ans.first - pot[r-l+1][0]*has[l-1][0])%mod[0] + mod[0])%mod[0]);
			ans.second = (((ans.second - pot[r-l+1][1]*has[l-1][1])%mod[1] + mod[1])%mod[1]);
		} 
		return ans;
	}
};