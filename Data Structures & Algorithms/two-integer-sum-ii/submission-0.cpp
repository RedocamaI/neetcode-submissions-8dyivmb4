class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=0;j<n;j++){
                if(j == i)  continue;
                if(nums[i]+nums[j] == target)   return {i < j ? i+1 : j+1, i < j ? j+1 : i+1};
            }
        }

        return {-1, -1};
    }
};
