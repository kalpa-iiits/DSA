i
// value(n) = summation(i=0 to n-1)(price[i] + value(n-i-1))

nt cutRod(vector<int> &price, int n)
{
	int dp[n+1];

	memset(dp, -1, sizeof(dp);

	for(int i=0; i<=n; i++){
		for(j=0; j<i;j++){
			dp[i] = max(dp[i], price[j] + dp[i-j-1]);
		}
	}
	return dp[n];
}