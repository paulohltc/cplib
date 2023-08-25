// Factorization
vector<pii> getFact(int n){
	vector<pii> primes;
	for(int p = 2; p*p <= n; p++){
		if(n % p == 0){
			int exp = 0;
			while(n % p == 0){
				exp++;
				n /= p;
			}
			primes.PB({p,exp});
		}
	}
	if(n > 1) primes.PB({n,1});
	return primes;
}