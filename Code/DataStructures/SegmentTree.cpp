vi cell(maxn), tree(4*maxn);

void build(int pos, int i, int j){
	int mid = (i+j)/2;
	int esq = pos*2;
	int dir = pos*2 + 1;
	if (i==j){
		tree[pos] = cell[i];
		return;
	}
	build(esq, i, mid);
	build(dir, mid+1, j);
	
	tree[pos] = tree[esq] + tree[dir];
}

int query(int pos, int i, int j, int l, int r){
	int mid = (i+j)/2;
	int esq = pos*2;
	int dir = pos*2 + 1;
	
	if (j < l || i > r){
		return 0;
	}
	if (i >= l && j <= r){
		return tree[pos];
	}
	
	return query(esq, i, mid, l, r) + query(dir, mid+1, j, l, r);
}

void update(int pos, int i, int j, int x, int value){
	int mid = (i+j)/2;
	int esq = pos*2;
	int dir = pos*2 + 1;
	
	if (x < i || x > j) return;
	
	if (i == j){
		tree[pos] = value;
		return;
	}
	
	update(esq, i, mid, x, value);
	update(dir, mid+1, j, x, value);
	
	tree[pos] = tree[esq] + tree[dir];
}

/*
build(1,0,N-1);
update(1, 0, N-1, pos, valores[str])
query(1, 0, N-1, i, j)
*/
