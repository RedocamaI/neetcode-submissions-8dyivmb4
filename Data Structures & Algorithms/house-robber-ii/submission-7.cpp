class Solution {
public:
    int getMaxMoney(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        
        // base case:
        int prev = nums[n-1];
        int cur = max(nums[n-2], nums[n-1]);
        for(int i=n-3;i>=0;i--) {
            int next = max(prev + nums[i], cur);
            prev = cur;
            cur = next;
        }

        return max(prev, cur);
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
