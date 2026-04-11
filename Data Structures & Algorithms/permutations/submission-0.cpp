class Solution {
public:
    vector<vector<int>> ans;

    void getPermutes(int ind, vector<int>& nums) {
        if(ind == nums.size())
            ans.push_back(nums);
        
        for(int j=ind;j<nums.size();j++) {
            swap(nums[ind], nums[j]);

            getPermutes(ind+1, nums);

            swap(nums[ind], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1)    return {nums};
        
        getPermutes(0, nums);
        return ans;
    }
};
