//Knapsack Problem iterative with retrieve of items
const int N = ms, P = ms;
ll dp[N+1][P+1];
vector<ll> weight, value;

si uses;
int bt(int i, ll j){//Get items
	if (i-1 < 0) return 0;
	if (dp[i][j] == dp[i-1][j]){
		return bt(i-1, j);
	}
	uses.insert(i);
	return bt(i-1, j-weight[i]) + 1;
}


weight.push_back(0); value.push_back(0);
memset(dp, 0, sizeof(dp));

for (int i = 0; i <= N; i++){//Iterative part
	for (int j = 0; j <= P; j++){
		ll a,b;
		(i > 0) ? a = dp[i-1][j] : a = 0;
		(i > 0 && j-weight[i] >= 0) ? b = dp[i-1][j-weight[i]] + value[i] : b = 0;
		dp[i][j] = max(a,b);
	}
}

cout << "Max value: " << dp[N][P] << endl;
cout << "Number of itens in the bag: " << bt(N, P) << endl;
for (int i : uses) cout << "Weight: " << weight[i] << " Value: " << value[i] << endl;


//Recursively
ll dp[N][W], N, W;
vector<ii> H;
 
ll solve(int n, int left){
	if (n == N) return 0;
	
	if (dp[n][left] != -1) return dp[n][left];
	
	ll skip = solve(n+1, left), buy = 0;
	
	if (left-H[n].first >= 0)//Check if has money to buy
		buy = H[n].second + solve(n+1, left-H[n].first);
	
	return dp[n][left] = max(skip, buy);
	
}

cout << solve(0, avaible) << endl;
