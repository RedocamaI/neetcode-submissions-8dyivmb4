class Solution {
public:
    pair<bool, bool> isPos(vector<int>& nums, int val, int k) {
        int x = 0;
        bool isThere = false;
        for(auto& num:nums){
            if(num > val)   x++;
            if(num == val)  isThere = true;
        }

        return {x <= k, isThere};
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int minel = 1e9;
        int maxel = -1001;
        for(auto& num:nums){
            minel = min(minel, num);
            maxel = max(maxel, num);
        }

        int l = minel;
        int h = maxel;
        int ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            pair<bool, bool> p = isPos(nums, mid, k-1);
            bool pos = p.first;
            bool isThere = p.second;
            if(pos){
                ans = isThere ? mid : -1;
                h = mid-1;
            }else   l = mid+1;
        }

        return ans;
    }
};
