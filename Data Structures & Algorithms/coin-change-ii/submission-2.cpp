class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

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
