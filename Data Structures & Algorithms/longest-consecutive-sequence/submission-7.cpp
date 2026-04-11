class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;

        sort(nums.begin(), nums.end());
        int ans = 1;
        int l = 1;

        for(int i=1;i<n;i++){
            if(nums[i]-1 == nums[i-1]){
                l++;
            }else if(nums[i] == nums[i-1])  continue;
            else{
                ans = max(l, ans);
                l = 1;
            }
        }

        return max(ans, l);
    }
};
