class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));

        dp[n][0] = 0;
        dp[n][1] = 0;
        dp[n][2] = 0;
        for(int ind=n-1;ind>=0;ind--) {
            int profit = 0;

            // baught at ind:
            // sell at any i:
            for(int i=ind+1;i<n;i++) {
                if(prices[i] < prices[ind])
                    continue;
                profit = max(profit,
                    prices[i]-prices[ind] + dp[i][2]);
            }
            dp[ind][1] = profit;

            // sold at ind:
            // buy or pass at any i:
            profit = 0;
            for(int i=ind+2;i<n;i++) {
                profit = max({
                    profit, dp[i][1], dp[i][0]
                });
            }
            dp[ind][2] = profit;

            // pass at ind
            // buy or pass at ind+1:
            profit = max({
                0, dp[ind+1][1], dp[ind+1][0]
            });
            dp[ind][0] = profit;
        }

        return max(dp[0][0], dp[0][1]);
    }
};
