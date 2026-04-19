class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        int cnt = 1;
        for(int i=1;i<n;i++) {
            if(x == nums[i]) {
                cnt++;
            }else {
                cnt--;
                if(cnt == 0) {
                    x = nums[i];
                    cnt = 1;
                }
            }
        }

        return x;
    }
};