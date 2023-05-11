// You are given an integer array coins representing coins of different 
//denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. 
//If that amount of money cannot be made up by any combination of the coins, return 0.

class Solution {
public:

    int solve(vector<int>& coins, int amount,int n){
        int dp[n+1][amount+1];
        for(int i = 0; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j=1; j<=amount; j++){
               if(coins[i-1] <=j){
                   int take = dp[i][j-coins[i-1]];
                   int discard = dp[i-1][j];
                   dp[i][j] = take + discard;
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
            }
        }
        return dp[n][amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(n == 0) return 0;
        int ans = solve(coins, amount, n);

        return ans;
    }
};