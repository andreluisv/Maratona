vector<vi > adj;
vi vis;

void BFS(){
    queue<int> q;
    vis[0] = 0;
    q.push(0);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto x : adj[v]){
        	if (vis[x] != -1) continue;
        	
            vis[x] = !vis[v];
            q.push(x);
        }
    }
}

/*
adj.resize(ver, vi());
vis.resize(ver, -1);
*/
