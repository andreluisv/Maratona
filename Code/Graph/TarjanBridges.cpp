vector<pair<int,int>> bridges; // {u,v} -> edge linking vertice "u" to vertice "v"

// This function will find all edges that are bridges on an UNDIRECTED graph.
// An edge in an undirected connected graph is a bridge if removing it disconnects the graph.
void find_bridges(int v, vector<si> &adj, vector<bool> &vis, vector<int> &disc, vector<int> &low, int parent){
	static int time = 0;
	vis[v] = 1;
	disc[v] = low[v] = ++time;

	for (auto u : adj[v]){
		if (u==parent) continue;
		if (vis[u]){
			low[v] = min(low[v], disc[u]);
			continue;
		}

		dfs(u, adj, vis, disc, low, v);
		low[v] = min(low[v], low[u]);

		if (low[u] > disc[v]){
			bridges.pb({u,v});
		}
	}
}

void traverse_node(int v, vector<set<int>> &adj, vector<bool> &vis, set<int> &nodes){
	nodes.insert(v);
	if (vis[v]) return;
	vis[v] = 1;

	for (auto u : adj[v]){
		if (!vis[u])
			traverse_node(u, adj, vis, nodes);
	}
}

// This function will return the vertices of an UNDIRECTED graph that are part of a cycle.
set<int> getVerticesCycles(int n, vector<set<int>> adj){
  set<int> verts;
	vector<bool> vis(n);
	vector<int> disc(n,-1);
	vector<int> low(n,-1);

	bridges.resize(0);
	for (int i = 0; i < n; i++){
		if (vis[i]) continue;
		find_bridges(i, adj, vis, disc, low, -1);
	}

	for (auto pp : bridges){
		adj[pp.first].erase(pp.second);
		adj[pp.second].erase(pp.first);
	}

	vis.clear(); vis.resize(n);

	for (int i = 0; i < n; i++){
		if (vis[i]) continue;
		if (adj[i].size() > 0){
			traverse_node(i, adj, vis, verts);
		}
	}

	return verts;
}

// Ref: alpvj submission at https://codeforces.com/contest/1873/problem/H
