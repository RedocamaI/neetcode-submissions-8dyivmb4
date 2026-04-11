class Solution {
public:
    int getMaxMoney(int ind, vector<int>& dp, vector<int>& nums) {
        if(ind >= nums.size())  return 0;
        if(dp[ind] != -1)   return dp[ind];
        
        int max1 = getMaxMoney(ind+2, dp, nums) + nums[ind];
        int max2 = getMaxMoney(ind+1, dp, nums);

        return dp[ind] = max(max1, max2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int max1 = getMaxMoney(0, dp, nums);
        dp.resize(n, -1);
        int max2 = getMaxMoney(1, dp, nums);

        return max(max1, max2);
    }
};
