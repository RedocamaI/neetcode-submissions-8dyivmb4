class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind = -1;
        int n = nums.size();
        int l = 0, h = n-1;
        while(l <= h){
            int mid = l + (h-l)/2;

            if(target == nums[mid]) return mid;

            if(target > nums[mid])  l = mid+1;
            else    h = mid-1;
        }

        return nums[h] == target ? h : -1;
    }
};
