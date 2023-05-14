// https://www.youtube.com/watch?v=mFwf1YbH-Jk
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();
        if (k >= n / 2)
        { // if k is large, buy and sell every day
            int profit = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }

        vector<int> dp(n, 0);
        for (int j = 1; j <= k; j++)
        {
            vector<int> dp2(n, 0);
            int max_diff = -prices[0];
            for (int i = 1; i < n; i++)
            {
                dp2[i] = max(dp2[i - 1], prices[i] + max_diff);
                max_diff = max(max_diff, dp[i - 1] - prices[i]);
            }
            dp = dp2;
        }
        return dp[n - 1];
    }
};