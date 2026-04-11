class Solution {
public:
    int getMaxMoney(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        vector<int> dp(n, -1);

        // base case:
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2], nums[n-1]);

        for(int i=n-3;i>=0;i--) {
            dp[i] = max(dp[i+2] + nums[i], dp[i+1]);
        }

        return max(dp[0], dp[1]);
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
