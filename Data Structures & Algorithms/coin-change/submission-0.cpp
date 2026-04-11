class Solution {
public:
    bool pos = true;
    int getMinCoins(int ind, vector<int>& coins, int amount,
    vector<vector<int>>& dp) {
        if(ind == coins.size()-1) {
            if(amount % coins[ind] == 0) {
                return dp[ind][amount] = amount/coins[ind];
            }
            return 1e9;
        }
        if(dp[ind][amount] != -1)
            return dp[ind][amount];

        // take:
        int take = 1e9;
        if(amount >= coins[ind])
            take = 1 + getMinCoins(ind, coins, amount-coins[ind], dp);
        
        int notTake = getMinCoins(ind+1, coins, amount, dp);

        return dp[ind][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = getMinCoins(0, coins, amount, dp);

        return dp[0][amount] >= 1e9 ? -1 : dp[0][amount];
    }
};
