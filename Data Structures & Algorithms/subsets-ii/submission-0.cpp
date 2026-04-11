class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void getSub(int ind, vector<int> sub, vector<int>& nums) {
        ans.push_back(sub);

        for(int i=ind;i<n;i++) {
            if(i > ind && nums[i] == nums[i-1])
                continue;
            
            // take:
            sub.push_back(nums[i]);
            getSub(i+1, sub, nums);

            // backtrack:
            sub.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->n = nums.size();
        sort(nums.begin(), nums.end());

        getSub(0, {}, nums);
        return ans;
    }
};

// ind
// [1,  1,  2]
//  i.      i


// sub: [1,2]
// ans: [[1], [1,1], [1,1,2], [1,2], []]








