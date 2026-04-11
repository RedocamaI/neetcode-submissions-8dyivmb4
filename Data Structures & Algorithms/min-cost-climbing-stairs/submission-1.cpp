class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        dp[n] = 0;
        dp[n-1] = cost[n-1];
        for(int i=n-2;i>=0;i--) {
            int currCost = cost[i];
            int c1 = currCost + dp[i+1];
            int c2 = currCost + dp[i+2];

            dp[i] = min(c1, c2);
        }

        return min(dp[0], dp[1]);
    }
};
