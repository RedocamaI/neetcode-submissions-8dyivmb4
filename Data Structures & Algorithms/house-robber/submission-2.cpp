class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        if(n < 3)   return max(nums[0], nums[1]);

        vector<int> dp(n, -1);
        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];

        for(int i=n-3;i>=0;i--) {
            int maxMoneyTillNow = 0;
            for(int j=i+2;j<n;j++) {
                maxMoneyTillNow = max(maxMoneyTillNow, dp[j]);
            }

            dp[i] = nums[i] + maxMoneyTillNow;
        }

        return max(dp[0], dp[1]);
    }
};
