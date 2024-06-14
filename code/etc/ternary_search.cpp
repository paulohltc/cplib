double f(double t){
	// alguma funcao unimodal -> maximo ou minimo
	//     /\
	//    /  \ 
	// __/    \__
}

double tern_search(double l, double r){
  for(int it = 0; it < 300; it++){ 
    double m1 = l + (r-l)/3;
    double m2 = r - (r-l)/3;
    double f1 = f(m1), f2 = f(m2);
    if(f1 < f2) l = m1; 
    else r = m2; 
  } 
  return max(f(l),f(r)); 
}
// retorna mais a esquerda no empate
int int_tern_search(int l, int r){
	int lo = l - 1, hi = r;
	while(hi - lo > 1){
		int m = (lo+hi)/2;
		if(f(m) >= f(m+1)){ // decrescendo
			hi = m;
		}else{ // crescendo;
			lo = m;
		}
	}
	return lo + 1;
}