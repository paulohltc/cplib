// Knapsack
const int MXW = 1e5+5;
const int MXN = 105;

int n,w;
vector<int> weight(MXN), value(MXN);
vector<vector<ll>> dp(MXN,vector<ll>(MXW,-1));
 
ll solveDp(int i, int k){ // k -> peso atual
	if(i == n) return 0;
	if(dp[i][k] != -1) return dp[i][k];
 
	ll ignore = solveDp(i+1,k);
	ll add = -1;
	if(weight[i] + k <= w){
		add = value[i] + solveDp(i+1, weight[i] + k);
	}
	return dp[i][k] = max(ignore,add);
}