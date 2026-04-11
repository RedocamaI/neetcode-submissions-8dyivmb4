class Solution {
public:
    vector<vector<int>> combos;
    vector<int> combo;
    int n;
    void getCombos(int ind, int t, 
    vector<int>& nums) {
        if(t < 0)   return;
        if(ind == n) {
            if(t > 0 || t < 0)   return;
            combos.push_back(combo);
            return;
        }
        if(t == 0) {
            combos.push_back(combo);
            return;
        }

        // take:
        combo.push_back(nums[ind]);
        getCombos(ind, t-nums[ind], nums);

        // backtrack:
        combo.pop_back();
        // not take:
        getCombos(ind+1, t, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->n = nums.size();
        getCombos(0, target, nums);
        
        return combos;
    }
};
