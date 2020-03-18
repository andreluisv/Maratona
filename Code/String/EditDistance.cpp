const int inf = INT_MAX;
/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
->Insert a character
->Delete a character
->Replace a character
*/

vector<vector<int>> dp;
string str1, str2;
int solveMinDistance(int i, int j){
    if (i<0) return j+1;
    if (j<0) return i+1;
    if (dp[i][j] != inf) return dp[i][j];
    if (str1[i]==str2[j]) return dp[i][j] = solveMinDistance(i-1,j-1);
    
    int a = inf, b = inf, c = inf;
    //rem i
    a = solveMinDistance(i-1,j) +1;
    //rem j
    b = solveMinDistance(i,j-1) +1;
    //replace
    c = solveMinDistance(i-1,j-1) +1;
    
    return dp[i][j] = min(dp[i][j], min(a,min(b,c)));
}

int GetEditDistance(string word1, string word2) {
    str1 = word1; str2 = word2;
    dp.resize(str1.size(), vector<int>(str2.size(), inf));
    return solveMinDistance(str1.size()-1, str2.size()-1);
}
