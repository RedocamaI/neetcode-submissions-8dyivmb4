class Solution {
public:
    int getMaxProfit(int ind, int buy, 
    vector<int>& prices, vector<vector<int>>& dp) {
        if(ind == prices.size()) {
            return 0;
        }
        if(dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;
        // sell:
        if(buy == 1) {
            for(int i=ind+1;i<prices.size();i++) {
                if(prices[i] < prices[ind])
                    continue;
                profit = max(profit,
                    (prices[i]-prices[ind]) + getMaxProfit(i, 2, prices, dp));
            }
        }else if(buy == 2) {
            // can't buy the next day!
            // so buying or passing from next to next day:
            for(int i=ind+2;i<prices.size();i++) {
                profit = max({
                    profit, getMaxProfit(i, 1, prices, dp),
                    getMaxProfit(i, 0, prices, dp)
                });
            }
        }else
            profit = max({
                profit, getMaxProfit(ind+1, buy, prices, dp),
                getMaxProfit(ind+1, 1, prices, dp)
            });

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return max(
            getMaxProfit(0, 0, prices, dp),
            getMaxProfit(0, 1, prices, dp)
        );
    }
};
