// medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for (auto price : prices)
        {
            buy1 = min(buy1, price);
            profit1 = max(profit1, price - buy1);
            buy2 = min(buy2, price - profit1); // Already ,made profit1, so pay only price-proit1 from pocket
            profit2 = max(profit2, price - buy2);
        }
        return profit2;
    }
};