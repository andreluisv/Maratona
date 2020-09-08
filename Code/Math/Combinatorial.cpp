typedef long long ll;
const ll mod = 1e9+7;
vector<ll>fat,inv; 
// inv[k] = modular inverse of k! mod
//a^(phi(mod)-1) = a^-1 mod
//a^(mod-2)=a^-1 mod

void fill_fat(int n){
	fat=vector<ll>(n+1,1);
	inv=vector<ll>(n+1,-1);
	for(ll i=1;i<=n;i++){
		fat[i]=fat[i-1]*i %mod;
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
	if(inv[k]==-1)inv[k]=binExp(fat[k],mod-2);
	if(inv[n-k]==-1)inv[n-k]=binExp(fat[n-k],mod-2);

	ll ret = fat[n]*inv[k]%mod;
	return ret = ret*inv[n-k]%mod;
}

ll arra(ll n, ll k){
	return ((comb(n,k)%mod) * (fat[k]%mod))%mod;
}
