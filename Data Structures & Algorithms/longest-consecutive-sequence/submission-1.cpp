class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // brute force: O(n^2)
        int l = 0;
        int ans = 1;
        int n = nums.size();
        if(n == 0)  return 0;
        unordered_map<int, int> ump;

        for(auto& num:nums){
            ump[num]++;
        }

        for(int i=0;i<n;i++){
            l = 1;
            int curr = nums[i]+1;
            while(ump.find(curr) != ump.end()){
                l++;
                curr++;
            }

            ans = max(ans, l);
        }

        return ans;
    }
};
