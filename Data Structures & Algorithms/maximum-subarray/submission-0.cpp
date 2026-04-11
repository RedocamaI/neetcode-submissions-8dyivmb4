class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e9;
        int sum = 0;

        for(auto& num:nums) {
            sum += num;
            maxSum = max(sum, maxSum);

            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};
