class Solution {
public:
    int total;
    bool isPos(int ind, int sum,
    vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == nums.size())
            return dp[ind][sum] = (sum == 0);
        if(sum == 0)
            return dp[ind][sum] = true;
        if(dp[ind][sum] != -1)
            return dp[ind][sum];

        // take:
        bool take = false;
        if(sum - nums[ind] >= 0)
            take = isPos(ind+1, sum-nums[ind], nums, dp);

        if(take)
            return dp[ind][sum] = take;
        // not take:
        bool notTake = isPos(ind+1, sum, nums, dp);

        return dp[ind][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        if(sum%2)   return false;
        vector<vector<int>> dp(n+1, vector<int>(sum/2 + 1, -1));
        return isPos(0, sum/2, nums, dp);
    }
};
