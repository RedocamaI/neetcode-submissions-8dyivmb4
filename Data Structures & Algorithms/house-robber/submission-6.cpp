class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];

        // base case:
        int prev = nums[n-1];
        int cur = nums[n-2];
        for(int i=n-3;i>=0;i--) {
            int next = max(prev + nums[i], cur);
            prev = cur;
            cur = next;
        }

        return max(cur, prev);
    }
};
