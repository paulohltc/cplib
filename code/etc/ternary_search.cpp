double f(double t){
	// alguma funcao unimodal -> maximo ou minimo
	//     /\
	//    /  \ 
	// __/    \__
}

double tern_search(double l, double r){ // achar o maximo
	double eps = 1e-8;
	while(r - l > eps){
		double m1 = l + (r-l)/3;
		double m2 = r - (r-l)/3;
		double f1 = f(m1), f2 = f(m2);
		if(f1 < f2)	l = m1; // (m1,r)
		else r = m2; // (l,m2);
	}
	return max(f(l),f(r));
}
