int Un_knapsack(int wt[], int val[], int W, int n) {
    
	vector<vector<int>> dp(n+1, vector<int> (W+1, INT_MIN));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

    for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
	
			if (wt[i - 1] <= j) {
				int val1 = val[i - 1] + t[i][j - wt[i - 1]];
				int val2 = t[i - 1][j]; 
				dp[i][j] = max(val1, val2);
			}
			else 
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][W];
}