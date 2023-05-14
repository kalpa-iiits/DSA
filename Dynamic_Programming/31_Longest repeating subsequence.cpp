int lcs(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();

    int dp[n + 1][m + 1];

    if (n == 0 || m == 0)
        return 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][m];
}

int LRS(string text1)
{
    int n = text1.length();
    cout << LCS(text1, text1, n, n) << endl;
}