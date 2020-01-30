//A*x + B*y = C

ll gcd_ext(ll a, ll b, ll &x, ll &y){
	if (b==0){
		x = 1;
		y = 0;
		return a;
	}
	ll nx, ny;
	ll gc = gcd_ext(b, a%b, nx, ny);
	x = ny;
	y = nx - (a/b)*ny;
	
	return gc;
}

//how to use:
	ll x, y, A = 1, B = 2, C = 3;
	ll GCD = gcd(A,B);
	
	if(C%GCD != 0){
		//if that holds true, there is no integer solution for this eq.
	}
	gcd_ext(A, B, x, y);
	x *= C/GCD;
	y *= C/GCD;
	
	//Try to find positive x & y
	while(x<0){
		x += B/GCD;
		y -= A/GCD;
	}
	while(y<0){
		y += A/GCD;
		x -= B/GCD;
	}
	
	cout << x << " " << y << endl;
