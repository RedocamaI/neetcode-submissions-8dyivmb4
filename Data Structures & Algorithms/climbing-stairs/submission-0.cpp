class Solution {
public:
    vector<int> dp;
    int getWays(int n) {
        if(n == 0)
            return dp[n] = 1;
        if(dp[n] != -1) return dp[n];

        dp[n] = getWays(n-1) + getWays(n-2);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        this->dp = dp;
        
        return getWays(n);
    }
};
