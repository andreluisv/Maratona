const int ms = 1e5*32, sigma = 26;
int trie[ms][sigma], terminal[ms], ter[ms], z;

int get_id(char c){
	return c - 'a';
}

void init(){
	memset(trie[0], -1, sizeof(trie[0]));
	z = 1;
}

void insert(string &p){
	int cur = 0;
	for (int i = 0; i < int(p.size()); i++){
		int id = get_id(p[i]);
		ter[cur]++;
		if (trie[cur][id] == -1){
			memset(trie[z], -1, sizeof(trie[z]));
			trie[cur][id] = z++;
		}
		cur = trie[cur][id];
	}
	terminal[cur]++;
	ter[cur]++;
}

int count(string &p){
	int cur = 0;
	for (int i = 0; i < int(p.size()); i++){
		int id = get_id(p[i]);
		if (trie[cur][id] == -1)
			return false;
		cur = trie[cur][id];
	}
	return terminal[cur];
}

void remove(string &p){
	int cur = 0;
	for(int i = 0 ; i < int(p.size()) ; i++){
		int id = get_id(p[i]);
		ter[cur]--;
		cur = trie[cur][id];
	}
	terminal[cur]--;
	ter[cur]--;
}

//See if it has a word wich it is a prefix or suffix
bool exists = false;
void ans(int cur, int cnt, int l, int k){
	if(exists) return;
	if(l == cnt){
		if(ter[cur] >= k)
			exists = true;
		return;
	}
	if(ter[cur] < k) return;
	for(int id = 0 ; id < 26 ; id++){
		if(trie[cur][id] != -1){
			ans(trie[cur][id], cnt+1, l, k);
		}
	}
}
