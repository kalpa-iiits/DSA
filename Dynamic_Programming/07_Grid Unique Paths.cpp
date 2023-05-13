class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return dp[i][j] = 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = solve(i, j - 1, dp) + solve(i - 1, j, dp);
    }
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, dp);
    }
};
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

                                                                                 class Solution
{
public:
    int uniquePaths(int m, int n){
        int uniquePaths(int m, int n){
            int dp[m + 1][n + 1];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1)
                dp[i][j] = 1;
        }
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}
}
;