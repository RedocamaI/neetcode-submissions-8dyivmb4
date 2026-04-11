class Solution {
public:
    int getMaxCoins(int l, int r, 
    vector<int>& nums,
    vector<vector<int>>& dp) {
        if(l > r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];

        int maxCoins = 0;
        for(int i=l;i<=r;i++) {
            int coins = nums[l-1]*nums[i]*nums[r+1] +
            getMaxCoins(l, i-1, nums, dp) + 
            getMaxCoins(i+1, r, nums, dp);

            maxCoins = max(maxCoins, coins);
        }

        return dp[l][r] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        // return getMaxCoins(1, n, nums, dp);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i=n;i>=1;i--) {
            for(int j=1;j<=n;j++) {
                if(i > j)
                    continue;
                
                int maxCoins = -1e9;
                for(int k=i;k<=j;k++) {
                    int coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1]
                    + dp[k+1][j];

                    maxCoins = max(maxCoins, coins);
                }

                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
};
