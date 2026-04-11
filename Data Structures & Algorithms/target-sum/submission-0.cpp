class Solution {
public:
    int getWays(int ind, int target, 
    vector<int>& nums) {
        if(ind == nums.size()) {
            return (target == 0);
        }
        
        // add:
        int add = getWays(ind+1, target-nums[ind], nums);
        // sub:
        int sub = getWays(ind+1, target+nums[ind], nums);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        return getWays(0, target, nums);
    }
};
