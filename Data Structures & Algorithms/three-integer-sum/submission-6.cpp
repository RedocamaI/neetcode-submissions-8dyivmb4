class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1])   continue;
            int a = nums[i];
            unordered_map<int, int> ump;
            int l = i+1, r = n-1;
            while(l < r){
                int t = a + nums[l] + nums[r];
                if(t > 0)   r--;
                else if(t < 0)  l++;
                else{
                    ans.push_back({a, nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l-1])    l++;
                }
            }
        }

        return ans;
    }
};
