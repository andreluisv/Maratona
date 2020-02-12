//Travelling Salesman Problem
//Visited all vertices and return (or not) to initial vertice;

const int inf = 0x3f3f3f3f, V = 15;

int n, graph[15][15], dp[15][1<<V];//n = 15 vertices
//graph[i][j] means distance (i --> j)

int solve(int pos, int visited){
	if (visited+1 == (1<<(n+1)))
		return graph[pos][0];
		//return 0; <-- if doesn't go back to initial vertice
		
	int &ans = dp[pos][visited];
	
	if (~ans) return ans;
	
	ans = inf;
	
	for (int i = 0; i < n+1; i++){
		if (!(visited & (1<<i) ){
			ans = min(ans, graph[pos][i] + solve(i, visited|(1<<i)) );
		}
	}
	
	return dp[pos][visited] = ans;
}

memset(dp, -1, sizeof(dp));
memset(graph, 0, sizeof(graph));


cout << solve(0,0) << endl;
