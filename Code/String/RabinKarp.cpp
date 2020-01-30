string str;
ll pot[maxn], ahash[maxn];

int get_id(int i){
	return abc[str[i]-'a'];
}

void build(){
	pot[0] = 1;
	ahash[0] = get_id(0);
	for (int i = 1; i < int(str.size()); i++){
		pot[i] = (pot[i-1] * base) % mod;
		ahash[i] = ((ahash[i-1]*base) + get_id(i)) % mod;
	}
}

ll getkey(int l, int r){
	ll res = ahash[r];
	if (l > 0) res = (res - ((pot[r-l+1] * ahash[l-1]) % mod) + mod) % mod;
	return res;
}

//Check if it has a palindromic substring of size k
bool checkPal(int k){
	for (int i = 0; i <= n-k; i++){//n is size of string
		ll hash1 = getkey(i, i+k-1, 0);//build for str1
		ll hash2 = getkey(n-i-k, n-1-i, 1);//build for str2
		if (hash1 == hash2)
			return true;
	}
	return false;
}

