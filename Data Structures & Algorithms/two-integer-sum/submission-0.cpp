class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> ump;

        for(int i=0;i<n;i++){
            int val = target - nums[i];

            if(ump.find(val) != ump.end())  return {ump[val], i};
            
            ump[nums[i]] = i;
        }

        return {-1, -1};
    }
};
