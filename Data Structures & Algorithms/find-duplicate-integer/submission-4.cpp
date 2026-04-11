class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast)    break;
        }

        int slow2 = 0;
        while(true) {
            slow2 = nums[slow2];
            slow = nums[slow];

            if(slow == slow2)
                return slow;
        }

        return -1;
    }
};
// 0 1 2 3 4
// 1,2,3,2,2
// s s s
// f . f .
//     f




