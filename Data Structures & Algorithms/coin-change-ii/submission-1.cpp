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
        vector<int> prev(amount+1, 0);
        for(int t=0;t<=amount;t++) {
            prev[t] = ((t % coins[n-1]) == 0);
        }

        for(int i=n-2;i>=0;i--) {
            vector<int> cur(amount+1, 0);
            for(int target=0; target<=amount; target++) {
                
                int take = 0;
                if(target >= coins[i])
                    take = cur[target-coins[i]];
                
                int notTake = prev[target];

                cur[target] = take + notTake;
            }

            prev = cur;
        }

        return prev[amount];
    }
};
