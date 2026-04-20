class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k%n;
        reverse(nums.begin(), nums.end());

        int i = 0;
        int j = k-1;
        while(i < j) {
            swap(nums[i++], nums[j--]);
        }

        i = k;
        j = n-1;
        while(i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};