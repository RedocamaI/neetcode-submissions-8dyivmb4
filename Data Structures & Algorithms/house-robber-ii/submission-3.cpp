class Solution {
public:
    int getMaxMoney(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        vector<int> dp(n, -1);

        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];
        for(int i=n-3;i>=0;i--) {
            int maxMoneyTillNow = 0;
            for(int j=i+2;j<n;j++) {
                maxMoneyTillNow = max(maxMoneyTillNow, dp[j]);
            }

            dp[i] = maxMoneyTillNow + nums[i];
        }

        return max(dp[0], dp[1]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];

        // 0 to n-2:
        int x = nums[n-1];
        nums.pop_back();
        int max1 = getMaxMoney(nums);

        // 1 to n-1:
        nums.push_back(x);
        nums.erase(nums.begin());
        int max2 = getMaxMoney(nums);

        return max(max1, max2);
    }
};
