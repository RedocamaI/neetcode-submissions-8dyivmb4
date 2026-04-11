class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    vector<int> sub;
    int n;
    void getSubsets(int ind) {
        if(ind == n) {
            ans.push_back(sub);
            return;
        }
        // take:
        sub.push_back(nums[ind]);
        getSubsets(ind+1);

        // backtrack:
        sub.pop_back();
        getSubsets(ind+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();

        getSubsets(0);
        return ans;
    }
};
