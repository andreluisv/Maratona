vi ds, sz;
void dsBuild(int n){
	ds.resize(0); sz.resize(0);
	for (int i = 0; i < n; i++){
		ds.pb(i);
		sz.pb(1);
	}
}
 
int dsFind(int i){
	if (ds[i] != i) ds[i] = dsFind(ds[i]);
	return ds[i];
}
 
void dsUnion(int a, int b){
	a = dsFind(a); b = dsFind(b);
	if (sz[a]<sz[b]) swap(a,b);
	if (a!=b) sz[a] += sz[b];
	ds[b] = a;
}
