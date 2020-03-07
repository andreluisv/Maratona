//Count cycles on a bidirectional Graph with all components connected

vector<vector<int> > adj;
vector<bool> vis;
int nodes;
 
int dfs(int u) {
    vis[u] = 1;
    int edge = 0;
    nodes++;
    for(auto v : adj[u]) {
        if(vis[v]==1) continue;
        edge += dfs(v);
    }
    return edge + adj[u].size();
}

//How to use it
int n;// n is the size of the Graph
adj.resize(n, vector<int>());
vis.resize(n, 0);
int x = 0;// x can be any node of the connected component
nodes = 0;// reset node count
int edges = dfs(x)/2;

if (edges==nodes-1){
	cout << "No cycles\n";
}else if (edges==nodes){
	cout << "One cycle\n";
}else{
	cout << "More than one cycles\n";
}
