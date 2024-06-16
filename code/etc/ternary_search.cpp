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
    if(f1 < f2) l = m1; //change to > to find maximum
    else r = m2; 
  } 
  return l; 
}
// golden section search
double gss(double a, double b) {
  const double r = (sqrt(5)-1)/2, eps = 1e-7;
  double x1 = b - r*(b-a), x2 = a + r*(b-a);
  double f1 = f(x1), f2 = f(x2);
  for(int it = 0; it < 250 && b-a > eps; it++)
    if (f1 < f2) { //change to > to find maximum
      b = x2; x2 = x1; f2 = f1;
      x1 = b - r*(b-a); f1 = f(x1);
    } else {
      a = x1; x1 = x2; f1 = f2;
      x2 = a + r*(b-a); f2 = f(x2);
    }
  return a;
}
// retorna mais a esquerda no empate
int int_tern_search(int l, int r){
	int lo = l - 1, hi = r;
	while(hi - lo > 1){
		int m = (lo+hi)/2;
		if(f(m) < f(m+1)){ // 
			lo = m;
		}else{ 
			hi = m;
		}
	}
	return lo + 1;
}