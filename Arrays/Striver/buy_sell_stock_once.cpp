/* 
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0, min_val = prices[0];
        int n = prices.size();

        for(int i = 1; i < n; i++) {

            min_val = min(min_val, prices[i]);
            max_profit = max(max_profit, prices[i] - min_val); 
        
        }
        return max_profit;
    };
}