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
        if (m == 0 || n == 0)
            return 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1, dp);
    }
};