class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int mid = -1;

        while(l <= h){
            mid = l + (h-l)/2;
            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[l]){
                if(nums[l] <= target && target < nums[mid])
                    h = mid-1;
                else    l = mid+1;
            }else if(nums[mid] < nums[h]){
                if(nums[mid] < target && target <= nums[h])
                    l = mid+1;
                else    h = mid-1;
            }
        }

        if(mid != -1 && nums[mid] == target) return mid;
        return -1;
    }
};

// t = 3
// 0 1 2 3 4 5
// 6,1,2,3,4,5
// 3,4,5,6,1,2

