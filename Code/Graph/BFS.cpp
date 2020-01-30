vector<vi > adj;
vi dist; vi vis;

void BFS(int u){
	queue<int> q;
	vis[u] = 1; q.push(u);
	
	while(!q.empty()){
		int v = q.front(); q.pop();
		for (auto  x : adj[v]){
			if (vis[x]) continue;
			
			vis[x] = 1;
			q.push(x);
		}
	}
}

void BFS(int u){//With distance from edge u
	queue<int> q;
	dist[u] = 0; q.push(u);
	
	while(!q.empty()){
		int v = q.front(); q.pop();
		for (auto  x : adj[v]){
			if (dist[x] == -1){
				dist[x] = dist[v] + 1;
				q.push(x);
			}
		}
	}
}
