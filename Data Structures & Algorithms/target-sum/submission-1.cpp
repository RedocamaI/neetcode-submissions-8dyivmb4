class Solution {
public:
    int getWays(int ind, int target, 
    vector<int>& nums, vector<vector<int>>& dp) {
        if(ind == 0) {
            if(target == 0 && nums[ind] == 0)
                return dp[ind][target] = 2;
            if(target == 0 || nums[ind] == target)
                return dp[ind][target] = 1;
            
            return 0;
        }
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        // add:
        int t = 0;
        if(target >= nums[ind])
            t = getWays(ind-1, target-nums[ind], nums, dp);
        // sub:
        int nt = getWays(ind-1, target, nums, dp);

        return dp[ind][target] = t + nt;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }

        if(sum - target < 0)
            return 0;
        if((sum + target) % 2)
            return 0;

        int newTarget = (sum + target)/2;
        vector<vector<int>> dp(n+1, vector<int>(newTarget+1, -1));
        
        return getWays(n-1, newTarget, nums, dp);
    }
};
