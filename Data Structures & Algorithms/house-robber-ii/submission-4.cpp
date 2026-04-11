class Solution {
public:
    int getMoney(int ind, vector<int>& dp, vector<int>& nums) {
        if(ind >= nums.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];

        // take:
        int max1 = getMoney(ind+2, dp, nums) + nums[ind];
        // not take:
        int max2 = getMoney(ind+1, dp, nums);

        return dp[ind] = max(max1, max2);
    }

    int getMaxMoney(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        int max1 = getMoney(0, dp, nums);
        int max2 = getMoney(1, dp, nums);

        return max(max1, max2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];

        int last = nums.back();
        nums.pop_back();
        int max1 = getMaxMoney(nums);
        
        nums.push_back(last);
        nums.erase(nums.begin());
        int max2 = getMaxMoney(nums);

        return max(max1, max2);
    }
};
