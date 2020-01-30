vector<vi > adj;
vb vis;
 
void DFS(int u){
	vis[u] = true;
	cyc.push_back(u);
	for (int v : adj[u]){
		if (vis[v]) continue;
		DFS(v);
	}
}
