class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // base case:
        for(int amt=0;amt<=amount;amt++) {
            dp[n-1][amt] = ((amt % coins[n-1]) == 0 ? amt/coins[n-1] : 1e9);
        }

        for(int amt=0;amt<=amount;amt++) {
            for(int i=n-2;i>=0;i--) {
                int take = 1e9;
                if(coins[i] <= amt)
                    take = 1 + dp[i][amt-coins[i]];
                
                int notTake = dp[i+1][amt];

                dp[i][amt] = min(take, notTake);
            }
        }
        
        return dp[0][amount] >= 1e9 ? -1 : dp[0][amount];
    }
};
