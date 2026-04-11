class Solution {
public:
    int getWays(int ind, int target, 
    vector<int>& coins, vector<vector<int>>& dp) {
        if(ind == coins.size())
            return target == 0;
        if(ind == coins.size()-1)
            return dp[ind][target] = (target%coins[ind] == 0);
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        // take:
        int take = 0;
        if(target >= coins[ind])
            take = getWays(ind, target-coins[ind], coins, dp);
        
        // not take:
        int notTake = getWays(ind+1, target, coins, dp);

        return dp[ind][target] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return getWays(0, amount, coins, dp);
    }
};
