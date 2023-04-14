const int MXN = 1e6+5;
bitset<MXN> isPrime;

vector<int> sieve(){
	isPrime.set();
	vector<int> primes;
	for(int i = 2; i < MXN; i++){
		if(isPrime[i]){
			primes.PB(i);
			for(int j = 2*i; j < MXN; j += i){
				isPrime[j] = 0;
			}
		}
	}
	return primes;
}