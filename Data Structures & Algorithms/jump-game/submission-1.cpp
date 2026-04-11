class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;
        for(int i=n-2;i>=0;i--) {
            if(i + nums[i] >= goal)
                goal = i;
        }

        return goal == 0;
    }
};


// 0 1 2 3 4
// 1,2,0,1,0
// goal = 1
//       