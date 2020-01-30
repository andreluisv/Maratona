ll gcd(ll a, ll b){
	while(b) a %= b, swap(a, b);
	return a;
}

ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}
