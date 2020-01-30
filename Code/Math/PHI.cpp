//Euler Totient Function

const int P = 1e4;
int phi[P+1];
void PHI(){//sieve
	for (int i = 1; i <= P; i++) phi[i] = i;
	for(int i = 2; i <= P; i++){
		if (phi[i]==i)
			for (int j = i; j <= P; j+=i)
				phi[j]=phi[j]/i*(i-1);
	}
}

int PHI(int n){
	int ans = n;
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0){
			ans -= ans/i;
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans -= ans/n;
	return ans;
}
