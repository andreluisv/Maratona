//Kruskal
vector< pair< int, pair<int, int> > > edges; //(w, (u,v))
vector< pair< int, pair<int, int> > > mst;

int Kruskal(){
	sort(edges.begin(), edges.end());
	int sum_edges = 0;
	
	for (int i = 0; i < edges.size(); i++){
		if (dsFind(edges[i].second.first) != dsFind(edges[i].second.second)){
			dsUnion(edges[i].second.first, edges[i].second.second);
			mst.push_back(edges[i]);
			sum_edges += edges[i].first;
		}
	}
	
	return sum_edges;
}

//Prim
void Prim(int souce = 0){
	for (int i = 0; i < n; i++) dist[i] = inf;
	dist[source] = 0;
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
	pq.push({0, source});
	
	while(!pq.empty()){
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if (inMST[u]) continue;
		inMST[u] = true;
		
		for (auto e : adj[u]){
			int v = e.first, w = e.second;
			if (!inMST[v] && w < dist[v]){
				parent[v] = u;
				dist[v] = w;
				pq.push({dist[v], v});
			}
		}
	}
}
