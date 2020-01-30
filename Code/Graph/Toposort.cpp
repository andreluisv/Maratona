vector<vi > adj;
vi indegree;
vi topo_order;

void BFS(){
    priority_queue<int, vi, greater<int>> q;
	//find the vertices with 0 dependencies
	for (int u = 0; u < indegree.size();u++){
		if (indegree[u] == 0) q.push(u);
	}
	while(!q.empty()){
		//grab the smallest with no dependecies
		int u = q.top(); q.pop();
		topo_order.push_back(u);
		//decrement all the dependecies from each vertices connected and if 0 put in q
		for(int v: adj[u]){
			if (--indegree[v] == 0) q.push(v);
		}
	}
}
/*
adj.resize(ver, vi());
indegree.resize(ver, 0);
while(n--){
    int v1, v2; cin >> v1 >> v2;
	adj[v1].push_back(v2);
	indegree[v2]++;
}
BFS()
if (topo_order.size() != ver) NOT POSSIBLE
*/
