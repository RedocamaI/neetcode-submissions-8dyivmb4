class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

// 0 0 0 0
//             ----> [0, ]
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int a = -1*nums[i];
            int j = i+1, k = n-1;
            while(j < k) {
                int b = nums[j];
                int c = nums[k];

                if((b+c) == a) {
                    ans.push_back({nums[i], b, c});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                    
                    continue;
                }

                if((b+c) < a) {
                    j++;
                }else if((b+c) > a) {
                    k--;
                }
            }
        }

        return ans;
    }
};
