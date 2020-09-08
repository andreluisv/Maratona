const ll mod = 1e9+7;
vector<ll>fat;

void fill_fat(int n){
	fat=vector<ll>(n+1,1);
	for(ll i=1;i<=n;i++){
		fat[i]=(fat[i-1]*i)%mod;
	}
}
 
ll binExp(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1){
			ret=ret*b%mod;
		}
		b=b*b%mod;
		e/=2;
	}
	return ret;
}
 
ll comb(ll n, ll k){
	ll ret = fat[n]*binExp(fat[k],mod-2)%mod;
	ret=ret*binExp(fat[n-k],mod-2)%mod;
 
	return ret;
}

ll arra(ll n, ll k){
	return ((comb(n,k)%mod) * (fat[k]%mod))%mod;
}
