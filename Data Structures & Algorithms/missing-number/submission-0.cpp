class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i=1;i<=n;i++) {
            x ^= i;
        }

        for(auto& num:nums)
            x ^= num;
        
        return x;
    }
};
