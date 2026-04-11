class Solution {
public:
    int longestIncLength(int i, int j, vector<int>& nums,
    vector<vector<int>>& dp) {
        if(i == nums.size())
            return 0;
        if(dp[i][j+1] != -1)
            return dp[i][j+1];
        
        // take:
        int take = 0;
        if(j == -1) {
            take = 1 + longestIncLength(i+1, i, nums, dp);
        }else if(nums[j] < nums[i])
            take = 1 + longestIncLength(i+1, i, nums, dp);
        
        // not take:
        int notTake = longestIncLength(i+1, j, nums, dp);

        return dp[i][j+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return longestIncLength(0, -1, nums, dp);
    }
};
