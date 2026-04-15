class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int li = -1;
        int numVals = 0;
        for(int i=n-1;i>=0;i--) {
            if(nums[i] == val) {
                if(li == -1)
                    li = i;
                numVals++;
            }
        }

        int i = li+1;
        int x = numVals;
        for(int i=li+1;i<n;i++) {
            nums[i-x] = nums[i];
        }

        return n - x;
    }
};