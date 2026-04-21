class Solution {
public:
    void merge(int i, int mid, int j, vector<int>& nums) {
        int x = i;
        int y = mid+1;
        vector<int> merged;
        while(x <= mid && y <= j) {
            if(nums[x] <= nums[y]) {
                merged.push_back(nums[x++]);
            }else {
                merged.push_back(nums[y++]);
            }
        }

        while(x <= mid) {
            merged.push_back(nums[x++]);
        }

        while(y <= j) {
            merged.push_back(nums[y++]);
        }

        x = 0;
        for(int ind=i;ind<=j;ind++) {
            nums[ind] = merged[x++];
        }
    }

    void mergeSort(int i, int j, vector<int>& nums) {
        if(i == j)
            return;
        
        int mid = (i+j)/2;
        
        mergeSort(i, mid, nums);
        mergeSort(mid+1, j, nums);
        merge(i, mid, j, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        mergeSort(0, n-1, nums);
        return nums;
    }
};