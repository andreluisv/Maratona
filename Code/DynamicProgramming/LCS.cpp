//Longest Common Subsequence

string str1, str2;

//Recursive function returning only the size
int dp[ms][ms];

int LCS(int i, int j){
	if (dp[i][j] != -1) return dp[i][j];
 
	if (i >= str1.size() || j >= str2.size())
		return dp[i][j] = 0;
	else if (str1[i] == str2[j])
		return dp[i][j] =  1 + LCS(i+1, j+1);
	else{
		int one = LCS(i+1,j), two = LCS(i,j+1);
		return dp[i][j] = max(one, two);
	}
}

//Recursive function with retrieve of the string
string dp[ms][ms];

string LCS(int i, int j){
	if (dp[i][j] != "-1") return dp[i][j];
 
	if (i >= str1.size() || j >= str2.size())
		return dp[i][j] = "";
	else if (str1[i] == str2[j])
		return dp[i][j] =  str1[i] + LCS(i+1, j+1);
	else{
		string one = LCS(i+1,j), two = LCS(i,j+1);
		if (one.size() > two.size())
			return dp[i][j] = one;
		return dp[i][j] = two;
	}
}

//Iterative

string X, Y;
int LCS(int m, int n){
	int L[m+1][n+1];
	int i, j;
	
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				L[i][j] = 1 + L[i-1][j-1];
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	
	return L[m][n];
}
