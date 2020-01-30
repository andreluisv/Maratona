vector<bool> crivo(2e6 + 1, true);
vector<ll> primes;

void fastPrime(ll lim){
	primes.push_back(2);
	
	for (ll i = 3; i < lim; i+=2){
		if (crivo[i]){
			primes.push_back(i);
			if (i > lim/i) continue;
			for (ll j = i*i; j < lim; j += i+i){
				crivo[j] = false;
			}
		}
	}
}
