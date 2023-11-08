const int LIM = 1e6+5;
int phi[LIM];
void sieve(){
	iota(phi, phi + LIM, 0);
	for(int i = 2; i < LIM; i++){
		if(phi == i){
			for(int j = i; j < LIM; j += i){
				phi[j] -= phi[j] / i;
			}
		}
	}
}

template<typename T>
T phi(T n) {
  T ans = n;
  for(T p = 2; p * p <= n; p++) {
    if(n % p == 0) {
      ans -= ans / p;
      while(n % p == 0) {
        n /= p;
      }
    }
  }
  if(n > 1) {
    ans -= ans / n;
  }
  return ans;
}