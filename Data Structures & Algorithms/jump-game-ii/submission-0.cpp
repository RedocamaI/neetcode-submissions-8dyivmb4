class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        for(int i=n-2;i>=0;i--) {
            int minJump = 1e9;
            for(int j=1;j<=nums[i];j++) {
                if(i+j >= n)    break;
                
                minJump = min(minJump, 1+dp[i+j]);
            }

            dp[i] = minJump;
        }

        return dp[0];
    }
};
