class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
            return 0;
        if (i < 0 || j < 0)
            return 0;
        if (i == 0 && j == 0)
            return dp[i][j] = 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = solve(i, j - 1, dp, obstacleGrid) + solve(i - 1, j, dp, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp, obstacleGrid);
    }
};