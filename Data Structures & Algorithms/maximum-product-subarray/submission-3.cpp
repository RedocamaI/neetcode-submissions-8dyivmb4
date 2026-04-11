class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[n-1] = nums[n-1];
        int mn = nums[n-1];
        int mx = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            dp[i] = max({nums[i], nums[i]*mx, nums[i]*mn});
            int tmx = mx;
            mx = max({nums[i], nums[i]*mx, nums[i]*mn});
            mn = min({nums[i], nums[i]*tmx, nums[i]*mn});
        }

        return *max_element(dp.begin(), dp.end());
    }
};
