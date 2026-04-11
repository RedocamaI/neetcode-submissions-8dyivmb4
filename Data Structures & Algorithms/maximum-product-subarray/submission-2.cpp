class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = -1e9;
        for(int i=0;i<n;i++) {
            int prod = 1;
            for(int j=i;j<n;j++) {
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }

        return ans;
    }
};
