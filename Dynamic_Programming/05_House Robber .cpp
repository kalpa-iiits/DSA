class Solution
{

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        int pick, notPick;

        for (int i = 1; i < n; i++)
        {
            pick = nums[i] + dp[i - 2];
            notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};