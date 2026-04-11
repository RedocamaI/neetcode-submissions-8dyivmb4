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
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return getMaxCoins(1, n, nums, dp);
    }
};
