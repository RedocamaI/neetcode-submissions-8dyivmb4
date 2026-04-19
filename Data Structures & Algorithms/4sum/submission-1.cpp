class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(target < 0 && nums[0] >= 0)
            return {};
        if(target > 0 && nums[n-1] <= 0)
            return {};
        set<vector<int>> combos;

        for(int i=0;i<n;i++) {
            int a = nums[i];
            for(int j=i+1;j<n;j++) {
                int b = nums[j];
                unordered_map<int, int> ump;
                int t = target - (a + b);
                for(int k=j+1;k<n;k++) {
                    int val = t - nums[k];
                    if(ump.find(val) != ump.end()) {
                        combos.insert({a, b, val, nums[k]});
                        continue;
                    }
                    ump[nums[k]]++;
                }
            }
        }

        if(combos.empty())
            return {};

        vector<vector<int>> ans;
        for(auto& vec:combos) {
            ans.push_back(vec);
        }

        return ans;
    }
};