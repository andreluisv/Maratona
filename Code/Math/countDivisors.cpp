int cDivs(ll n){
	int c = 0;
	for (int i = 1; i <= sqrt(n); i++){
		if (n%i == 0){
			c++;
			if (n/i != i) c++;
		}
	}
	return c;
}

vector<int> gDivs(ll n){
	vector<int> d;
	for (int i = 1; i <= sqrt(n); i++){
		if (n%i == 0){
			d.push_back(i);
			if (n/i != i) d.push_back(n/i);
		}
	}
	//sort(d.begin(), d.end());
	return d;
}
