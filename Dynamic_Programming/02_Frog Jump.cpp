class Solution
{
public:
    map<pair<int, int>, bool> dp;
    map<int, bool> stone;
    bool solve(int pos, int k, int lastPos)
    {
        if (pos == lastPos)
            return true;

        if (k <= 0 || pos > lastPos)
            return false;

        if (dp.find({pos, k}) != dp.end())
        {
            return dp[{pos, k}];
        }

        if (stone[pos])
        {
            return dp[{pos, k}] = (solve(pos + k, k, lastPos) ||
                                   solve(pos + k + 1, k + 1, lastPos) ||
                                   solve(pos + k - 1, k - 1, lastPos));
        }

        return dp[{pos, k}] = false;
    }
    bool canCross(vector<int> &stones)
    {
        int lastPos = stones.back();
        for (int i : stones)
        {
            stone[i] = true;
        }
        return solve(1, 1, lastPos);
    }
};