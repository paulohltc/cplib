// Longest Increasing Sequence
int lis(vector<ll>& nums){
	int n = nums.size();
	vector<ll> s;
	for(int i = 0; i < n; i++){
		auto it = lower_bound(s.begin(),s.end(),nums[i]);
		if(it == s.end()){
			s.PB(nums[i]);
		}
		else{
			*it = nums[i];
		}
	}
	return (int)s.size();
}