class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int val = nums[abs(nums[i])-1];
            if(val < 0) return abs(nums[i]);
            nums[abs(nums[i])-1] *= -1;
        }

        return -1;
    }
};
