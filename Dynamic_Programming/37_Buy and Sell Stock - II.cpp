https://medium.com/@punitkmr/best-time-to-buy-and-sell-stock-ii-7826845144eb (peak valley approach)

https://medium.com/@rebeccahezhang/leetcode-122-best-time-to-buy-and-sell-stock-ii-fbf6d66d62e3

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1])
                maxProfit += prices[i] - prices[i-1];
        }
        return maxProfit;
    }
};