class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> pos(n, false);
        pos[n-1] = true;
        int last = n-1;
        for(int i=n-2;i>=0;i--) {
            int maxJump = min(nums[i], last-i);
            bool isPos = false;
            for(int j=1;j<=maxJump;j++) {
                if(pos[i+j]) {
                    isPos = true;
                    break;
                }
            }

            pos[i] = isPos;
        }

        return pos[0];
    }
};
