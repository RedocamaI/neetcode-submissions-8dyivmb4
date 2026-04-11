class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n-k+1;i++){
            int maxel = -1e9;
            for(int j=i;j<i+k;j++){
                maxel = max(maxel, nums[j]);
            }
            ans.push_back(maxel);
        }

        return ans;
    }
};
