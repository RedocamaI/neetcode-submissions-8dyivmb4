class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = -1e9;
        int val = nums[n-1];
        ans = max(ans, val);
        
        int mn = nums[n-1];
        int mx = nums[n-1];
        for(int i=n-2;i>=0;i--) {
            val = max({nums[i], nums[i]*mx, nums[i]*mn});
            ans = max(ans, val);

            int tmx = mx;
            mx = max({nums[i], nums[i]*mx, nums[i]*mn});
            mn = min({nums[i], nums[i]*tmx, nums[i]*mn});
        }

        return ans;
    }
};
