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

const int maxn = 1005, mod = INT_MAX, base = 7;
ll pot[2][maxn], ahash[2][maxn];
string str1, str2;
int sz;
int get_id(int i, int m){
    if (!m) return str1[i]-'a'+1;
    return str2[i]-'a'+1;
}

void build(){
    pot[0][0] = 1;
    ahash[0][0] = get_id(0,0);
    pot[1][0] = 1;
    ahash[1][0] = get_id(0,1);
    for (int i = 1; i < sz; i++){
        pot[0][i] = (pot[0][i-1]*base) % mod;
        ahash[0][i] = ((ahash[0][i-1]*base) + get_id(i, 0)) % mod;
        pot[1][i] = (pot[1][i-1]*base) % mod;
        ahash[1][i] = ((ahash[1][i-1]*base) + get_id(i, 1)) % mod;
    }
}

ll getkey(int l, int r, int m){
    ll res = ahash[m][r];
    if (l >0) res = (res - ((pot[m][r-l+1] * ahash[m][l-1]) % mod) + mod) % mod;
    return res;
}

bool checkPal(int k){
	for (int i = 0; i <= n-k; i++){//n is size of string
		ll hash1 = getkey(i, i+k-1, 0);//build for str1
		ll hash2 = getkey(n-i-k, n-1-i, 1);//build for str2
		if (hash1 == hash2)
			return true;
	}
	return false;
}

sz = s.size();
str1 = s;
str2 = string(s.rbegin(), s.rend());
build();
