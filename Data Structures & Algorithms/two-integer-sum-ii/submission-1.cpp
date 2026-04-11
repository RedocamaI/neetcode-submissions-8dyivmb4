class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> ump;

        for(int i=0;i<n;i++){
            int num = nums[i];
            if(ump.find(target - num) != ump.end()){
                int x = ump[target-num];
                int y = i;
                return {x+1, y+1};
            }

            ump[nums[i]] = i;
        }

        return {-1, -1};
    }
};
