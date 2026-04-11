class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, -1);
        
        // base case:
        for(int amt=0;amt<=amount;amt++) {
            prev[amt] = ((amt % coins[n-1]) == 0 ? amt/coins[n-1] : 1e9);
        }

        for(int i=n-2;i>=0;i--) {
            vector<int> cur(amount+1, -1);
            for(int amt=0;amt<=amount;amt++) {
                int take = 1e9;
                if(amt >= coins[i])
                    take = 1 + cur[amt-coins[i]];
                
                int notTake = prev[amt];

                cur[amt] = min(take, notTake);
            }
            prev = cur;
        }
        
        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};
