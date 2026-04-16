class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        for(int i=0;i<m;i++) {
            nums1[n+i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};