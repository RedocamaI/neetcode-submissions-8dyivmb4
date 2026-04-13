class Solution {
public:
    int getSubsetXORSum(int ind, int xOr, vector<int>& nums) {
        if(ind == nums.size()) {
            return xOr;
        }
        // take:
        int take = getSubsetXORSum(ind+1, xOr^nums[ind], nums);
        // not take:
        int notTake = getSubsetXORSum(ind+1, xOr, nums);

        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = getSubsetXORSum(0, 0, nums);

        return ans;
    }
};