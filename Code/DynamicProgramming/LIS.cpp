//Longest Increasing Subsequence

vector<int> data, dp, ans;
dp.resize(data.size(), 1); ans.resize(data.size(), -1);
pair<int, int> best = {0,0};

for (int i = 0; i < data.size(); i++){
	for (int j = 0; j < i; j++){
		if (data[j] < data[i]){
			//dp[i] = max(dp[i], dp[j]+1);
			if (dp[j]+1 > dp[i]){
				dp[i] = dp[j]+1;
				ans[i] = j;
			}
		}
	}
	best = max(best, {dp[i], i});
	//if (best.x < dp[i]) best = {dp[i], i};
}

int index = best.y; set<int> print;
while(index > -1){
	print.insert(data[index]);
	index = ans[index];
}

printf("Size of LIS: %d\n", best.x);
for (auto x : print) printf("%d\n", x);
